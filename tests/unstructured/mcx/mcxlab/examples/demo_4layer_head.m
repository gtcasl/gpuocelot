%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% MCXLAB - Monte Carlo eXtreme for MATLAB/Octave by Qianqina Fang
%
% In this example, we simulate a 4-layer brain model using MCXLAB.
% We will investigate the differences between the solutions with and 
% witout boundary reflections (both external and internal) and show
% you how to display and analyze the resulting data.
%
% This file is part of Monte Carlo eXtreme (MCX) URL:http://mcx.sf.net
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clear cfg;

%% preparing the input data
% set seed to make the simulation repeatible
cfg.seed=hex2dec('623F9A9E'); 

cfg.nphoton=5e7;

% define a 4 layer structure
cfg.vol=ones(100,100,50);
cfg.vol(:,:,21:25)=2;
cfg.vol(:,:,26:35)=3;
cfg.vol(:,:,36:end)=4;
cfg.vol=uint8(cfg.vol);

% define the source position
cfg.srcpos=[50,50,0]+1;
cfg.srcdir=[0 0 1];

% use the brain optical properties defined at
% http://mcx.sourceforge.net/cgi-bin/index.cgi?MMC/CollinsAtlasMesh
% format: [mua(1/mm) mus(1/mm) g n]

cfg.prop=[0 0 1 1            % medium 0: the environment
   0.019 7.8   0.89 1.37     % medium 1: skin & skull
   0.004 0.009 0.89 1.37     % medium 2: CSF
   0.02  9.0   0.89 1.37     % medium 3: gray matter
   0.08 40.9   0.84 1.37];   % medium 4: white matter

% time-domain simulation parameters
cfg.tstart=0;
cfg.tend=5e-9;
cfg.tstep=5e-10;

% GPU thread configuration
cfg.autopilot=1;
cfg.gpuid=1;

%% running simulation without boundary reflection
fprintf('running simulation ... this takes about 35 seconds on a GTX 470\n');
cfg.isreflect=0; % disable reflection at exterior boundary
tic;
f1=mcxlab(cfg);
toc;

%% running simulation with boundary reflection enabled
fprintf('running simulation ... this takes about 50 seconds on a GTX 470\n');
cfg.isreflect=1; % enable reflection at exterior boundary
cfg.isrefint=1;  % enable reflection at interior boundary too
cfg.issavedet=1; % enable recording partial pathlength of detected photons
cfg.detpos=[31 51 1 2];
tic;
[f2,det2]=mcxlab(cfg);
toc;

%% plot the results
figure
subplot(221);
contourf(log10(squeeze(sum(f1.data(:,51,:,:),4))'),1:0.5:8);
hold on
plot([0 100],[21 21],'--',[0 100],[26 26],'--',[0 100],[36 36],'--');
title('flux with no reflection');

subplot(222);
contourf(log10(squeeze(sum(f2.data(:,51,:,:),4))'),1:0.5:8);
hold on
plot([0 100],[21 21],'--',[0 100],[26 26],'--',[0 100],[36 36],'--');
title('flux with reflection at boundaries');

subplot(223);
hold on;
xi=1e9*((cfg.tstart:cfg.tstep:cfg.tend-cfg.tstep)+0.5*cfg.tstep);
for i=31:49
    semilogy(xi,squeeze(f2.data(51,i,1,:)),'color',[1-(i-25)/25 1-(i-25)/25 1]);
end
xlabel('time (ns)')
ylabel('flux (1/mm^2/s)')
set(gca,'yscale','log');
title('time point spread functions (TPSF)');

subplot(224);
hold on;
[hs1,c1]=hist(det2.data(3,find(det2.data(3,:))),200);
[hs2,c2]=hist(det2.data(4,find(det2.data(4,:))),200);
[hs3,c3]=hist(det2.data(5,find(det2.data(5,:))),200);
[hs4,c4]=hist(det2.data(6,find(det2.data(6,:))),200);
bar(c1,hs1,'edgecolor','none','facecolor','r');
bar(c2,hs2,'edgecolor','none','facecolor','b');
bar(c3,hs3,'edgecolor','none','facecolor','g');
bar(c4,hs4,'edgecolor','none','facecolor','k');
legend('tissue 1','tissue 2','tissue 3','tissue 4');
xlabel('partial pathlength (mm)');
title(sprintf('detected %d photons',size(det2.data,2)));
