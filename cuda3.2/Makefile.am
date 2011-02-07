################################################################################
#	\file Makefile.am
#	\author Gregory Diamos, Andrew Kerr
#	\date Monday October 26, 2010
# 	\brief Automake input file describing the programs and sources needed to
#			build Ocelot's CUDA SDK 3.2 regression tests
################################################################################

################################################################################
## Autoconf configuration
ACLOCAL_AMFLAGS = -I m4
OCELOT_LIBS = $(OCELOT_LDFLAGS) $(LLVM_LDFLAGS) libsdkShared.la libCUDASDK.la
CUDA_CFLAGS = -I $(srcdir)/sdk -std=c++0x
SDK_CFLAGS = -I $(srcdir)/sdk -I $(srcdir)/shared
################################################################################

################################################################################
## Programs and Libraries
bin_PROGRAMS = 

lib_LTLIBRARIES = libCUDASDK.la libsdkShared.la 
check_PROGRAMS = MergeSort \
	QuasirandomGenerator \
	SimpleVoteIntrinsics \
	Dct8x8 \
	SimpleTexture3D \
	DwtHaar1D \
	VolumeRender \
	Reduction \
	OceanFFT \
	SimpleZeroCopy \
	Template \
	CppIntegration \
	ConvolutionFFT2D \
	SimpleGL \
	SimpleAtomicIntrinsics \
	MersenneTwister \
	SimpleMultiCopy \
	Histogram \
	BicubicTexture \
	MonteCarloMultiGPU \
	Dxtc \
	PostProcessGL \
	Eigenvalues \
	BlackScholes \
	SimpleCUBLAS \
	SimpleCUFFT \
	MonteCarlo \
	SimpleTemplates \
	Scan \
	RecursiveGaussian \
	SortingNetworks \
	ConvolutionSeparable \
	SimplePitchLinearTexture \
	BandwidthTest \
	ImageDenoising \
	BoxFilter \
	ConvolutionTexture \
	AlignedTypes \
	Transpose \
	BilateralFilter \
	Nbody \
	FluidsGL \
	SimpleStreams \
	Mandelbrot \
	FastWalshTransform \
	FDTD3d \
	SimpleTexture \
	SimplePrintf \
	MatrixMul \
	DeviceQuery \
	ScalarProd \
	AsyncAPI \
	BinomialOptions \
	VectorAdd \
	ThreadFenceReduction \
	SimpleMultiGPU \
	SobolQRNG \
	SobelFilter \
	MatrixMulDynlinkJIT \
	Clock
	
################################################################################

################################################################################
## Shared SDK library
libsdkShared_la_CXXFLAGS = -Ishared $(CUDA_CFLAGS)  $(SDK_CFLAGS)
libsdkShared_la_SOURCES = \
	shared/cmd_arg_reader.cpp  \
	shared/multithreading.cpp  \
	shared/rendercheckGL.cpp  \
	shared/shrUtils.cpp  \
	shared/stopwatch.cpp  \
	shared/stopwatch_linux.cpp
################################################################################


################################################################################
## Shared SDK library
libCUDASDK_la_CXXFLAGS = -Isdk $(CUDA_CFLAGS)  $(SDK_CFLAGS)
libCUDASDK_la_SOURCES = \
	sdk/bank_checker.cpp \
	sdk/multithreading.cpp \
	sdk/stopwatch_linux.cpp \
	sdk/cmd_arg_reader.cpp \
	sdk/param.cpp \
	sdk/paramgl.cpp \
	sdk/rendercheck_gl.cpp \
	sdk/cutil.cpp \
	sdk/stopwatch.cpp
################################################################################

################################################################################
#
# Applications depending on CUDPP have been removed/commented out
#

################################################################################
## MergeSort
MergeSort_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
MergeSort_SOURCES = ./tests/mergeSort/main.cpp \
	./tests/mergeSort/mergeSort_host.cpp \
	./tests/mergeSort/mergeSort_validate.cpp \
	./tests/mergeSort/bitonic.cu.cpp \
	./tests/mergeSort/mergeSort.cu.cpp
MergeSort_LDADD = $(OCELOT_LIBS)
MergeSort_LDFLAGS = -static
################################################################################

