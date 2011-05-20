%%-----------------------------------------------------------------
%% add paths to the necessary toolboxes
%%-----------------------------------------------------------------

addpath('~/space/Projects/mcx/utils/')
addpath('~/space/Projects/mmc/matlab/')

c0=299792458000;
twin=[5e-11:1e-10:5e-9];
gates=50;
clines=[-1:0.5:8];

%%-----------------------------------------------------------------
%% load MCX results
%%-----------------------------------------------------------------
mcx=loadmc2('spherebox.mc2', [60 60 60 gates]);
cwmcx=sum(mcx,4);

%%-----------------------------------------------------------------
%% generate/load analytical solution for sphere inside infinite slab
%%-----------------------------------------------------------------

%[phi_ana,xa,ya,za]=sphdiffusionslab(0,0,60,-22:0.8:22,0,-30:0.8:10);
%save sphdiffsemiinf.mat phi_ana xa ya za

load sphdiffsemiinf.mat
idx=find((xa(:)<-12 | xa(:)>12) & za(:)>-5);
phi_ana(idx)=nan;
idx=find((xa(:)<-10 | xa(:)>10) & za(:)>0);
phi_ana(idx)=nan;

%%-----------------------------------------------------------------
%% generate the contour of the inclusion
%%-----------------------------------------------------------------

[xcirc,ycirc] = cylinder(10,200);
xcirc=xcirc(1,:)+30;
ycirc=ycirc(1,:)+30;

figure
hold on
[cc,hc]=contour(xa+30,za+31,log10(abs(phi_ana))+10,clines,'color',[0.7 0.7 0.7],'linewidth',2);
contour(log10(squeeze(abs(cwmcx(:,30,:)))'),clines,'b-')
plot(xcirc,ycirc,'k--','linewidth',2);

axis equal
set(gca,'xlim',[1 60]);
set(gca,'ylim',[1 60]);
set(gca,'fontsize',18)
xlabel('x (mm)')
ylabel('z (mm)')
legend('Diffusion','MCX')
legend boxoff;
box on;
set(gcf,'PaperPositionMode','auto');

