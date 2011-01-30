#include <stdio.h>
#include <string.h>

#include <fstream>

#define ulong4 uint32_t
#define int2 int32_t
#define uint4 uint32_t

#include "omp.h"
#include "mummergpu.h"
// Matches are reported as a node in the suffix tree,
// plus a distance up the node's parent link for partial
// matches on the patch from the root to the node

#define OMP
#define N_THREADS 4


static const int maxdim = 4096;

#define __VERBOSE___no 

#ifdef __VERBOSE__
#define XPRINTF(...)  printf(__VA_ARGS__)
#else
#define XPRINTF(...)  do{}while(0)
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


#define GETQCHAR(qrypos) queries[qrypos]
#define RESULT_SPAN 1
#define MATCH_BASE(match_coords, qryid) (MatchCoord*)match_coords + qryAddr - (qryid * (min_match_len + 1))

#define GETRCHAR(refpos) getRef(refpos, ref)



#if MERGETEX

#if TREE_ACCESS_HISTOGRAM
#define GETNODE(addr, two_level)         getMerged(nodes, childrenarr, addr,  0, NULL, NULL).node
#define GETNODEHIST(addr, two_level)     getMerged(nodes, childrenarr, addr,  0, node_hist, child_hist).node
#define GETCHILDREN(addr, two_level)     getMerged(nodes, childrenarr, addr,  1, NULL, NULL).children
#define GETCHILDRENHIST(addr, two_level) getMerged(nodes, childrenarr, addr,  1, node_hist, child_hist).children
#else
#define GETNODE(addr, two_level)         getMerged(nodes, childrenarr, addr,  0).node
#define GETNODEHIST(addr, two_level)     getMerged(nodes, childrenarr, addr,  0).node
#define GETCHILDREN(addr, two_level)     getMerged(nodes, childrenarr, addr,  1).children
#define GETCHILDRENHIST(addr, two_level) getMerged(nodes, childrenarr, addr,  1).children
#endif

#else

#if TREE_ACCESS_HISTOGRAM
#define GETNODEHIST(addr, two_level)    getNode(addr,  nodes, node_hist)
#define GETNODE(addr, two_level)        getNode(addr,  nodes, NULL)
#else
#define GETNODEHIST(addr, two_level)    getNode(addr,  nodes)
#define GETNODE(addr, two_level)        getNode(addr,  nodes)
#endif


#if TREE_ACCESS_HISTOGRAM
#define GETCHILDRENHIST(addr, two_level)    getChildren(addr,  childrenarr, child_hist) 
#define GETCHILDREN(addr, two_level)        getChildren(addr,  childrenarr, NULL)
#else
#define GETCHILDRENHIST(addr, two_level)    getChildren(addr,  childrenarr)
#define GETCHILDREN(addr, two_level)        getChildren(addr,  childrenarr)
#endif

#endif

#define SHIFT_QUERIES(queries, qryAddr) queries += qryAddr
#define SET_RESULT(c, r, e, q, m, rc) set_result(c, r, e, q, m, rc)
//////////////////////////////////
/// getRef
//////////////////////////////////

char getRef(int refpos, char* ref)
{
	return ref[refpos];
}


union SingleNode
{
	PixelOfNode node;
	PixelOfChildren children;
};


//////////////////////////////////
/// getNode
//////////////////////////////////

PixelOfNode getNode(unsigned int cur,  PixelOfNode* nodes
#if TREE_ACCESS_HISTOGRAM
               , int* node_hist
#endif
               ) 
{
#if TREE_ACCESS_HISTOGRAM
  int id = addr2id(cur);
  if (node_hist) { node_hist[id]++; }
#endif

#if REORDER_TREE
  return *(nodes + (cur & 0x0000FFFF) + (((cur & 0xFFFF0000)>>16) * MAX_TEXTURE_DIMENSION));
#else
  return *(nodes + cur);
#endif
}

//////////////////////////////////
/// getChildren
//////////////////////////////////

PixelOfChildren getChildren(unsigned int cur, PixelOfChildren* childrenarr
#if TREE_ACCESS_HISTOGRAM
                   , int* child_hist
#endif
                   )
{
#if TREE_ACCESS_HISTOGRAM
  int id = addr2id(cur);
  if (child_hist) { child_hist[id]++; }
#endif

#if REORDER_TREE
  return *(childrenarr +  (cur & 0x0000FFFF) + (((cur & 0xFFFF0000)>>16) * MAX_TEXTURE_DIMENSION));
#else
  return *(childrenarr + cur);
#endif
}

#if MERGETEX

//////////////////////////////////
/// getMerged
//////////////////////////////////

