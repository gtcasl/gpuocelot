function Phi = cwdiffusion(mua, musp, Reff, srcpos,detpos)
%
%  Phi = cwdiffusion(mua, musp, Reff, srcpos,detpos)
%
%  semi-infinite medium analytical solution to diffusion model
%
%    author: Qianqian Fang (fangq <at> nmr.mgh.harvard.edu)
%
%    input:
%        mua:   the absorption coefficients in 1/mm
%        musp:  the reduced scattering coefficients in 1/mm
%        Reff:  the effective reflection coeff.
%        srcpos:array for the source positions (x,y,z)
%        detpos:array for the detector positions (x,y,z)
%
%    output:
%        Phi:  the output fluence for all source/detector pairs
%
%    this file is part of Monte Carlo eXtreme (MCX)
%    License: GPLv3, see http://mcx.sf.net for details
%    see Boas2002, Heskell1996
%

D = 1/(3*(mua+musp));
zb = (1+Reff)/(1-Reff)*2*D;

z0 = 1/(musp+mua);
r=getdistance([srcpos(:,1:2) srcpos(:,3)+z0],detpos);
r2=getdistance([srcpos(:,1:2) srcpos(:,3)-z0-2*zb],detpos);

b=sqrt(3*mua*musp);

% unit of phi:  1/(mm^2)
Phi =1./(4*pi*D).*(exp(-b*r)./r - exp(-b*r2)./r2);
