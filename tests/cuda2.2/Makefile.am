################################################################################
#	\file Makefile.am
#	\author Gregory Diamos
#	\date Monday June 15, 2009
# 	\brief Automake input file describing the programs and sources needed to
#			build Ocelot's SDK 2.2 regression tests
################################################################################

################################################################################
## Autoconf configuration
ACLOCAL_AMFLAGS = -I m4
OCELOT_LIBS = $(OCELOT_LDFLAGS) libsdk.la
CUFFT_LIBS = -lcufft -lGLU
CUBLAS_LIBS = -lcublas -lGLU
CUDA_CFLAGS = -I $(srcdir)/sdk
SDK_CFLAGS = -I $(srcdir)/sdk -lGLU
################################################################################

################################################################################
## Programs and Libraries
bin_PROGRAMS = 
check_PROGRAMS = AlignedTypes AsyncAPI BandwidthTest BicubicTexture \
	BinomialOptions Bitonic BlackScholes BoxFilter Clock ConvolutionFFT2D \
	ConvolutionSeparable ConvolutionTexture CppIntegration Dct8x8 DeviceQuery \
	DwtHaar1D Dxtc Eigenvalues FluidsGL FastWalshTransform Histogram256 \
	Histogram64 ImageDenoising Mandelbrot MatrixMul MersenneTwister \
	Nbody OceanFFT Particles PostProcessGL MonteCarlo \
	QuasirandomGenerator UnstructuredMandelbrot \
	RecursiveGaussian Reduction ScalarProd Scan ScanLargeArray \
	SimpleAtomicIntrinsics SimpleCUBLAS SimpleCUFFT SimpleGL SimpleMultiGPU \
	SimpleStreams SimpleTemplates SimpleTexture SimpleTexture3D \
	SimpleVoteIntrinsics SimpleZeroCopy SobelFilter SobolQRNG Template \
	ThreadFenceReduction Transpose TransposeNew VolumeRender
lib_LTLIBRARIES = libsdk.la
#
# 	MonteCarloMultiGPU \
#
################################################################################

################################################################################
## SDK 2.2 common libraries
libsdk_la_CXXFLAGS = -I sdk $(CUDA_CFLAGS)
libsdk_la_SOURCES = sdk/bank_checker.cpp \
	sdk/cutil.cpp \
	sdk/param.cpp \
	sdk/rendercheck_gl.cpp \
	sdk/stopwatch_linux.cpp \
	sdk/cmd_arg_reader.cpp \
	sdk/multithreading.cpp \
	sdk/paramgl.cpp \
	sdk/stopwatch.cpp
################################################################################

################################################################################
## AlignedTypes
AlignedTypes_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
AlignedTypes_SOURCES = tests/AlignedTypes/alignedTypes.cu.cpp
AlignedTypes_LDADD = $(OCELOT_LIBS)
AlignedTypes_LDFLAGS = -static
################################################################################

################################################################################
## AsyncAPI
AsyncAPI_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
AsyncAPI_SOURCES = tests/AsyncAPI/asyncAPI.cu.cpp
AsyncAPI_LDADD = $(OCELOT_LIBS)
AsyncAPI_LDFLAGS = -static
################################################################################

################################################################################
## BandwidthTest
BandwidthTest_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
BandwidthTest_SOURCES = tests/BandwidthTest/bandwidthTest.cu.cpp
BandwidthTest_LDADD = $(OCELOT_LIBS)
BandwidthTest_LDFLAGS = -static
################################################################################

################################################################################
## BicubicTexture
BicubicTexture_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
BicubicTexture_SOURCES = tests/BicubicTexture/bicubicTexture.cu.cpp \
	tests/BicubicTexture/bicubicTexture-host.cpp
BicubicTexture_LDADD = $(OCELOT_LIBS)
BicubicTexture_LDFLAGS = -static
################################################################################

################################################################################
## BinomialOptions
BinomialOptions_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
BinomialOptions_SOURCES = tests/BinomialOptions/binomialOptions_SM10.cu.cpp \
	tests/BinomialOptions/binomialOptions_SM13.cu.cpp \
	tests/BinomialOptions/binomialOptions.cpp \
	tests/BinomialOptions/binomialOptions_gold.cpp