SingleNode getMerged(PixelOfNode * nodes,
                 PixelOfChildren * childrenarr,
                 unsigned int cur, 
                 int   getChildrenData
#if TREE_ACCESS_HISTOGRAM
               , int* node_hist
               , int* child_hist
#endif
                            )
{
	SingleNode n;
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
	    n.children = getChildren(cur, childrenarr
	#if TREE_ACCESS_HISTOGRAM
	                       , child_hist
	#endif
	                       );
	  }
	  else
	  {
	    n.node =  getNode(cur, nodes
	#if TREE_ACCESS_HISTOGRAM
	                   , node_hist
	#endif
	                   );
	  }
	return n;
}

#endif


//////////////////////////////////
/// set_result
//////////////////////////////////

void set_result(unsigned int cur,
					   MatchCoord* result, 
					   int edge_match_length,
                       int qry_match_len,
                       int min_match_len,
                       int rc
                       )
{
  if (qry_match_len > min_match_len)
  {
    edge_match_length |= rc;
	result->node.data = cur;
	result->edge_match_length = edge_match_length;
  }
  else
  {
    XPRINTF("  match too short (%d < %d)\n", qry_match_len, min_match_len);
  }
}

void arrayToAddress(unsigned char arr[3], unsigned int& addr)
{
#if REORDER_TREE
  addr = (arr[0] | ((arr[2] & 0xF) << 8)) | ((arr[1] | ((arr[2] & 0xF0) << 4)) << 16); 
#else
  addr = MK3(arr);
#endif
}

template<typename T>
inline T min(T x, T y)
{
	return x < y ? x : y;
}

template<typename T>
inline T max(T x, T y)
{
	return x < y ? y : x;
}

