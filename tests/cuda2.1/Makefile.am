################################################################################
#	\file Makefile.am
#	\author Gregory Diamos
#	\date Monday June 15, 2009
# 	\brief Automake input file describing the programs and sources needed to
#			build Ocelot's SDK 2.1 regression tests
################################################################################

################################################################################
## Autoconf configuration
ACLOCAL_AMFLAGS = -I m4
OCELOT_LIBS = ../../libcudart.la ../../libexecutive.la ../../libtrace.la \
	../../libir.la ../../libparser.la ../../libhydrazine.la
################################################################################

################################################################################
## Programs and Libraries
bin_PROGRAMS = 
check_PROGRAMS = AlignedTypes ConvolutionFFT2D FastWalshTransform MatrixMul \
	 QuasirandomGenerator SimpleCUFFT SmokeParticles AsyncAPI \
	 ConvolutionSeparable FluidsGL RecursiveGaussian SimpleGL \
	 SobelFilter BandwidthTest ConvolutionTexture Histogram256 MersenneTwister \
	 Reduction SimpleMultiGPU Template BicubicTexture CppIntegration \
	 Histogram64 MonteCarlo ScalarProd SimpleStreams \
	 BinomialOptions Dct8x8 ImageDenoising MonteCarloMultiGPU Scan \
	 SimpleTemplates Transpose Bitonic DeviceQuery LineOfSight Nbody \
	 ScanLargeArray SimpleTexture VolumeRender BlackScholes DwtHaar1D \
	 Mandelbrot OceanFFT SimpleTexture3D BoxFilter Dxtc MarchingCubes \
	 Particles SimpleAtomicIntrinsics Clock Eigenvalues \
	 PostProcessGL SimpleCUBLAS SimpleVoteIntrinsics SimplerFFT \
	 Sequence MatrixMultiply CapModel3 RangeDopplerGen \
	 RangeDopplerMap Sequence MatrixMultiply CapModel3 
################################################################################

################################################################################
## AlignedTypes
AlignedTypes_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall \
	-std=c++0x $(SDK_CFLAGS)
AlignedTypes_SOURCES = AlignedTypes/alignedTypes.cu.cpp
AlignedTypes_LDADD = $(OCELOT_LIBS)
AlignedTypes_LDFLAGS = -static
################################################################################

################################################################################
## AsyncAPI
AsyncAPI_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall \
	-std=c++0x -D__DEVICE_EMULATION__
AsyncAPI_SOURCES = AsyncAPI/AsyncAPI.cu.cpp
AsyncAPI_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
AsyncAPI_LDFLAGS = -static
################################################################################

################################################################################
## BandwidthTest
BandwidthTest_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall \
	-std=c++0x $(SDK_CFLAGS)
BandwidthTest_SOURCES = BandwidthTest/BandwidthTest.cu.cpp
BandwidthTest_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
BandwidthTest_LDFLAGS = -static
################################################################################

################################################################################
## BicubicTexture
BicubicTexture_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall \
	-std=c++0x $(SDK_CFLAGS)
BicubicTexture_SOURCES = BicubicTexture/BicubicTexture.cu.cpp \
	BlackScholes/BlackScholes_gold.cpp
BicubicTexture_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
BicubicTexture_LDFLAGS = -static
################################################################################

################################################################################
## BinomialOptions
BinomialOptions_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall \
	-std=c++0x -I BinomialOptions $(SDK_CFLAGS)
BinomialOptions_SOURCES = BinomialOptions/BinomialOptions_SM13.cu.cpp \
	BinomialOptions/BinomialOptions_SM10.cu.cpp \
	BinomialOptions/binomialOptions_common.h \
	BinomialOptions/binomialOptions.cpp  \
	BinomialOptions/binomialOptions_gold.cpp
BinomialOptions_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la \
	libtrace.la libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) \
	$(BOOST_LIBS)
BinomialOptions_LDFLAGS = -static
################################################################################

################################################################################
## Bitonic
Bitonic_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x $(SDK_CFLAGS)
Bitonic_SOURCES = Bitonic/Bitonic.cu.cpp
Bitonic_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
Bitonic_LDFLAGS = -static
################################################################################

################################################################################
## BlackScholes
BlackScholes_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x $(SDK_CFLAGS)
BlackScholes_SOURCES = BlackScholes/BlackScholes.cu.cpp \
	BlackScholes/BlackScholes_gold.cpp
BlackScholes_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
BlackScholes_LDFLAGS = -static
################################################################################

################################################################################
## BoxFilter
BoxFilter_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x $(SDK_CFLAGS)
BoxFilter_SOURCES = BoxFilter/BoxFilter.cu.cpp \
	BoxFilter/boxFilter_gold.cpp \
	BoxFilter/boxFilter.cpp