BinomialOptions_LDADD = $(OCELOT_LIBS)
BinomialOptions_LDFLAGS = -static
################################################################################

################################################################################
## Bitonic
Bitonic_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
Bitonic_SOURCES = tests/Bitonic/bitonic.cu.cpp
Bitonic_LDADD = $(OCELOT_LIBS)
Bitonic_LDFLAGS = -static
################################################################################

################################################################################
## BlackScholes
BlackScholes_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
BlackScholes_SOURCES = tests/BlackScholes/BlackScholes.cu.cpp \
	tests/BlackScholes/BlackScholes_gold.cpp
BlackScholes_LDADD = $(OCELOT_LIBS)
BlackScholes_LDFLAGS = -static
################################################################################

################################################################################
## BoxFilter
BoxFilter_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
BoxFilter_SOURCES = tests/BoxFilter/boxFilter_kernel.cu.cpp \
	tests/BoxFilter/boxFilter_gold.cpp \
	tests/BoxFilter/boxFilter.cpp
BoxFilter_LDADD = $(OCELOT_LIBS)
BoxFilter_LDFLAGS = -static
################################################################################

################################################################################
## Clock
Clock_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
Clock_SOURCES = tests/Clock/clock.cu.cpp
Clock_LDADD = $(OCELOT_LIBS)
Clock_LDFLAGS = -static
################################################################################

################################################################################
## ConvolutionFFT2D
ConvolutionFFT2D_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
ConvolutionFFT2D_SOURCES = tests/ConvolutionFFT2D/convolutionFFT2D.cu.cpp \
	tests/ConvolutionFFT2D/convolutionFFT2D_gold.cpp
ConvolutionFFT2D_LDADD = $(CUFFT_LIBS) $(OCELOT_LIBS)
################################################################################

################################################################################
## ConvolutionSeparable
ConvolutionSeparable_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
ConvolutionSeparable_SOURCES = \
	tests/ConvolutionSeparable/convolutionSeparable.cu.cpp \
	tests/ConvolutionSeparable/convolutionSeparable_gold.cpp
ConvolutionSeparable_LDADD = $(OCELOT_LIBS)
ConvolutionSeparable_LDFLAGS = -static
################################################################################

################################################################################
## ConvolutionTexture
ConvolutionTexture_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
ConvolutionTexture_SOURCES = \
	tests/ConvolutionTexture/convolutionTexture.cu.cpp \
	tests/ConvolutionTexture/convolutionTexture_gold.cpp
ConvolutionTexture_LDADD = $(OCELOT_LIBS)
ConvolutionTexture_LDFLAGS = -static
################################################################################

################################################################################
## CppIntegration
CppIntegration_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
CppIntegration_SOURCES = \
	tests/CppIntegration/cppIntegration.cu.cpp \
	tests/CppIntegration/cppIntegration_gold.cpp \
	tests/CppIntegration/main.cpp
CppIntegration_LDADD = $(OCELOT_LIBS)
CppIntegration_LDFLAGS = -static
################################################################################

################################################################################
## Dct8x8
Dct8x8_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
Dct8x8_SOURCES = tests/Dct8x8/dct8x8.cu.cpp \
	tests/Dct8x8/DCT8x8_Gold.cpp \
	tests/Dct8x8/BmpUtil.cpp
Dct8x8_LDADD = $(OCELOT_LIBS)
Dct8x8_LDFLAGS = -static
################################################################################

################################################################################
## DeviceQuery
DeviceQuery_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
DeviceQuery_SOURCES = tests/DeviceQuery/deviceQuery.cpp
DeviceQuery_LDADD = $(OCELOT_LIBS)
DeviceQuery_LDFLAGS = -static
################################################################################

################################################################################
## DwtHaar1D
DwtHaar1D_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
DwtHaar1D_SOURCES = tests/DwtHaar1D/dwtHaar1D.cu.cpp
DwtHaar1D_LDADD = $(OCELOT_LIBS)
DwtHaar1D_LDFLAGS = -static
################################################################################

