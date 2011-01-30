#ifndef _MUMMERGPU_KERNEL_H_
#define _MUMMERGPU_KERNEL_H_

#include <stdio.h>
#include <common.cu>

#ifdef  n__DEVICE_EMULATION__

#define XPRINTF(...)  printf(__VA_ARGS__)
#define VERBOSE 0
#else
#define XPRINTF(...)  do{}while(0)
#define VERBOSE 0
#endif

#define WARP_SIZE 16

#if REORDER_TREE            
#define fNID "%d,%d"
#define NID(addr) (addr & 0x0000FFFF), ((addr & 0xFFFF0000)>>16)
#define GOROOT(addr) addr = 0x00010000
//#define GOROOT(addr) addr.x = 0; addr.y = 1
#else
#define fNID "%d"
#define NID(addr) addr
#define GOROOT(addr) addr = 1
#endif

#if COALESCED_QUERIES
#define GETQCHAR(qrypos) ((queries[((qrypos) >> 2) << 4]) & ((0xFF) << (((qrypos) & 0x00000003)) << 3)) >> ((((qrypos) & 0x00000003 )) << 3)
#elif QRYTEX
#define GETQCHAR(qrypos) tex1Dfetch(qrytex, qryAddr + qrypos)
#else
#define GETQCHAR(qrypos) queries[qrypos]
#endif

#if COALESCED_QUERIES
#define RESULT_SPAN WARP_SIZE
#define MATCH_BASE(match_coords, qryid) (_MatchCoord*)match_coords + coordAddrs[qryid]
#else
#define RESULT_SPAN 1
#define MATCH_BASE(match_coords, qryid) (_MatchCoord*)match_coords + qryAddr - __umul24(qryid, min_match_len + 1)
#endif

#if REFTEX
#define GETRCHAR(refpos) getRef(refpos)
#else
#define GETRCHAR(refpos) getRef(refpos, ref)
#endif



#if MERGETEX

#if TREE_ACCESS_HISTOGRAM

#if NODETEX
#define GETNODE(addr, two_level)         getMerged(addr, two_level, 0, NULL, NULL)
#define GETNODEHIST(addr, two_level)     getMerged(addr, two_level, 0, node_hist, child_hist)
#define GETCHILDREN(addr, two_level)     getMerged(addr, two_level, 1, NULL, NULL)
#define GETCHILDRENHIST(addr, two_level) getMerged(addr, two_level, 1, node_hist, child_hist)
#else
#define GETNODE(addr, two_level)         getMerged(nodes, childrenarr, addr, two_level, 0, NULL, NULL)
#define GETNODEHIST(addr, two_level)     getMerged(nodes, childrenarr, addr, two_level, 0, node_hist, child_hist)
#define GETCHILDREN(addr, two_level)     getMerged(nodes, childrenarr, addr, two_level, 1, NULL, NULL)
#define GETCHILDRENHIST(addr, two_level) getMerged(nodes, childrenarr, addr, two_level, 1, node_hist, child_hist)
#endif

#else
#if NODETEX
#define GETNODE(addr, two_level)         getMerged(addr, two_level, 0)
#define GETNODEHIST(addr, two_level)     getMerged(addr, two_level, 0)
#define GETCHILDREN(addr, two_level)     getMerged(addr, two_level, 1)
#define GETCHILDRENHIST(addr, two_level) getMerged(addr, two_level, 1)
#else
#define GETNODE(addr, two_level)         getMerged(nodes, childrenarr, addr, two_level, 0)
#define GETNODEHIST(addr, two_level)     getMerged(nodes, childrenarr, addr, two_level, 0)
#define GETCHILDREN(addr, two_level)     getMerged(nodes, childrenarr, addr, two_level, 1)
#define GETCHILDRENHIST(addr, two_level) getMerged(nodes, childrenarr, addr, two_level, 1)
#endif
#endif

#else

#if NODETEX
#if TREE_ACCESS_HISTOGRAM
#define GETNODEHIST(addr, two_level)    getNode(addr, two_level, node_hist)
#define GETNODE(addr, two_level)        getNode(addr, two_level, NULL)
#else
#define GETNODEHIST(addr, two_level)    getNode(addr, two_level)
#define GETNODE(addr, two_level)        getNode(addr, two_level)
#endif
#else
#if TREE_ACCESS_HISTOGRAM
#define GETNODEHIST(addr, two_level)    getNode(addr, two_level, nodes, node_hist)
#define GETNODE(addr, two_level)        getNode(addr, two_level, nodes, NULL)
#else
#define GETNODEHIST(addr, two_level)    getNode(addr, two_level, nodes)
#define GETNODE(addr, two_level)        getNode(addr, two_level, nodes)
#endif
#endif

