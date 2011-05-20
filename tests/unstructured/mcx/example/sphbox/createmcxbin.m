dim=60;
[xi,yi,zi]=meshgrid(1:dim,1:dim,1:dim);
dist=(xi-30).^2+(yi-30).^2+(zi-30).^2;

v=zeros(size(xi));
v(dist<100)=1;
v=v+1;

fid=fopen('spherebox.bin','wb');
aa=fwrite(fid,v,'uchar');
fclose(fid);
