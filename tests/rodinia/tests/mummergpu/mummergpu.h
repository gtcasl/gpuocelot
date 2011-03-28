#include <stdlib.h>
#include "common.cuh"


extern "C" {
struct QuerySet {
    int qfile;
    
    char* h_tex_array;
    char* d_tex_array;
    int* d_addrs_tex_array;
    int* h_addrs_tex_array;
    int* h_lengths_array;
    int* d_lengths_array;

    char** h_names;
    
    unsigned int count;
    size_t texlen;
    
    // total device memory occupied by this query set
    size_t bytes_on_board;
};


struct AuxiliaryNodeData {
    int length;
    int numleaves;
    TextureAddress printParent;
};


struct Reference {
    /* Reference string */
    char* str;
    size_t len;
	float t_load_from_disk;
    
    unsigned int pitch;
    void* d_ref_array;  //cudaArray*
    char* h_ref_array;
    
    /* Suffix tree for reference */
    void* d_node_tex_array;  //really a cudaArray* (or PixelOfNode* if NODETEX == 1)
    void* h_node_tex_array;  //really a PixelOfNode*
    
    void* d_children_tex_array; //cudaArray* (or PixelOfChildren* if CHILDTEX == 1)
    void* h_children_tex_array; //PixelOfChildren*

    void* d_parent_tex_array; //cudaArray*
    void* h_parent_tex_array; //PixelOfParent*
    
#if TREE_ACCESS_HISTOGRAM
	int* d_node_hist;
	int* h_node_hist;
	
	int* d_child_hist;
	int* h_child_hist;
#endif

    unsigned int tex_node_height;
    unsigned int tex_children_height;
    unsigned int tex_width;
    
    // total device memory occupied by this query set
    size_t bytes_on_board;
    
    AuxiliaryNodeData* aux_data;
    int num_nodes;
    
};


// Matches are reported as a node in the suffix tree,
// plus a distance up the node's parent link for partial
// matches on the patch from the root to the node


struct MatchCoord{
	union 
	{
		int2 data;
   		struct
		{
			TextureAddress node; // match node
   			int edge_match_length;  // number of missing characters UP the parent edge
		};
	};
};

struct MatchResults{
    // Each MatchCoord in the buffers below corresponds to the first character
    // of some substring of one of the queries
    MatchCoord* d_match_coords;
    MatchCoord* h_match_coords;
    
    unsigned int numCoords;
    
// The kernel only needs this array if the queries are coalesced
// We build it on the host side to make printing simpler.
#if COALESCED_QUERIES
	int* d_coord_tex_array;
#endif

    int* h_coord_tex_array;

    // total device memory occupied by this query set
    size_t bytes_on_board;
};

//All times in milliseconds
struct Statistics {
    float t_end_to_end;
    float t_match_kernel;
    float t_print_kernel;
    float t_results_to_disk;
    float t_queries_to_board;
    float t_match_coords_to_board;
    float t_match_coords_from_board;
    float t_tree_to_board;
    float t_ref_str_to_board;
    float t_queries_from_disk;
    float t_ref_from_disk;
    float t_tree_construction;
    float t_tree_reorder;
    float t_tree_flatten;
	float t_reorder_ref_str;
	float t_build_coord_offsets;
	float t_coords_to_buffers;
    float bp_avg_query_length;
#if TREE_ACCESS_HISTOGRAM
	int* node_hist;
	int* child_hist;
	int node_hist_size;
    int child_hist_size;
#endif
};

struct MatchContext {
    char* full_ref;
    size_t full_ref_len;
    
    Reference* ref;
    QuerySet* queries;
    MatchResults results;
    
    bool on_cpu;
    
    int min_match_length;
    
    bool reverse;
    bool forwardreverse;
    bool forwardcoordinates;
    bool show_query_length;
    bool maxmatch;
    
    char* stats_file;
	char* dotfilename;
    char* texfilename;
    Statistics statistics;
};


struct ReferencePage {
    int begin;
    int end;
    int shadow_left;
    int shadow_right;
    MatchResults results;
    unsigned int id;
    Reference ref;
};

TextureAddress id2addr(int id);

int createReference(const char* fromFile, Reference* ref);
int destroyReference(Reference* ref);

int createQuerySet(const char* fromFile, QuerySet* queries);
int destroyQuerySet(QuerySet* queries);

int createMatchContext(Reference* ref,
                       QuerySet* queries,
                       MatchResults* matches,
                       bool on_cpu,
                       int min_match_length,
                       char* stats_file,
                       bool reverse,
                       bool forwardreverse,
                       bool forwardcoordinates,
                       bool showQueryLength,
                       char* dotfilename,
                       char* texFilename,
                       MatchContext* ctx);

                       
int destroyMatchContext(MatchContext* ctx);


int matchQueries(MatchContext* ctx);

void printStringForError(int err);

// Timer management
struct Timer_t
{
  struct timeval start_m;
  struct timeval end_m;
};

char* createTimer();
void startTimer(char* ptr);
void stopTimer(char* ptr);
float getTimerValue(char* ptr);
void deleteTimer(char* ptr);

}