int kernel_gold(int qryid,
				MatchResults* results, 		
				char* queries,
                PixelOfNode* nodes,
                PixelOfChildren* childrenarr,
                char* ref,
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
	    if (qryid >= numQueries) { return 0; }
	    XPRINTF("> qryid: %d\n", qryid);

	    int qlen = queryLengths[qryid];
	    int qryAddr = queryAddrs[qryid];
 
		unsigned int cur = 0;

	    int mustmatch = 0;
	    int qry_match_len = 0;
		MatchCoord* match_coords = results->h_match_coords;
	    MatchCoord * result = MATCH_BASE(match_coords, qryid);

	    SHIFT_QUERIES(queries, qryAddr);

	    int last = qlen - min_match_len;
	    for (int qrystart = 0;
	             qrystart <= last;
	             qrystart++, 
	             result += RESULT_SPAN) 
	    {
			//PixelOfNode node;
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

	        unsigned int refpos = 0;
	        while ((c != '\0')) 
	        {
	            XPRINTF("Next edge to follow: %c (%d)\n", c, qry_match_len);

				PixelOfChildren children;
	            children = GETCHILDRENHIST(cur, false);
				prev = cur;

				switch (c) 
	            {
					case 'A': arrayToAddress(children.a,cur); break;
	                case 'C': arrayToAddress(children.c,cur); break;
	                case 'G': arrayToAddress(children.g,cur); break;
	                case 'T': arrayToAddress(children.t,cur); break;
					default: cur = 0; break;
	            };

				//arrayToAddress(next, cur);

	            XPRINTF(" In node: ("fNID")\n", NID(cur));

	            // No edge to follow out of the node
	            if (cur == 0) {
	                XPRINTF(" no edge\n");
	                SET_RESULT(prev, result, 0, qry_match_len, min_match_len, FORWARD);

	                qry_match_len -= 1;
	                mustmatch = 0;

	                goto NEXT_SUBSTRING;
	            }

				PixelOfNode node;
				node = GETNODEHIST(cur, true);
				node_start = MK3(node.start);
				unsigned int node_end = MK3(node.end);

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
				//PixelOfNode node;
				//node.data = getnodehist(cur, false);
		        SET_RESULT(cur, result, refpos - node_start, qry_match_len,
		                   min_match_len, FORWARD);

		        mustmatch = refpos - node_start;
		        qry_match_len -= mustmatch + 1;
	    	}
	NEXT_SUBSTRING:
			{
				PixelOfNode node;
				node = GETNODEHIST(prev, false);
		        arrayToAddress(node.suffix, cur);
			}
	        //XPRINTF(" following suffix link. mustmatch:%d qry_match_len:%d sl:("fNID")\n",
	        //       mustmatch, qry_match_len, NID(cur));
	        do {} while (0);
	    }

	    return 0;

#if 0

   XPRINTF("> qryid: %d\n", qryid);

   int qlen = queryLengths[qryid];

   // start at root for first query character
   TextureAddress cur;
   cur.data = 0;
   int mustmatch = 0;
   int qry_match_len = 0;

   int qryAddr=queryAddrs[qryid];
   MatchCoord * result = results->h_match_coords + qryAddr - (qryid * ( min_match_len + 1));
   queries += qryAddr;

   int last = qlen - min_match_len;
   for (int qrystart = 0;
       qrystart <= last;
       qrystart++, result++, queries++)
   {
	  XPRINTF("qry: %s\n", queries + 1);

	  PixelOfNode node;
      TextureAddress prev;

      if ((cur.data == 0) || (qry_match_len < 1))
      {
	    // start at root of tree
	    cur.x = 0; cur.y = 1;
	    qry_match_len = 1; 
        mustmatch = 0;
      }

	  char c = queries[qry_match_len];

	  XPRINTF("In node (%d,%d): starting with %c [%d] =>  \n", cur.x, cur.y, c, qry_match_len);

	  int refpos = 0;
	  while ((c != '\0'))
	  {
		 XPRINTF("Next edge to follow: %c (%d)\n", c, qry_match_len);

	     PixelOfChildren children;
		 children = *(childrenTexture +  (cur.x) + ((cur.y) * maxdim));
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
	        set_result(prev, result, 0, qry_match_len, min_match_len, FORWARD);

            qry_match_len -= 1;
            mustmatch = 0;

			goto NEXT_SUBSTRING;
		 }

         {
           unsigned short xval = cur.data & 0xFFFF;
           unsigned short yval = (cur.data & 0xFFFF0000) >> 16;
		   node = *(nodeTexture +  (xval) + (yval * maxdim));
         }

		 XPRINTF(" Edge coordinates: %d - %d\n", node.start, node.end);

         if (mustmatch)
         {
           int edgelen = node.end - node.start+1;
           if (mustmatch >= edgelen)
           {
             XPRINTF(" mustmatch(%d) >= edgelen(%d), skipping edge\n", mustmatch, edgelen);

             refpos = node.end+1;
             qry_match_len += edgelen;
             mustmatch -= edgelen;
           }
           else
           {
             XPRINTF(" mustmatch(%d) < edgelen(%d), skipping to:%d\n", 
                     mustmatch, edgelen, node.start+mustmatch);

             qry_match_len += mustmatch;
             refpos = node.start + mustmatch;
             mustmatch = 0;
           }
         }
         else
         {
           // Try to walk the edge, the first char definitely matches
           qry_match_len++;
           refpos = node.start+1;
         }

		 c = queries[qry_match_len];

		 while (refpos <= node.end && c != '\0')
		 { 
            //char r = getRef(refpos);
			char r = refstr[refpos];
			XPRINTF(" Edge cmp ref: %d %c, qry: %d %c\n", refpos, r, qry_match_len, c);
						
			if (r != c)
			{
			   // mismatch on edge
			   XPRINTF("mismatch on edge: %d, edge_pos: %d\n", qry_match_len,refpos - (node.start));
               goto RECORD_RESULT;
			}

	        qry_match_len++;
			refpos++;
			c = queries[qry_match_len];
		 }
	  }

	  XPRINTF("end of string\n");

      RECORD_RESULT:
	
      set_result(cur, result, refpos - node.start, qry_match_len, min_match_len, FORWARD);
      mustmatch = refpos - node.start;
      qry_match_len -= mustmatch + 1;

      NEXT_SUBSTRING:

      //node.data = texfetch(nodetex, prev.x, prev.y);
	  node = *(nodeTexture +  (prev.x) + ((prev.y) * maxdim));
      cur = node.suffix;

      XPRINTF(" following suffix link. mustmatch:%d qry_match_len:%d sl:(%d,%d)\n", 
              mustmatch, qry_match_len, cur.x, cur.y);

      do {} while(0);
   }

#endif
	
   return 0 ;
}



inline char rc(char c)
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

///////////////////////////////////////
//// Compute reverse substring matches
///////////////////////////////////////