BoxFilter_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
BoxFilter_LDFLAGS = -static
################################################################################

################################################################################
## Clock
Clock_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x
Clock_SOURCES = Clock/Clock.cu.cpp
Clock_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
Clock_LDFLAGS = -static
################################################################################

################################################################################
## ConvolutionFFT2D
ConvolutionFFT2D_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x
ConvolutionFFT2D_SOURCES = ConvolutionFFT2D/ConvolutionFFT2D.cu.cpp \
	ConvolutionFFT2D/convolutionFFT2D_gold.cpp
ConvolutionFFT2D_LDADD = $(SDK_LIBS) $(CUFFT_LIBS) libcudart.la \
	libexecutive.la libtrace.la libir.la libparser.la libhydrazine.la $(LIBRT) \
	$(GL_LIBS) $(BOOST_LIBS)
################################################################################

################################################################################
## ConvolutionSeparable
ConvolutionSeparable_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x
ConvolutionSeparable_SOURCES = \
	ConvolutionSeparable/ConvolutionSeparable.cu.cpp \
	ConvolutionSeparable/convolutionSeparable_gold.cpp
ConvolutionSeparable_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la \
	libtrace.la libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) \
	$(BOOST_LIBS)
ConvolutionSeparable_LDFLAGS = -static
################################################################################

################################################################################
## ConvolutionTexture
ConvolutionTexture_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x
ConvolutionTexture_SOURCES = ConvolutionTexture/ConvolutionTexture.cu.cpp \
	ConvolutionTexture/convolutionTexture_gold.cpp
ConvolutionTexture_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la \
	libtrace.la libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) \
	$(BOOST_LIBS)
ConvolutionTexture_LDFLAGS = -static
################################################################################

################################################################################
## CppIntegration
CppIntegration_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall \
	-std=c++0x $(SDK_CFLAGS)
CppIntegration_SOURCES = CppIntegration/CppIntegration.cu.cpp \
	CppIntegration/cppIntegration_gold.cpp \
	CppIntegration/main.cpp
CppIntegration_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
CppIntegration_LDFLAGS = -static
################################################################################

################################################################################
## Dct8x8
Dct8x8_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall \
	-std=c++0x $(SDK_CFLAGS)
Dct8x8_SOURCES = Dct8x8/Dct8x8.cu.cpp \
	Dct8x8/DCT8x8_Gold.cpp \
	Dct8x8/BmpUtil.cpp
Dct8x8_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
Dct8x8_LDFLAGS = -static
################################################################################

################################################################################
## DeviceQuery
DeviceQuery_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x
DeviceQuery_SOURCES = DeviceQuery/DeviceQuery.cu.cpp
DeviceQuery_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
DeviceQuery_LDFLAGS = -static
################################################################################

################################################################################
## DwtHaar1D
DwtHaar1D_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x
DwtHaar1D_SOURCES = DwtHaar1D/DwtHaar1D.cu.cpp
DwtHaar1D_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
DwtHaar1D_LDFLAGS = -static
################################################################################

################################################################################
## Dxtc
Dxtc_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x
Dxtc_SOURCES = Dxtc/Dxtc.cu.cpp Dxtc/DxtcTests.cu.cpp
Dxtc_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
Dxtc_LDFLAGS = -static
################################################################################

################################################################################
## Eigenvalues
Eigenvalues_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x
Eigenvalues_SOURCES = Eigenvalues/Eigenvalues.cu.cpp \
	Eigenvalues/matlab.cpp \
	Eigenvalues/gerschgorin.cpp \
	Bisect_large.cu.cpp \
	Bisect_small.cu.cpp
Eigenvalues_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
Eigenvalues_LDFLAGS = -static
################################################################################

################################################################################
## FluidsGL
FluidsGL_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x \
	$(SDK_CFLAGS)
FluidsGL_SOURCES = FluidsGL/FluidsGL.cu.cpp
FluidsGL_LDADD = $(SDK_LIBS) $(LIBRT) $(GL_LIBS) $(CUFFT_LIBS) libcudart.la \
	libexecutive.la libtrace.la libir.la libparser.la libhydrazine.la $(BOOST_LIBS)
################################################################################

################################################################################
## FastWalshTransform
FastWalshTransform_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x
FastWalshTransform_SOURCES = Histogram256/FastWalshTransform.cu.cpp \
	FastWalshTransform/fastWalshTransform_gold.cpp
FastWalshTransform_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la \
	libtrace.la libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) \
	$(BOOST_LIBS)