#if CHILDTEX
#if TREE_ACCESS_HISTOGRAM
#define GETCHILDRENHIST(addr, two_level)    getChildren(addr, two_level, child_hist)
#define GETCHILDREN(addr, two_level)        getChildren(addr, two_level, NULL)
#else
#define GETCHILDRENHIST(addr, two_level)    getChildren(addr, two_level)
#define GETCHILDREN(addr, two_level)        getChildren(addr, two_level)
#endif
#else
#if TREE_ACCESS_HISTOGRAM
#define GETCHILDRENHIST(addr, two_level)    getChildren(addr, two_level, childrenarr, child_hist) 
#define GETCHILDREN(addr, two_level)        getChildren(addr, two_level, childrenarr, NULL)
#else
#define GETCHILDRENHIST(addr, two_level)    getChildren(addr, two_level, childrenarr)
#define GETCHILDREN(addr, two_level)        getChildren(addr, two_level, childrenarr)
#endif
#endif

#endif


#if QRYTEX
#define SHIFT_QUERIES(queries, qryAddr) 
#else
#define SHIFT_QUERIES(queries, qryAddr) queries += qryAddr
#endif

#if REORDER_TREE
texture<uint4, 2, cudaReadModeElementType> nodetex;
texture<uint4, 2, cudaReadModeElementType> childrentex;
#else
texture<uint4, 1, cudaReadModeElementType> nodetex;
texture<uint4, 1, cudaReadModeElementType> childrentex;
#endif


#if REORDER_REF
texture<char, 2, cudaReadModeElementType> reftex;
#else
texture<char, 1, cudaReadModeElementType> reftex;
#endif

texture<char, 1, cudaReadModeElementType> qrytex;

 struct __align__(8) _MatchCoord
 {
 	union
	{
 		int2 data;
 		struct
		{
 			int node;               // match node
     		int edge_match_length;  // number of matching characters UP the parent edge
 		};
 	};
};

// If leafchar is 0, store the ACGT$ links, else store the leafid
struct _PixelOfChildren
{
  union
  {
    uint4 data;

    union
    {
      struct
      {
        uchar3 a;
        uchar3 c;
        uchar3 g;
        uchar3 t;
        uchar3 d;

        char leafchar;
      };
      
      struct
      {
        uchar3 leafid;
        unsigned char pad [12];
        char leafchar0;
      };
    };
  };
};

// Store the start, end coordinate of node, and the parent, suffix links
struct _PixelOfNode
{
  union
  {
    uint4 data;
    struct
    {
      uchar3 parent;
      uchar3 suffix;

      uchar3 start;
      uchar3 end;
      uchar3 depth;

      unsigned char pad;
    };
  };
};

#if TWO_LEVEL_CHILD_TREE
#define CHILD_THRESH 128
__constant__ _PixelOfChildren child_tree_top[CHILD_THRESH];
#endif

#if TWO_LEVEL_NODE_TREE
#define NODE_THRESH 128
__constant__ _PixelOfNode node_tree_top[NODE_THRESH];
#endif


////////////////////////////////////////////////////////////////////


//////////////////////////////////
/// addr2id
//////////////////////////////////

__device__ int addr2id(unsigned int addr)
{
#if MERGETEX & REORDER_TREE
	addr |= (((addr & 0x800) << 1) << 16);
	addr &= 0xFFFF07FF;
    
	int blocky = (addr >> 16) & 0x1F;
	
    int bigy = (addr >> 16) >> 5;
    int bigx = ((addr & 0x0000FFFF) << 5) + blocky;
    return bigx + (bigy << 16);
    
#elif REORDER_TREE
    int blocky = (addr >> 16) & 0x1F;
    int bigy   = (addr >> 16) >> 5;
    int bigx   = ((addr & 0x0000FFFF) << 5) + blocky;
    return bigx + (bigy << 17);
    
#elif MERGETEX
    return addr;
    
#else
    return addr;
#endif
}

 __device__ TextureAddress id2addr(int id)
 {
     TextureAddress retval;
 
 #if MERGETEX & REORDER_TREE
     // Half width is 2048 => 11 bits
     // TEXBLOCKSIZE is 32 => 5 bits
     int bigx = id & 0xFFFF; // 11 + 5 bits
    int bigy = id >> 16;
 
     retval.y = (bigy << 5) + (bigx & 0x1F);
     retval.x = bigx >> 5;
 
     // now stuff y's 13th bit into x's 12th bit
 
     retval.x |= (retval.y & 0x1000) >> 1;
     retval.y &= 0xFFF;
 
 #elif REORDER_TREE
     int bigx = id & 0x1FFFF;
     int bigy = id >> 17;
     retval.y = (bigy << 5) + (bigx & 0x1F);
     retval.x = bigx >> 5;
 
 #elif MERGETEX
     retval.x = id;
 #else
     retval.x = id;
 #endif
     return retval;
 }


