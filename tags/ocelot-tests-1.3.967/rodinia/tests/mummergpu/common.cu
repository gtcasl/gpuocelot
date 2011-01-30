#ifndef COMMON_CU__
#define COMMON_CU__ 1
typedef unsigned int uint32_t;

// Children are labeled as ACGT$
const int basecount = 5;


// Note: max pixel size is 16 bytes


// COALESCED_QUERIES only works in the forward kernel and is NOT STABLE
// COALESCED_QUERIES and QRYTEX are mutually exclusive
#ifndef QRYTEX
#define QRYTEX 0
#endif

#ifndef COALESCED_QUERIES
#define COALESCED_QUERIES 0
#endif

// Reference parameters
#ifndef REFTEX
#define REFTEX 0
#endif

#ifndef REORDER_REF
#define REORDER_REF 0
#endif

// Tree parameters
#ifndef TREETEX
#define TREETEX 1
#endif

#if !TREETEX
#define NODETEX 0
#define CHILDTEX 0
#else
#define NODETEX 1
#define CHILDTEX 1
#endif

// #ifndef NODETEX
// #define NODETEX 1
// #endif
// 
// #ifndef CHILDTEX
// #define CHILDTEX 1
// #endif

#ifndef MERGETEX
#define MERGETEX 0
#endif

#ifndef REORDER_TREE
#define REORDER_TREE 1
#endif

// Curl up node reordering
#ifndef RENUMBER_TREE
#define RENUMBER_TREE 1
#endif

#if MERGETEX && (CHILDTEX != NODETEX)
#error CHILDTEX must equal NODETEX when using MERGETEX
#endif

#if QRYTEX && COALESCED_QUERIES
#error QRYTEX and COALESCED_QUERIES are mutually exclusive
#endif

// Two level tree means that nodes with nodeid < threshhold (define in the 
// kernel), are accessed through the constant memory, instead of global/tex
// Since the access patterns for PixelOfNode and PixelOfChildren are different
// we provide the option to store one side in a single-level memory hierarchy,
// and the other in a double-level.
#ifndef TWO_LEVEL_NODE_TREE
#define TWO_LEVEL_NODE_TREE 0
#endif

#ifndef TWO_LEVEL_CHILD_TREE
#define TWO_LEVEL_CHILD_TREE 0
#endif


//PARMETERS FROM PAPER:
// #define QRYTEX 0
// #define COALESCED_QUERIES 0
// 
// // Reference parameters
// #define REFTEX 1
// #define REORDER_REF 1
// 
// // Tree parameters
// #define NODETEX 1
// #define CHILDTEX 1
// #define REORDER_TREE 1
// #define MERGETEX 0
// 
// // Two level tree means that nodes with nodeid < threshhold (define in the 
// // kernel), are accessed through the constant memory, instead of global/tex
// // Since the access patterns for PixelOfNode and PixelOfChildren are different
// // we provide the option to store one side in a single-level memory hierarchy,
// // and the other in a double-level.
// #define TWO_LEVEL_NODE_TREE 0
// #define TWO_LEVEL_CHILD_TREE 0


// DO NOT USE in device mode, emulation ONLY
#define TREE_ACCESS_HISTOGRAM 0

// 4 bytes
struct TextureAddress {
    union {
        unsigned int data;
        
        struct {
#if REORDER_TREE
            unsigned short x;  // really just 12 bits
            unsigned short y;  // really just 12 bits
#else
            unsigned int x;
#endif
        };
    };
};

// Store the start, end coordinate of node, and the parent, suffix links
struct PixelOfNode
{
  union
  {
    uint4 data;
    struct
    {
      unsigned char parent[3];
      unsigned char suffix[3];

      unsigned char start [3];
      unsigned char end   [3];
      unsigned char depth [3];

      unsigned char pad;
    };
  };
};

// If leafchar is 0, store the ACGT$ links, else store the leafid
struct PixelOfChildren
{
  union
  {
    uint4 data;

    union
    {
      struct
      {
        unsigned char a[3];
        unsigned char c[3];
        unsigned char g[3];
        unsigned char t[3];
        unsigned char d[3];

        char leafchar;
      };
      
      struct
      {
        unsigned char leafid [3];
        unsigned char pad [12];
        char leafchar0;
      };
    };
  };
};

typedef struct MatchInfo
{
  unsigned int resultsoffset;
  unsigned int queryid;
  TextureAddress matchnode;
  unsigned int numLeaves;
  unsigned short edgematch;
  unsigned short qrystartpos;
} MatchInfo;

typedef struct Alignment
{
  int left_in_ref;
  unsigned short matchlen;
} Alignment;



static const int MAX_TEXTURE_DIMENSION = 4096;
static const int MAX_GRID_DIMENSION = 65535;
static const int MAX_QUERY_LEN = 8192;

#define FORWARD   0x0000
#define REVERSE   0x8000
#define FRMASK    0x8000
#define FRUMASK   0x7FFF
#define MK3(base) (base[0] | (base[1] << 8) | (base[2]) << 16)

#endif