################################################################################
## QuasirandomGenerator
QuasirandomGenerator_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
QuasirandomGenerator_SOURCES = ./tests/quasirandomGenerator/quasirandomGenerator.cpp \
	./tests/quasirandomGenerator/quasirandomGenerator_gold.cpp \
	./tests/quasirandomGenerator/quasirandomGenerator_SM10.cu.cpp \
	./tests/quasirandomGenerator/quasirandomGenerator_SM13.cu.cpp
QuasirandomGenerator_LDADD = $(OCELOT_LIBS)
QuasirandomGenerator_LDFLAGS = -static
################################################################################

################################################################################
## SimpleVoteIntrinsics
SimpleVoteIntrinsics_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
SimpleVoteIntrinsics_SOURCES = ./tests/simpleVoteIntrinsics/simpleVoteIntrinsics.cu.cpp
SimpleVoteIntrinsics_LDADD = $(OCELOT_LIBS)
SimpleVoteIntrinsics_LDFLAGS = -static
################################################################################

################################################################################
## Dct8x8
Dct8x8_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
Dct8x8_SOURCES = ./tests/dct8x8/BmpUtil.cpp \
	./tests/dct8x8/DCT8x8_Gold.cpp \
	./tests/dct8x8/dct8x8.cu.cpp
Dct8x8_LDADD = $(OCELOT_LIBS)
Dct8x8_LDFLAGS = -static
################################################################################

################################################################################
## SimpleTexture3D
SimpleTexture3D_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
SimpleTexture3D_SOURCES = ./tests/simpleTexture3D/simpleTexture3D.cpp \
	./tests/simpleTexture3D/simpleTexture3D_kernel.cu.cpp
SimpleTexture3D_LDADD = $(OCELOT_LIBS)
SimpleTexture3D_LDFLAGS = -static
################################################################################

################################################################################
## MatrixMulDrv
# MatrixMulDrv_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
# MatrixMulDrv_SOURCES = ./tests/matrixMulDrv/matrixMul_gold.cpp \
# 	./tests/matrixMulDrv/matrixMulDrv.cpp
# MatrixMulDrv_LDADD = $(OCELOT_LIBS)
# MatrixMulDrv_LDFLAGS = -static
################################################################################

################################################################################
## DwtHaar1D
DwtHaar1D_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
DwtHaar1D_SOURCES = ./tests/dwtHaar1D/dwtHaar1D.cu.cpp
DwtHaar1D_LDADD = $(OCELOT_LIBS)
DwtHaar1D_LDFLAGS = -static
################################################################################

################################################################################
## VolumeRender
VolumeRender_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
VolumeRender_SOURCES = ./tests/volumeRender/volumeRender.cpp \
	./tests/volumeRender/volumeRender_kernel.cu.cpp
VolumeRender_LDADD = $(OCELOT_LIBS)
VolumeRender_LDFLAGS = -static
################################################################################

################################################################################
## MarchingCubes
# MarchingCubes_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
# MarchingCubes_SOURCES = ./tests/marchingCubes/marchingCubes.cpp \
# 	./tests/marchingCubes/marchingCubes_kernel.cu.cpp
# MarchingCubes_LDADD = $(OCELOT_LIBS)
# MarchingCubes_LDFLAGS = -static
################################################################################

################################################################################
## Reduction
Reduction_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
Reduction_SOURCES = ./tests/reduction/reduction.cpp \
	./tests/reduction/reduction_kernel.cu.cpp
Reduction_LDADD = $(OCELOT_LIBS)
Reduction_LDFLAGS = -static
################################################################################

################################################################################
## OceanFFT
OceanFFT_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
OceanFFT_SOURCES = ./tests/oceanFFT/oceanFFT.cpp \
	./tests/oceanFFT/oceanFFT_kernel.cu.cpp
OceanFFT_LDADD = $(OCELOT_LIBS) -lcufft
OceanFFT_LDFLAGS = -static
################################################################################

################################################################################
## ConjugateGradient
## ConjugateGradient_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
## ConjugateGradient_SOURCES = ./tests/conjugateGradient/main.cpp
## ConjugateGradient_LDADD = $(OCELOT_LIBS)
## ConjugateGradient_LDFLAGS = -static
################################################################################

