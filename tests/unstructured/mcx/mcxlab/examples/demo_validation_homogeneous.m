%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% MCXLAB - Monte Carlo eXtreme for MATLAB/Octave by Qianqina Fang
%
% In this example, we validate MCXLAB with a homogeneous medium in a 
% cubic domain. This is exactly the example shown in Fig.5 of Fang2009.
%
% You can also use the alternative optical properties that has a high g
% value to observe the similarity between the two scattering/g configurations.
%
% [Fang2009] Qianqian Fang and David A. Boas, "Monte Carlo simulation 
% of photon migration in 3D turbid media accelerated by graphics processing 
% units," Opt. Express 17, 20178-20190 (2009)
%
% This file is part of Monte Carlo eXtreme (MCX) URL:http://mcx.sf.net
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

if(exist('tddiffusion','file')~=2 | exist('cwdiffusion','file')~=2)
    error(sprintf('Scripts "tddiffusion.m" and "cwdiffusion.m" were not found.\nThis demo requires you to add the "mcx/utils" directory first.'));
end

clear cfg;

%% preparing the input data
% set seed to make the simulation repeatible
cfg.seed=hex2dec('623F9A9E'); 

cfg.nphoton=3e7;

% define a 1cm radius sphere within a 6x6x6 cm box
dim=60;
cfg.vol=ones(dim,dim,dim);
cfg.vol=uint8(cfg.vol);

% define the source position
cfg.srcpos=[dim/2,dim/2,1];
cfg.srcdir=[0 0 1];

% define optical properties, format: [mua(1/mm) mus(1/mm) g n]
cfg.prop=[0 0 1 1          % medium 0: the environment
    0.005 1 0.01 1.0];     % medium 1: the cube

% medium 1a: an alternative that has the same mus'=mus*(1-g) as medium 1.
% use medium 1a can significantly reduce racing
%cfg.prop(2,:)=[0.005 10.1 0.9 1.0];   

% time-domain simulation parameters
cfg.tstart=0;
cfg.tend=5e-9;
cfg.tstep=1e-10;

% GPU thread configuration
cfg.autopilot=1;
cfg.gpuid=1;

cfg.isreflect=0; % disable reflection at exterior boundary

%% running simulation without boundary reflection
fprintf('running simulation ... this takes about 6 seconds on a GTX 470\n');
tic;
f1=mcxlab(cfg);
toc;
f1=f1.data;

%% running simulation with boundary reflection
cfg.prop(2,4)=1.37;
cfg.isreflect=1; % enable reflection at exterior boundary

fprintf('running simulation ... this takes about 11 seconds on a GTX 470\n');
tic;
f2=mcxlab(cfg);
toc;
f2=f2.data;

%% plotting the results

%% plotting TPSF at voxel [30 14 9]

figure
subplot(221);
hold on;

c0=299792458000;
detpos=[30 14 9]; % choose a point inside the domain

twin=cfg.tstart+cfg.tstep/2:cfg.tstep:cfg.tend;
semilogy(twin*1e9,tddiffusion(cfg.prop(2,1), cfg.prop(2,2)*(1-cfg.prop(2,3)), c0, 0, cfg.srcpos, detpos+1, twin),'r');
semilogy(twin*1e9,squeeze(f1(detpos(1),detpos(2),detpos(3),:)),'o');

semilogy(twin*1e9,tddiffusion(cfg.prop(2,1), cfg.prop(2,2)*(1-cfg.prop(2,3)), c0/1.37, 0.493, cfg.srcpos, detpos, twin),'r--');
semilogy(twin*1e9,squeeze(f2(detpos(1),detpos(2),detpos(3),:)),'+');

set(gca,'ylim',[1 10^8.5]);

legend('Diffusion (no reflection)','MCX (no reflection)','Diffusion (with reflection)','MCX (with reflection)');
legend boxoff;
set(gca,'yscale','log');
xlabel('time (ns)')
ylabel('Flux in 1/(mm^2 s)')
box on;

%% plotting spatial decay profile along line y=30 && z=0
subplot(222);
hold on;
cwf1=sum(f1,4);
cwf2=sum(f2,4);

srcpos=[0 0 0];
detpos=[0.5+(0:29)', 0.5*ones(30,1),0.5*ones(30,1)];

phicw=cwdiffusion(cfg.prop(2,1), cfg.prop(2,2)*(1-cfg.prop(2,3)), 0, srcpos, detpos);
phimcx=cwf1(30,:,1);
phicwb=cwdiffusion(cfg.prop(2,1), cfg.prop(2,2)*(1-cfg.prop(2,3)), 0.493, srcpos, detpos);
phimcxb=cwf2(30,:,1);

h=semilogy(1:30, phicw, 'r-', 1:30, phimcx(30:59)*cfg.tstep, 'o', 1:30, ...
    phicwb, 'r--', 1:30, phimcxb(30:59)*cfg.tstep, 'b+');
box on;
set(gca,'yscale','log')

legend('Diffusion (no reflection)','MCX (no reflection)','Diffusion (with reflection)','MCX(with reflection)');
legend boxoff;
xlabel('x (mm)')
ylabel('Flux in 1/(mm^2 s)')

%% plotting the cross-cut view along y=30
subplot(223);
hold on;
clines = -1.5:-0.5:-4;
srcpos=cfg.srcpos-0.5;
[xi,yi]=meshgrid(0.5:59.5,0.5:59.5);
detpos=[xi(:) 30*ones(size(xi(:))) yi(:)];
phicw=reshape(cwdiffusion(cfg.prop(2,1), cfg.prop(2,2)*(1-cfg.prop(2,3)), 0, srcpos, detpos),size(xi));

[c h2]=contour(xi,yi, log10(max(squeeze(phicw),1e-8)), clines, 'k-' );
[c h1]=contour(log10(max(squeeze(cwf1(:,30,:)*cfg.tstep)',1e-8)), clines, 'k:' );
legend('Diffusion','MCX')
legend boxoff;
box on;
xlabel('x (mm)')
ylabel('z (mm)')

%% plotting the temporal evolution at the cross-cut along y=30
subplot(224);
hold on;
twin=5e-11:1e-10:5e-9;
Reff=0;

srcpos=[29.5 29.5 0];
[xi,yi]=meshgrid(0.5:59.5,0.5:59.5);

detpos=[xi(:) 29.5*ones(size(xi(:))) yi(:)];
for i=1:length(twin)
  phitd(:,:,i)=reshape(tddiffusion(cfg.prop(2,1), cfg.prop(2,2)*(1-cfg.prop(2,3)),c0,Reff,srcpos,detpos,twin(i)),size(xi));
end

for i=1:5:21
  halfmax=max(max(phitd(:,:,i)))/2;
  [c h2]=contour(xi, yi,max(squeeze(phitd(:,:,i)),1e-12),[halfmax halfmax], 'k-');
  halfmax=max(max(f1(:,30,:,i)))/2;
  [c h2]=contour(max(squeeze(f1(:,30,:,i))',1e-12),[halfmax halfmax], 'k:');
end
legend('Diffusion','MCX')
legend boxoff;
box on;
xlabel('x (mm)')
ylabel('z (mm)')
