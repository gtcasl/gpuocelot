% you should add the path first
% addpath('../../utils/');

b0=loadmc2('bubble0.mc2',[60 60 60]);
b3=loadmc2('bubble3.mc2',[60 60 60]);
b5=loadmc2('bubble5.mc2',[60 60 60]);

figure
imagesc(flipud(squeeze(log10(b0(:,30,:)))'))
colorbar
crange=get(gca,'clim');

figure
imagesc(flipud(squeeze(log10(b3(:,30,:)))'))
set(gca,'clim',crange);
colorbar

figure
imagesc(flipud(squeeze(log10(b5(:,30,:)))'))
set(gca,'clim',crange);
colorbar

figure
hold on;
plot(1:60, squeeze(log10(b0(30,30,:))),'.')
plot(1:60, squeeze(log10(b3(30,30,:))),'r.')
plot(1:60, squeeze(log10(b5(30,30,:))),'g.')

plot(1:60, squeeze(log10(b0(:,30,3))),'-')
plot(1:60, squeeze(log10(b3(:,30,3))),'r')
plot(1:60, squeeze(log10(b5(:,30,3))),'g')

legend('cut 1:no skip','cut 1:skip 3mm','cut 1:skip 5mm',...
       'cut 2:no skip','cut 2:skip 3mm','cut 2:skip 5mm');