################################################################################
## SimpleZeroCopy
SimpleZeroCopy_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
SimpleZeroCopy_SOURCES = ./tests/simpleZeroCopy/simpleZeroCopy.cu.cpp
SimpleZeroCopy_LDADD = $(OCELOT_LIBS)
SimpleZeroCopy_LDFLAGS = -static
################################################################################

################################################################################
## Template
Template_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
Template_SOURCES = ./tests/template/template_gold.cpp \
	./tests/template/template.cu.cpp
Template_LDADD = $(OCELOT_LIBS)
Template_LDFLAGS = -static
################################################################################

################################################################################
## DeviceQueryDrv
# DeviceQueryDrv_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
# DeviceQueryDrv_SOURCES = ./tests/deviceQueryDrv/deviceQueryDrv.cpp
# DeviceQueryDrv_LDADD = $(OCELOT_LIBS)
# DeviceQueryDrv_LDFLAGS = -static
################################################################################

################################################################################
## CppIntegration
CppIntegration_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
CppIntegration_SOURCES = ./tests/cppIntegration/main.cpp \
	./tests/cppIntegration/cppIntegration_gold.cpp \
	./tests/cppIntegration/cppIntegration.cu.cpp
CppIntegration_LDADD = $(OCELOT_LIBS)
CppIntegration_LDFLAGS = -static
################################################################################

################################################################################
## ConvolutionFFT2D
ConvolutionFFT2D_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
ConvolutionFFT2D_SOURCES = ./tests/convolutionFFT2D/main.cpp \
	./tests/convolutionFFT2D/convolutionFFT2D_gold.cpp \
	./tests/convolutionFFT2D/convolutionFFT2D.cu.cpp
ConvolutionFFT2D_LDADD = $(OCELOT_LIBS) -lcufft
ConvolutionFFT2D_LDFLAGS = -static
################################################################################

################################################################################
## SimpleGL
SimpleGL_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
SimpleGL_SOURCES = ./tests/simpleGL/simpleGL.cpp \
	./tests/simpleGL/simpleGL_kernel.cu.cpp
SimpleGL_LDADD = $(OCELOT_LIBS)
SimpleGL_LDFLAGS = -static
################################################################################

################################################################################
## SimpleAtomicIntrinsics
SimpleAtomicIntrinsics_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
SimpleAtomicIntrinsics_SOURCES = ./tests/simpleAtomicIntrinsics/simpleAtomicIntrinsics_gold.cpp \
	./tests/simpleAtomicIntrinsics/simpleAtomicIntrinsics.cu.cpp
SimpleAtomicIntrinsics_LDADD = $(OCELOT_LIBS)
SimpleAtomicIntrinsics_LDFLAGS = -static
################################################################################

################################################################################
## MersenneTwister
MersenneTwister_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
MersenneTwister_SOURCES = ./tests/MersenneTwister/MersenneTwister_gold.cpp \
	./tests/MersenneTwister/genmtrand.c \
	./tests/MersenneTwister/MersenneTwister.cu.cpp
MersenneTwister_LDADD = $(OCELOT_LIBS)
MersenneTwister_LDFLAGS = -static
################################################################################

################################################################################
## SimpleMultiCopy
SimpleMultiCopy_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
SimpleMultiCopy_SOURCES = ./tests/simpleMultiCopy/simpleMultiCopy.cu.cpp
SimpleMultiCopy_LDADD = $(OCELOT_LIBS)
SimpleMultiCopy_LDFLAGS = -static
################################################################################

################################################################################
## Histogram
Histogram_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
Histogram_SOURCES = ./tests/histogram/main.cpp \
	./tests/histogram/histogram_gold.cpp \
	./tests/histogram/histogram64.cu.cpp \
	./tests/histogram/histogram256.cu.cpp
Histogram_LDADD = $(OCELOT_LIBS)
Histogram_LDFLAGS = -static
################################################################################

################################################################################
## BicubicTexture
BicubicTexture_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
BicubicTexture_SOURCES = ./tests/bicubicTexture/bicubicTexture.cpp \
	./tests/bicubicTexture/bicubicTexture.cu.cpp
