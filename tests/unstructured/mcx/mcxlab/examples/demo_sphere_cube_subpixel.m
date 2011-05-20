%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% MCXLAB - Monte Carlo eXtreme for MATLAB/Octave by Qianqina Fang
%
% In this example, we demonstrate how to use sub-pixel resolution 
% to represent the problem domain. The domain is consisted of a 
% 6x6x6 cm box with a 2cm diameter sphere embedded at the center.
%
% This file is part of Monte Carlo eXtreme (MCX) URL:http://mcx.sf.net
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

clear cfg;

% set seed to make the simulation repeatible
cfg.seed=hex2dec('623F9A9E'); 

cfg.nphoton=1e7;

% define a 1cm radius sphere within a 6x6x6 cm box
dim=60;
[xi,yi,zi]=meshgrid(1:dim,1:dim,1:dim);
dist=(xi-30).^2+(yi-30).^2+(zi-30).^2;
cfg.vol=ones(size(xi));
cfg.vol(dist<100)=2;
cfg.vol=uint8(cfg.vol);

% define the source position
cfg.srcpos=[30,30,0]+1;
cfg.srcdir=[0 0 1];

% format: [mua(1/mm) mus(1/mm) g n]
cfg.prop=[0 0 1 1          % medium 0: the environment
   0.002 1.0 0.01 1.37     % medium 1: cube
   0.050 0.5 0.01 1.37];   % medium 2: spherical inclusion

% time-domain simulation parameters
cfg.tstart=0;
cfg.tend=5e-9;
cfg.tstep=5e-10;

% GPU thread configuration
cfg.autopilot=1;
cfg.gpuid=1;

cfg.isreflect=1; % enable reflection at exterior boundary
cfg.isrefint=1;  % enable reflection at interior boundary too

fprintf('running simulation ... this takes about 3 seconds on a GTX 470\n');
tic;
f1=mcxlab(cfg);
toc;

% define a 1cm radius sphere within a 6x6x6 cm box with a 0.5mm resolution
dim=120;
[xi,yi,zi]=meshgrid(1:dim,1:dim,1:dim);
dist=(xi-60).^2+(yi-60).^2+(zi-60).^2;
cfg.vol=ones(size(xi));
cfg.vol(dist<400)=2;
cfg.srcpos=[60,60,0]+1;
cfg.vol=uint8(cfg.vol);

cfg.unitinmm=0.5; % define the pixel size in terms of mm
cfg.nphoton=8e7;  % you need to simulate 8x photons to get the same noise

fprintf('running simulation ... this takes about 40 seconds on a GTX 470\n');
tic;
[f2,det2]=mcxlab(cfg);
toc;

% plot the results
figure
subplot(121);
if(exist('OCTAVE_VERSION')~=0)
    imagesc(log10(squeeze(sum(f1.data(:,30,:,:),4))'));
else
    contourf(log10(squeeze(sum(f1.data(:,30,:,:),4))'),1:0.5:8);
end
axis equal;
colorbar('SouthOutside');
title('simulation with 1x1x1 mm resolution');

subplot(122);
if(exist('OCTAVE_VERSION')~=0)
    imagesc(log10(squeeze(sum(f2.data(:,60,:,:),4))'));
else
    contourf(log10(squeeze(sum(f2.data(:,60,:,:),4))'),1:0.5:8);
end
axis equal;
colorbar('SouthOutside');
title('simulation with 0.5x0.5x0.5 mm resolution');
