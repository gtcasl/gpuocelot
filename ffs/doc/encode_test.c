#include <fcntl.h>
#include <stdlib.h>
#include "io.h"

typedef struct _dyn_rec {
    char	*string;
    long	icount;
    double	*double_array;
} dyn_rec, *dyn_rec_ptr;

IOField dyn_field_list[] = {
    {"string field", "string", sizeof(char *), 
      IOOffset(dyn_rec_ptr, string)},
    {"icount", "integer", sizeof(long), 
      IOOffset(dyn_rec_ptr, icount)},
    {"double_array", "float[icount]", sizeof(double), 
      IOOffset(dyn_rec_ptr, double_array)},
    { NULL, NULL, 0, 0}
};

void main()
{
    IOContext src_context = create_IOcontext();
    IOFormat dyn_rec_ioformat;
    dyn_rec rec;
    int buf_size, fd, i;
    char *encoded_buffer;
    dyn_rec_ioformat = register_IOcontext_format("dynamic format",
						  dyn_field_list,
						  src_context);
    rec.string = "Hi Mom!";
    rec.icount = 5;
    rec.double_array = (double*) malloc(sizeof(double) * 5);
    for (i=0; i<5; i++) 
	rec.double_array[i] = i*2.717;
    encoded_buffer = encode_IOcontext_buffer(src_context, 
			dyn_rec_ioformat, &rec, &buf_size);

    /* "transmit" encoded record over a file */
    fd = open("enc_file", O_WRONLY|O_CREAT|O_TRUNC, 0777);
    write(fd, encoded_buffer, buf_size);
}
