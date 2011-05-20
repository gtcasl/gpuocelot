%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% MCXLAB - Monte Carlo eXtreme for MATLAB/Octave by Qianqina Fang
%
% In this example, we validate the MCXLAB solver with a heterogeneous
% domain and the analytical solution of the diffusion model. We also 
% demonstrate how to use sub-pixel resolution to refine the representation
% of heterogeneities. The domain is consisted of a 6x6x6 cm box with a 
% 2cm diameter sphere embedded at the center. 
%.
% This test is identical to that used for Fig. 3 in Fang2010.
%
% [Fang2010] Fang Q, "Mesh-based Monte Carlo method using fast ray-tracing
%    in Plücker coordinates," Biomed. Opt. Express 1, 165-175 (2010) 
%
% This file is part of Monte Carlo eXtreme (MCX) URL:http://mcx.sf.net
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

if(exist('sphdiffusionslab','file')~=2)
    error(sprintf('Script "sphdiffusionslab.m" was not found.\nThis demo requires you to add the "mmc/matlab" directory first.'));
end

clear cfg ana;

%% preparing the input data
% structure for sphere-diffusion toolbox for the analytical solution
ana.v=299792458000;  % mm/s
ana.a=10;            % radius, mm
ana.omua=0.002;      % outside mua 1/mm
ana.omusp=1.0;       % outside mus' 1/mm
ana.imua=0.05;
ana.imusp=0.5;
ana.src=[30,pi,0];
ana.maxl=20;
ana.omega=0;

clines=-1:0.25:8;

% set seed to make the simulation repeatible
cfg.seed=hex2dec('623F9A9E'); 

cfg.nphoton=3e7;

% define a 1cm radius sphere within a 6x6x6 cm box
dim=60;
[xi,yi,zi]=meshgrid(1:dim,1:dim,1:dim);
dist=(xi-30.5).^2+(yi-30.5).^2+(zi-30.5).^2;
cfg.vol=ones(size(xi));
cfg.vol(dist<ana.a*ana.a)=2;
cfg.vol=uint8(cfg.vol);

% define the source position
cfg.srcpos=[30,30,0]+1;
cfg.srcdir=[0 0 1];

% format: [mua(1/mm) mus(1/mm) g n]
cfg.prop=[0 0 1 1          % medium 0: the environment
   ana.omua ana.omusp/(1-0.01) 0.01 1.37     % medium 1: cube
   ana.imua ana.imusp/(1-0.01) 0.01 1.37];   % medium 2: spherical inclusion

% time-domain simulation parameters
cfg.tstart=0;
cfg.tend=5e-9;
cfg.tstep=5e-10;

% GPU thread configuration
cfg.autopilot=1;
cfg.gpuid=1;

cfg.isreflect=0; % disable reflection at exterior boundaries

%% running simulation with 1x1x1 mm input volume (60x60x60 grid)
fprintf('running simulation ... this takes about 6 seconds on a GTX 470\n');
tic;
f1=mcxlab(cfg);
toc;

%% set up simulation with 0.5x0.5x0.5 mm input volume (120x120x120 grid)
cfg2x=cfg;
dim=120;
[xi,yi,zi]=meshgrid(1:dim,1:dim,1:dim);
dist=(xi-60).^2+(yi-60).^2+(zi-60).^2;
cfg2x.vol=ones(size(xi));
cfg2x.vol(dist<400)=2;
cfg2x.srcpos=[60,60,0]+1;
cfg2x.vol=uint8(cfg2x.vol);

cfg2x.unitinmm=0.5;  %this statement specifies that each grid-edge is 0.5mm
cfg2x.nphoton=8*cfg.nphoton; % it needs 8x photons to get the same noise

fprintf('running simulation ... this takes about 110 seconds on a GTX 470\n');
tic;
f2=mcxlab(cfg2x);
toc;

%% calculating the analytical solution from the sphere-diffusion toolbox
fprintf('calculating the analytical solution. this may take a few minutes ...\n');
[phi_ana,xa,ya,za]=sphdiffusionslab(0,0,dim,-22:0.8:22,0,-30:0.8:10,ana);
save demo_sphbox.mat phi_ana xa ya za
%load demo_sphbox.mat
phi_ana((xa(:)<-15 | xa(:)>15) & za(:)>-10)=nan;
phi_ana((xa(:)<-12 | xa(:)>12) & za(:)>0)=nan;

%% plotting the results
figure
subplot(121);
contourf(log10(squeeze(sum(f1.data(:,30,:,:),4))'),clines);
hold on;
c=contourc(squeeze(double(cfg.vol(:,30,:))),1);
contour(xa+30.5,za+31,log10(abs(phi_ana/cfg.tstep)),clines,'color',[0.7 0.7 0.7],'linewidth',2);
plot(c(1,2:end),c(2,2:end),'b--')
axis equal;

colorbar('NorthOutside');
title('simulation with 1x1x1 mm resolution');

subplot(122);
[xx,yy]=meshgrid(0.5:0.5:dim/2,0.5:0.5:dim/2);
contourf(xx,yy,log10(squeeze(sum(f2.data(:,60,:,:),4))'),clines);
hold on;
contour(xa+30,za+30.5,log10(abs(phi_ana/cfg2x.tstep)),clines,'color',[0.7 0.7 0.7],'linewidth',2);
c=contourc(squeeze(double(cfg2x.vol(:,60,:))),1);
plot(c(1,2:end)/2,c(2,2:end)/2,'b--')
axis equal;
colorbar('NorthOutside');
title('simulation with 0.5x0.5x0.5 mm resolution');