#define MKI(uc3) (uc3.x | (uc3.y << 8) | (uc3.z << 16))

//////////////////////////////////
/// arrayToAddress
//////////////////////////////////

__device__ void arrayToAddress(uchar3 arr, unsigned int& addr)
{
#if REORDER_TREE
  addr = (arr.x | ((arr.z & 0xF) << 8)) | ((arr.y | ((arr.z & 0xF0) << 4)) << 16); 
#else
  addr = MKI(arr);
#endif
}

//////////////////////////////////
/// getRef
//////////////////////////////////

__device__ char getRef(int refpos
#if !REFTEX
					   ,char* ref
#endif
)
{
#if REORDER_REF
    int bigx = refpos & 0x3FFFF;
    int bigy = refpos >> 18;
    int y = (bigy << 2) + (bigx & 0x3);
    int x = bigx >> 2;
   
	#if REFTEX
		return tex2D(reftex, x, y);
	#else
		return *(ref + 65536 * y + x);
	#endif
#else
	#if REFTEX
		return tex1Dfetch(reftex, refpos);
	#else
		return ref[refpos];
	#endif
#endif	
}

//////////////////////////////////
/// RC
//////////////////////////////////

__device__ char rc(char c)
{
  switch(c)
  {
    case 'A': return 'T';
    case 'C': return 'G';
    case 'G': return 'C';
    case 'T': return 'A';
    case 'q': return '\0';
    default:  return c;
  };
}

//////////////////////////////////
/// getNode
//////////////////////////////////

__device__ uint4 getNode(unsigned int cur, 
                          bool use_two_level
#if !NODETEX
                          , _PixelOfNode* nodes
#endif
#if TREE_ACCESS_HISTOGRAM
                          , int* node_hist
#endif
                         ) 
{
#if TREE_ACCESS_HISTOGRAM
  int id = addr2id(cur);
  if (node_hist) { node_hist[id]++; }
#endif

#if TWO_LEVEL_NODE_TREE
  int id = addr2id(cur);
  if (use_two_level && id < NODE_THRESH) { return node_tree_top[id].data; }
#endif

#if NODETEX
#if REORDER_TREE
  return tex2D(nodetex, cur & 0x0000FFFF, (cur & 0xFFFF0000) >> 16);
#else
  return tex1Dfetch(nodetex, cur);
#endif

#else

#if REORDER_TREE
  return (nodes + (cur & 0x0000FFFF) + (((cur & 0xFFFF0000)>>16) * MAX_TEXTURE_DIMENSION))->data;
#else
  return (nodes + cur)->data;
#endif
#endif
}



//////////////////////////////////
/// getChildren
//////////////////////////////////

__device__ uint4 getChildren(unsigned int cur, 
                              bool use_two_level
#if !CHILDTEX
                          , _PixelOfChildren* childrenarr
#endif
#if TREE_ACCESS_HISTOGRAM
                          , int* child_hist
#endif
                          )
{
#if TREE_ACCESS_HISTOGRAM
  int id = addr2id(cur);
  if (child_hist) { child_hist[id]++; }
#endif

#if TWO_LEVEL_CHILD_TREE
  int id = addr2id(cur);
  if (id < CHILD_THRESH) { return child_tree_top[id].data; }
#endif

#if CHILDTEX
#if REORDER_TREE
  return tex2D(childrentex, cur & 0x0000FFFF, (cur & 0xFFFF0000) >> 16);
#else
  return tex1Dfetch(childrentex, cur);
#endif
#else
#if REORDER_TREE
  return (childrenarr +  (cur & 0x0000FFFF) + (((cur & 0xFFFF0000)>>16) * MAX_TEXTURE_DIMENSION))->data;
#else
  return (childrenarr + cur)->data;
#endif
#endif
}

#if MERGETEX

//////////////////////////////////
/// getMerged
//////////////////////////////////

