function data=loadmc2(fname,dim,format)
%
%    data=loadmc2(fname,dim,format)
%
%    author: Qianqian Fang (fangq <at> nmr.mgh.harvard.edu)
%
%    input:
%        fname: the file name to the output .mc2 file
%        dim:   an array to specify the output data dimension
%               normally, dim=[nx,ny,nz,nt]
%        format:a string to indicate the format used to save
%               the .mc2 file; if omitted, it is set to 'float'
%
%    output:
%        data:  the output MCX solution data array, in the
%               same dimension specified by dim
%
%    this file is part of Monte Carlo eXtreme (MCX)
%    License: GPLv3, see http://mcx.sf.net for details
%

if(nargin==2)
   format='float';
end

fid=fopen(fname,'rb');
data=fread(fid,inf,format);
fclose(fid);

data=reshape(data,dim);
