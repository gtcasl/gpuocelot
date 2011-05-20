function phi=normalizemcx(data,mua,Vvox,dt,energyabsorbed,energytotal)
%
% phi=normalizemcx(data,mua,Vvox,dt,energyabsorbed,energytotal)
% 
% Normalization of fluence distributions from Monte-Carlo simulations
%
% Author: Qianqian Fang <fangq at nmr.mgh.harvard.edu>
%
% input: 
%    data: a 3D or 4D array for the raw output from MCX (probability)
%    mua:  absorption coeff, with the same dimensions as data
%    Vvox: volume of a voxel (1/mm^3)
%    dt:   time-gate width of MC simulation (s)
%    energyabsorbed: total energy being absorbed in the simulation
%    energytotal:    total photon energy launched in the simulation
%
% output:
%    phi: the fluence under a unitary source
%
% For tMCimg output, set energyabsorbed to -1 and energytotal to 
% the total photon numbers
%
% This subroutine of part of Monte-Carlo eXtreme (mcx) package
%

if(energyabsorbed<0)
   energyabsorbed=energytotal+sum(data(find(data<0)));
   data(find(data<0))=0;
end
alpha=energyabsorbed/energytotal/(Vvox*sum(data(:).*mua(:)))/(dt);
phi=alpha*data;