void
rc_kernel_gold(int qryid,
			   MatchResults* results,
			   char* refstr,
               char* queries, 
               const int* queryAddrs,
			   const int* queryLengths,
			   PixelOfNode* nodeTexture,
				PixelOfChildren* childrenTexture,
               const int numQueries,
			   const int min_match_len) 
{
   
   if (qryid >= numQueries) { return; }

#if 0

   int qlen = queryLengths[qryid];

   XPRINTF("> rc qryid: %d\n", qryid);

   queries++; // skip the 'q' character


   // start at root for first query character
   TextureAddress cur;

   int mustmatch = 0;
   int qry_match_len = 0;

   int qryAddr=queryAddrs[qryid]; 
   MatchCoord * result = results->h_match_coords + qryAddr - (qryid * ( min_match_len + 1));
   queries += qryAddr;

   for (int qrystart = qlen;
       qrystart >= min_match_len ;
       qrystart--, result++)
   {
      #ifdef VERBOSE
      queries[qrystart] = '\0';
	  XPRINTF("qry: ", queries);
      for (int j = qrystart-1; j >= 0; j--)
      { XPRINTF("%c", rc(queries[j])); }
      XPRINTF("\n");
      #endif

	  PixelOfNode node;
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

	     PixelOfChildren children;
		 children = *(childrenTexture +  (cur.x) + ((cur.y) * maxdim));
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
	        set_result(prev, result, 0, qry_match_len, min_match_len, 
                       REVERSE);

            qry_match_len -= 1;
            mustmatch = 0;

			goto NEXT_SUBSTRING;
		 }

         {
           unsigned short xval = cur.data & 0xFFFF;
           unsigned short yval = (cur.data & 0xFFFF0000) >> 16;
		   node = *(nodeTexture +  (xval) + (yval * maxdim));
         }

		 XPRINTF(" Edge coordinates: %d - %d\n", node.start, node.end);

         if (mustmatch)
         {
           int edgelen = node.end - node.start+1;
           if (mustmatch >= edgelen)
           {
             XPRINTF(" mustmatch(%d) >= edgelen(%d), skipping edge\n", mustmatch, edgelen);

             refpos = node.end+1;
             qry_match_len += edgelen;
             mustmatch -= edgelen;
           }
           else
           {
             XPRINTF(" mustmatch(%d) < edgelen(%d), skipping to:%d\n", 
                     mustmatch, edgelen, node.start+mustmatch);

             qry_match_len += mustmatch;
             refpos = node.start + mustmatch;
             mustmatch = 0;
           }
         }
         else
         {
           // Try to walk the edge, the first char definitely matches
           qry_match_len++;
           refpos = node.start+1;
         }

		 c = rc(queries[qrystart-qry_match_len]);

		 while (refpos <= node.end && c != '\0')
		 { 
            //char r = getRef(refstr, refpos);
			char r = refstr[refpos];
			XPRINTF(" Edge cmp ref: %d %c, qry: %d %c\n", refpos, r, qry_match_len, c);
						
			if (r != c)
			{
			   // mismatch on edge
			   XPRINTF("mismatch on edge: %d, edge_pos: %d\n", qry_match_len,refpos - (node.start));
               goto RECORD_RESULT;
			}

	        qry_match_len++;
			refpos++;
			c = rc(queries[qrystart-qry_match_len]);
		 }
	  }

	  XPRINTF("end of string\n");

      RECORD_RESULT:
	
      set_result(cur, result, refpos - node.start, qry_match_len, 
                 min_match_len, REVERSE);

      mustmatch = refpos - node.start;
      qry_match_len -= mustmatch + 1;

      NEXT_SUBSTRING:

	  node = *(nodeTexture +  (prev.x) + ((prev.y) * maxdim));
      cur = node.suffix;

      XPRINTF(" following suffix link. mustmatch:%d qry_match_len:%d sl:(%d,%d)\n", 
              mustmatch, qry_match_len, cur.x, cur.y);

      do {} while(0);
   }

#endif
	
   return;
}


extern "C" 
void computeGold(MatchResults* results,
				 char* refstr, 
				 char* queries, 
				 int* queryAddrs,
				 int* queryLengths,
				 PixelOfNode* nodeTexture,
				 PixelOfChildren* childrenTexture,
				 int numQueries,
				 int match_length,
				 int rc)
{

   if (rc == REVERSE)
   {
   
#ifdef OMP
    omp_set_num_threads(N_THREADS);
	//fprintf(stderr, "num of omp threads: %d\n", omp_get_num_threads());
   #pragma omp parallel for 
#endif
	  for (int i = 0; i < numQueries; ++i)
	  {
		 rc_kernel_gold(i, 
					 results, 
					 refstr, 
					 queries, 
					 queryAddrs, 
					 queryLengths,
					 nodeTexture, 
					 childrenTexture,
					 numQueries, 
					 match_length);
	  }

	  
   }
   else
   {
    
#ifdef OMP
	omp_set_num_threads(N_THREADS);
	//fprintf(stderr, "num of omp threads: %d\n", omp_get_num_threads());
	#pragma omp parallel for 
#endif
	  for (int i = 0; i < numQueries; ++i)
	  {
		
		/*
		int qryid,
						MatchResults* results, 		
						char* queries,
		                PixelOfNode* nodes,
		                PixelOfChildren* childrenarr,
		                char* ref,
		                const int* queryAddrs,
		                const int* queryLengths,
		                const int numQueries,
		                const int min_match_len
		#if TREE_ACCESS_HISTOGRAM
						,int* node_hist,
						int* child_hist
		#endif
		*/
		 kernel_gold(i, 
					 results, 
					 queries, 
					 nodeTexture, 
					 childrenTexture,
					 refstr, 
					 queryAddrs, 
					 queryLengths,
					 numQueries, 
					 match_length
#if TREE_ACCESS_HISTOGRAM
					 ,int* node_hist,
					 int* child_hist
#endif
					 );
	  }
   }
}