__device__ uint4 getMerged(
#if !NODETEX
                            _PixelOfNode * nodes,
                            _PixelOfChildren * childrenarr,
#endif
                            unsigned int cur, 
                            int  use_two_level,
                            int   getChildrenData
#if TREE_ACCESS_HISTOGRAM
                          , int* node_hist
                          , int* child_hist
#endif
                            )
{
//	TextureAddress cur = _cur;
#if !REORDER_TREE
  //cur.x *= 2;
	unsigned int x = cur * 2;
  int useChildrenForData = 0;

  if (x >= MAX_TEXTURE_DIMENSION*MAX_TEXTURE_DIMENSION)
  {
    x -= MAX_TEXTURE_DIMENSION*MAX_TEXTURE_DIMENSION;
    useChildrenForData = 1;
  }

#else
	unsigned short x = cur & 0x0000FFFF;
	unsigned short y = (cur & 0xFFFF0000) >> 16;
  int useChildrenForData = 0; 

  // WARNING INSANE HACK TO WORK AROUND NVCC BUG

  goto TEST;
  MASK:

  x &= 0x7FF;
  x *= 2;

  goto INC;
  TEST:

  if (x >= 2048)
  {
    useChildrenForData = 1;
  }

  goto MASK;
  INC:

#endif

  x += getChildrenData;

#if !REORDER_TREE
	cur = x;
#else
	cur = (y << 16) | x;
#endif

	  if (useChildrenForData)
	  {
	    return getChildren(cur, use_two_level
	#if !CHILDTEX
	                       , childrenarr
	#endif

	#if TREE_ACCESS_HISTOGRAM
	                       , child_hist
	#endif
	                       );
	  }
	  else
	  {
	    return getNode(cur, use_two_level
	#if !NODETEX
	                   , nodes
	#endif

	#if TREE_ACCESS_HISTOGRAM
	                   , node_hist
	#endif
	                   );
	  }
}

#endif




//////////////////////////////////
/// printNode, Emulator only
//////////////////////////////////

#if VERBOSE

#if CHILDTEX && NODETEX
#define PRINTNODE(id)   printNode(id)
#define PRINTNODES(s,e) printNodes(s,e)
#elif CHILDTEX
#define PRINTNODE(id)   printNode(id, nodes)
#define PRINTNODES(s,e) printNodes(s, e, nodes)
#elif NODETEX
#define PRINTNODE(id)   printNode(id, childarr)
#define PRINTNODES(s,e) printNodes(s, e, childrenarr)
#else
#define PRINTNODE(id)   printNode(id, nodes, childrenarr)
#define PRINTNODES(s,e) printNodes(s, e, nodes, childrenarr)
#endif

__device__ void printNode(int nodeid
#if !NODETEX
                          , _PixelOfNode* nodes
#endif
#if !CHILDTEX
                          , _PixelOfChildren* childrenarr
#endif

                          )
{
  TextureAddress addr = id2addr(nodeid);

  _PixelOfNode nd;
  nd.data = GETNODE(addr.data, false);
  
  _PixelOfChildren cd;
  cd.data = GETCHILDREN(addr.data, false);

  unsigned int a; arrayToAddress(cd.a, a);
  unsigned int c; arrayToAddress(cd.c, c);
  unsigned int g; arrayToAddress(cd.g, g);
  unsigned int t; arrayToAddress(cd.t, t);
  unsigned int d; arrayToAddress(cd.d, d);

  unsigned int p; arrayToAddress(nd.parent, p);
  unsigned int s; arrayToAddress(nd.suffix, s);

  int start = MKI(nd.start);
  int end   = MKI(nd.end);
  int depth = MKI(nd.depth);

  char leafchar = cd.leafchar;


  XPRINTF("%d\t"fNID"\t%d\t%d\t%d\t%d\t"fNID"\t"fNID"\t"fNID"\t"fNID"\t"fNID"\t"fNID"\t"fNID"\n",
          nodeid, NID(addr), start, end, depth, leafchar, 
          NID(a), NID(c), NID(g), NID(t), NID(d), NID(p), NID(s));
}


__device__ void printNodes(int start, int end
#if !NODETEX
                , _PixelOfNode * nodes
#endif
#if !CHILDTEX
                ,_PixelOfChildren * childrenarr
#endif
                )
{
  XPRINTF("id\taddr\tstart\tend\tdepth\tleaf\ta\tc\tg\tt\t$\tp\ts\n");

  for (int i = start; i <= end; i++)
  {
    PRINTNODE(i);
  }
}
              

#else // !VERBOSE

#define PRINTNODE(id) 
#define PRINTNODES(s,e)

#endif

#if VERBOSE
#if NODETEX && CHILDTEX
#define SET_RESULT(c, r, e, q, m, rc) set_result(c, r, e, q, m, rc)
#elif NODETEX
#define SET_RESULT(c, r, e, q, m, rc) set_result(c, r, e, q, m, rc, childrenarr)
#elif CHILDTEX
#define SET_RESULT(c, r, e, q, m, rc) set_result(c, r, e, q, m, rc, nodes)
#else
#define SET_RESULT(c, r, e, q, m, rc) set_result(c, r, e, q, m, rc, nodes, childrenarr)
#endif

#else

#define SET_RESULT(c, r, e, q, m, rc) set_result(c, r, e, q, m, rc)

#endif



//////////////////////////////////
/// set_result
//////////////////////////////////

