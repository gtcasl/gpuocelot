function Phi = tddiffusion(mua, musp, v, Reff, srcpos,detpos, t)
%
%  Phi = tddiffusion(mua, musp, v, Reff, srcpos,detpos, t)
%    
%  semi-infinite medium analytical solution to diffusion model
%
%    author: Qianqian Fang (fangq <at> nmr.mgh.harvard.edu)
%
%    input:
%        mua:   the absorption coefficients in 1/mm
%        musp:  the reduced scattering coefficients in 1/mm
%        v:     the speed of light
%        Reff:  the effective reflection coeff.
%        srcpos:array for the source positions (x,y,z)
%        detpos:array for the detector positions (x,y,z)
%        t:     a list of time in s at which to evaluate the 
%               analytical diffusion solution
%
%    output:
%        Phi:  the output fluence for all time points
%
%    this file is part of Monte Carlo eXtreme (MCX)
%    License: GPLv3, see http://mcx.sf.net for details
%    see Boas2002
%

D = 1/(3*(mua+musp));
zb = (1+Reff)/(1-Reff)*2*D;

z0 = 1/(musp+mua);
r=getdistance([srcpos(:,1:2) srcpos(:,3)+z0],detpos);
r2=getdistance([srcpos(:,1:2) srcpos(:,3)-z0-2*zb],detpos);

s=4*D*v*t;

% unit of phi:  1/(mm^2*s)
Phi =v./((s*pi).^(3/2)).*exp(-mua*v*t).*(exp(-(r.^2)./s) - exp(-(r2.^2)./s));
