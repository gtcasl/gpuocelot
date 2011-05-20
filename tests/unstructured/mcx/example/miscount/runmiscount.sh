#!/bin/sh

RT=`pwd`

# generate a 60x60x60 homogeneous medium filled with index 1

dd if=/dev/zero of=seg60x60x60.bin bs=1000 count=216
perl -pi -e 's/\x0/\x1/g' seg60x60x60.bin

cd "$RT/../../src/"
make racing
cd $RT

echo 'run MCX with various threads and scattering coeff.'

nthread="128 256 512 1024 1280 1536 1792"
nscat="0.25 0.5 1.01 2.02 3.03 4.04 5.05 6.06 7.07 8.08"
mcxbin="../../bin/mcx"

for th in $nthread
do 
  for sc in $nscat
  do
       echo "<mcx_session thread='$th' scat='$sc'>"
       echo "<cmd>$mcxbin -t $th -T 128 -m 1000000 -g 10 -f benchmiscnt.inp -s speed -a 0 -b 0 -p 1 -U 0</cmd>"
       echo "<output>"
       cat miscnt.template | sed -e "s/%SCA%/$sc/g" > benchmiscnt.inp
       $mcxbin -t $th -T 128 -m 1000000 -g 10 -f benchmiscnt.inp -s miscnt -a 0 -b 0 -p 1 -U 0
       echo "</output>"
       echo "</mcx_session>"
  done
done