BicubicTexture_LDADD = $(OCELOT_LIBS)
BicubicTexture_LDFLAGS = -static
################################################################################

################################################################################
## MonteCarloMultiGPU
MonteCarloMultiGPU_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
MonteCarloMultiGPU_SOURCES = ./tests/MonteCarloMultiGPU/MonteCarloMultiGPU.cpp \
	./tests/MonteCarloMultiGPU/MonteCarlo_gold.cpp \
	./tests/MonteCarloMultiGPU/MonteCarlo_SM10.cu.cpp \
	./tests/MonteCarloMultiGPU/MonteCarlo_SM13.cu.cpp
MonteCarloMultiGPU_LDADD = $(OCELOT_LIBS)
MonteCarloMultiGPU_LDFLAGS = -static
################################################################################

################################################################################
## Dxtc
Dxtc_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
Dxtc_SOURCES = ./tests/dxtc/dxtc.cu.cpp
Dxtc_LDADD = $(OCELOT_LIBS)
Dxtc_LDFLAGS = -static
################################################################################

################################################################################
## PostProcessGL
PostProcessGL_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
PostProcessGL_SOURCES = ./tests/postProcessGL/main.cpp \
	./tests/postProcessGL/postProcessGL.cu.cpp
PostProcessGL_LDADD = $(OCELOT_LIBS)
PostProcessGL_LDFLAGS = -static
################################################################################

################################################################################
## Eigenvalues
Eigenvalues_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
Eigenvalues_SOURCES = ./tests/eigenvalues/matlab.cpp \
	./tests/eigenvalues/gerschgorin.cpp \
	./tests/eigenvalues/config.h \
	./tests/eigenvalues/util.h \
	./tests/eigenvalues/gerschgorin.h \
	./tests/eigenvalues/main.cu.cpp \
	./tests/eigenvalues/bisect_small.cu.cpp \
	./tests/eigenvalues/bisect_large.cu.cpp
Eigenvalues_LDADD = $(OCELOT_LIBS)
Eigenvalues_LDFLAGS = -static
################################################################################

################################################################################
## BlackScholes
BlackScholes_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
BlackScholes_SOURCES = ./tests/BlackScholes/BlackScholes_gold.cpp \
	./tests/BlackScholes/BlackScholes.cu.cpp
BlackScholes_LDADD = $(OCELOT_LIBS)
BlackScholes_LDFLAGS = -static
################################################################################

################################################################################
## SimpleCUBLAS
SimpleCUBLAS_CFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
SimpleCUBLAS_SOURCES = ./tests/simpleCUBLAS/simpleCUBLAS.c
SimpleCUBLAS_LDADD = $(OCELOT_LIBS) -lcublas
SimpleCUBLAS_LDFLAGS = -static
################################################################################

################################################################################
## SimpleCUFFT
SimpleCUFFT_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
SimpleCUFFT_SOURCES = ./tests/simpleCUFFT/simpleCUFFT.cu.cpp
SimpleCUFFT_LDADD = $(OCELOT_LIBS) -lcufft
SimpleCUFFT_LDFLAGS = -static
################################################################################

################################################################################
## VectorAddDrv
# VectorAddDrv_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
# VectorAddDrv_SOURCES = ./tests/vectorAddDrv/vectorAdd.cpp
# VectorAddDrv_LDADD = $(OCELOT_LIBS)
# VectorAddDrv_LDFLAGS = -static
################################################################################

################################################################################
## MonteCarlo
MonteCarlo_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
MonteCarlo_SOURCES = ./tests/MonteCarlo/MonteCarlo.cpp \
	./tests/MonteCarlo/MonteCarlo_gold.cpp \
	./tests/MonteCarlo/MonteCarlo_SM10.cu.cpp \
	./tests/MonteCarlo/MonteCarlo_SM13.cu.cpp
MonteCarlo_LDADD = $(OCELOT_LIBS)
MonteCarlo_LDFLAGS = -static
################################################################################

