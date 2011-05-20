noinst_PROGRAMS = cudaRenderer

cudaRenderer_SOURCES = cudarenderer.cu Algebra.cpp Camera.cpp Keyboard.cpp main.cpp 3d.h Algebra.h Base3d.h Camera.h Clock.h Keyboard.h Types.h cudarenderer.h Loader.cpp Loader.h Utility.cpp Utility.h BVH.h BVH.cpp

cudaRenderer_CPPFLAGS = @SDL_CFLAGS@ -I$(srcdir)/../lib3ds-1.3.0/

cudaRenderer_LDADD = @SDL_LIBS@ @CUDA_LIBS@ @SYS_GL_LIBS@ ../lib3ds-1.3.0/lib3ds/.libs/lib3ds.a

LINK=$(CC) $(AM_CFLAGS) $(CFLAGS) $(AM_LDFLAGS) $(LDFLAGS) -o $@

cudarenderer.o:	cudarenderer.cu cudarenderer.h Types.h Base3d.h Camera.h
	$(NVCC) -o $@ -c $< @NVCCFLAGS@ @SDL_CFLAGS@ @CUDA_LIBS@ @CUDA_CFLAGS@

.cu.o:
	$(NVCC) -o $@ -c $< @NVCCFLAGS@ @SDL_CFLAGS@ @CUDA_LIBS@ @CUDA_CFLAGS@