FastWalshTransform_LDFLAGS = -static
################################################################################

################################################################################
## Histogram256
Histogram256_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall \
	-std=c++0x $(SDK_CFLAGS)
Histogram256_SOURCES = Histogram256/Histogram256_SM10.cu.cpp \
	Histogram256/Histogram256_SM11.cu.cpp \
	Histogram256/Histogram256_SM12.cu.cpp \
	Histogram256/histogram256_gold.cpp \
	Histogram256/histogram256.cpp
Histogram256_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
Histogram256_LDFLAGS = -static
################################################################################

################################################################################
## Histogram64
Histogram64_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x
Histogram64_SOURCES = Histogram64/Histogram64.cu.cpp \
	Histogram64/histogram64_gold.cpp
Histogram64_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
Histogram64_LDFLAGS = -static
################################################################################

################################################################################
## ImageDenoising
ImageDenoising_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall \
	-std=c++0x $(SDK_CFLAGS)
ImageDenoising_SOURCES = ImageDenoising/ImageDenoising.cu.cpp \
	ImageDenoising/bmploader.cpp \
	ImageDenoising/imageDenoisingGL.cpp
ImageDenoising_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
ImageDenoising_LDFLAGS = -static
################################################################################

################################################################################
## Mandelbrot
Mandelbrot_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x $(SDK_CFLAGS)
Mandelbrot_SOURCES = Mandelbrot/Mandelbrot_sm10.cu.cpp \
	Mandelbrot/Mandelbrot_sm13.cu.cpp \
	Mandelbrot/Mandelbrot.cpp \
	Mandelbrot/Mandelbrot_gold.cpp
Mandelbrot_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
Mandelbrot_LDFLAGS = -static
################################################################################

################################################################################
## MatrixMul
MatrixMul_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x
MatrixMul_SOURCES = MatrixMul/MatrixMul.cu.cpp \
	MatrixMul/matrixMul_gold.cpp
MatrixMul_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
MatrixMul_LDFLAGS = -static
################################################################################

################################################################################
## MersenneTwister
MersenneTwister_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x
MersenneTwister_SOURCES = MonteCarlo/MersenneTwister.cu.cpp \
	MersenneTwister/MersenneTwister_gold.cpp \
	MersenneTwister/genmtrand.c 
MersenneTwister_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
MersenneTwister_LDFLAGS = -static
################################################################################

################################################################################
## MonteCarlo
MonteCarlo_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x $(SDK_CFLAGS)
MonteCarlo_SOURCES = MonteCarlo/MonteCarlo_SM13.cu.cpp \
	MonteCarlo/MonteCarlo_SM10.cu.cpp \
	MonteCarlo/MonteCarlo_gold.cpp \
	MonteCarlo/MonteCarlo.cpp
MonteCarlo_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
MonteCarlo_LDFLAGS = -static
################################################################################

################################################################################
## MonteCarloMultiGPU
MonteCarloMultiGPU_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x \
	$(SDK_CFLAGS)
MonteCarloMultiGPU_SOURCES =  \
	MonteCarloMultiGPU/MonteCarloMultiGPU_SM13.cu.cpp \
	 MonteCarloMultiGPU/MonteCarloMultiGPU_SM10.cu.cpp \
	MonteCarlo/MonteCarlo_gold.cpp \
	MonteCarlo/MonteCarlo.cpp
MonteCarloMultiGPU_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la \
	libtrace.la libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) \
	$(BOOST_LIBS)
MonteCarloMultiGPU_LDFLAGS = -static
################################################################################

################################################################################
## Nbody
Nbody_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x $(SDK_CFLAGS)
Nbody_SOURCES = Nbody/Nbodysystemcuda.cu.cpp Nbody/nbody.cpp \
	Nbody/bodysystemcpu.cpp \
	Nbody/bodysystemcuda.cpp \
	Nbody/nbody_gold.cpp \
	Nbody/render_particles.cpp
Nbody_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la libir.la \
	libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
Nbody_LDFLAGS = -static
################################################################################

################################################################################
## OceanFFT
OceanFFT_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x $(SDK_CFLAGS)
OceanFFT_SOURCES = OceanFFT/OceanFFT_kernel.cu.cpp \
	OceanFFT/oceanFFT.cpp
OceanFFT_LDADD = $(SDK_LIBS) $(LIBRT) $(GL_LIBS) $(CUFFT_LIBS) \
	libcudart.la libexecutive.la libtrace.la libir.la libparser.la libhydrazine.la\
	$(BOOST_LIBS)
################################################################################