################################################################################
## ThreadMigration
# ThreadMigration_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
# ThreadMigration_SOURCES = ./tests/threadMigration/threadMigration.cpp
# ThreadMigration_LDADD = $(OCELOT_LIBS)
# ThreadMigration_LDFLAGS = -static
################################################################################

################################################################################
## SimpleTemplates
SimpleTemplates_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
SimpleTemplates_SOURCES = ./tests/simpleTemplates/simpleTemplates.cu.cpp
SimpleTemplates_LDADD = $(OCELOT_LIBS)
SimpleTemplates_LDFLAGS = -static
################################################################################

################################################################################
## Scan
Scan_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
Scan_SOURCES = ./tests/scan/main.cpp \
	./tests/scan/scan_gold.cpp \
	./tests/scan/scan.cu.cpp
Scan_LDADD = $(OCELOT_LIBS)
Scan_LDFLAGS = -static
################################################################################

################################################################################
## RecursiveGaussian
RecursiveGaussian_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
RecursiveGaussian_SOURCES = ./tests/recursiveGaussian/recursiveGaussian.cpp \
	./tests/recursiveGaussian/recursiveGaussian.cu.cpp
RecursiveGaussian_LDADD = $(OCELOT_LIBS)
RecursiveGaussian_LDFLAGS = -static
################################################################################

################################################################################
## SortingNetworks
SortingNetworks_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
SortingNetworks_SOURCES = ./tests/sortingNetworks/main.cpp \
	./tests/sortingNetworks/sortingNetworks_validate.cpp \
	./tests/sortingNetworks/bitonicSort.cu.cpp \
	./tests/sortingNetworks/oddEvenMergeSort.cu.cpp
SortingNetworks_LDADD = $(OCELOT_LIBS)
SortingNetworks_LDFLAGS = -static
################################################################################

################################################################################
## ConvolutionSeparable
ConvolutionSeparable_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
ConvolutionSeparable_SOURCES = ./tests/convolutionSeparable/main.cpp \
	./tests/convolutionSeparable/convolutionSeparable_gold.cpp \
	./tests/convolutionSeparable/convolutionSeparable.cu.cpp
ConvolutionSeparable_LDADD = $(OCELOT_LIBS)
ConvolutionSeparable_LDFLAGS = -static
################################################################################

################################################################################
## SimplePitchLinearTexture
SimplePitchLinearTexture_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
SimplePitchLinearTexture_SOURCES = ./tests/simplePitchLinearTexture/simplePitchLinearTexture.cu.cpp
SimplePitchLinearTexture_LDADD = $(OCELOT_LIBS)
SimplePitchLinearTexture_LDFLAGS = -static
################################################################################

################################################################################
## BandwidthTest
BandwidthTest_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
BandwidthTest_SOURCES = ./tests/bandwidthTest/bandwidthTest.cu.cpp
BandwidthTest_LDADD = $(OCELOT_LIBS)
BandwidthTest_LDFLAGS = -static
################################################################################

################################################################################
## ImageDenoising
ImageDenoising_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
ImageDenoising_SOURCES = ./tests/imageDenoising/imageDenoisingGL.cpp \
	./tests/imageDenoising/bmploader.cpp \
	./tests/imageDenoising/imageDenoising.cu.cpp
ImageDenoising_LDADD = $(OCELOT_LIBS)
ImageDenoising_LDFLAGS = -static
################################################################################

################################################################################
## SimpleTextureDrv
# SimpleTextureDrv_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
# SimpleTextureDrv_SOURCES = ./tests/simpleTextureDrv/simpleTextureDrv.cpp
# SimpleTextureDrv_LDADD = $(OCELOT_LIBS)
# SimpleTextureDrv_LDFLAGS = -static
################################################################################

################################################################################
## BoxFilter
BoxFilter_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
BoxFilter_SOURCES = ./tests/boxFilter/boxFilter.cpp \
	./tests/boxFilter/boxFilter_gold.cpp \
	./tests/boxFilter/boxFilter_kernel.cu.cpp
BoxFilter_LDADD = $(OCELOT_LIBS)
BoxFilter_LDFLAGS = -static
################################################################################