################################################################################
## Dxtc
Dxtc_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
Dxtc_SOURCES = tests/Dxtc/dxtc.cu.cpp tests/Dxtc/tests.cu.cpp
Dxtc_LDADD = $(OCELOT_LIBS)
Dxtc_LDFLAGS = -static
################################################################################

################################################################################
## Eigenvalues
Eigenvalues_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
Eigenvalues_SOURCES = tests/Eigenvalues/main.cu.cpp \
	tests/Eigenvalues/matlab.cpp \
	tests/Eigenvalues/gerschgorin.cpp \
	tests/Eigenvalues/bisect_large.cu.cpp \
	tests/Eigenvalues/bisect_small.cu.cpp
Eigenvalues_LDADD = $(OCELOT_LIBS)
Eigenvalues_LDFLAGS = -static
################################################################################

################################################################################
## FluidsGL
FluidsGL_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
FluidsGL_SOURCES = tests/FluidsGL/fluidsGL.cu.cpp
FluidsGL_LDADD = $(CUFFT_LIBS) $(OCELOT_LIBS)
################################################################################

################################################################################
## FastWalshTransform
FastWalshTransform_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
FastWalshTransform_SOURCES = \
	tests/FastWalshTransform/fastWalshTransform.cu.cpp \
	tests/FastWalshTransform/fastWalshTransform_gold.cpp
FastWalshTransform_LDADD = $(OCELOT_LIBS)
FastWalshTransform_LDFLAGS = -static
################################################################################

################################################################################
## Histogram256
Histogram256_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
Histogram256_SOURCES = tests/Histogram256/histogram256_SM10.cu.cpp \
	tests/Histogram256/histogram256_SM11.cu.cpp \
	tests/Histogram256/histogram256_SM12.cu.cpp \
	tests/Histogram256/histogram256_gold.cpp \
	tests/Histogram256/histogram256.cpp
Histogram256_LDADD = $(OCELOT_LIBS)
Histogram256_LDFLAGS = -static
################################################################################

################################################################################
## Histogram64
Histogram64_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
Histogram64_SOURCES = tests/Histogram64/histogram64.cu.cpp \
	tests/Histogram64/histogram64_gold.cpp
Histogram64_LDADD = $(OCELOT_LIBS)
Histogram64_LDFLAGS = -static
################################################################################

################################################################################
## ImageDenoising
ImageDenoising_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
ImageDenoising_SOURCES = tests/ImageDenoising/imageDenoising.cu.cpp \
	tests/ImageDenoising/bmploader.cpp \
	tests/ImageDenoising/imageDenoisingGL.cpp
ImageDenoising_LDADD = $(OCELOT_LIBS)
ImageDenoising_LDFLAGS = -static
################################################################################

################################################################################
## Mandelbrot
Mandelbrot_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
Mandelbrot_SOURCES = tests/Mandelbrot/Mandelbrot.cpp \
	tests/Mandelbrot/Mandelbrot_sm10.cu.cpp \
	tests/Mandelbrot/Mandelbrot_sm13.cu.cpp \
	tests/Mandelbrot/Mandelbrot_gold.cpp
Mandelbrot_LDADD = $(OCELOT_LIBS)
Mandelbrot_LDFLAGS = -static
################################################################################

################################################################################
## UnstructuredMandelbrot
UnstructuredMandelbrot_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
UnstructuredMandelbrot_SOURCES = \
	tests/UnstructuredMandelbrot/Mandelbrot_sm10.cu.cpp \
	tests/UnstructuredMandelbrot/Mandelbrot_sm13.cu.cpp \
	tests/UnstructuredMandelbrot/Mandelbrot.cpp \
	tests/UnstructuredMandelbrot/Mandelbrot_gold.cpp
UnstructuredMandelbrot_LDADD = $(OCELOT_LIBS)
UnstructuredMandelbrot_LDFLAGS = -static
################################################################################

################################################################################
## MatrixMul
MatrixMul_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
MatrixMul_SOURCES = tests/MatrixMul/matrixMul.cu.cpp \
	tests/MatrixMul/matrixMul_gold.cpp
