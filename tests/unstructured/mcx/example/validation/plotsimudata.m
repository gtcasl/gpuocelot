%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  matlab script to produce the validation plots (Fig. 4)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

if(exist('loadmc2')~=2)
	error('you need to first add path to ''<mcx>/utils'' in order to run this script');
end

c0=299792458000;
srcpos=[30 30 1];
detpos=[30 15 10];
twin=[5e-11:1e-10:5e-9];

%----------------------------------------------------------------
%  Plot time-domain comparison at a given position
%----------------------------------------------------------------

figure;
hold on;

mcx=loadmc2('semi_infinite.mc2',[60 60 60 50]);
semilogy((1:50)/10,tddiffusion(0.005, 1, c0, 0, srcpos, detpos,twin),'r');
semilogy((1:50)/10,squeeze(mcx(30,14,9,:)),'o');

mcxb=loadmc2('semi_infinite_b.mc2',[60 60 60 50]);
semilogy((1:50)/10,tddiffusion(0.005, 1, c0/1.37, 0.493, srcpos, detpos,twin),'r--');
semilogy((1:50)/10,squeeze(mcxb(30,14,9,:)),'+');

set(gca,'ylim',[1 10^8.5]);

legend('Diffusion (no reflection)','MCX (no reflection)','Diffusion (with reflection)','MCX (with reflection)');
legend boxoff;
set(gca,'yscale','log');
set(gca,'fontsize',18);
xlabel('time (ns)')
ylabel('Fluence in 1/(m^2s)')
box on;
saveas(gcf,'td_validate.fig')
print -depsc2 td_validate.eps

%----------------------------------------------------------------
%  Plot	CW comparison along a line
%----------------------------------------------------------------

figure;
hold on;

cwmcx=sum(mcx,4); 
srcpos=[0 0 0];
detpos=[0.5+(0:29)', 0.5*ones(30,1),0.5*ones(30,1)];
phicw=cwdiffusion(0.005, 1, 0, srcpos, detpos);
phimcx=cwmcx(30,:,1);

cwmcxb=sum(mcxb,4);
phicwb=cwdiffusion(0.005, 1, 0.493, srcpos, detpos);
phimcxb=(cwmcxb(30,:,1));
h=semilogy(1:30, phicw, 'r-', 1:30, phimcx(30:59)*1e-10, 'o', 1:30, phicwb, 'r--', 1:30, phimcxb(30:59)*1e-10, 'b+');
box on;
set(gca,'yscale','log')

legend('Diffusion (no reflection)','MCX (no reflection)','Diffusion (with reflection)','MCX(with reflection)');
legend boxoff;
set(gca,'fontsize',18);
xlabel('x (mm)')
ylabel('Fluence in 1/(m^2s)')
saveas(gcf,'td_validate_cw.fig')
print -depsc2 td_validate_cw.eps

%----------------------------------------------------------------
%  Plot CW comparison at a cross-section
%----------------------------------------------------------------

figure
hold on;

clines = -1.5:-0.5:-4;
srcpos=[29.5 29.5 0.5];
[xi,yi]=meshgrid(0.5:59.5,0.5:59.5);
detpos=[xi(:) 30*ones(size(xi(:))) yi(:)];
phicw=reshape(cwdiffusion(0.005, 1.0, 0, srcpos, detpos),size(xi));

[c h2]=contour(xi,yi, log10(max(squeeze(phicw),1e-8)), clines, 'k-' );
[c h1]=contour(log10(max(squeeze(cwmcx(:,30,:)*1e-10)',1e-8)), clines, 'k:' );
legend('Diffusion','MCX')
legend boxoff;
box on;
set(gca,'fontsize',18);
xlabel('x (mm)')
ylabel('z (mm)')
saveas(gcf,'td_validate_cw_2d.fig')
print -depsc2 td_validate_cw_2d.eps

%----------------------------------------------------------------
%  Plot time-domain comparison at a cross-section
%----------------------------------------------------------------

c0=299792458000;
twin=5e-11:1e-10:5e-9;
mua=0.005;
musp=1;
Reff=0;

srcpos=[29.5 29.5 0];
[xi,yi]=meshgrid(0.5:59.5,0.5:59.5);

detpos=[xi(:) 29.5*ones(size(xi(:))) yi(:)];		  
for i=1:length(twin)
  phitd(:,:,i)=reshape(tddiffusion(mua,musp,c0,Reff,srcpos,detpos,twin(i)),size(xi));
end

figure;
hold on

for i=1:5:21
  halfmax=max(max(phitd(:,:,i)))/2;
  [c h2]=contour(xi, yi,max(squeeze(phitd(:,:,i)),1e-12),[halfmax halfmax], 'k-');
  halfmax=max(max(mcx(:,30,:,i)))/2;
  [c h2]=contour(max(squeeze(mcx(:,30,:,i))',1e-12),[halfmax halfmax], 'k:');
end
legend('Diffusion','MCX')
legend boxoff;
box on;
set(gca,'fontsize',18);
xlabel('x (mm)')
ylabel('z (mm)')
saveas(gcf,'td_validate_2d.fig')   

print -depsc2 td_validate_2d.eps

