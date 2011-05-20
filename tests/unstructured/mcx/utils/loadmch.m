function [data, headerstruct]=loadmch(fname,format)
%
%    [data, header]=loadmch(fname,format)
%
%    author: Qianqian Fang (fangq <at> nmr.mgh.harvard.edu)
%
%    input:
%        fname: the file name to the output .mch file
%        format:a string to indicate the format used to save
%               the .mch file; if omitted, it is set to 'float'
%
%    output:
%        data:   the output detected photon data array
%                data has header.medium+2 columns, the first column is the 
%                ID of the detector; the 2nd column is the number of 
%                scattering events for a detected photon; the remaining 
%                columns are the partial path lengths (in mm) for each medium type
%        header: file header info, a structure has the following fields
%                [version,medianum,detnum,recordnum,totalphoton,
%                 detectedphoton,savedphoton,lengthunit]
%
%    this file is part of Monte Carlo eXtreme (MCX)
%    License: GPLv3, see http://mcx.sf.net for details
%

if(nargin==1)
   format='float';
end

fid=fopen(fname,'rb');

data=[];
header=[];
while(~feof(fid))
	magicheader=fread(fid,4,'char');
	if(strcmp(char(magicheader(:))','MCXH')~=1)
		if(isempty(header))
			fclose(fid);
			error('can not find a MCX history data block');
		end
		break;
	end
	hd=fread(fid,7,'uint');
	if(hd(1)~=1) error('version higher than 1 is not supported'); end
	unitmm=fread(fid,1,'float32');
	junk=fread(fid,7,'uint');
	
	dat=fread(fid,hd(7)*hd(4),format);
	dat=reshape(dat,[hd(4),hd(7)])';
	dat(:,3:end)=dat(:,3:end)*unitmm;
	data=[data;dat];
	if(isempty(header))
		header=[hd;unitmm]';
	else
		if(any(header([1:4 8])~=[hd([1:4])' unitmm]))
			error('loadmch can only load data generated from a single session');
		else
			header(5:7)=header(5:7)+hd(5:7)';
		end
	end
end

fclose(fid);

if(nargout>=2)
   headerstruct=struct('version',header(1),'medianum',header(2),'detnum',header(3),...
                       'recordnum',header(4),'totalphoton',header(5),...
                       'detectedphoton',header(6),'savedphoton',header(7),'lengthunit',header(8));
end