MatrixMul_LDADD = $(OCELOT_LIBS)
MatrixMul_LDFLAGS = -static
################################################################################

################################################################################
## MersenneTwister
MersenneTwister_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
MersenneTwister_SOURCES = tests/MersenneTwister/MersenneTwister.cu.cpp \
	tests/MersenneTwister/MersenneTwister_gold.cpp \
	tests/MersenneTwister/genmtrand.c 
MersenneTwister_LDADD = $(OCELOT_LIBS)
MersenneTwister_LDFLAGS = -static
################################################################################

################################################################################
# MonteCarlo
MonteCarlo_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
MonteCarlo_SOURCES = tests/MonteCarlo/MonteCarlo_SM13.cu.cpp \
	tests/MonteCarlo/MonteCarlo_SM10.cu.cpp \
	tests/MonteCarlo/MonteCarlo_gold.cpp \
	tests/MonteCarlo/MonteCarlo.cpp
MonteCarlo_LDADD = $(OCELOT_LIBS)
MonteCarlo_LDFLAGS = -static
################################################################################

################################################################################
## MonteCarloMultiGPU
# MonteCarloMultiGPU_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
# MonteCarloMultiGPU_SOURCES =  \
# 	tests/MonteCarloMultiGPU/MonteCarlo_SM13.cu.cpp \
# 	tests/MonteCarloMultiGPU/MonteCarlo_SM10.cu.cpp \
# 	tests/MonteCarlo/MonteCarlo_gold.cpp \
# 	tests/MonteCarlo/MonteCarlo.cpp
# MonteCarloMultiGPU_LDADD = $(OCELOT_LIBS)
# MonteCarloMultiGPU_LDFLAGS = -static
################################################################################

################################################################################
## Nbody
Nbody_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
Nbody_SOURCES = tests/Nbody/bodysystemcuda.cu.cpp tests/Nbody/nbody.cpp \
	tests/Nbody/bodysystemcpu.cpp \
	tests/Nbody/bodysystemcuda-host.cpp \
	tests/Nbody/nbody_gold.cpp \
	tests/Nbody/render_particles.cpp
Nbody_LDADD = $(OCELOT_LIBS)
Nbody_LDFLAGS = -static
################################################################################

################################################################################
## OceanFFT
OceanFFT_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
OceanFFT_SOURCES = tests/OceanFFT/oceanFFT_kernel.cu.cpp \
	tests/OceanFFT/oceanFFT.cpp
OceanFFT_LDADD = $(CUFFT_LIBS) $(OCELOT_LIBS)
################################################################################

################################################################################
## Particles
Particles_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
Particles_SOURCES = tests/Particles/particleSystem.cu.cpp \
	tests/Particles/particles.cpp \
	tests/Particles/particleSystem-host.cpp \
	tests/Particles/render_particles.cpp \
	tests/Particles/shaders.cpp
Particles_LDADD = $(OCELOT_LIBS)
Particles_LDFLAGS = -static
################################################################################

################################################################################
## PostProcessGL
PostProcessGL_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
PostProcessGL_SOURCES = tests/PostProcessGL/postProcessGL.cu.cpp \
	tests/PostProcessGL/main.cpp
PostProcessGL_LDADD = $(OCELOT_LIBS)
PostProcessGL_LDFLAGS = -static
################################################################################

################################################################################
## QuasirandomGenerator
QuasirandomGenerator_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
QuasirandomGenerator_SOURCES = \
	tests/QuasirandomGenerator/quasirandomGenerator_SM13.cu.cpp \
	tests/QuasirandomGenerator/quasirandomGenerator_SM10.cu.cpp \
	tests/QuasirandomGenerator/quasirandomGenerator_gold.cpp \
	tests/QuasirandomGenerator/quasirandomGenerator.cpp
QuasirandomGenerator_LDADD = $(OCELOT_LIBS)
QuasirandomGenerator_LDFLAGS = -static
################################################################################