################################################################################
## Particles
Particles_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x $(SDK_CFLAGS)
Particles_SOURCES = Particles/ParticleSystem.cu.cpp \
	Particles/particles.cpp \
	Particles/particleSystem.cpp \
	Particles/render_particles.cpp \
	Particles/shaders.cpp
Particles_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
Particles_LDFLAGS = -static
################################################################################

################################################################################
## PostProcessGL
PostProcessGL_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x $(SDK_CFLAGS)
PostProcessGL_SOURCES = PostProcessGL/PostProcessGL.cu.cpp \
	PostProcessGL/main.cpp
PostProcessGL_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
PostProcessGL_LDFLAGS = -static
################################################################################

################################################################################
## QuasirandomGenerator
QuasirandomGenerator_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x \
	$(SDK_CFLAGS)
QuasirandomGenerator_SOURCES = \
	QuasirandomGenerator/QuasirandomGenerator_SM13.cu.cpp \
	QuasirandomGenerator/QuasirandomGenerator_SM10.cu.cpp \
	QuasirandomGenerator/quasirandomGenerator_gold.cpp \
	QuasirandomGenerator/quasirandomGenerator.cpp
QuasirandomGenerator_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la \
	libtrace.la libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) \
	$(BOOST_LIBS)
QuasirandomGenerator_LDFLAGS = -static
################################################################################

################################################################################
## RecursiveGaussian
RecursiveGaussian_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x \
	$(SDK_CFLAGS)
RecursiveGaussian_SOURCES = RecursiveGaussian/RecursiveGaussian.cu.cpp
RecursiveGaussian_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la \
	libtrace.la libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) \
	$(BOOST_LIBS)
RecursiveGaussian_LDFLAGS = -static
################################################################################

################################################################################
## Reduction
Reduction_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x $(SDK_CFLAGS)
Reduction_SOURCES = Reduction/Reduction_kernel_SM13.cu.cpp \
	Reduction/Reduction_kernel_SM10.cu.cpp \
	Reduction/Reduction.cu.cpp
Reduction_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
Reduction_LDFLAGS = -static
################################################################################

################################################################################
## ScalarProd
ScalarProd_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x
ScalarProd_SOURCES = ScalarProd/ScalarProd.cu.cpp \
	ScalarProd/scalarProd_gold.cpp
ScalarProd_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
ScalarProd_LDFLAGS = -static
################################################################################

################################################################################
## Scan
Scan_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x
Scan_SOURCES = Scan/Scan.cu.cpp \
	Scan/scan_gold.cpp
Scan_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
Scan_LDFLAGS = -static
################################################################################

################################################################################
## ScanLargeArray
ScanLargeArray_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x
ScanLargeArray_SOURCES = ScanLargeArray/ScanLargeArray.cu.cpp \
	ScanLargeArray/scan_gold.cpp
ScanLargeArray_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
ScanLargeArray_LDFLAGS = -static
################################################################################

################################################################################
## SimpleAtomicIntrinsics
SimpleAtomicIntrinsics_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x
SimpleAtomicIntrinsics_SOURCES = \
	SimpleAtomicIntrinsics/SimpleAtomicIntrinsics.cu.cpp \
	SimpleAtomicIntrinsics/simpleAtomicIntrinsics_gold.cpp
SimpleAtomicIntrinsics_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la \
	libtrace.la libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) \
	$(BOOST_LIBS)
SimpleAtomicIntrinsics_LDFLAGS = -static
################################################################################

################################################################################
## SimpleCUBLAS
SimpleCUBLAS_CFLAGS = -I source $(CUDA_CFLAGS) -Wall
SimpleCUBLAS_SOURCES = SimpleCUBLAS/simpleCUBLAS.c
SimpleCUBLAS_LDADD = $(SDK_LIBS) $(CUBLAS_LIBS) libcudart.la libexecutive.la \
	libtrace.la libir.la libparser.la libhydrazine.la $(LIBRT) $(BOOST_LIBS) \
	$(GL_LIBS)
################################################################################

################################################################################
## SimpleCUFFT
SimpleCUFFT_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x
SimpleCUFFT_SOURCES = SimpleCUFFT/SimpleCUFFT.cu.cpp
SimpleCUFFT_LDADD = $(SDK_LIBS) $(GL_LIBS) $(CUFFT_LIBS) $(LIBRT) libcudart.la \
	libexecutive.la libtrace.la libir.la libparser.la libhydrazine.la \
	$(BOOST_LIBS)
################################################################################

################################################################################
## SimpleCUFFT
SimplerFFT_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x
SimplerFFT_SOURCES = SimpleCUFFT/SimplerFFT.cu.cpp
SimplerFFT_LDADD = $(SDK_LIBS) $(LIBRT) $(CUFFT_LIBS) libcudart.la \
	libexecutive.la libtrace.la libir.la libparser.la libhydrazine.la $(GL_LIBS) \
	$(BOOST_LIBS)