__device__ void set_result(unsigned int cur,
					   _MatchCoord* result, 
					   int edge_match_length,
                       int qry_match_len,
                       int min_match_len,
                       int rc
#if VERBOSE
#if !NODETEX
                       , _PixelOfNode * nodes
#endif
#if !CHILDTEX
                       , _PixelOfChildren * childrenarr
#endif
#endif
                       )
{
  if (qry_match_len > min_match_len)
  {
    edge_match_length |= rc;
	result->data = make_int2(cur, edge_match_length);

#if VERBOSE
    _PixelOfNode nd; nd.data = GETNODE(cur, false);

    XPRINTF("  saving match cur=%d "fNID" len=%d edge_match=%d depth=%d\n",
            result->data.x, NID(cur), qry_match_len, edge_match_length, MKI(nd.depth));

#endif
  }
  else
  {
    XPRINTF("  match too short (%d < %d)\n", qry_match_len, min_match_len);
  }
}



/////////////////////////////////////
// Compute forward substring matches
/////////////////////////////////////

__global__ void
mummergpuKernel(void* match_coords,
#if COALESCED_QUERIES
				int*		coordAddrs,
#endif

#if !QRYTEX
#if COALESCED_QUERIES
                int* queries,
#else 			
				char* queries,
#endif
#endif
                
#if !NODETEX
                _PixelOfNode* nodes,
#endif
                
#if !CHILDTEX
                _PixelOfChildren* childrenarr,
#endif
                
#if !REFTEX
                char* ref,
#endif
                const int* queryAddrs,
                const int* queryLengths,
                const int numQueries,
                const int min_match_len
#if TREE_ACCESS_HISTOGRAM
				,int* node_hist,
				int* child_hist
#endif
) 
{
    int qryid = __umul24(blockIdx.x, blockDim.x) + threadIdx.x;
    if (qryid >= numQueries) { return; }
    XPRINTF("> qryid: %d\n", qryid);

    if (qryid == 0)
    {
      PRINTNODES(0,200);
    }

    int qlen = queryLengths[qryid];
    int qryAddr = queryAddrs[qryid];

    //TextureAddress cur;
	unsigned int cur = 0;
    //cur.data = 0;

    int mustmatch = 0;
    int qry_match_len = 0;
    
    _MatchCoord * result = MATCH_BASE(match_coords, qryid);

    SHIFT_QUERIES(queries, qryAddr);
    
    int last = qlen - min_match_len;
    for (int qrystart = 0;
             qrystart <= last;
             qrystart++, 
             result += RESULT_SPAN) 
    {
		//_PixelOfNode node;
		unsigned int node_start;
        unsigned int prev;

        if ((cur == 0) || (qry_match_len < 1)) 
        {
            // start at root of tree
            GOROOT(cur);
            qry_match_len = 1;
            mustmatch = 0;
        }

        char c = GETQCHAR(qrystart + qry_match_len);

        XPRINTF("In node ("fNID"): starting with %c [%d] =>  \n",
                NID(cur), c, qry_match_len);

        int refpos = 0;
        while ((c != '\0')) 
        {
            XPRINTF("Next edge to follow: %c (%d)\n", c, qry_match_len);
            
			_PixelOfChildren children;
            children.data = GETCHILDRENHIST(cur, false);
			prev = cur;
			uchar3 next;
            switch (c) 
            {
				case 'A': next = children.a; break;
                case 'C': next = children.c; break;
                case 'G': next = children.g; break;
                case 'T': next = children.t; break;
				default: next = make_uchar3(0,0,0); break;
            };
			
			arrayToAddress(next, cur);
				
            XPRINTF(" In node: ("fNID")\n", NID(cur));

            // No edge to follow out of the node
            if (cur == 0) {
                XPRINTF(" no edge\n");
                SET_RESULT(prev, result, 0, qry_match_len, min_match_len, FORWARD);
                           
                qry_match_len -= 1;
                mustmatch = 0;
                
                goto NEXT_SUBSTRING;
            }

			_PixelOfNode node;
			node.data = GETNODEHIST(cur, true);
			node_start = MKI(node.start);
			unsigned int node_end = MKI(node.end);
			
            XPRINTF(" Edge coordinates: %d - %d\n", node_start, node_end);
            {
                int edgelen = node_end - node_start + 1;
                int edge_matchlen = node_start + mustmatch;
                int past_node_end = node_end + 1;
                int dist_to_edge_end = mustmatch - edgelen;
                if (mustmatch) {
                    refpos = min(edge_matchlen, past_node_end);
                    qry_match_len += min(edgelen, mustmatch);
                    mustmatch = max(dist_to_edge_end, 0);
                }
                else {
                    // Try to walk the edge, the first char definitely matches
                    qry_match_len++;
                    refpos = node_start + 1;
                }
            }
            
            c = GETQCHAR(qrystart + qry_match_len);

            while (refpos <= node_end && c != '\0') 
            {
                char r = GETRCHAR(refpos);
                               
                XPRINTF(" Edge cmp ref: %d %c, qry: %d %c\n", refpos, r, qry_match_len, c);
                
                if (r != c) 
                {
                    // mismatch on edge
                    XPRINTF("mismatch on edge: %d, edge_pos: %d\n", qry_match_len, refpos - (node_start));
                    goto RECORD_RESULT;
                }
                
                qry_match_len++;
                refpos++;

                c = GETQCHAR(qrystart + qry_match_len);
            }
        }
        
        XPRINTF("end of string\n");
        
RECORD_RESULT:
		{
			//_PixelOfNode node;
			//node.data = getnodehist(cur, false);
	        SET_RESULT(cur, result, refpos - node_start, qry_match_len,
	                   min_match_len, FORWARD);
                   
	        mustmatch = refpos - node_start;
	        qry_match_len -= mustmatch + 1;
    	}
NEXT_SUBSTRING:
		{
			_PixelOfNode node;
			node.data = GETNODEHIST(prev, false);
	        arrayToAddress(node.suffix, cur);
		}
        //XPRINTF(" following suffix link. mustmatch:%d qry_match_len:%d sl:("fNID")\n",
        //       mustmatch, qry_match_len, NID(cur));
        do {} while (0);
    }

    return;
}