################################################################################
## ConvolutionTexture
ConvolutionTexture_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
ConvolutionTexture_SOURCES = ./tests/convolutionTexture/main.cpp \
	./tests/convolutionTexture/convolutionTexture_gold.cpp \
	./tests/convolutionTexture/convolutionTexture.cu.cpp
ConvolutionTexture_LDADD = $(OCELOT_LIBS)
ConvolutionTexture_LDFLAGS = -static
################################################################################

################################################################################
## AlignedTypes
AlignedTypes_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
AlignedTypes_SOURCES = ./tests/alignedTypes/alignedTypes.cu.cpp
AlignedTypes_LDADD = $(OCELOT_LIBS)
AlignedTypes_LDFLAGS = -static
################################################################################

################################################################################
## Transpose
Transpose_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
Transpose_SOURCES = ./tests/transpose/transpose.cu.cpp
Transpose_LDADD = $(OCELOT_LIBS)
Transpose_LDFLAGS = -static
################################################################################

################################################################################
## BilateralFilter
BilateralFilter_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
BilateralFilter_SOURCES = ./tests/bilateralFilter/bilateralFilter.cpp \
	./tests/bilateralFilter/bilateralFilter_gold.cpp \
	./tests/bilateralFilter/bmploader.cpp \
	./tests/bilateralFilter/filter_kernel.cu.cpp
BilateralFilter_LDADD = $(OCELOT_LIBS)
BilateralFilter_LDFLAGS = -static
################################################################################

################################################################################
## Particles
## Particles_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
## Particles_SOURCES = ./tests/particles/particles.cpp \
## 	./tests/particles/particleSystem.cpp \
## 	./tests/particles/render_particles.cpp \
## 	./tests/particles/shaders.cpp \
## 	./tests/particles/particleSystem.cu.cpp
## Particles_LDADD = $(OCELOT_LIBS)
## Particles_LDFLAGS = -static
################################################################################

################################################################################
## Interval
# Interval_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
# Interval_SOURCES = ./tests/Interval/interval.cu.cpp
# Interval_LDADD = $(OCELOT_LIBS)
# Interval_LDFLAGS = -static
################################################################################

################################################################################
## Nbody
Nbody_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
Nbody_SOURCES = ./tests/nbody/nbody.cpp \
	./tests/nbody/render_particles.cpp \
	./tests/nbody/bodysystemcuda.cu.cpp
Nbody_LDADD = $(OCELOT_LIBS)
Nbody_LDFLAGS = -static
################################################################################

################################################################################
## FluidsGL
FluidsGL_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
FluidsGL_SOURCES = ./tests/fluidsGL/fluidsGL.cu.cpp
FluidsGL_LDADD = $(OCELOT_LIBS) -lcufft
FluidsGL_LDFLAGS = -static
################################################################################

################################################################################
## SimpleStreams
SimpleStreams_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
SimpleStreams_SOURCES = ./tests/simpleStreams/simpleStreams.cu.cpp
SimpleStreams_LDADD = $(OCELOT_LIBS)
SimpleStreams_LDFLAGS = -static
################################################################################

################################################################################
## Mandelbrot
Mandelbrot_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
Mandelbrot_SOURCES = ./tests/Mandelbrot/Mandelbrot.cpp \
	./tests/Mandelbrot/Mandelbrot_gold.cpp \
	./tests/Mandelbrot/Mandelbrot_sm11.cu.cpp \
	./tests/Mandelbrot/Mandelbrot_sm13.cu.cpp
Mandelbrot_LDADD = $(OCELOT_LIBS)
Mandelbrot_LDFLAGS = -static
################################################################################

################################################################################
## FastWalshTransform
FastWalshTransform_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
FastWalshTransform_SOURCES = ./tests/fastWalshTransform/fastWalshTransform_gold.cpp \
	./tests/fastWalshTransform/fastWalshTransform.cu.cpp
FastWalshTransform_LDADD = $(OCELOT_LIBS)
FastWalshTransform_LDFLAGS = -static
################################################################################

################################################################################
## FDTD3d
FDTD3d_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS) -I ./tests/FDTD3d/inc/
FDTD3d_SOURCES = ./tests/FDTD3d/src/FDTD3d.cpp \
	./tests/FDTD3d/src/FDTD3dGPU.cu.cpp \
	./tests/FDTD3d/src/FDTD3dReference.cpp