################################################################################
## RecursiveGaussian
RecursiveGaussian_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
RecursiveGaussian_SOURCES = tests/RecursiveGaussian/recursiveGaussian.cu.cpp \
	tests/RecursiveGaussian/recursiveGaussian-host.cpp
RecursiveGaussian_LDADD = $(OCELOT_LIBS)
RecursiveGaussian_LDFLAGS = -static
################################################################################

################################################################################
## Reduction
Reduction_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
Reduction_SOURCES = tests/Reduction/reduction_kernel_sm13.cu.cpp \
	tests/Reduction/reduction_kernel_sm10.cu.cpp \
	tests/Reduction/reduction.cu.cpp
Reduction_LDADD = $(OCELOT_LIBS)
Reduction_LDFLAGS = -static
################################################################################

################################################################################
## ScalarProd
ScalarProd_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
ScalarProd_SOURCES = tests/ScalarProd/scalarProd.cu.cpp \
	tests/ScalarProd/scalarProd_gold.cpp
ScalarProd_LDADD = $(OCELOT_LIBS)
ScalarProd_LDFLAGS = -static
################################################################################

################################################################################
## Scan
Scan_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
Scan_SOURCES = tests/Scan/scan.cu.cpp \
	tests/Scan/scan_gold.cpp
Scan_LDADD = $(OCELOT_LIBS)
Scan_LDFLAGS = -static
################################################################################

################################################################################
## ScanLargeArray
ScanLargeArray_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS) -D__DEVICE_EMULATION__
ScanLargeArray_SOURCES = tests/ScanLargeArray/scanLargeArray.cu.cpp \
	tests/ScanLargeArray/scan_gold.cpp
ScanLargeArray_LDADD = $(OCELOT_LIBS)
ScanLargeArray_LDFLAGS = -static
################################################################################

################################################################################
## SimpleAtomicIntrinsics
SimpleAtomicIntrinsics_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
SimpleAtomicIntrinsics_SOURCES = \
	tests/SimpleAtomicIntrinsics/simpleAtomicIntrinsics.cu.cpp \
	tests/SimpleAtomicIntrinsics/simpleAtomicIntrinsics_gold.cpp
SimpleAtomicIntrinsics_LDADD = $(OCELOT_LIBS)
SimpleAtomicIntrinsics_LDFLAGS = -static
################################################################################

################################################################################
## SimpleCUBLAS
SimpleCUBLAS_CFLAGS = -Wall $(CUDA_CFLAGS)
SimpleCUBLAS_SOURCES = tests/SimpleCUBLAS/simpleCUBLAS.c
SimpleCUBLAS_LDADD = $(CUBLAS_LIBS) $(OCELOT_LIBS)
################################################################################

################################################################################
## SimpleCUFFT
SimpleCUFFT_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
SimpleCUFFT_SOURCES = tests/SimpleCUFFT/simpleCUFFT.cu.cpp
SimpleCUFFT_LDADD = $(CUFFT_LIBS) $(OCELOT_LIBS) 
################################################################################

################################################################################
## SimpleGL
SimpleGL_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
SimpleGL_SOURCES = tests/SimpleGL/simpleGL_kernel.cu.cpp \
	tests/SimpleGL/simpleGL.cpp
SimpleGL_LDADD = $(OCELOT_LIBS)
SimpleGL_LDFLAGS = -static
################################################################################

################################################################################
## SimpleMultiGPU
SimpleMultiGPU_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
SimpleMultiGPU_SOURCES = tests/SimpleMultiGPU/simpleMultiGPU_kernel.cu.cpp \
	tests/SimpleMultiGPU/simpleMultiGPU.cpp
SimpleMultiGPU_LDADD = $(OCELOT_LIBS)
SimpleMultiGPU_LDFLAGS = -static
################################################################################

################################################################################
## SimpleStreams
SimpleStreams_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
SimpleStreams_SOURCES = tests/SimpleStreams/simpleStreams.cu.cpp
SimpleStreams_LDADD = $(OCELOT_LIBS)
SimpleStreams_LDFLAGS = -static
################################################################################

