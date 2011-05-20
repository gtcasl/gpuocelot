function separation=getdistance(srcpos,detpos)
%  separation=getdistance(srcpos,detpos)
%
%  compute the source/detector separation from the positions
%
%    author: Qianqian Fang (fangq <at> nmr.mgh.harvard.edu)
%
%    input:
%        srcpos:array for the source positions (x,y,z)
%        detpos:array for the detector positions (x,y,z)
%
%    output:
%        separation:  the distance matrix between all combinations
%              of sources and detectors. separation has the number
%              of source rows, and number of detector of columns.
%
%    this file is part of Monte Carlo eXtreme (MCX)
%    License: GPLv3, see http://mcx.sf.net for details

srcnum=length(srcpos(:,1));
detnum=length(detpos(:,1));
for s=1:srcnum
	for r=1:detnum
             separation(r,s)=norm(srcpos(s,:)-detpos(r,:),'fro');
	end
end