FDTD3d_LDADD = $(OCELOT_LIBS)
FDTD3d_LDFLAGS = -static
################################################################################

################################################################################
## SimpleTexture
SimpleTexture_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
SimpleTexture_SOURCES = ./tests/simpleTexture/simpleTexture.cu.cpp
SimpleTexture_LDADD = $(OCELOT_LIBS)
SimpleTexture_LDFLAGS = -static
################################################################################

################################################################################
## SimplePrintf
SimplePrintf_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
SimplePrintf_SOURCES = ./tests/simplePrintf/simplePrintf.cu.cpp
SimplePrintf_LDADD = $(OCELOT_LIBS)
SimplePrintf_LDFLAGS = -static
################################################################################

################################################################################
## MatrixMul
MatrixMul_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
MatrixMul_SOURCES = ./tests/matrixMul/matrixMul_gold.cpp \
	./tests/matrixMul/matrixMul.cu.cpp
MatrixMul_LDADD = $(OCELOT_LIBS)
MatrixMul_LDFLAGS = -static
################################################################################

################################################################################
## ConcurrentKernels
# ConcurrentKernels_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
# ConcurrentKernels_SOURCES = ./tests/concurrentKernels/concurrentKernels.cu.cpp
# ConcurrentKernels_LDADD = $(OCELOT_LIBS)
# ConcurrentKernels_LDFLAGS = -static
################################################################################

################################################################################
## DeviceQuery
DeviceQuery_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
DeviceQuery_SOURCES = ./tests/deviceQuery/deviceQuery.cpp
DeviceQuery_LDADD = $(OCELOT_LIBS)
DeviceQuery_LDFLAGS = -static
################################################################################

################################################################################
## ScalarProd
ScalarProd_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
ScalarProd_SOURCES = ./tests/scalarProd/scalarProd_gold.cpp \
	./tests/scalarProd/scalarProd.cu.cpp
ScalarProd_LDADD = $(OCELOT_LIBS)
ScalarProd_LDFLAGS = -static
################################################################################

################################################################################
## AsyncAPI
AsyncAPI_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
AsyncAPI_SOURCES = ./tests/asyncAPI/asyncAPI.cu.cpp
AsyncAPI_LDADD = $(OCELOT_LIBS)
AsyncAPI_LDFLAGS = -static
################################################################################

################################################################################
## LineOfSight
# LineOfSight_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
# LineOfSight_SOURCES = ./tests/lineOfSight/lineOfSight.cu.cpp
# LineOfSight_LDADD = $(OCELOT_LIBS)
# LineOfSight_LDFLAGS = -static
################################################################################

################################################################################
## BinomialOptions
BinomialOptions_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
BinomialOptions_SOURCES = ./tests/binomialOptions/binomialOptions.cpp \
	./tests/binomialOptions/binomialOptions_gold.cpp \
	./tests/binomialOptions/binomialOptions_SM10.cu.cpp \
	./tests/binomialOptions/binomialOptions_SM13.cu.cpp
BinomialOptions_LDADD = $(OCELOT_LIBS)
BinomialOptions_LDFLAGS = -static
################################################################################

################################################################################
## VectorAdd
VectorAdd_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
VectorAdd_SOURCES = ./tests/vectorAdd/vectorAdd.cu.cpp
VectorAdd_LDADD = $(OCELOT_LIBS)
VectorAdd_LDFLAGS = -static
################################################################################

################################################################################
## ThreadFenceReduction
ThreadFenceReduction_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
ThreadFenceReduction_SOURCES = ./tests/threadFenceReduction/threadFenceReduction.cu.cpp
ThreadFenceReduction_LDADD = $(OCELOT_LIBS)
ThreadFenceReduction_LDFLAGS = -static
################################################################################

################################################################################
## SimpleMultiGPU
SimpleMultiGPU_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
SimpleMultiGPU_SOURCES = ./tests/simpleMultiGPU/simpleMultiGPU.cpp \
	./tests/simpleMultiGPU/simpleMultiGPU_kernel.cu.cpp