################################################################################
## SimpleTemplates
SimpleTemplates_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
SimpleTemplates_SOURCES = tests/SimpleTemplates/simpleTemplates.cu.cpp
SimpleTemplates_LDADD = $(OCELOT_LIBS)
SimpleTemplates_LDFLAGS = -static
################################################################################

################################################################################
## SimpleTexture
SimpleTexture_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
SimpleTexture_SOURCES = tests/SimpleTexture/simpleTexture.cu.cpp
SimpleTexture_LDADD = $(OCELOT_LIBS)
SimpleTexture_LDFLAGS = -static
###############################################################################

################################################################################
## SimpleTexture3D
SimpleTexture3D_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
SimpleTexture3D_SOURCES = tests/SimpleTexture3D/simpleTexture3D_kernel.cu.cpp \
	tests/SimpleTexture3D/simpleTexture3D-host.cpp
SimpleTexture3D_LDADD = $(OCELOT_LIBS)
SimpleTexture3D_LDFLAGS = -static
################################################################################

################################################################################
## SimpleVoteIntrinsics
SimpleVoteIntrinsics_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
SimpleVoteIntrinsics_SOURCES = \
	tests/SimpleVoteIntrinsics/simpleVoteIntrinsics.cu.cpp
SimpleVoteIntrinsics_LDADD = $(OCELOT_LIBS)
SimpleVoteIntrinsics_LDFLAGS = -static
################################################################################

################################################################################
## SimpleZeroCopy
SimpleZeroCopy_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
SimpleZeroCopy_SOURCES = \
	tests/SimpleZeroCopy/simpleZeroCopy.cu.cpp
SimpleZeroCopy_LDADD = $(OCELOT_LIBS)
SimpleZeroCopy_LDFLAGS = -static
################################################################################

################################################################################
## SobelFilter
SobelFilter_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
SobelFilter_SOURCES = tests/SobelFilter/SobelFilter_kernels.cu.cpp \
	tests/SobelFilter/SobelFilter.cpp
SobelFilter_LDADD = $(OCELOT_LIBS)
SobelFilter_LDFLAGS = -static
################################################################################

################################################################################
## SobolQRNG
SobolQRNG_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
SobolQRNG_SOURCES = tests/SobolQRNG/sobol.cpp \
	tests/SobolQRNG/sobol_gold.cpp \
	tests/SobolQRNG/sobol_gpu.cu.cpp \
	tests/SobolQRNG/sobol_primitives.cpp
SobolQRNG_LDADD = $(OCELOT_LIBS)
SobolQRNG_LDFLAGS = -static
################################################################################

################################################################################
## Template
Template_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
Template_SOURCES = tests/Template/template.cu.cpp \
	tests/Template/template_gold.cpp
Template_LDADD = $(OCELOT_LIBS)
Template_LDFLAGS = -static
################################################################################

################################################################################
## ThreadFenceReduction
ThreadFenceReduction_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
ThreadFenceReduction_SOURCES = \
	tests/ThreadFenceReduction/threadFenceReduction.cu.cpp
ThreadFenceReduction_LDADD = $(OCELOT_LIBS)
ThreadFenceReduction_LDFLAGS = -static
################################################################################

################################################################################
## Transpose
Transpose_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
Transpose_SOURCES = tests/Transpose/transpose.cu.cpp \
	tests/Transpose/transpose_gold.cpp
Transpose_LDADD = $(OCELOT_LIBS)
Transpose_LDFLAGS = -static
################################################################################

################################################################################
## TransposeNew
TransposeNew_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
TransposeNew_SOURCES = tests/TransposeNew/transposeNew.cu.cpp
TransposeNew_LDADD = $(OCELOT_LIBS)
TransposeNew_LDFLAGS = -static
################################################################################

################################################################################
## VolumeRender
VolumeRender_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
VolumeRender_SOURCES = tests/VolumeRender/volumeRender_kernel.cu.cpp \
	tests/VolumeRender/volumeRender.cpp
VolumeRender_LDADD = $(OCELOT_LIBS)
VolumeRender_LDFLAGS = -static
################################################################################

