#include <stdio.h>
#include <unistd.h>
#include <fstream>

#define int2 int32_t
#define ulong4 uint32_t
#define uint4 uint32_t
#include "mummergpu.h"

char * OPT_reffilename = NULL;
char * OPT_qryfilename = NULL;
char * OPT_dotfilename = NULL;
char * OPT_texfilename = NULL;
int    OPT_num_reference_pages = 1;
char * OPT_stats_file = NULL;

// MUMmer options
int  OPT_match_length = 20;
bool OPT_reverse = false;
bool OPT_forwardreverse = false;
bool OPT_forwardcoordinates = false;
bool OPT_showQueryLength = false;
bool OPT_maxmatch = false;
bool OPT_on_cpu = false;
bool OPT_stream_queries = false;

void printHelp()
{
   fprintf(stderr, 
		   "Align a set of query strings to a reference sequence using the GPU.\n"
		   "\n"
		   "Usage: mummergpu [options] reference.fa query.fa\n"
		   "\n"
		   "Options\n"
		   "  -h Print this help\n"
		   "  -d file.dot Output suffix tree in dot format\n"
		   "  -t file.tex Output suffix tree texture\n"
		   "  -C             Compute the matches using the CPU instead of the GPU\n"
		   "  -s <file>      write timing and memory stats to <file> \n"
           "\n"
           "  -l <matchlen>  minimal match length to report [Default: 20]\n"
           "  -b             compute forward and reverse complement matches\n"
           "  -r             only compute reverse complement matches\n"
           "  -c             report the query-position of a reverse complement match\n"
           "                 relative to the original query sequence\n"
           "  -L             show the length of the query sequences on the header line\n"
	  );

   exit(0);
}

void printUsage()
{
   fprintf(stderr, "Usage: mummergpu [options] reference.fa query.fa\n");
   exit(0);
}


void ParseCommandLine(int argc, char ** argv)
{
   bool errflg = false;
   int ch;
   optarg = NULL;

   while(!errflg && ((ch = getopt (argc, argv, "aCchql:d:t:s:brcLM")) != EOF))
   {
      switch  (ch)
	  {
		 case 'h': printHelp(); break;
		 case '?': fprintf(stderr, "Unknown option %c\n", optopt); errflg = true; break;
		 case 'd': OPT_dotfilename = optarg; break;
		 case 't': OPT_texfilename = optarg; break;
		 case 'C': OPT_on_cpu = true; break;
		 case 'l': OPT_match_length = atoi(optarg); break;
         case 'b': OPT_forwardreverse = true; break;
         case 'r': OPT_reverse = true; break;
		 case 's': OPT_stats_file = optarg; break;
         case 'c': OPT_forwardcoordinates = true; break;
         case 'L': OPT_showQueryLength = true; break;
         case 'M': OPT_maxmatch = true; break;

		 default: errflg = true; break;
	  };
   }

   if ((optind != argc-2) || errflg) { printUsage(); }

   if (!OPT_maxmatch)
   {
     OPT_maxmatch = true;
   }

   if (OPT_reverse && OPT_forwardreverse)
   {
     fprintf(stderr, "ERROR: Reverse (-r) and Forward & Reverse (-b) specified\n");
     exit(1);
   }

   OPT_reffilename = argv[optind++];
   OPT_qryfilename = argv[optind++];
}

int main(int argc, char* argv[])
{
   ParseCommandLine(argc, argv);

   fprintf(stderr, "TWO_LEVEL_NODE_TREE is %d\n", TWO_LEVEL_NODE_TREE);
   fprintf(stderr, "TWO_LEVEL_CHILD_TREE is %d\n", TWO_LEVEL_CHILD_TREE);
   fprintf(stderr, "QRYTEX is %d\n", QRYTEX);
   fprintf(stderr, "COALESCED_QUERIES is %d\n", COALESCED_QUERIES);
   fprintf(stderr, "REFTEX is %d\n", REFTEX);
   fprintf(stderr, "REORDER_REF is %d\n", REORDER_REF);
   fprintf(stderr, "NODETEX is %d\n", NODETEX);
   fprintf(stderr, "CHILDTEX is %d\n", CHILDTEX);
   fprintf(stderr, "MERGETEX is %d\n", MERGETEX);
   fprintf(stderr, "REORDER_TREE is %d\n", REORDER_TREE);
	fprintf(stderr, "RENUMBER_TREE is %d\n", RENUMBER_TREE);

   int err = 0;

   Reference ref;
   if ((err = createReference(OPT_reffilename, &ref)))
   {
	  printStringForError(err);
	  exit(err);
   }
   
   QuerySet queries;
   if ((err = createQuerySet(OPT_qryfilename, &queries)))
   {
	  printStringForError(err);
	  exit(err);
   }

   MatchContext ctx;
   if ((err = createMatchContext(&ref, 
								&queries, 
								0, 
								OPT_on_cpu, 
								OPT_match_length, 
								OPT_stats_file,
								OPT_reverse,
                                OPT_forwardreverse,
                                OPT_forwardcoordinates,
                                OPT_showQueryLength,
								OPT_dotfilename,
                                OPT_texfilename,
								&ctx)))
   {
	  printStringForError(err);
	  exit(err);
   }   

   if ((err = matchQueries(&ctx)))
   {
	  printStringForError(err);
	  exit(err);
   }   
   
   if ((err = destroyMatchContext(&ctx)))
   {
	  printStringForError(err);
	  exit(err);
   }   
   
   printf("\nTEST PASSED\n");
}