///////////////////////////////////////
//// Compute reverse substring matches
///////////////////////////////////////

__global__ void
mummergpuRCKernel(MatchCoord* match_coords,
               char* queries, 
               const int* queryAddrs,
			   const int* queryLengths,
               const int numQueries,
			   const int min_match_len) 
{
/*
   int qryid = __umul24(blockIdx.x,blockDim.x) + threadIdx.x;
   if (qryid >= numQueries) { return; }

   int qlen = queryLengths[qryid];

   XPRINTF("> rc qryid: %d\n", qryid);

   queries++; // skip the 'q' character


   // start at root for first query character
   TextureAddress cur;

   int mustmatch = 0;
   int qry_match_len = 0;

   int qryAddr=queryAddrs[qryid];
   MatchCoord * result = match_coords + qryAddr - __umul24(qryid, min_match_len + 1);
   queries += qryAddr;

   for (int qrystart = qlen;
       qrystart >= min_match_len ;
       qrystart--, result++)
   {
      #if VERBOSE
      queries[qrystart] = '\0';
	  XPRINTF("qry: ", queries);
      for (int j = qrystart-1; j >= 0; j--)
      { XPRINTF("%c", rc(queries[j])); }
      XPRINTF("\n");
      #endif

	  _PixelOfNode node;
      TextureAddress prev;

      if (((cur.data == 0)) || (qry_match_len < 1))
      {
	    // start at root of tree
	    cur.x = 0; cur.y = 1;
	    qry_match_len = 1; 
        mustmatch = 0;
      }

	  char c = rc(queries[qrystart-qry_match_len]);

	  XPRINTF("In node (%d,%d): starting with %c [%d] =>  \n", cur.x, cur.y, c, qry_match_len);

	  int refpos = 0;
	  while ((c != '\0'))
	  {
		 XPRINTF("Next edge to follow: %c (%d)\n", c, qry_match_len);

	     _PixelOfChildren children;
		 children.data = tex2D(childrentex,cur.x, cur.y);
		 prev = cur;

		 switch(c)
		 {
			case 'A': cur=children.children[0]; break;
			case 'C': cur=children.children[1]; break;
			case 'G': cur=children.children[2]; break;
			case 'T': cur=children.children[3]; break;
            default: cur.data = 0; break;
		 };		 

		 XPRINTF(" In node: (%d,%d)\n", cur.x, cur.y);

		 // No edge to follow out of the node
         if (cur.data == 0)
		 {
			XPRINTF(" no edge\n");

	        SET_RESULT(prev, (_MatchCoord*)result, 0, qry_match_len, min_match_len, 

                       REVERSE);

            qry_match_len -= 1;
            mustmatch = 0;

			goto NEXT_SUBSTRING;
		 }

         {
		   node.data = tex2D(nodetex, cur.data & 0xFFFF, cur.data >> 16);
         }

		 XPRINTF(" Edge coordinates: %d - %d\n", MKI(node.start), MKI(node.end));

         if (mustmatch)
         {
           int edgelen = MKI(node.end) - MKI(node.start)+1;
           if (mustmatch >= edgelen)
           {
             XPRINTF(" mustmatch(%d) >= edgelen(%d), skipping edge\n", mustmatch, edgelen);

             refpos = MKI(node.end)+1;
             qry_match_len += edgelen;
             mustmatch -= edgelen;
           }
           else
           {
             XPRINTF(" mustmatch(%d) < edgelen(%d), skipping to:%d\n", 
                     mustmatch, edgelen, MKI(node.start)+mustmatch);

             qry_match_len += mustmatch;
             refpos = MKI(node.start) + mustmatch;
             mustmatch = 0;
           }
         }
         else
         {
           // Try to walk the edge, the first char definitely matches
           qry_match_len++;
           refpos = MKI(node.start)+1;
         }

		 c = rc(queries[qrystart-qry_match_len]);

		 while (refpos <= MKI(node.end) && c != '\0')
		 { 
            char r = getRef(refpos
#if !REFTEX
							//FIXME: this needs to be a pointer to ref->d_ref_array
							,NULL
#endif
);

			XPRINTF(" Edge cmp ref: %d %c, qry: %d %c\n", refpos, r, qry_match_len, c);
						
			if (r != c)
			{
			   // mismatch on edge
			   XPRINTF("mismatch on edge: %d, edge_pos: %d\n", qry_match_len,refpos - (MKI(node.start)));
               goto RECORD_RESULT;
			}

	        qry_match_len++;
			refpos++;
			c = rc(queries[qrystart-qry_match_len]);
		 }
	  }

	  XPRINTF("end of string\n");

      RECORD_RESULT:
	
      SET_RESULT(cur, (_MatchCoord*)result, refpos - MKI(node.start), qry_match_len, 

                 min_match_len, REVERSE);

      mustmatch = refpos - MKI(node.start);
      qry_match_len -= mustmatch + 1;

      NEXT_SUBSTRING:

      node.data = tex2D(nodetex, prev.x, prev.y);
      cur = node.suffix;

      XPRINTF(" following suffix link. mustmatch:%d qry_match_len:%d sl:(%d,%d)\n", 
              mustmatch, qry_match_len, cur.x, cur.y);

      do {} while(0);
   }
*/	
   return;
}