################################################################################

################################################################################
## SimpleGL
SimpleGL_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x $(SDK_CFLAGS)
SimpleGL_SOURCES = SimpleGL/SimpleGL_kernel.cu.cpp SimpleGL/simpleGL.cpp
SimpleGL_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la libir.la \
	libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
SimpleGL_LDFLAGS = -static
################################################################################

################################################################################
## SimpleMultiGPU
SimpleMultiGPU_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x \
	$(SDK_CFLAGS)
SimpleMultiGPU_SOURCES = SimpleMultiGPU/SimpleMultiGPU.cu.cpp \
	SimpleMultiGPU/simpleMultiGPU.cpp
SimpleMultiGPU_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
SimpleMultiGPU_LDFLAGS = -static
################################################################################

################################################################################
## SimpleStreams
SimpleStreams_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x $(SDK_CFLAGS)
SimpleStreams_SOURCES = SimpleStreams/SimpleStreams.cu.cpp
SimpleStreams_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
SimpleStreams_LDFLAGS = -static
################################################################################

################################################################################
## SimpleTemplates
SimpleTemplates_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x \
	$(SDK_CFLAGS)
SimpleTemplates_SOURCES = SimpleTemplates/SimpleTemplates.cu.cpp
SimpleTemplates_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
SimpleTemplates_LDFLAGS = -static
################################################################################

################################################################################
## SimpleTexture
SimpleTexture_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x $(SDK_CFLAGS)
SimpleTexture_SOURCES = SimpleTexture/SimpleTexture.cu.cpp
SimpleTexture_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
SimpleTexture_LDFLAGS = -static
###############################################################################

################################################################################
## SimpleTexture3D
SimpleTexture3D_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x \
	$(SDK_CFLAGS)
SimpleTexture3D_SOURCES = SimpleTexture3D/SimpleTexture3D.cu.cpp
SimpleTexture3D_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
SimpleTexture3D_LDFLAGS = -static
################################################################################

################################################################################
## SimpleVoteIntrinsics
SimpleVoteIntrinsics_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x \
	$(SDK_CFLAGS)
SimpleVoteIntrinsics_SOURCES = SimpleVoteIntrinsics/SimpleVoteIntrinsics.cu.cpp
SimpleVoteIntrinsics_LDADD = $(SDK_LIBS) libcudart.la \
	libexecutive.la libtrace.la libir.la libparser.la libhydrazine.la $(LIBRT) \
	$(GL_LIBS) $(BOOST_LIBS)	
SimpleVoteIntrinsics_LDFLAGS = -static
################################################################################

################################################################################
## SobelFilter
SobelFilter_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x \
	$(SDK_CFLAGS)
SobelFilter_SOURCES = SobelFilter/SobelFilter.cu.cpp \
	SobelFilter/SobelFilter.cpp
SobelFilter_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
SobelFilter_LDFLAGS = -static
################################################################################

################################################################################
## Template
Template_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x \
	$(SDK_CFLAGS)
Template_SOURCES = Template/Template.cu.cpp \
	Template/template_gold.cpp
Template_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
Template_LDFLAGS = -static
################################################################################

################################################################################
## Transpose
Transpose_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x \
	$(SDK_CFLAGS)
Transpose_SOURCES = Transpose/Transpose.cu.cpp \
	Transpose/transpose_gold.cpp
Transpose_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
Transpose_LDFLAGS = -static
################################################################################

################################################################################
## VolumeRender
VolumeRender_CXXFLAGS = -I source $(CUDA_CFLAGS) -Wall -std=c++0x \
	$(SDK_CFLAGS)
VolumeRender_SOURCES = VolumeRender/VolumeRender.cu.cpp
VolumeRender_LDADD = $(SDK_LIBS) libcudart.la libexecutive.la libtrace.la \
	libir.la libparser.la libhydrazine.la $(LIBRT) $(GL_LIBS) $(BOOST_LIBS)
VolumeRender_LDFLAGS = -static
################################################################################

################################################################################
## Headers
nobase_include_HEADERS = 

################################################################################

################################################################################
## Regression tests
sdkTest : tests/regression/sdkRegression.log

tests/regression/sdkRegression.log : sdk
	@echo
	@echo "Running CUDA SDK regression test"
	@python hydrazine/python/RunRegression.py \
		-t regression/sdkRegressionTests.txt \
		-l regression/sdkRegression.log -v

test : sdkTest

################################################################################


