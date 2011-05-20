%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% MCXLAB - Monte Carlo eXtreme for MATLAB/Octave by Qianqina Fang
%
% In this example, we show the most basic usage of MCXLAB.
%
% This file is part of Monte Carlo eXtreme (MCX) URL:http://mcx.sf.net
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

cfg.nphoton=1e7;
cfg.vol=uint8(ones(60,60,60));
cfg.srcpos=[30 30 1];
cfg.srcdir=[0 0 1];
cfg.gpuid=1;
cfg.autopilot=1;
cfg.prop=[0 0 1 1;0.005 1 0 1.37];
cfg.tstart=0;
cfg.tend=5e-9;
cfg.tstep=5e-10;
% calculate the flux distribution with the given config
flux=mcxlab(cfg);

cfgs(1)=cfg;
cfgs(2)=cfg;
cfgs(1).isreflect=0;
cfgs(2).isreflect=1;
cfgs(2).issavedet=1;
cfgs(2).detpos=[30 20 1 1;30 40 1 1;20 30 1 1;40 30 1 1];
% calculate the flux and partial path lengths for the two configurations
[fluxs,detps]=mcxlab(cfgs);

imagesc(squeeze(log(fluxs(1).data(:,30,:,1)))-squeeze(log(fluxs(2).data(:,30,:,1))));