__global__ void
printKernel(MatchInfo * matches,
            int totalMatches,
            Alignment * alignments,
#if !QRYTEX
#if COALESCED_QUERIES
            int  * queries,
#else
            char * queries,
#endif
#endif

#if !NODETEX
            _PixelOfNode* nodes,
#endif
                
#if !CHILDTEX
            _PixelOfChildren* childrenarr,
#endif
            const int * queryAddrs,
            const int * queryLengths,
            const int page_begin,
            const int page_end,
            const int page_shadow_left,
            const int page_shadow_right,
            const int min_match_length

#if TREE_ACCESS_HISTOGRAM
				,int* node_hist,
				int* child_hist
#endif
            ) 
{
  int matchid = __umul24(blockIdx.x, blockDim.x) + threadIdx.x;
  if (matchid >= totalMatches) { return; }
    
  XPRINTF(">matchid: %d qry: %d\n", matchid, matches[matchid].queryid);

  int qryAddr = queryAddrs[matches[matchid].queryid];

  SHIFT_QUERIES(queries, qryAddr);
  
#if !QRYTEX
  XPRINTF("query: %s\n", queries);
#endif
  
  char queryflankingbase = GETQCHAR(matches[matchid].qrystartpos);
  
  // Find the top node to start printing from
  unsigned int matchaddr = matches[matchid].matchnode.data;
  unsigned int cur = matchaddr;
  unsigned int printParent = cur;
  
  _PixelOfNode node;
  node.data = GETNODE(cur, true);
  
  XPRINTF("starting node: %d "fNID" depth: %d\n", matches[matchid].matchnode, NID(cur), MKI(node.depth));

  while (MKI(node.depth) > min_match_length)
  {
    printParent = cur;
    arrayToAddress(node.parent, cur);
    node.data = GETNODE(cur, true);

    XPRINTF("par: "fNID" depth: %d\n", NID(cur), MKI(node.depth));
  }

  
  // traverse the tree starting at printParent
  unsigned int badParent = cur;
  cur = printParent;
  
  XPRINTF(" printParent: "fNID"\n", NID(printParent));
  
  char curchild = 'A';
  bool forceToParent = false;
  
  node.data = GETNODE(printParent, true);
  
  int matchlen = MKI(node.depth) - 1;
  int depthToGoldenPath = 0;
  
  int matchnum = matches[matchid].resultsoffset;

  // If the printparent is the matchnode, then we are already off the golden path
  if (printParent == matchaddr)
  {
    if (matches[matchid].edgematch > 0)
    {
      node.data = GETNODE(badParent, true);
      matchlen = MKI(node.depth)-1+matches[matchid].edgematch;
    }

    depthToGoldenPath = 1;
  }


  // keep going until I hit the printParent's parent
  while (cur != badParent)
  {
    _PixelOfChildren children;
    children.data = GETCHILDREN(cur, true);
    char isLeaf = children.leafchar;

    XPRINTF(" cur: "fNID" curchild: %c isLeaf:%d forceToParent:%d\n", 
            NID(cur), curchild, isLeaf, forceToParent);

    if (isLeaf || forceToParent)
    {
      // See if I am left maximal and print
      if (isLeaf && isLeaf != queryflankingbase)
      {
        int leafid = MKI(children.leafid);
        int left_in_ref = (leafid - 1) + page_begin; 
        int right_in_ref = left_in_ref + matchlen;

        if ((left_in_ref != page_begin || page_shadow_left == -1) && 
            (right_in_ref != page_end || page_shadow_right == -1))
        {
          if (!(left_in_ref > page_begin && right_in_ref < page_shadow_left))
          {
            //sprintf(buf, "%8d%10d%10d\n", left_in_ref, qrystartpos+1, matchlen);
            XPRINTF("%8d%10d%10d\n", 
                    left_in_ref, 
                    matches[matchid].qrystartpos+1, 
                    matchlen);

            alignments[matchnum].left_in_ref = left_in_ref;
            alignments[matchnum].matchlen = matchlen;
            matchnum++;
          }
        }
      }

      forceToParent = false;
      
      // now return to my parent and advance curchild

      node.data = GETNODE(cur, true);

      unsigned int myParent;
      arrayToAddress(node.parent, myParent);

      _PixelOfChildren pchildren;
      pchildren.data = GETCHILDREN(myParent, true);

      unsigned int pa, pc, pg, pt;
      arrayToAddress(pchildren.a, pa);
      arrayToAddress(pchildren.c, pc);
      arrayToAddress(pchildren.g, pg);
      arrayToAddress(pchildren.t, pt);

      if      (pa == cur) { curchild = 'C'; }
      else if (pc == cur) { curchild = 'G'; }
      else if (pg == cur) { curchild = 'T'; }
      else if (pt == cur) { curchild = '$'; }
      else  // I must be the $ child, go up a level
      {
        forceToParent = true;
      }

      cur = myParent;

      if (depthToGoldenPath) { depthToGoldenPath--; }

      if (depthToGoldenPath == 0)
      {
        node.data = GETNODE(cur, true);
        matchlen = MKI(node.depth)-1;
      }
    }
    else
    {
      // try to walk down the tree
      _PixelOfChildren children;
      children.data = GETCHILDREN(cur, true);

      char goldenChild = 0;

      if (depthToGoldenPath == 0)
      {
        // we are currently on the golden path
        // one of the children is also on the golden path
        goldenChild = GETQCHAR(matches[matchid].qrystartpos+matchlen+1);
      }

      do
      {
        if (curchild == 'A')
        {
          if (children.a.x || children.a.y || children.a.z)
          { 
            XPRINTF("  -> A\n"); 
            arrayToAddress(children.a, cur);
            break; 
          }

          curchild = 'C';
        }

        if (curchild == 'C')
        {
          if (children.c.x || children.c.y || children.c.z)
          { 
            XPRINTF("  -> C\n"); 
            arrayToAddress(children.c, cur); 
            break; 
          }
          curchild = 'G';
        }

        if (curchild == 'G')
        {
          if (children.g.x || children.g.y || children.g.z)
          { 
            XPRINTF("  -> G\n"); 
            arrayToAddress(children.g, cur); 
            break; 
          }
          curchild = 'T';
        }

        if (curchild == 'T')
        {
          if (children.t.x || children.t.y || children.t.z)
          { 
            XPRINTF("  -> T\n"); 
            arrayToAddress(children.t, cur); 
            break; 
          }
          curchild = '$';
        }

        if (curchild == '$')
        {
          if (children.d.x || children.d.y || children.d.z)
          { 
            XPRINTF("  -> $\n"); 
            arrayToAddress(children.d, cur); 
            break; 
          }
        }

        // checked all of the children, go back to parent
        forceToParent = true;
      } 
      while (0);

      if (!forceToParent)
      {
        if (depthToGoldenPath == 0)
        {
          if (curchild == goldenChild)
          {
            node.data = GETNODE(cur, true);
            matchlen = MKI(node.depth)-1;

            if (cur == matchaddr)
            {
              // we overextended the golden path
              depthToGoldenPath = 1;

              if (matches[matchid].edgematch > 0)
              {
				unsigned int par;
                arrayToAddress(node.parent, par);

                node.data = GETNODE(par, true);
                matchlen = MKI(node.depth) - 1 + matches[matchid].edgematch;
              }
            }
          }
          else
          {
            depthToGoldenPath = 1;
          }
        }
        else
        {
          depthToGoldenPath++;
        }
          
        curchild = 'A';
      }
    }
  }
}
  
#endif // #ifndef _MUMMERGPU_HH_