SimpleMultiGPU_LDADD = $(OCELOT_LIBS)
SimpleMultiGPU_LDFLAGS = -static
################################################################################

################################################################################
## Ptxjit
# Ptxjit_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
# Ptxjit_SOURCES = ./tests/ptxjit/ptxjit.cpp
# Ptxjit_LDADD = $(OCELOT_LIBS)
# Ptxjit_LDFLAGS = -static
################################################################################

################################################################################
## SobolQRNG
SobolQRNG_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
SobolQRNG_SOURCES = ./tests/SobolQRNG/sobol.cpp \
	./tests/SobolQRNG/sobol_gold.cpp \
	./tests/SobolQRNG/sobol_primitives.cpp \
	./tests/SobolQRNG/sobol_gpu.cu.cpp
SobolQRNG_LDADD = $(OCELOT_LIBS)
SobolQRNG_LDFLAGS = -static
################################################################################

################################################################################
## SobelFilter
SobelFilter_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
SobelFilter_SOURCES = ./tests/SobelFilter/SobelFilter.cpp \
	./tests/SobelFilter/SobelFilter_kernels.cu.cpp
SobelFilter_LDADD = $(OCELOT_LIBS)
SobelFilter_LDFLAGS = -static
################################################################################

################################################################################
## SmokeParticles
# SmokeParticles_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
# SmokeParticles_SOURCES = ./tests/smokeParticles/particleDemo.cpp \
# 	./tests/smokeParticles/ParticleSystem.cpp \
# 	./tests/smokeParticles/SmokeRenderer.cpp \
# 	./tests/smokeParticles/SmokeShaders.cpp \
# 	./tests/smokeParticles/framebufferObject.cpp \
# 	./tests/smokeParticles/renderbuffer.cpp \
# 	./tests/smokeParticles/GLSLProgram.cpp \
# 	./tests/smokeParticles/ParticleSystem.cu.cpp
# SmokeParticles_LDADD = $(OCELOT_LIBS)
# SmokeParticles_LDFLAGS = -static
################################################################################

################################################################################
## RadixSort
# RadixSort_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
# RadixSort_SOURCES = ./tests/radixSort/testradixsort.cpp \
# 	./tests/radixSort/radixsort.cpp \
# 	./tests/radixSort/radixsort.cu.cpp
# RadixSort_LDADD = $(OCELOT_LIBS)
# RadixSort_LDFLAGS = -static
################################################################################

################################################################################
## MatrixMulDynlinkJIT
MatrixMulDynlinkJIT_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
MatrixMulDynlinkJIT_SOURCES = ./tests/matrixMulDynlinkJIT/matrixMul_gold.cpp \
	./tests/matrixMulDynlinkJIT/matrixMulDynlinkJIT.cpp \
	./tests/matrixMulDynlinkJIT/matrixMul_ptxdump.c \
	./tests/matrixMulDynlinkJIT/cuda_drvapi_dynlink.c
MatrixMulDynlinkJIT_LDADD = $(OCELOT_LIBS)
MatrixMulDynlinkJIT_LDFLAGS = -static
################################################################################

################################################################################
## Clock
Clock_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
Clock_SOURCES = ./tests/clock/clock.cu.cpp
Clock_LDADD = $(OCELOT_LIBS)
Clock_LDFLAGS = -static
################################################################################


################################################################################

################################################################################
## Data
EXTRA_DIST = 
##
################################################################################

################################################################################
## Regression tests
regression/regression.log : check
	@echo
	@echo "Running CUDA SDK 2.3 regression test"
	@python hydrazine/python/RunRegression.py \
		-t regression/tests.txt \
		-l regression/regression.log -v

test : regression/regression.log

query:
	@echo "LLVM_LDFLAGS =" $(LLVM_LDFLAGS)
	@echo "OCELOT_LDFLAGS =" $(OCELOT_LDFLAGS)
	@echo "CUDA_CFLAGS =" $(CUDA_CFLAGS) 
	@echo "SDK_CFLAGS =" $(SDK_CFLAGS)

recompile:
	@python hydrazine/python/CompileCudaTests.py -a "-arch=sm_20 -Isdk -Ishared" -d tests/

################################################################################

