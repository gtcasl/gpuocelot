#define MAGIC_NUMBER 0x4356ffa9	/* random magic */
#define REVERSE_MAGIC_NUMBER 0xa9ff5643		/* byte reversed random
						 * magic */
#define MAGIC_FLOAT 0.0078125	/* random float */

extern FMdata_type str_to_data_type(const char *str);
extern FMdata_type array_str_to_data_type(const char *str, 
						long *element_count_ptr);
extern const char *data_type_to_str(FMdata_type data_type);
extern int field_offset_compar(const void *a, const void *b);
extern void dump_FMFormat(FMFormat ioformat);
extern FMContext new_FMContext();

struct _format_server;

typedef struct _FMContextStruct {
    int ref_count;
    int reg_format_count;
    int byte_reversal;
    int native_pointer_size;
    FMfloat_format native_float_format;
    int native_column_major_arrays;  /* False for C, True for Fortran */
    int errno_val;
    char *result;

    FMContext master_context;
    int self_server;
    void *server_client_data;
    void *server_fd;
    int server_pid;
    int server_byte_reversal;

    int format_list_size;
    FMFormat *format_list;
} FMContextStruct;

typedef struct _format_server *format_server;

typedef struct _FSclient {
    int port;			/* port's port number */
    char *hostname;		/* port's host name */
    char *usock_name;		/* port's unix socket name */
    void *fd;
    int byte_reversal;
    format_server fs;
    int provisional;
    int version;
    long created;
    int input_bytes;
    int output_bytes;
    int formats_registered;
    int formats_fetched;
    unsigned char *key;
    int key_len;
} *FSClient;

#if SIZEOF_INT == 4
#define INT4 int
#endif

#define INT2 short
#define UINT2 unsigned short

struct _field_wire_format {  /* 12 bytes total */
    UINT2 field_name_offset;
    UINT2 field_type_offset;
    INT4 field_size;
    INT4 field_offset;
};

struct _opt_info_wire_format {  /* 12 bytes total */
    INT4 info_type;
    INT4 info_len;
    INT4 info_offset;
};

struct _format_wire_format_0 {
/*byte 0*/    UINT2 format_rep_length;  /* transmitted in net byte order */
/*byte 2*/    unsigned char record_byte_order;
/*byte 3*/    unsigned char server_rep_version;
/*byte 4*/    unsigned char subformat_count;
/*byte 5*/    unsigned char recursive_flag;
/*byte 6*/    unsigned char unused1_in_format_0;
/*byte 7*/    unsigned char unused2_in_format_0;
};

struct _subformat_wire_format_0 {  /* 20 bytes for base */
/*byte 0*/    UINT2 subformat_rep_length;  /* transmitted in net byte order */
/*byte 2*/    unsigned char server_rep_version;
/*byte 3*/    unsigned char record_byte_order;
/*byte 4*/    unsigned char pointer_size;
/*byte 5*/    unsigned char header_size;
/*byte 6*/    UINT2 name_offset;	/* native host byte order */
/*byte 8*/    UINT2 field_count;
/*byte 10*/   UINT2 floating_point_rep;
/*byte 12*/   INT4 record_length;
/*byte 16*/   UINT2 opt_info_offset;
/*byte 18*/   unsigned char column_major_arrays;  /* false for C, true for Fortran */
/*byte 19*/   unsigned char alignment;
};

struct _format_wire_format {
    union {
	struct _format_wire_format_0 f0;
    }f;
};

struct _subformat_wire_format {
    union {
	struct _subformat_wire_format_0 f0;
    }f;
};

typedef struct {
    unsigned char version;
    unsigned char salt;
    unsigned INT2 port;
    unsigned INT4 IP_addr;
    unsigned INT2 format_identifier;
} version_1_format_ID;

typedef struct {
    unsigned char version;
    unsigned char unused;
    unsigned INT2 rep_len;
    unsigned INT4 hash1;
    unsigned INT4 hash2;
} version_2_format_ID;

#define DEFAULT_FS_PORT 5347

#if SIZEOF_LONG_DOUBLE != 0 && SIZEOF_LONG_DOUBLE != SIZEOF_DOUBLE
#define MAX_FLOAT_TYPE long double
#else
#define MAX_FLOAT_TYPE double
#define MAX_FLOAT_GET get_FMdouble
#endif
#if SIZEOF_LONG_LONG != 0
#define MAX_INTEGER_TYPE long long
#else
#define MAX_INTEGER_TYPE long
#endif

#define MAX_UNSIGNED_TYPE unsigned MAX_INTEGER_TYPE

extern FMfloat_format ffs_reverse_float_formats[];
extern char *base_data_type(const char *str);
extern char *get_FMstring_base(FMFieldPtr iofield, void *data, void *string_base);
extern void *get_FMaddr (FMFieldPtr iofield, void *data, void *string_base, int encode);
extern FMFieldPtr get_FMfieldPtrFromList(FMFieldList field_list, 
					 const char *fieldname);

typedef int (*IOinterface_func)(void *conn, void *buffer, int length,
				      int *errno_p, char **result_p);

typedef int (*IOinterface_close)(void *conn);

typedef int (*IOinterface_poll)(void *conn);

typedef void *(*IOinterface_open)(const char *path,
					const char *flag_str, 
					int *input, int *output);
typedef void (*IOinterface_init)(void );

extern IOinterface_func os_file_read_func;
extern IOinterface_func os_file_write_func;

extern IOinterface_func os_read_func;
extern IOinterface_func os_write_func;
extern int os_max_iov;
extern IOinterface_close os_close_func;
extern IOinterface_poll os_poll_func;
extern IOinterface_open os_file_open_func;
extern IOinterface_func os_server_read_func;
extern IOinterface_func os_server_write_func;
extern IOinterface_init os_sockets_init_func;

extern int version_of_format_ID(void *server_ID);
extern int FFS_gen_authentication (unsigned char *outbuf);
extern int serverAtomicRead(void *fd, void *buffer, int length);
extern void stringify_server_ID(unsigned char *ID, char *buffer, int len);
extern void 
generate_format2_server_ID(server_ID_type *server_ID,
			   struct _format_wire_format_0 *server_format_rep);
extern void server_read_header(FSClient fsc);
extern void
add_format_to_iofile(FMContext fmc, FMFormat ioformat, int id_size, 
		     void *id_buffer, int index);
typedef enum {
    local_only, never_local, host_only, host_and_fallback
} action_t;

extern int establish_server_connection(FMContext iofile, action_t action);
extern void general_format_server(int port, int do_restart, int verbose, int do_proxy);
extern void dump_FMFormat(FMFormat ioformat);
extern int format_server_restarted(FMContext context);
extern int FMhas_XML_info(FMFormat format);