################################################################################
## Headers
nobase_include_HEADERS = sdk/stopwatch_base.h \
	sdk/cutil.h \
	sdk/cutil_math.h \
	sdk/cuComplex.h \
	sdk/param.h \
	sdk/vector_types.h \
	sdk/nvGLWidgets.h \
	sdk/driver_types.h \
	sdk/cutil_gl_inline.h \
	sdk/nvVector.h \
	sdk/exception.h \
	sdk/channel_descriptor.h \
	sdk/cuda_gl_interop.h \
	sdk/rendercheck_gl.h \
	sdk/nvShaderUtils.h \
	sdk/cutil_inline_bankchecker.h \
	sdk/cublas.h \
	sdk/device_types.h \
	sdk/host_config.h \
	sdk/driver_functions.h \
	sdk/texture_types.h \
	sdk/cutil_inline_runtime.h \
	sdk/error_checker.h \
	sdk/cmd_arg_reader.h \
	sdk/cutil_inline_drvapi.h \
	sdk/cufft.h \
	sdk/builtin_types.h \
	sdk/cuda_runtime.h \
	sdk/paramgl.h \
	sdk/multithreading.h \
	sdk/cutil_gl_error.h \
	sdk/host_defines.h \
	sdk/cuda.h \
	sdk/nvGlutWidgets.h \
	sdk/stopwatch.h \
	sdk/stopwatch_base.inl \
	sdk/cuda_runtime_api.h \
	sdk/bank_checker.h \
	sdk/nvMatrix.h \
	sdk/stopwatch_linux.h \
	sdk/nvWidgets.h \
	sdk/nvMath.h \
	sdk/nvQuaternion.h \
	sdk/math_constants.h \
	sdk/cutil_inline.h \
	sdk/vector_functions.h \
	tests/SimpleMultiGPU/simpleMultiGPU.h \
	tests/Eigenvalues/gerschgorin.h \
	tests/Eigenvalues/util.h \
	tests/Eigenvalues/matlab.h \
	tests/Eigenvalues/structs.h \
	tests/Eigenvalues/config.h \
	tests/MonteCarloMultiGPU/MonteCarlo_common.h \
	tests/MonteCarloMultiGPU/realtype.h \
	tests/MatrixMul/matrixMul.h \
	tests/Histogram256/histogram256_common.h \
	tests/ThreadFenceReduction/threadFenceReduction.h \
	tests/SobolQRNG/sobol_gpu.h \
	tests/SobolQRNG/sobol_gold.h \
	tests/SobolQRNG/sobol.h \
	tests/SobolQRNG/sobol_primitives.h \
	tests/BinomialOptions/binomialOptions_common.h \
	tests/BinomialOptions/realtype.h \
	tests/MonteCarlo/MonteCarlo_common.h \
	tests/MonteCarlo/realtype.h \
	tests/Reduction/reduction.h \
	tests/ImageDenoising/imageDenoising.h \
	tests/Dct8x8/DCT8x8_Gold.h \
	tests/Dct8x8/Common.h \
	tests/Dct8x8/BmpUtil.h \
	tests/Dxtc/dds.h \
	tests/Dxtc/permutations.h \
	tests/Dxtc/CudaMath.h \
	tests/SobelFilter/SobelFilter_kernels.h \
	tests/Nbody/bodysystemcpu.h \
	tests/Nbody/render_particles.h \
	tests/Nbody/bodysystemcuda.h \
	tests/Nbody/bodysystem.h \
	tests/Mandelbrot/Mandelbrot_gold.h \
	tests/Mandelbrot/Mandelbrot_kernel.h \
	tests/FluidsGL/fluidsGL_kernels.h \
	tests/MersenneTwister/MersenneTwister.h \
	tests/MersenneTwister/dci.h \
	tests/QuasirandomGenerator/quasirandomGenerator_common.h \
	tests/QuasirandomGenerator/realtype.h \
	tests/Eigenvalues/bisect_small.cuh \
	tests/Eigenvalues/bisect_large.cuh \
	tests/MonteCarloMultiGPU/quasirandomGenerator_kernel.cuh \
	tests/MonteCarloMultiGPU/MonteCarlo_reduction.cuh \
	tests/MonteCarloMultiGPU/MonteCarlo_kernel.cuh \
	tests/Histogram256/histogram256_kernel.cuh \
	tests/SimpleTemplates/sharedmem.cuh \
	tests/BinomialOptions/binomialOptions_kernel.cuh \
	tests/MonteCarlo/quasirandomGenerator_kernel.cuh \
	tests/MonteCarlo/MonteCarlo_reduction.cuh \
	tests/MonteCarlo/MonteCarlo_kernel.cuh \
	tests/Reduction/sharedmem.cuh \
	tests/Histogram64/histogram64_kernel.cuh \
	tests/BlackScholes/BlackScholes_kernel.cuh \
	tests/QuasirandomGenerator/quasirandomGenerator_kernel.cuh \
	tests/BicubicTexture/bicubicTexture_kernel.cuh


