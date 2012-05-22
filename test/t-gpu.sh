#!/bin/sh

if [ ! -n "$1" ]; then
  echo "usage:$0 cl_file"
  exit;
fi

TRANSLATOR=$SNUCLROOT/bin/clang

OPTIONS=""

while [ $# -gt 1 ]
do
  shift
  OPTIONS=$OPTIONS" "$2
done

echo "$TRANSLATOR -cc1 -load $SNUCLROOT/lib/libSnuCLCuTranslator.so -plugin snuclcu -I$SNUCLROOT/src/runtime/arch/x86/include/compiler -include $SNUCLROOT/src/runtime/arch/x86/include/compiler/cl_kernel.h -I. $1 -o $1.cu $OPTIONS"


$TRANSLATOR -cc1 -load $SNUCLROOT/lib/libSnuCLCuTranslator.so -plugin snuclcu -I$SNUCLROOT/src/runtime/arch/x86/include/compiler -include $SNUCLROOT/src/runtime/arch/x86/include/compiler/cl_kernel.h -I. $1 -o $1.cu $OPTIONS

echo "nvcc -w -m64 -O3 -I$SNUCLROOT/src/runtime/arch/NVIDIA/include/kernel -arch=sm_20 -ptx $1.cu -o $1.ptx"

nvcc -w -m64 -O3 -I$SNUCLROOT/src/runtime/arch/NVIDIA/include/kernel -arch=sm_20 -ptx $1.cu -o $1.ptx

exit 0