################################################################################

################################################################################
## Data
EXTRA_DIST = data/regression_2_18.gold.dat \
	data/diagonal.dat \
	data/ref_nlm2.ppm \
	data/ref_2.ppm \
	data/lena_22.ppm \
	data/signal_2_14.dat \
	data/compVoxelArray.bin \
	data/ref_18.ppm \
	data/ref_16.ppm \
	data/03_bicubic.ppm \
	data/ref_rotated.pgm \
	data/lorikeet-orig.ppm \
	data/ref_orig.ppm \
	data/01_nearest.ppm \
	data/lena_bw.pgm \
	data/ref_nlm.ppm \
	data/Mandelbrot_fp32.ppm \
	data/lena_ref.dds \
	data/referenceJulia_fp32.ppm \
	data/Mandelbrot_fp64.ppm \
	data/posArray.bin \
	data/ref_orig.pgm \
	data/regression.gold.dat \
	data/ref_particles.ppm \
	data/ref_4.ppm \
	data/ref_10.ppm \
	data/portrait_noise.bmp \
	data/lena-orig.ppm \
	data/smokeParticles_ref.ppm \
	data/ocean.frag \
	data/04_fastbicubic.ppm \
	data/lena_std.dds \
	data/ref_spatialDomain_sm13.bin \
	data/ref_texture3D.bin \
	data/signal.dat \
	data/referenceJulia_fp64.ppm \
	data/ref_spatialDomain.bin \
	data/particles_4.ppm \
	data/ocean.vert \
	data/ref_shared_tex.ppm \
	data/barbara.ppm \
	data/lena.ppm \
	data/params.txt \
	data/ref_slopeShading_sm13.bin \
	data/MersenneTwister.dat \
	data/ref_slopeShading.bin \
	data/lena_bw_out.pgm \
	data/barbara.bmp \
	data/ref_particles.bin \
	data/ref_shared.ppm \
	data/lena_std.ppm \
	data/ref_simpleTex3D.ppm \
	data/ref_shared.pgm \
	data/signal_2_18.dat \
	data/ref_volume.ppm \
	data/ref_march_cubes.ppm \
	data/lena.pgm \
	data/ref_simpleGL.ppm \
	data/regression_2_14.gold.dat \
	data/reference.ppm \
	data/ref_22.ppm \
	data/lena_18.ppm \
	data/colors.ppm \
	data/ref_passthru.ppm \
	data/normalArray.bin \
	data/Bucky.raw \
	data/02_bilinear.ppm \
	data/ref_8.ppm \
	data/lena_14.ppm \
	data/ref_shared_tex.pgm \
	data/MersenneTwister.raw \
	data/floortile.ppm \
	data/lena_10.ppm \
	data/superdiagonal.dat \
	data/ref_knn.ppm \
	data/reference.dat \
	data/ref_14.ppm \
	regression/tests.txt \
	hydrazine/python/RunRegression.py

################################################################################

query:
	@echo "OCELOT_LDFLAGS =" $(OCELOT_LDFLAGS)

################################################################################
## Regression tests
regression/regression.log : check
	@echo
	@echo "Running CUDA SDK 2.2 regression test"
	@python hydrazine/python/RunRegression.py \
		-t regression/tests.txt \
		-l regression/regression.log -v

test : regression/regression.log

################################################################################


