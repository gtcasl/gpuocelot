#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cmath>
#include <sys/time.h>
#include <list>
#include <map>
#include <vector>
#include <queue>

#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <errno.h>
#include <assert.h>
#include <cstring>

#define ulong4 uint32_t
#define uint4 uint32_t
#define int2 int32_t
#include "mummergpu.h"

#define MPOOL 0

#include "PoolMalloc.hh"

using namespace std;

// Enable verification/debug options
#define VERIFY  0
#define VERBOSE 0
const bool DEBUG = 0;

// Setting for linear time alg
bool FORCEROOT = false;
bool DOJUMP = true;
bool DOINTERNALSKIP = true;
bool DOPHASETRICK = true;

// Statistics
int skippedbases = 0;
int skippedextensions = 0;

char substrbuffer[1024];
const char * substr(const char * str, int start, int len)
{
  if (len > 1024) { len = 1024; }
  strncpy(substrbuffer, str+start, len);
  substrbuffer[len] = '\0';

  return substrbuffer;
}


// Helper to convert from ascii to single byte
unsigned char b2i(char base)
{
  switch (base)
  {
    case 'A' : return 0;
    case 'C' : return 1;
    case 'G' : return 2;
    case 'T' : return 3;
    case '$' : return 4;

    default: 
      cerr << "Unknown base: " << base << endl;
      return b2i('A');
  };
}

#include <sys/time.h>
#include <string>

class EventTime_t
{
public:
  /// Constructor, starts the stopwatch
  EventTime_t()
  {
    start();
    memset(&m_end, 0, sizeof(struct timeval));
  }


  /// Explicitly restart the stopwatch
  void start()
  {
    gettimeofday(&m_start, NULL);
  }


  /// Explicitly stop the stopwatch
  void stop()
  {
    gettimeofday(&m_end, NULL);
  }


  /// Return the duration in seconds
  double duration()
  {
    if ((m_end.tv_sec == 0) && (m_end.tv_usec == 0)) { stop(); }
    return ((m_end.tv_sec - m_start.tv_sec)*1000000.0 + (m_end.tv_usec - m_start.tv_usec)) / 1e6;
  }


  /** \brief Pretty-print the duration in seconds.
   ** If stop() has not already been called, uses the current time as the end
   ** time.
   ** \param format Controls if time should be enclosed in [ ] 
   ** \param precision Controls number of digits past decimal pt
   **/
  std::string str(bool format = true, 
                  int precision=2)
  {
    double r = duration();

    char buffer[1024];
    sprintf(buffer, "%0.*f", precision, r);

    if (format)
    {
      string s("[");
      s += buffer;
      s += "s]";
      return s;
    }

    return buffer;
  }


private:
  /// Start time
  struct timeval m_start;

  /// End time
  struct timeval m_end;
};


// A node in the suffix tree
class SuffixNode
{
public:
  static int s_nodecount;

#ifdef MPOOL
  void *operator new( size_t num_bytes, PoolMalloc_t *mem)
  {
    return mem->pmalloc(num_bytes);
  }
#endif

  SuffixNode(int s, int e, int leafid,
             SuffixNode * p, SuffixNode * x)
    : m_start(s), m_end(e), 
      m_nodeid(++s_nodecount),
      m_leafid(leafid),
      m_numleaves(0),
      m_parent(p), 
	  m_suffix(x),
      m_printParent(NULL)
  {
    for (int i = 0; i < basecount; i++)
    { m_children[i] = NULL; }
	
	m_depth = len();
	if (p)
	   m_depth += p->m_depth;
  }

  ~SuffixNode()
  {
    for (int i = 0; i < basecount; i++)
    {
      if (m_children[i]) { delete m_children[i]; }
    }
  }

  int id()
  {
    if (this) { return m_nodeid; }
    return 0;
  }

  void setPrintParent(int min_match_len)
  {
    if (!m_parent)
    {
      // at root
      m_printParent = this;
    }
    else if (m_parent->m_depth <= min_match_len)
    {
      m_printParent = this;
    }
    else
    {
      m_printParent = m_parent->m_printParent;
    }

    for (int i = 0; i < basecount; i++)
    {
      if (m_children[i])
      {
        m_children[i]->setPrintParent(min_match_len);
      }
    }
  }

  bool isLeaf()
  {
    for (int i = 0; i < basecount; i++)
    {
      if (m_children[i]) { return false; }
    }

    return true;
  }

  const char * str(const char * refstr)
  {
    return substr(refstr, m_start, m_end-m_start+1);
  }

  int len(int i=-1)
  {
    if (i != -1)
    {
      if (i < m_end)
      {
        return i - m_start + 1;
      }
    }

    return m_end - m_start + 1;
  }

  int depth()
  { 
	 return m_depth;
  }

  ostream & printLabel(ostream & os, const char * refstr)
  {
    if (m_start == m_end && m_start == 0)
    {
      os << "\"ROOT\"";
    }
    else
    {
      os << "\"" << str(refstr) << "\"";

       //  << " [" << m_start 
       //  << ","  << m_end 
       //  << "(" << m_nodeid << ")\"";
    }

    return os;
  }


  ostream & printNodeLabel(ostream & os)
  {
    os << m_nodeid;
    return os;
  }

  ostream & printEdgeLabel(ostream & os, const char * refstr)
  {
    string seq = substr(refstr, m_start, m_end-m_start+1);
    os << "\"" << seq << "\"";
    //os << "\"" << seq << " [" << m_start << "," << m_end << "]\"";
    return os;
  }

  int setNumLeaves()
  {
    if (isLeaf())
    {
      m_numleaves = 1;
      return 1;
    }

    int sum = 0;
    for (int i = 0; i < basecount; i++)
    {
      if (m_children[i])
      {
        sum += m_children[i]->setNumLeaves();
      }
    }

    m_numleaves = sum;
    return sum;
  }


  int  m_start;                         // start pos in string
  int  m_end;                           // end pos in string
  int  m_nodeid;                        // the id for this node
  int  m_leafid;                        // For leafs, the start position of the suffix in the string
  int  m_depth;                         // string depth to me
  int  m_numleaves;                     // number of leaves below me
  SuffixNode * m_children [basecount];  // children nodes
  SuffixNode * m_parent;                // parent node
  SuffixNode * m_suffix;                // suffixlink
  SuffixNode * m_printParent;           // where to start printing

#if VERIFY
  string m_pathstring;                  // string of path to node
#endif
};

int SuffixNode::s_nodecount(0);

ostream & operator<< (ostream & os, SuffixNode * n)
{
  return n->printNodeLabel(os);
}


// Encapsulate the tree with some helper functions
class SuffixTree
{
public:
  SuffixTree(const char * s) : m_string(s)
  { 
    m_strlen = strlen(s);
#ifdef MPOOL
    m_root = new (&m_pool) SuffixNode(0,0,0,NULL,NULL); // whole tree
#else
    m_root = new SuffixNode(0,0,0,NULL,NULL); // whole tree
#endif
    m_root->m_suffix = m_root;
  }

  ~SuffixTree()
  {
#ifdef MPOOL
#else
	 delete m_root;
#endif
  }

  SuffixNode * m_root;
  const char * m_string;
  int m_strlen;

#ifdef MPOOL
  PoolMalloc_t m_pool;
#endif

  // Print a node for dot
  void printNodeDot(SuffixNode * node, ostream & dfile)
  {
    int children = 0;
    for (int i = 0; i < basecount; i++)
    {
      SuffixNode * child = node->m_children[i];
      if (child)
      {
        children++;

        dfile << " " << node << "->" << child;

        //node->printNodeLabel(dfile, m_string) << " -> ";
        //child->printNodeLabel(dfile, m_string);

        //dfile << " [minlen=" << child->len() << ", label=";
        dfile << " [minlen=1, label=";
        child->printEdgeLabel(dfile, m_string) << "]" << endl;

        printNodeDot(child, dfile);
      }
    }

    if (node->m_suffix)
    {
      dfile << " " << node << " -> " << node->m_suffix
           << " [style=dotted, constraint=false]" << endl;

      //node->printLabel(dfile, m_string) << " -> ";
      //node->m_suffix->printLabel(dfile, m_string) << " [style=dotted, constraint=false]" << endl;
    }

    if (children == 0)
    {
      //dfile << " " << node << " [shape=box, label=";
      //node->printLabel(dfile, m_string) << "]" << endl;

      dfile << " " << node << " [shape=box,width=.2,height=.2,label=\"" << node->id() << ":" << node->m_leafid << "\"]" << endl;
    }
    else
    {
      //dfile << " " << node << " [label=";
      //node->printLabel(dfile, m_string) << "]" << endl;
      dfile << " " << node << " [width=.2,height=.2,label=\"" << node->id() << "\"]" << endl;
    }
  }

  // Print the whole tree for dot
  void printDot(const char * dotfilename)
  {
    ofstream dfile;
    dfile.open(dotfilename, ofstream::out | ofstream::trunc);

    cerr << "Printing dot tree to " << dotfilename << endl;

    dfile << "digraph G {" << endl;
    dfile << " size=\"7.5,10\"" << endl;
    dfile << " center=true" << endl;
    dfile << " label=\"Suffix tree of \'" << m_string << "\' len:" 
          << m_strlen-1 << " nc:"
          << SuffixNode::s_nodecount << "\"" << endl;

    printNodeDot(m_root, dfile);
    dfile << "}" << endl;
  }

  // Print a node in text format
  void printNodeText(ostream & out, SuffixNode * n, int depth)
  {
    for (int b = 0; b < basecount; b++)
    {
      if (n->m_children[b])
      {
        for (int i = 0; i < depth; i++)
        {
          out << " ";
        }
        out << " ";
        out << n->m_children[b]->str(m_string) << endl;
        printNodeText(out, n->m_children[b], depth+1);
      }
    }
  }

  // Print the tree in Text
  void printText(ostream & out)
  {
    out << "Suffix Tree len=" << m_strlen-1 << endl; 
    out << "String: \"" << m_string << "\"" << endl;
    out << "+" << endl;
    printNodeText(out, m_root, 0);
  }

  // Print the tree as list of sorted suffixes
  void printTreeSorted(ostream & out, SuffixNode * node, const string & pathstring)
  {
    bool isLeaf = true;

    string ps(pathstring);
    if (node != m_root) { ps.append(node->str(m_string)); }

    for (int i = 0; i < basecount; i++)
    {
      if (node->m_children[i])
      {
        isLeaf = false;
        printTreeSorted(out, node->m_children[i], ps);
      }
    }

    if (isLeaf) { out << ps << endl; }
  }

  void printTreeFlat(ostream & out)
  {
    out << "nodeid\tparent\tSL\tstart\tend\t$\tA\tC\tG\tT\tnodestring" << endl;
    out << "0\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0" << endl;
    printNodeFlat(out, m_root);
  }

  void printNodeFlat(ostream & out, SuffixNode * node)
  {
    out << node->id()           << "\t"
        << node->m_parent->id() << "\t"
        << node->m_suffix->id() << "\t"
        << node->m_start        << "\t"
        << node->m_end          << "\t";

    for (int i = 0; i < basecount; i++)
    {
      out << node->m_children[i]->id() << "\t";
    }

	out << node->m_start << "\t" << node->m_end << "\t"; 

    if (node == m_root) { out << "ROOT" << endl; } 
    else                { out << node->str(m_string) << endl; }

    for (int i = 0; i < basecount; i++)
    {
      if (node->m_children[i]) { printNodeFlat(out, node->m_children[i]); }
    }
  }

#if VERIFY
  void setNodePath(SuffixNode * node, const string & parentString)
  {
    node->m_pathstring = parentString;

    if (node != m_root)
    {
      node->m_pathstring.append(m_string, node->m_start, node->m_end - node->m_start + 1);
    }

    for (int b = 0; b < basecount; b++)
    {
      if (node->m_children[b])
      {
        setNodePath(node->m_children[b], node->m_pathstring);
      }
    }
  }

  int verifyNodeSuffixLinks(SuffixNode * node, int & linkcount)
  {
    int errs = 0;
    if (node != m_root && node->m_suffix)
    {
      const string & np = node->m_pathstring;
      const string & sp = node->m_suffix->m_pathstring;
      if (np.substr(1, np.length() -1) != sp)
      {
        cerr << "Suffix Link Mismatch!!" << endl;
        node->printLabel(cerr, m_string) << ": " << np << endl;
        node->m_suffix->printLabel(cerr, m_string) << ": " << sp << endl;
        errs++;
      }

      linkcount++;
    }

    if (node == m_root && node->m_suffix != m_root)
    {
      cerr << "Error m_root suffix != m_root !!!" << endl;
      errs++;
    }

    int childcount = 0;
    for (int b = 0; b < basecount; b++)
    {
      if (node->m_children[b])
      {
        childcount++;
        errs += verifyNodeSuffixLinks(node->m_children[b], linkcount);
      }
    }

    if (childcount && !node->m_suffix)
    {
      errs++;
      node->printLabel(cerr, m_string) << " has no suffix link!!!" << endl;
    }

    return errs;
  }

  void verifySuffixLinks()
  {
    cerr << endl;
    cerr << "Verifing links" << endl;
    setNodePath(m_root, "");
    int linkcount = 0;
    int err = verifyNodeSuffixLinks(m_root, linkcount);
    cerr << err << " suffix link errors detected" << endl;
    cerr << linkcount << " suffix links checked" << endl;

    if (err) { exit(1); }
  }
#endif
  

  void buildUkkonen()
  {
    int len = m_strlen - 1; // length of the string, not of the buffer (remove s)
    char base = m_string[1];

    if (DEBUG)
    {
      cerr << "Building Ukkonen Tree for " << m_string << endl
           << "Len: " << len << endl;
    }

    // Construct T1
#ifdef MPOOL
    SuffixNode * node = new (&m_pool) SuffixNode(1, len, 1, m_root, NULL); // leaf: 1
#else
    SuffixNode * node = new SuffixNode(1, len, 1, m_root, NULL); // leaf: 1
#endif
    m_root->m_children[b2i(base)] = node;
    SuffixNode * firstleaf = node;
    SuffixNode * lastleaf = node;

    if (DEBUG)
    { cerr << "Phase 1 Child: "; node->printLabel(cerr, m_string) << endl; }

    int startj = 2;

    // phase i+1
    for (int i = 2; i <= len; i++)
    {
      // Start at the last leaf created which will allow easy
      // access to the node for startj
      node = lastleaf;
      int nodewalk = 0;

      // Keep track of last internal nodes created in split so we can add suffix links
      SuffixNode * splitnode = NULL;

      if (!DOPHASETRICK)
      {
        startj = 2;
        node = firstleaf;
      }

      if (DEBUG) 
      { 
        char next = m_string[i];
        cerr << endl;
        cerr << i << ".0 " << "Phase " << i << " adding " << next << " starting with " << startj << endl; 

        string beta = substr(m_string, 1, i);
        cerr << i << ".1" << " Extension 1: \"" << beta << "\" [implicit]" << endl;
      }

      for (int j = startj; j <= i; j++)
      {
        // Goal: Ensure S[j .. i] (beta) is in the suffix tree 
        // Precondition: S[j-1 .. i] (alpha) is in the suffix tree "near" node
        //               All Internal nodes have a suffix link

        // Idea: 1) Remember where alpha is in the tree relative to node
        //       2) Walk up the tree w bases until we get to a node with a suffix link.
        //       3) Follow suffix link which shifts the path from S[j-1..i] to S[j..i]
        //       4) Walk down tree in new location ensuring S[i-w .. i] is in tree

        // Notes: 1) All internal nodes have a suffix link by next extension
        //        2) Any time we walk up to root, have to check S[j..i]
        //        3) Suffix [1..i] is always present so start extension j with 2

        int betapos = i; // The first position in string we need to check in tree

        if (DEBUG)
        {
          cerr << endl;
          string beta = substr(m_string, j, i-j+1);
          cerr << i << "." << j << " Phase " << i << " Extension " << j << ": \"" << beta << "\" bp:" << betapos << endl;

          cerr << i << "." << j << "  Walking up from n:"; 
          node->printLabel(cerr, m_string) << " nw: " << nodewalk << endl;
        }

        if (node == m_root)
        {
          // If we are at root, we have to check the full string s[j..i] anyways
        }
        else
        {
          if (nodewalk)
          {
            // partially walked down node->child, but didn't switch to child
            // Match at i=6 on left... nodewalk=2, at 5 after suffix link
            // 5 = i-2+1
            //                 o ----- o
            //               5 A       A 5  <-
            //            -> 6 T       T 6 

            betapos -= nodewalk-1;

            if (DEBUG)
            {
              cerr << i << "." << j << "   Adjusted nw: " << nodewalk << endl;
            }
          }
          else
          {
            // Exactly at a node or leaf. 
            // Walk up to parent, subtracting length of that edge
            int len = node->len(i);
            betapos -= len-1;
            node = node->m_parent;

            if (DEBUG)
            {
              cerr << i << "." << j << "   Adjusted len: " << len << endl;
            }
          }
          
          if (DEBUG)
          {
            cerr << i << "." << j << "   parent bp: " << betapos <<  " n:";
            node->printLabel(cerr, m_string) << endl;
          }

          if (node->m_suffix == NULL)
          {
            // Subtract entire edge length
            betapos -= node->len(i);
            node = node->m_parent;

            if (DEBUG)
            {
              cerr << i << "." << j << "   grandparent bp: " << betapos << " n:";
              node->printLabel(cerr, m_string) << endl;
            }

            #if VERIFY
            if (node->m_suffix == NULL)
            {
              cerr << "Missing suffix link!!! ";
              exit(1);
            }
            #endif
          }
        }

        // jump across suffix link
        node = node->m_suffix;
        if (node == m_root) { betapos = j; } // have to check full string

        if (DEBUG)
        {
          cerr << i << "." << j << "  Starting to walk down from bp: " << betapos << " to " << i << " n:";
          node->printLabel(cerr, m_string) << endl;
        }

        if (FORCEROOT && node != m_root)
        {
          node = m_root;
          betapos = j;

          if (DEBUG)
          {
            cerr << i << "." << j << " AtRoot bp: " << betapos << endl;
          }
        }

        bool done = false;
        startj = j+1; // assume this extension should be skipped in the next phase

        while ((betapos <= i) && !done)
        {
          char base = m_string[betapos];
          unsigned char b = b2i(base);
          SuffixNode * child = node->m_children[b];

          if (DEBUG)
          {
            cerr << i << "." << j << "  node betapos: " << betapos << "[" << base << "] n:";
            node->printLabel(cerr, m_string) << " ";
            if (child) { cerr << "c: "; child->printLabel(cerr, m_string); } 
            cerr << endl;
          }

          if (!child)
          {
            if (splitnode && betapos == splitnode->m_start)
            {
              if (DEBUG)
              {
                cerr << i << "." << j << "   Add SL1: ";
                splitnode->m_parent->printLabel(cerr, m_string) << " sl-> ";
                node->printLabel(cerr, m_string) << endl;
              }

              splitnode->m_parent->m_suffix = node;
              splitnode = NULL;
            }

#ifdef MPOOL
            SuffixNode * newnode = new (&m_pool) SuffixNode(betapos, len, j, node, NULL); // leaf: j
#else
            SuffixNode * newnode = new SuffixNode(betapos, len, j, node, NULL); // leaf: j
#endif
            node->m_children[b] = newnode; 
            lastleaf = newnode;

            if (DEBUG)
            {
              cerr << i << "." << j << "   New Node: ";
              newnode->printLabel(cerr, m_string) << endl;
            }

            node = newnode;

            // This is the first base that differs, but the edgelength to 
            // i may be longer. Therefore set nodewalk to 0, so the entire
            // edge is subtracted.
            nodewalk = 0;
            done = true;
            break;
          }
          else
          {
            int nodepos = child->m_start;
            nodewalk = 0;

            char nodebase = m_string[nodepos];

            #if VERIFY
            if (nodebase != base)
            {
              char nb = m_string[nodepos];
              cerr << "ERROR: first base on edge doesn't match edge label" << endl;
              cerr << "       nb: " << nb << " base: " << base << endl;
              exit(1);
            }
            #endif

            // By construction, the string from j-1 to betapos to i-1
            // must already by present in the suffix tree
            // Therefore, we can skip checking every character, and zoom
            // to exactly the right character, possibly skipping the entire edge

            if (DOJUMP)
            {
              int mustmatch = i-1 - betapos + 1;
              int childlen = child->len(i);

              if (mustmatch >= childlen)
              {
                betapos += childlen;
                nodepos += childlen;

                skippedbases += childlen;

                if (DEBUG)
                {
                  cerr << i << "." << j << "   Edge Jump by: " << childlen << " new bp: " << betapos << " np: " << nodepos << endl;
                }

                #if VERIFY
                if (nodepos != child->m_end+1)
                {
                  cerr << "ERROR: jump should have skipped entire edge, but didn't!" << endl;
                  exit(1);
                }
                #endif
              }
              else if (mustmatch)
              {
                betapos += mustmatch;
                nodepos += mustmatch;
                nodewalk += mustmatch;

                skippedbases += mustmatch;

                if (DEBUG)
                {
                  cerr << i << "." << j << "   Partial Jump by: " << mustmatch << " new bp: " << betapos << " np: " << nodepos << endl;
                }

                #if VERIFY
                if (VERIFY)
                {
                  if (m_string[betapos-1] != m_string[nodepos-1])
                  {
                    cerr << "ERROR: jump should have matched at least the mustmatch-1 characters" << endl;
                    cerr << "s[bp-1]: " << m_string[betapos-1] << " s[np-1]: " << m_string[nodepos-1] << endl;
                    exit(1);
                  }
                }
                #endif
              }
            }

            while (nodepos <= child->m_end && betapos <= i)
            {
              nodebase = m_string[nodepos];

              #if VERBOSE
                cerr << i << "." << j << "   child bp: " << betapos << "[" << m_string[betapos] 
                     << "] nb [" << nodebase << "]" << endl;
              #endif

              if (m_string[betapos] == nodebase)
              {
                if (splitnode && betapos == splitnode->m_start)
                {
                  if (DEBUG)
                  {
                    cerr << i << "." << j << "   Add SL2: ";
                    splitnode->m_parent->printLabel(cerr, m_string) << " sl-> ";
                    node->printLabel(cerr, m_string) << endl;
                  }

                  splitnode->m_parent->m_suffix = node;
                  splitnode = NULL;
                }

                nodepos++; betapos++; nodewalk++;

                if (betapos == i+1)
                {
                  if (DEBUG)
                  {
                    cerr << i << "." << j << "    Internal edge match nw: " << nodewalk << endl;
                  }

                  if ((nodewalk == child->len(i)) && (child->m_end == len))
                  {
                    // we walked the whole edge to leaf, implicit rule I extension
                    if (DEBUG)
                    {
                      cerr << i << "." << j << "    Leaf Node, Implicit Rule I Extension" << endl;
                    }
                  }
                  else
                  {
                    // "Real" rule III implicit extension

                    // The j-1 extension was the last explicit extension in this round
                    // Start the next round at the last explicit extension
                    if (DOPHASETRICK)
                    {
                      startj = j;

                      int skip = startj - 2;

                      if (DEBUG)
                      {
                        cerr << i << "." << j << "    Implicit Extension... start next phase at " << startj << ", saved " << skip << endl;
                      }

                      skippedextensions += skip;
                    }

                    if (DOINTERNALSKIP)
                    {
                      // Since we hit an internal match on a non-leaf, we know every other 
                      // extension in this phase will also hit an internal match. 

                      // Have to be careful since leafs get the full string immediately, but
                      // they really have a Rule 1 extension

                      int skip = i-j;

                      if (DEBUG)
                      { 
                        cerr << i << "." << j << "    Implicit Extension... skipping rest of phase, saved " << skip << endl;
                      }

                      skippedextensions += skip;
                      j = i+1;
                    }
                  }

                  done = true;
                }
              }
              else
              {
                if (DEBUG) { cerr << i << "." << j << "   Spliting "; child->printLabel(cerr, m_string); }

                // Split is a copy of the child with the end shifted
                // Then adjust start of child
#ifdef MPOOL
                SuffixNode * split = new (&m_pool) SuffixNode(child->m_start, nodepos-1, 0, node, NULL); // internal
#else
                SuffixNode * split = new SuffixNode(child->m_start, nodepos-1, 0, node, NULL); // internal
#endif

                split->m_children[b2i(nodebase)] = child;
                child->m_start = nodepos;
                child->m_parent = split;

                if (DEBUG)
                {
                  cerr << " => ";
                  split->printLabel(cerr, m_string) << " + ";
                  child->printLabel(cerr, m_string) << endl;
                }

                node->m_children[b] = split;
                node = split;

                if (splitnode && betapos == splitnode->m_start)
                {
                  if (DEBUG)
                  {
                    cerr << i << "." << j << "   Add SL3: ";
                    splitnode->m_parent->printLabel(cerr, m_string) << " sl-> ";
                    node->printLabel(cerr, m_string) << endl;
                  }

                  splitnode->m_parent->m_suffix = split;
                  splitnode = NULL;
                }

                // Now create the new node
#ifdef MPOOL
                SuffixNode * newnode = new (&m_pool) SuffixNode(betapos, len, j, split, NULL); // leaf j
#else
                SuffixNode * newnode = new SuffixNode(betapos, len, j, split, NULL); // leaf j
#endif
                lastleaf = newnode;

                split->m_children[b2i(m_string[betapos])] = newnode; 
                splitnode = newnode;

                node = newnode;

                if (DEBUG)
                {
                  cerr << i << "." << j << "   Split New Node: ";
                  newnode->printLabel(cerr, m_string) << endl;
                }

                // This is the first base that differs, but the edgelength to 
                // i may be longer. Therefore set nodewalk to 0, so the entire
                // edge is subtracted.
                nodewalk = 0;
                done = true;
                break;
              }
            }
          }

          if (!done) { node = child; }
        }
      }

      #if VERIFY
      if (VERIFY) { verifySuffixLinks(); }
      #endif
    }
  }
};


SuffixTree * gtree = NULL;

void buildUkkonenSuffixTree(const char * str)
{
   gtree = new SuffixTree(str);
   gtree->buildUkkonen();
}

static const int TEXBLOCKSIZE = 32;

#define LOW3(x) (x & 0xFF)
#define MID3(x) (x & 0xFF00) >> 8
#define HI3(x)  (x & 0xFF0000) >> 16

#define HALF_TEXTURE_DIMENSION 2048

inline TextureAddress id2addr(int id)
{
  TextureAddress retval;

#if MERGETEX && REORDER_TREE
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
  // MAX_TEXTURE_DIMENSION is 4096 => 12 bits
  // TEXBLOCKSIZE is 32 => 5 bits
  int bigx = id & 0x1FFFF; // 12 + 5 bits
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

inline int addr2id(TextureAddress addr)
{
#if MERGETEX && REORDER_TREE
  // shift x'a 12th bit as y's 13th
  addr.y |= (addr.x & 0x800) << 1;
  addr.x &= 0x7FF;

  int blocky = addr.y & 0x1F;
  int bigy = addr.y >> 5;
  int bigx = (addr.x << 5) + blocky;
  return bigx + (bigy << 16);

#elif REORDER_TREE
  int blocky = addr.y & 0x1F;
  int bigy = addr.y >> 5;
  int bigx = (addr.x << 5) + blocky;
  return bigx + (bigy << 17);

#elif MERGETEX
    return addr.x;

#else
    return addr.x;

#endif
}

void writeAddress(unsigned char arr[3], TextureAddress addr)
{
#if REORDER_TREE
  arr[0] = addr.x & 0xFF;
  arr[1] = addr.y & 0xFF;
  arr[2] = (((addr.x) >> 8) & 0xF) | (((addr.y) >> 4) & 0xF0);
#else
  arr[0] = LOW3(addr.x);
  arr[1] = MID3(addr.x);
  arr[2] = HI3(addr.x);
#endif
}

TextureAddress arrayToAddress(unsigned char arr[3])
{
  TextureAddress retval;

#if REORDER_TREE
  retval.x = arr[0] | ((arr[2] & 0xF) << 8);
  retval.y = arr[1] | ((arr[2] & 0xF0) << 4);
#else
  retval.x = MK3(arr);
#endif

  return retval;
}



void buildNodeTexture(SuffixNode * node,
                      PixelOfNode * nodeTexture,
                      PixelOfChildren * childrenTexture,
                      AuxiliaryNodeData aux_data[],
                      const char * refstr)
{	
  int origid = node->id();
    
  aux_data[origid].length = node->len();
  aux_data[origid].numleaves = node->m_numleaves;
  aux_data[origid].printParent = id2addr(node->m_printParent->id());

  TextureAddress myaddress(id2addr(origid));

  PixelOfNode * nd;
  PixelOfChildren * cd;

#if MERGETEX && REORDER_TREE
  int tex = myaddress.x & 0x800;
  myaddress.x &= 0x7FF;
  myaddress.x *= 2;

  int loc = myaddress.x + myaddress.y*MAX_TEXTURE_DIMENSION;

  if (tex)
  {
    nd = (PixelOfNode*)    &childrenTexture[loc];
    cd = (PixelOfChildren*)&childrenTexture[loc+1];
  }
  else
  {
    nd = (PixelOfNode*)    &nodeTexture[loc];
    cd = (PixelOfChildren*)&nodeTexture[loc+1];
  }

#elif REORDER_TREE
  int loc = myaddress.x + myaddress.y*MAX_TEXTURE_DIMENSION;

  nd = &(nodeTexture[loc]);
  cd = &(childrenTexture[loc]);

#elif MERGETEX
  int loc = myaddress.x * 2;

  if (loc >= (MAX_TEXTURE_DIMENSION*MAX_TEXTURE_DIMENSION))
  {
    loc -= MAX_TEXTURE_DIMENSION*MAX_TEXTURE_DIMENSION;
    nd = (PixelOfNode*)    &(childrenTexture[loc]);
    cd = (PixelOfChildren*)&(childrenTexture[loc+1]);
  }
  else
  {
    nd = (PixelOfNode*)    &(nodeTexture[loc]);
    cd = (PixelOfChildren*)&(nodeTexture[loc+1]);
  }

#else
  int loc = myaddress.x;
  nd = &(nodeTexture[loc]);
  cd = &(childrenTexture[loc]);
#endif

  unsigned char arr[3];
  writeAddress(arr, myaddress);
  TextureAddress newaddr = arrayToAddress(arr);

  TextureAddress parent(id2addr(node->m_parent->id()));
  writeAddress(nd->parent, parent);
  assert(arrayToAddress(nd->parent).data == parent.data);

  TextureAddress suffix(id2addr(node->m_suffix->id()));
  writeAddress(nd->suffix, suffix);
  assert(arrayToAddress(nd->suffix).data == suffix.data);

  nd->start[0]  = LOW3(node->m_start);
  nd->start[1]  = MID3(node->m_start);
  nd->start[2]  = HI3(node->m_start);

  assert(MK3(nd->start) == node->m_start);

  nd->end[0]    = LOW3(node->m_end);
  nd->end[1]    = MID3(node->m_end);
  nd->end[2]    = HI3(node->m_end);

  assert(MK3(nd->end) == node->m_end);

  int depth = node->depth();
  nd->depth[0]  = LOW3(depth);
  nd->depth[1]  = MID3(depth);
  nd->depth[2]  = HI3(depth);
    
  assert(MK3(nd->depth) == depth);
    
  cd->leafchar = 0;

  if (node->m_leafid != 0)
  {
    cd->leafchar  = refstr[node->m_leafid-1];

    cd->leafid[0] = LOW3(node->m_leafid);
    cd->leafid[1] = MID3(node->m_leafid);
    cd->leafid[2] = HI3(node->m_leafid);
  }
  else
  {
    if (node->m_children[0]) 
    { 
      TextureAddress childaddr = id2addr(node->m_children[0]->id());
      writeAddress(cd->a, childaddr);
      assert(arrayToAddress(cd->a).data == childaddr.data);
      buildNodeTexture(node->m_children[0], nodeTexture, childrenTexture, aux_data, refstr); 
    }
            
    if (node->m_children[1]) 
    { 
      TextureAddress childaddr = id2addr(node->m_children[1]->id());
      writeAddress(cd->c, childaddr);
      assert(arrayToAddress(cd->c).data == childaddr.data);
      buildNodeTexture(node->m_children[1], nodeTexture, childrenTexture, aux_data, refstr); 
    }

    if (node->m_children[2]) 
    { 
      TextureAddress childaddr = id2addr(node->m_children[2]->id());
      writeAddress(cd->g, childaddr);
      assert(arrayToAddress(cd->g).data == childaddr.data);
      buildNodeTexture(node->m_children[2], nodeTexture, childrenTexture, aux_data, refstr); 
    }

    if (node->m_children[3]) 
    { 
      TextureAddress childaddr = id2addr(node->m_children[3]->id());
      writeAddress(cd->t, childaddr);
      assert(arrayToAddress(cd->t).data == childaddr.data);
      buildNodeTexture(node->m_children[3], nodeTexture, childrenTexture, aux_data, refstr); 
    }

    if (node->m_children[4]) 
    { 
      TextureAddress childaddr = id2addr(node->m_children[4]->id());
      writeAddress(cd->d, childaddr);
      assert(arrayToAddress(cd->d).data == childaddr.data);
      buildNodeTexture(node->m_children[4], nodeTexture, childrenTexture, aux_data, refstr); 
    }
  }
}

void buildSuffixTreeTexture(PixelOfNode** nodeTexture,
                            PixelOfChildren **childrenTexture,
                            unsigned int* width, 
                            unsigned int* node_height,
                            unsigned int* children_height,
                            AuxiliaryNodeData **aux_data,
                            const char * refstr,
                            int min_match_len) 
{
    // Leave space for NULL node
    int allnodes = SuffixNode::s_nodecount + 1;

    assert(allnodes < MAX_TEXTURE_DIMENSION*MAX_TEXTURE_DIMENSION);
    
    assert(sizeof(PixelOfNode) == 16);
    assert(sizeof(PixelOfChildren) == 16);
    

#if MERGETEX && REORDER_TREE
    *width = MAX_TEXTURE_DIMENSION;
    
	int numrows = ((int)ceil((allnodes+0.0) / ((MAX_TEXTURE_DIMENSION/2) * TEXBLOCKSIZE))) * TEXBLOCKSIZE;
    if (numrows <= MAX_TEXTURE_DIMENSION)
    {
      *node_height = numrows;
      *children_height = 0;
    }
    else
    {
      *node_height = MAX_TEXTURE_DIMENSION;
      *children_height = (numrows - MAX_TEXTURE_DIMENSION);
    }

#elif REORDER_TREE
    *width = MAX_TEXTURE_DIMENSION;
	int numrows = ((int)ceil((allnodes+0.0) / ((MAX_TEXTURE_DIMENSION) * TEXBLOCKSIZE))) * TEXBLOCKSIZE;
    *node_height = numrows;
    *children_height = numrows;

#elif MERGETEX
    *width = 1;
    int numcells = allnodes*2;

    if (numcells <= (MAX_TEXTURE_DIMENSION*MAX_TEXTURE_DIMENSION))
    {
      *node_height = numcells;
      *children_height = 0;
    }
    else
    {
      *node_height = MAX_TEXTURE_DIMENSION * MAX_TEXTURE_DIMENSION;
      *children_height = numcells - *node_height;
    }

#else
    *width = 1;
    *node_height = allnodes;
    *children_height = allnodes;
#endif

    int alloc = 0;

    // allocate space for the node and children textures
    *nodeTexture     = (PixelOfNode*) calloc((*width) * (*node_height), sizeof(PixelOfNode));
    alloc += (*width) * (*node_height) * sizeof(PixelOfNode);

    *childrenTexture = NULL;

    if (*children_height)
    {
      *childrenTexture = (PixelOfChildren*) calloc((*width) * (*children_height), sizeof(PixelOfChildren));
      alloc += (*width) * (*children_height) * sizeof(PixelOfChildren);
    }
    
    fprintf(stderr, " node: %dx%d",     *width, *node_height);
    fprintf(stderr, " children: %dx%d ", *width, *children_height);

    *aux_data = (AuxiliaryNodeData*)calloc(allnodes, sizeof(AuxiliaryNodeData));

    if (!*nodeTexture || (*children_height && !*childrenTexture) || !*aux_data) 
    {
        fprintf(stderr, "arg.  texture allocation failed.\n");
        exit(-1);
    }
    
    gtree->m_root->setNumLeaves();
    gtree->m_root->setPrintParent(min_match_len);
    
    buildNodeTexture(gtree->m_root,
                     *nodeTexture,
                     *childrenTexture,
                     *aux_data,
                     refstr);
};


void printTreeTexture(const char * texfilename,
                      PixelOfNode * nodeTexture,
                      PixelOfChildren * childrenTexture,
                      int nodecount)
{
  cerr << "Printing tree texture to " << texfilename << endl;

  ofstream texfile;
  texfile.open(texfilename, ofstream::out | ofstream::trunc);

  texfile << "id\tx\ty\tstart\tend\tdepth\ta.x\ta.y\tc.x\tc.y\tg.x\tg.y\tt.x\tt.y\t$.x\t$.y\tp.x\tp.y" << endl;
  for (int i = 0; i < nodecount; i++)
  {
    TextureAddress myaddress(id2addr(i)); 

    texfile << i << "\t"
            << myaddress.x << "\t"
#if REORDER_TREE
            << myaddress.y << "\t"
#endif
            << MK3(nodeTexture[i].start) << "\t"
            << MK3(nodeTexture[i].end)   << "\t"
            << MK3(nodeTexture[i].depth) << "\t";

    TextureAddress a = arrayToAddress(childrenTexture[i].a);
    texfile << a.x << "\t";
#if REORDER_TREE
    texfile << a.y << "\t";
#endif

    TextureAddress c = arrayToAddress(childrenTexture[i].c);
    texfile << c.x << "\t";
#if REORDER_TREE
    texfile << c.y << "\t";
#endif

    TextureAddress g = arrayToAddress(childrenTexture[i].g);
    texfile << g.x << "\t";
#if REORDER_TREE
    texfile << g.y << "\t";
#endif

    TextureAddress t = arrayToAddress(childrenTexture[i].t);
    texfile << t.x << "\t";
#if REORDER_TREE
    texfile << t.y << "\t";
#endif

    TextureAddress d = arrayToAddress(childrenTexture[i].d);
    texfile << d.x << "\t";
#if REORDER_TREE
    texfile << d.y << "\t";
#endif

    TextureAddress p = arrayToAddress(nodeTexture[i].parent);
    texfile << p.x << "\t";
#if REORDER_TREE
    texfile << p.y;
#endif

    texfile << endl;
  }

  texfile.close();
}

void renumberTree()
{
  queue<pair<SuffixNode *, int> > nodequeue;

  nodequeue.push(make_pair(gtree->m_root,0));
  int nodecount = 0;

  while(!nodequeue.empty())
  {
    pair<SuffixNode *,int> npair = nodequeue.front(); nodequeue.pop();

    SuffixNode * node = npair.first;
    int depth = npair.second;
    
    node->m_nodeid = ++nodecount;

    if (depth < 16)
    {
      for (int i = 0; i < basecount; i++)
      {
        SuffixNode * child = node->m_children[i];
        if (child) { nodequeue.push(make_pair(child,depth+1)); }
      }
    }
    else
    {
      for (int i = 0; i < basecount; i++)
      {
        SuffixNode * child = node->m_children[i];
        if (child)
        {
          child->m_nodeid = ++nodecount;
          
          for(int j = 0; j < basecount; j++)
          {
            SuffixNode * gchild = child->m_children[j];

            if (gchild)
            {
              gchild->m_nodeid = ++nodecount;
              for (int k = 0; k < basecount; k++)
              {
                SuffixNode * ggchild = gchild->m_children[k];

                if (ggchild)
                { 
                  ggchild->m_nodeid = ++nodecount;

                  for (int l = 0; l < basecount; l++)
                  {
                    SuffixNode * gggchild = ggchild->m_children[l];

                    if (gggchild)
                    {
                      gggchild->m_nodeid = ++nodecount;

                      for (int m = 0; m < basecount; m++)
                      {
                        SuffixNode * ggggchild = gggchild->m_children[m];
                        if (ggggchild){ nodequeue.push(make_pair(ggggchild, depth+5)); }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}


extern "C"
void createTreeTexture(const char * refstr,
                       PixelOfNode** nodeTexture,
                       PixelOfChildren** childrenTexture,
                       unsigned int* width,
                       unsigned int* node_height,
                       unsigned int* children_height,
                       AuxiliaryNodeData** aux_data,
                       int* num_nodes,
                       int min_match_len,
                       Statistics* statistics,
                       const char * dotfilename,
                       const char * texfilename)

{
    cerr << "  Creating Suffix Tree... ";
    EventTime_t btimer;
    char* ctimer = createTimer();
    startTimer(ctimer);

    SuffixNode::s_nodecount = 0;
    buildUkkonenSuffixTree(refstr);

	stopTimer(ctimer);
	if (statistics)
		statistics->t_tree_construction += getTimerValue(ctimer);
	deleteTimer(ctimer);
	
    cerr << SuffixNode::s_nodecount << " nodes "
    << btimer.str(true, 5) << endl;

#if RENUMBER_TREE    
    cerr << "  Renumbering tree... ";
    EventTime_t rtimer;
    char* reordertimer = createTimer();
    startTimer(reordertimer);
    renumberTree();
    stopTimer(reordertimer);
    if (statistics)
        statistics->t_tree_reorder += getTimerValue(reordertimer);
    deleteTimer(reordertimer);
    cerr << rtimer.str(true, 5) << endl;
#endif
    
    EventTime_t ftimer;
    cerr << "  Flattening Tree... ";
    char* flattentimer = createTimer();
    startTimer(flattentimer);
    buildSuffixTreeTexture(nodeTexture,
                           childrenTexture,
                           width, node_height, children_height,
                           aux_data,
                           gtree->m_string,
                           min_match_len);
    stopTimer(flattentimer);
    if (statistics)
        statistics->t_tree_flatten += getTimerValue(flattentimer);
    deleteTimer(flattentimer);  

    *num_nodes = SuffixNode::s_nodecount + 1;
    cerr << ftimer.str(true, 5) << endl;
    
    if (dotfilename)
    {
        gtree->printDot(dotfilename);
    }
    
    if (texfilename)
    {
        printTreeTexture(texfilename,
                         *nodeTexture,
                         *childrenTexture,
                         SuffixNode::s_nodecount + 1);
    }
    
    delete gtree;
    gtree = NULL;
}



extern "C"
void getReferenceString(const char * filename, char** refstr, size_t* reflen)
{
  EventTime_t timer;
  cerr << "Loading ref: " << filename << "... ";

  string S="s";

  ifstream file;
  file.open(filename);

  if (!file)
  {
    cerr << "Can't open " << filename << endl;
    exit (1);
  }

  // Skip over the reference header line
  char refline[2048];
  file.getline(refline, sizeof(refline));

  if (refline[0] != '>')
  {
    cerr << endl
         << "ERROR: Reference file is not in FASTA format"
         << endl;
  }

  // Now read the reference string
  string buffer;
  while (file >> buffer)
  {
    if (buffer[0] == '>')
    {
      cerr << endl
           << "ERROR: Only a single reference sequence is supported!" 
           << endl;

      exit (1);
    }
    else
    {
      for (unsigned int i = 0; i < buffer.length(); i++)
      {
        char b = toupper(buffer[i]);
		if (b == ' ')
			continue;
        if (b == 'A' || b == 'C' || b == 'G' || b=='T')
        {
          S += b;
        }
		else
		{
		   S += 'A';
		}
      }
    }
  }

  S += "$";
 *refstr = strdup(S.c_str());
  *reflen = strlen(*refstr) + 1;

  cerr << *reflen-3 << " bp. " << timer.str(true, 5) << endl;
}

inline void addChar(char **buf, int * size, int * pos, char c)
{
  if (*pos == *size)
  {
    (*size) *= 2; // double the size of the buffer
    *buf = (char *) realloc(*buf, *size);
    if (!*buf)
    {
      cerr << "ERROR: Realloc failed, requested: " << *size << endl;
      exit(1);
    }
  }

  (*buf)[*pos] = c;
  (*pos)++;
}

inline size_t bytesNeededOnGPU(unsigned int querylen, int min_match_len)
{
   if (min_match_len == -1)
	  return sizeof(MatchCoord) + (querylen + 10);
   else
	  return sizeof(MatchCoord) * (querylen - min_match_len + 1) + 
		(querylen + 10);
} 

#define WARP_SIZE 16

//Gets up to set_size queries.
extern "C"
    void getQueriesTexture(int qfile,
                           char** queryTexture,
                           size_t* queryTextureSize,
                           int** queryAddrs,
                           char*** queryNames,
                           int** queryLengths,
                           unsigned int* numQueries,
                           unsigned int* num_match_coords,
                           unsigned int memory_avail,
                           int min_match_length,
                           bool rc)
{
    EventTime_t timer;
    
    int qstringpos = 0;
    int qstringsize = 1024 * 1024;
    char * qstring = (char *) malloc(qstringsize);
    
    bool resetAmbiguity  = true;
    
    // offset of query i in qstring
    int offsetspos = 0;
    int offsetssize = 1024;
    int * offsets = (int *) malloc(offsetssize * sizeof(int));
    int * lengths = (int *) malloc(offsetssize * sizeof(int));
    
    int qrylen = 0;
    int this_qrylen = 0;
    
    int bytes_read;
    unsigned char buf[32*1024];
    
    vector<char*> names;
    string header;
    bool inheader = false;
    int total_read = 0;
    
    unsigned char dnachar [256];
    
    bool set_full = false;
    
#if COALESCED_QUERIES
    unsigned int curr_warp_padding = 0;
    unsigned int warp_max_qry_len = 2;
#endif
    
    // tracks the GPU memory needed by the queries read so far.
    unsigned int  curr_mem_usage = 0;
    
    for (int i = 0; i < 256; i++)
    {
        dnachar[i] = 0;
    }
    
    dnachar[(unsigned char) 'A'] = 1;
    dnachar[(unsigned char) 'C'] = 1;
    dnachar[(unsigned char) 'G'] = 1;
    dnachar[(unsigned char) 'T'] = 1;
    
    while ((bytes_read = read(qfile, buf, sizeof(buf))) != 0)
    {
        // cerr << "bytes_read: " << bytes_read << endl;
        
        if (bytes_read == -1)
        {
            cerr << "ERROR: Error reading file: " << errno << endl;
            exit(1);
        }
        
        int i = 0;
        
        if (inheader)
        {
            // Handle case where last read was inside a header
            for (; i < bytes_read; i++)
            {
                if (buf[i] == '\n')
                {
                    inheader = false;
                    i++;
                    char* name = strdup(header.c_str());
                    names.push_back(name);
                    header.clear();
                    break;
                }
                else
                {
                    header.insert(header.end(), buf[i]);
                }
            }
        }
        
        for (; i < bytes_read; i++)
        {
            unsigned char b = toupper(buf[i]);
            
            if (b == '>')
            {
            
                if (curr_mem_usage + bytesNeededOnGPU(MAX_QUERY_LEN, min_match_length) >= memory_avail)
                {
                    set_full = true;
                    off_t seek = lseek(qfile, -(bytes_read - i), SEEK_CUR);
                    if (seek == (off_t) - 1)
                    {
                        cerr << "lseek failed: " << errno << endl;
                        exit(-1);
                    }
                    break;
                }
                
                
                // in a header line
                if (offsetspos != 0)
                {
                    if (this_qrylen < min_match_length)
                    {
                        //printf("> %s\n", names.back());
                        //if (rc)
                        //    printf("> %s Reverse\n", names.back());
                        names.pop_back();
                        --offsetspos;
                        qstringpos -= this_qrylen  + 1;
                    }
                    else
                    {
                        addChar(&qstring, &qstringsize, &qstringpos, '\0');
                        lengths[offsetspos - 1] = this_qrylen;
#if COALESCED_QUERIES
                        if (warp_max_qry_len < this_qrylen + 2)
                        {
                            int num_warp_queries = (offsetspos - 1) % WARP_SIZE;
                            
                            curr_warp_padding -= num_warp_queries * warp_max_qry_len;
                            curr_mem_usage -= num_warp_queries * warp_max_qry_len;
                            
                            warp_max_qry_len = this_qrylen  + 2;
                            if (warp_max_qry_len % 4)
                                warp_max_qry_len += 4 - (warp_max_qry_len % 4);
                                
                            curr_warp_padding += num_warp_queries * warp_max_qry_len;
                            curr_mem_usage += num_warp_queries * warp_max_qry_len;
                        }
                        //TODO: We shouldn't simply pass in warp_max_qry_len,
                        // we really ought to pass the real length in, and then add the padding
                        // For now, we are overestimating.
                        curr_mem_usage += bytesNeededOnGPU(warp_max_qry_len, min_match_length);
                        curr_warp_padding += warp_max_qry_len;
#else
                        curr_mem_usage += bytesNeededOnGPU(this_qrylen, min_match_length);
#endif
                    }
                }
                
                if (offsetspos == offsetssize)
                {
                    offsetssize *= 2;
                    offsets = (int *) realloc(offsets, sizeof(int) * offsetssize);
                    lengths = (int *) realloc(lengths, sizeof(int) * offsetssize);
                    if (!offsets || !lengths)
                    {
                        cerr << endl
                        << "ERROR: Realloc failed: requested "
                        << sizeof(int) * offsetssize << endl;
                        exit(1);
                    }
                }
                
                offsets[offsetspos++] = qstringpos;
#if COALESCED_QUERIES
                if ((offsetspos % WARP_SIZE) == 0)
                {
                    warp_max_qry_len = 2;
                }
#endif
                inheader = true;
                
                // Try to walk out of header
                for (i++; i < bytes_read; i++)
                {
                    if (buf[i] == '\n')
                    {
                        inheader = false;
                        char* name = strdup(header.c_str());
                        names.push_back(name);
                        header.clear();
                        break;
                    }
                    else
                    {
                        header.insert(header.end(), buf[i]);
                    }
                }
                
                addChar(&qstring, &qstringsize, &qstringpos, 'q');
                this_qrylen = 0;
            }
            else if (dnachar[b])
            {
                addChar(&qstring, &qstringsize, &qstringpos, b);
                qrylen++;
                this_qrylen++;
            }
            else if (isspace(b))
            {
            
            }
            else if (resetAmbiguity)
            {
                addChar(&qstring, &qstringsize, &qstringpos, 'x');
                this_qrylen++;
            }
            else
            {
                cerr << endl
                << "ERROR: Unexpected character: " << buf[i]
                << " in query file at byte: " << total_read + i << endl;
                exit(1);
            }
        }
        
        if (set_full)
            break;
            
        total_read += bytes_read;
    }
    
    if (qstringpos)
    {
        if (this_qrylen < min_match_length)
        {
            //printf("> %s\n", names.back());
            //if (rc)
            //    printf("> %s Reverse\n", names.back());
            names.pop_back();
            --offsetspos;
            qstringpos -= this_qrylen + 1;
        }
        else
        {
            addChar(&qstring, &qstringsize, &qstringpos, '\0');
            lengths[offsetspos - 1] = this_qrylen;
#if COALESCED_QUERIES
            int num_warp_queries = (offsetspos - 1) % WARP_SIZE;
            if (warp_max_qry_len < this_qrylen + 2)
            {
            
            
                curr_warp_padding -= num_warp_queries * warp_max_qry_len;
                curr_mem_usage -= num_warp_queries * warp_max_qry_len;
                
                warp_max_qry_len = this_qrylen  + 2;
                if (warp_max_qry_len % 4)
                    warp_max_qry_len += 4 - (warp_max_qry_len % 4);
                    
                curr_warp_padding += num_warp_queries * warp_max_qry_len;
                curr_mem_usage += num_warp_queries * warp_max_qry_len;
            }
            curr_mem_usage += bytesNeededOnGPU(warp_max_qry_len, min_match_length);
            curr_warp_padding += warp_max_qry_len;
            
            if ((++num_warp_queries) % WARP_SIZE)
            {
                curr_warp_padding += warp_max_qry_len * (WARP_SIZE - (num_warp_queries % WARP_SIZE));
            }
#else
            curr_mem_usage += bytesNeededOnGPU(this_qrylen, min_match_length);
#endif
            
        }
    }
    
    *numQueries = offsetspos;
    
    if (offsetspos == 0)
    {
        free(offsets);
        free(lengths);
        free(qstring);
        *queryAddrs = NULL;
        *queryTexture = NULL;
        *queryTextureSize = 0;
        *queryNames = NULL;
        
        return;
    }
    
    
    *queryAddrs = offsets;
    
    *queryTexture = qstring;
    *queryTextureSize = qstringpos;
    *queryNames = (char**)malloc(names.size() * sizeof(char*));
    *queryLengths = lengths;
    
    for (unsigned int i = 0; i < *numQueries; ++i)
    {
        *(*queryNames + i) = names[i];
    }
    
    
#if COALESCED_QUERIES
    EventTime_t reorder_timer;
    unsigned int total_reordered_qry_size = 0;
    vector<pair<int*, int> > reordered_query_chunks;
    
    
    for (unsigned int i = 0; i < *numQueries; i += WARP_SIZE)
    {
        int max_qry_len = 0;
        for (unsigned int j = 0; j < WARP_SIZE && (i + j) < *numQueries; ++j)
        {
            if ( max_qry_len < lengths[i + j] )
                max_qry_len = lengths[i + j];
        }
        if (max_qry_len == 0)
        {
            int a = 0;
        }
        max_qry_len += 2;
        unsigned int block_size = WARP_SIZE * (max_qry_len + ((max_qry_len % 4) ? 4 - (max_qry_len % 4) : 0));
        int* reordered_query_chars = (int*)calloc(block_size / sizeof(int), sizeof(int));
        //fprintf (stderr, "reordering block for warp %d\n", i / WARP_SIZE);
        
        for (int curr_char = 0; curr_char < max_qry_len; ++curr_char)
        {
            for (unsigned int curr_qry = 0; curr_qry < WARP_SIZE && (i + curr_qry) < *numQueries; ++curr_qry)
            {
                int qlen = lengths[i + curr_qry] + 2;
                if (curr_qry == 16 && curr_char == 0)
                {
                    int a = 0;
                }
                if (curr_char < qlen)
                {
                    int* qry_word = reordered_query_chars + ((curr_char / 4) * WARP_SIZE + curr_qry);
                    int c = *(qstring + offsets[i + curr_qry] + curr_char);
                    //*((char*) ((void*)qry_word + (curr_char & 0x0000000f) = c;
                    //*qry_word |= c << ((curr_char & 0x0000000f) << (3 - (curr_char & 0x0000000f)));
                    *qry_word |= (c << (8 * ( (curr_char % 4))));
                    //fprintf(stderr, "writing (%d, %d, %d)\n",i, curr_qry, curr_char);
                }
            }
        }
        total_reordered_qry_size += block_size;
        
        reordered_query_chunks.push_back(make_pair<int*, int>(reordered_query_chars, block_size));
    }
    
    free(*queryTexture);
    *queryTexture = (char*)malloc( total_reordered_qry_size );
    *queryTextureSize = total_reordered_qry_size;
    unsigned int p = 0;
    *num_match_coords = 0;
    for (unsigned int i = 0; i < reordered_query_chunks.size(); ++i)
    {
        for (unsigned int j = 0; j < WARP_SIZE && (i*WARP_SIZE + j) < *numQueries; ++j)
        {
            int qryid = i * WARP_SIZE + j;
            offsets[qryid] = (p / 4) + j;
        }
        //*num_match_coords += reordered_query_chunks[i].second - WARP_SIZE * (min_match_length + 1);
        memcpy(*queryTexture + p, reordered_query_chunks[i].first, reordered_query_chunks[i].second);
        p += reordered_query_chunks[i].second;
        
    }
    cerr <<  "Reordering complete. " << reorder_timer.str(true, 5) << endl;
    fprintf(stderr, " curr_warp_padding = %d, total_reordered = %d\n", curr_warp_padding, total_reordered_qry_size);
    //assert (curr_warp_padding == total_reordered_qry_size);
    curr_mem_usage = total_reordered_qry_size;
#else
    
    *num_match_coords = *queryTextureSize - *numQueries * (min_match_length + 1);
#endif
	assert (curr_mem_usage < memory_avail);
    cerr << offsetspos << " queries ("
    << qrylen << " bp), need "
    << curr_mem_usage << " bytes on the GPU ("
    << memory_avail << " avail) "
    << timer.str(true, 5) << endl;
}



struct pathblock
{
    TextureAddress node_addr;
    int string_depth;
};


#define __USE_BUFFERED_IO__ 

static const size_t output_buf_limit = 32*1024;
char output_buf[output_buf_limit];

//FIXME: needs to be reinitialized to zero at the beginning of each round of printing.
size_t bytes_written = 0;

int addToBuffer(char* string)
{
	 size_t buf_length = strlen(string);
	 
	 if (buf_length + bytes_written>= output_buf_limit)
	 {
		size_t chunk = (output_buf_limit - bytes_written - 1);
		strncpy(output_buf + bytes_written, string, chunk);
		output_buf[bytes_written + chunk] = 0;
		printf("%s", output_buf);
		//memset(output_buf, 0, sizeof(output_buf));
		strncpy(output_buf, string + chunk, buf_length - chunk);
		bytes_written = buf_length - chunk;
	 }
	 else
	 {
		strncpy(output_buf + bytes_written, string, buf_length);
		bytes_written += buf_length;
	 }
   return 0;
}

void flushOutput()
{
   if (bytes_written)
   {
	  output_buf[bytes_written] = 0;
	  printf("%s", output_buf);
	  bytes_written  = 0;
   }
	//memset(output_buf, 0, sizeof(output_buf));
   //cerr << "expectedvisit: " << expectedvisit << endl;
   //cerr << "leavesvisited: " << leavesvisited << endl;
   //cerr << "leavesprinted: " << leavesprinted << endl;
}

inline char *itoa(int i, char *a)
{
	char b[24];
	char* c = b;
	while (i / 10 > 0)
	{
		*c = "0123456789"[i % 10];
		++c;
		i /= 10;
	}
	
	*c = "0123456789"[i % 10];
	++c;
	
	while (c > b) {--c; *a = *c; ++a;}
	return a;
}

int addMatchToBuffer(int left_in_ref, int qrypos, int matchlen)
{
	// The ridiculous second term here comes from the maximum number of 
	// characters one might need to express a match to a reference that is 
	// no more than 10 billion bases long, using a MAX_QUERY_LENGTH of 8192,
	// plus whitespace
	if (bytes_written >= output_buf_limit - (12 + 4 + 4 + 4))
	{
		flushOutput();
	}
	
	char* p_buf = output_buf + bytes_written;	
	p_buf = itoa(left_in_ref, p_buf);
	*p_buf = '\t';
	++p_buf;
	p_buf = itoa(qrypos,p_buf);
	*p_buf = '\t';
	++p_buf;
	p_buf = itoa(matchlen,p_buf);
	*p_buf = '\n';
	++p_buf;
	bytes_written +=  p_buf - (output_buf + bytes_written);
}

#define NODE_LENGTH(x)      (page->ref.aux_data[x].length)
#define NODE_PRINTPARENT(x) (page->ref.aux_data[x].printParent)
#define NODE_NUMLEAVES(x)   (page->ref.aux_data[x].numleaves)

#if REORDER_TREE
#define GETNODE(node_addr)     (((PixelOfNode*)    (page->ref.h_node_tex_array))     + (node_addr.x) + (node_addr.y * MAX_TEXTURE_DIMENSION))
#define GETCHILDREN(node_addr) (((PixelOfChildren*)(page->ref.h_children_tex_array)) + (node_addr.x) + (node_addr.y * MAX_TEXTURE_DIMENSION))
#define PADDR(node_addr)        node_addr.x << "," << node_addr.y
#else
#define GETCHILDREN(node_addr) (((PixelOfChildren*)(page->ref.h_children_tex_array)) + (node_addr.x))
#define GETNODE(node_addr)     (((PixelOfNode*)    (page->ref.h_node_tex_array))     + (node_addr.x))
#define PADDR(node_addr)       node_addr.x
#endif

#if MERGETEX

char * getMerged(const ReferencePage * page, TextureAddress cur, int getChildrenData)
{
#if !REORDER_TREE
  bool useChildrenForData = false;

  cur.x *= 2;
  if (cur.x >= (MAX_TEXTURE_DIMENSION*MAX_TEXTURE_DIMENSION))
  {
    useChildrenForData = true;
    cur.x -= MAX_TEXTURE_DIMENSION*MAX_TEXTURE_DIMENSION;
  }
#else
  bool useChildrenForData = cur.x & 0x800;
  cur.x &= 0x7FF;
  cur.x *= 2;
#endif

  cur.x += getChildrenData;

  if (useChildrenForData)
  {
    return (char *) GETCHILDREN(cur);
  }
  else
  {
    return (char *) GETNODE(cur);
  }
}

#define SDEPTH(node_addr)   (((PixelOfNode*)    getMerged(page, node_addr, 0))->depth)
#define PARENT(node_addr)   (((PixelOfNode*)    getMerged(page, node_addr, 0))->parent)

#define LEAFCHAR(node_addr) (((PixelOfChildren*)getMerged(page, node_addr, 1))->leafchar)
#define LEAFID(node_addr)   (((PixelOfChildren*)getMerged(page, node_addr, 1))->leafid)
#define CHILDA(node_addr)   (((PixelOfChildren*)getMerged(page, node_addr, 1))->a)
#define CHILDC(node_addr)   (((PixelOfChildren*)getMerged(page, node_addr, 1))->c)
#define CHILDG(node_addr)   (((PixelOfChildren*)getMerged(page, node_addr, 1))->g)
#define CHILDT(node_addr)   (((PixelOfChildren*)getMerged(page, node_addr, 1))->t)
#define CHILDD(node_addr)   (((PixelOfChildren*)getMerged(page, node_addr, 1))->d)

#else // !MERGETEX

#define SDEPTH(node_addr)   (GETNODE(node_addr)->depth)
#define PARENT(node_addr)   (GETNODE(node_addr)->parent)

#define LEAFCHAR(node_addr) (GETCHILDREN(node_addr)->leafchar)
#define LEAFID(node_addr)   (GETCHILDREN(node_addr)->leafid)
#define CHILDA(node_addr)   (GETCHILDREN(node_addr)->a)
#define CHILDC(node_addr)   (GETCHILDREN(node_addr)->c)
#define CHILDG(node_addr)   (GETCHILDREN(node_addr)->g)
#define CHILDT(node_addr)   (GETCHILDREN(node_addr)->t)
#define CHILDD(node_addr)   (GETCHILDREN(node_addr)->d)

#endif // MERGETEX



char buf[256];

void printNodeAlignments(const ReferencePage* page,
						 const char queryflankingbase, 
						 const TextureAddress node,
						 const int qrypos, 
						 int qrylen,
						 const pathblock path[],
						 int path_idx,
                         bool rc)
{
  char isLeaf = LEAFCHAR(node); 

  if (path[path_idx].node_addr.data == node.data)
  {
	 qrylen = path[path_idx].string_depth;
	 path_idx--;  
  }
  
  if (isLeaf)
  {
     if (isLeaf != queryflankingbase)
     {
       int leafid = MK3(LEAFID(node));
       int left_in_ref = (leafid - 1) + page->begin; 
       int right_in_ref = left_in_ref + qrylen;

       if ((left_in_ref != page->begin || page->shadow_left == -1) && 
           (right_in_ref != page->end || page->shadow_right == -1))
       {
		 if (!(left_in_ref > page->begin && right_in_ref < page->shadow_left))
		 {
		   sprintf(buf, "\t%d\t%d\t%d\n", left_in_ref, qrypos, qrylen);
		   //sprintf(buf, "%8d%10d%10d\n", left_in_ref, qrypos, qrylen);
		   addToBuffer(buf);
		 }
	   }
	 }
  }
  else
  {
    TextureAddress child;

    child = arrayToAddress(CHILDA(node));
    if (child.data) { printNodeAlignments(page, queryflankingbase, child, qrypos, 
                                          qrylen, path, path_idx, rc); }

    child = arrayToAddress(CHILDC(node));
    if (child.data) { printNodeAlignments(page, queryflankingbase, child, qrypos, 
                                          qrylen, path, path_idx, rc); }

    child = arrayToAddress(CHILDG(node));
    if (child.data) { printNodeAlignments(page, queryflankingbase, child, qrypos, 
                                          qrylen, path, path_idx, rc); }

    child = arrayToAddress(CHILDT(node));
    if (child.data) { printNodeAlignments(page, queryflankingbase, child, qrypos, 
                                          qrylen, path, path_idx, rc); }

    child = arrayToAddress(CHILDD(node));
    if (child.data) { printNodeAlignments(page, queryflankingbase, child, qrypos, 
                                          qrylen, path, path_idx, rc); }

  }
}

int expectedvisit = 0;
int leavesvisited = 0;
int leavesprinted = 0;


//FIXME: hardcoded path buffer, needs to be as long as the longest query in the query set.
pathblock path[8192];

char RC(char c)
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



void printAlignmentsOld( ReferencePage* page,
					 char* query, 
                     int qrylen,
					 int nodeid, 
					 int qrypos, 
					 int edge_match, 
					 int min_match,
                     bool rc,
                     bool forwardcoordinates)
{
   TextureAddress node_addr = id2addr(nodeid);
   TextureAddress prev;
   prev.data = 0; 
  
   int path_idx = 0;
   int string_depth = MK3(SDEPTH(node_addr)) - 1;

   if (edge_match > 0)
   {
     string_depth = MK3(SDEPTH(node_addr)) - (NODE_LENGTH(nodeid) - edge_match) - 1;
   }
   else
   {
     edge_match = NODE_LENGTH(nodeid);
   }

   path[path_idx].node_addr = node_addr;
   path[path_idx].string_depth = string_depth;
   path_idx++;
   string_depth -= edge_match;
   prev = node_addr;

   node_addr = arrayToAddress(PARENT(node_addr));
   
   while ((node_addr.data) && string_depth >= min_match)
   {
	  nodeid = addr2id(node_addr);
	  path[path_idx].node_addr = node_addr;
	  path[path_idx].string_depth = string_depth;
	  path_idx++;	
	  string_depth -= NODE_LENGTH(nodeid);	  
	  
	  prev = node_addr;
	  node_addr = arrayToAddress(PARENT(node_addr));
   }
   
   char flankingbase = query[qrypos];

   if (rc)
   {
     flankingbase = RC(query[strlen(query)-qrypos]);
     if (forwardcoordinates) { qrypos = qrylen - 1 - qrypos; }
   }

   printNodeAlignments(page, flankingbase, prev, qrypos + 1, 
   				       MK3(SDEPTH(prev)), path, path_idx - 1, rc);
}

inline char getQueryChar(char* query, int position)
{
#if COALESCED_QUERIES
	int shift = 8 * (position % 4);
    int mask = (0xFF) << shift;
    int c_word = ((int*)query)[(position >> 2) * WARP_SIZE];
//	XPRINTF("c_word = %x, mask = %x\n", c_word, mask);
	return (c_word & mask) >> shift;
#else
	return *(query + position);
#endif	
}

// Stackless printing
void printAlignments(ReferencePage* page,
					 Alignment* h_alignments,
                     char* query,
                     int qrylen,
                     TextureAddress matchNodeAddr,
                     int qrystartpos,
                     int edge_match,
                     int min_match,
                     bool rc,
                     bool forwardcoordinates) 
{
  char queryflankingbase = getQueryChar(query, qrystartpos);
	Alignment* alignments = h_alignments;  
  if (rc) 
  {
    queryflankingbase = RC(query[strlen(query)-qrystartpos]);
    if (forwardcoordinates) { qrystartpos = qrylen - 1 - qrystartpos; }
  }
    
  // Find the top node to start printing from
  TextureAddress cur = matchNodeAddr;
  TextureAddress printParent = cur;
	unsigned int matchNodeId = addr2id(matchNodeAddr);
  int verbose = 0;
    
  if (verbose)
  {
    cout << "query: " << query << endl;
    cout << "starting node: " << PADDR(cur)
         << " depth: " << MK3(SDEPTH(cur)) << endl;
  }

  while (MK3(SDEPTH(cur)) > min_match)
  {
    printParent = cur;
    cur = arrayToAddress(PARENT(cur));

    if (verbose)
    {
      cout << "par: " << PADDR(cur)
           << " depth: " << MK3(SDEPTH(cur)) << endl;
    }
  }

  if (printParent.data != NODE_PRINTPARENT(matchNodeId).data)
  {
    TextureAddress other;
    other.data = NODE_PRINTPARENT(matchNodeId).data;
    
    cout << "printParent ("          << PADDR(printParent) << "):" << MK3(SDEPTH(printParent)) 
         << " != NODE_PRINTPARENT (" << PADDR(other)       << "):" << MK3(SDEPTH(other)) 
         << endl;
        exit(1);
  }
    
  if (verbose)
  {
    cout << "printParent: " << PADDR(printParent) << endl;
  }
    
  expectedvisit += NODE_NUMLEAVES(addr2id(printParent));
    
  // traverse the tree starting at printParent
  TextureAddress badParent = cur;
  cur = printParent;
    
  char curchild = 'A';
  bool forceToParent = false;
    
  int printParentId = addr2id(printParent);
  int matchlen = MK3(SDEPTH(printParent))-1;
  int depthToGoldenPath = 0;
    
    
  // If the printparent is the matchnode, then we are already off the golden path
  if (printParentId == matchNodeId)
  {
    if (edge_match > 0)
    {
      matchlen = MK3(SDEPTH(badParent)) - 1 + edge_match;
    }
        
    depthToGoldenPath = 1;
  }
    
  // keep going until I hit the printParent's parent
  while (cur.data != badParent.data)
  {
    if (verbose)
    {
      cout << " cur: " << PADDR(cur)
           << " curchild: " << curchild << endl;
    }

    char isLeaf = LEAFCHAR(cur);
        
    if (isLeaf || forceToParent)
    {
      // See if I am left maximal and print
      if (isLeaf)
      {
        leavesvisited++;
                
        if (isLeaf != queryflankingbase)
        {
          int leafid = MK3(LEAFID(cur));
          int left_in_ref = (leafid - 1) + page->begin;
          int right_in_ref = left_in_ref + matchlen;
                    
          if ((left_in_ref != page->begin || page->shadow_left == -1) &&
              (right_in_ref != page->end || page->shadow_right == -1))
          {
            if (!(left_in_ref > page->begin && right_in_ref < page->shadow_left))
            {
              leavesprinted++;
	            alignments->left_in_ref = left_in_ref;
	            alignments->matchlen = matchlen;
	            ++alignments;

              if (verbose)
              {
                fprintf(stderr, "%8d%10d%10d\n", left_in_ref, qrystartpos+1, matchlen);
              }
            }
          }
        }
      }
            
      forceToParent = false;
            
      // now return to my parent and advance curchild
      TextureAddress myParent = arrayToAddress(PARENT(cur));

      if      (cur.data == arrayToAddress(CHILDA(myParent)).data) { curchild = 'C'; }
      else if (cur.data == arrayToAddress(CHILDC(myParent)).data) { curchild = 'G'; }
      else if (cur.data == arrayToAddress(CHILDG(myParent)).data) { curchild = 'T'; }
      else if (cur.data == arrayToAddress(CHILDT(myParent)).data) { curchild = '$'; }
      else  // I must be the $ child, go up a level
      {
                forceToParent = true;
      }
            
      cur = myParent;
            
      if (depthToGoldenPath) { depthToGoldenPath--; }
            
      if (depthToGoldenPath == 0)
      {
        matchlen = MK3(SDEPTH(cur)) - 1;
      }
    }
    else
    {
      // try to walk down the tree
            
      char goldenChild = 0;
            
      if (depthToGoldenPath == 0)
      {
        // we are currently on the golden path
        // one of the children is also on the golden path
        goldenChild = query[qrystartpos+matchlen+1];
      }
            
      do
      {
        TextureAddress a;
        if (curchild == 'A')
        {
          a = arrayToAddress(CHILDA(cur));
          if (a.data) { cur = a; break; }
          curchild = 'C';
        }
                
        if (curchild == 'C')
        {
          a = arrayToAddress(CHILDC(cur));
          if (a.data) { cur = a; break; }
          curchild = 'G';
        }
                
        if (curchild == 'G')
        {
          a = arrayToAddress(CHILDG(cur));
          if (a.data) { cur = a; break; }
          curchild = 'T';
        }
                
        if (curchild == 'T')
        {
          a = arrayToAddress(CHILDT(cur));
          if (a.data) { cur = a; break; }
          curchild = '$';
        }
                
        if (curchild == '$')
        {
          a = arrayToAddress(CHILDD(cur));
          if (a.data) { cur = a; break; }
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
            int cid = addr2id(cur);
            matchlen = MK3(SDEPTH(cur))-1;
                        
            if (cid == matchNodeId)
            {
              // we overextended the golden path
              depthToGoldenPath = 1;
                            
              if (edge_match > 0)
              {
                matchlen = MK3(SDEPTH(cur)) - (NODE_LENGTH(cid) - edge_match) - 1;
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

extern "C"
int lookupNumLeaves(ReferencePage * page, TextureAddress addr)
{
	unsigned int nodeid = addr2id(addr);
  	TextureAddress printParent = NODE_PRINTPARENT(nodeid);
	nodeid = addr2id(printParent);
  	return NODE_NUMLEAVES(nodeid);
}

#if 0
struct ExactMatch
{
	ExactMatch(unsigned int lr, unsigned short qs, unsigned short ml) 
		: left_in_ref(lr), qrystartpos(qs), matchlen(ml) {}
		
	unsigned int left_in_ref;
	unsigned short qrystartpos;
	unsigned short matchlen;
};

struct EMSortByRefPos
{
	bool operator()(const ExactMatch& lhs, const ExactMatch& rhs)
	{
		return lhs.left_in_ref < rhs.left_in_ref;
	}
};

void align(const string & S, 
           const string & T,
           int match_score,
           int mismatch_score,
           int gap_open,
		int gap_extension);

static const int MAX_MISMATCH = 4;
void mapQueryEndToEnd(MatchContext* ctx, vector<ExactMatch>& ems, unsigned int qry)
{
	sort(ems.begin(), ems.end(), EMSortByRefPos());
	vector<unsigned int> candidate_alignments;

	unsigned int length = ctx->queries->h_lengths_array[qry];
	unsigned int min_bases_covered = 2 * ctx->min_match_length;
	if (string(*(ctx->queries->h_names + qry)) == "rid754")
	{
		int a = 5;
	}
	
	for (int i = 0; i < (int)(ems.size() - 1); ++i)
	{
		if (candidate_alignments.size() && 
			(ems[i].left_in_ref - length > ems[candidate_alignments.back()].left_in_ref))
			continue;
		
		unsigned int j = i;
		unsigned int left_ref = ems[j].left_in_ref;
		unsigned int right_ref = left_ref + ems[j].matchlen;

		unsigned int leftmost_qrypos = ems[i].qrystartpos;
		unsigned int rightmost_qrypos = leftmost_qrypos + ems[i].matchlen;
		do {
			if (rightmost_qrypos - leftmost_qrypos >= min_bases_covered)
			{
				candidate_alignments.push_back(i);
				break;
			}
			++j;
			right_ref = ems[j].left_in_ref + ems[j].matchlen;
			unsigned int right_qpos = ems[j].qrystartpos + ems[j].matchlen;
			if (right_qpos > rightmost_qrypos)
				rightmost_qrypos = right_qpos;
		} while(right_ref - left_ref < length && j < ems.size());
	}
	for(unsigned int i = 0; i < candidate_alignments.size(); ++i)
	{
		char refstr[2 * (MAX_QUERY_LEN + MAX_MISMATCH)];
		memset(refstr, 0, sizeof(refstr));
		ExactMatch& m = ems[candidate_alignments[i]];
		strncpy(refstr, 
				ctx->ref->str + m.left_in_ref - m.qrystartpos - MAX_MISMATCH, 
				2 * (length + MAX_MISMATCH));
		char* qrystr = ctx->queries->h_tex_array + ctx->queries->h_addrs_tex_array[qry];
		align(string(refstr), string(qrystr), 10, -2, -2, -2);
	}
	// addToBuffer("> ");
	// addToBuffer(*(ctx->queries->h_names + qry));
	// addToBuffer("\n");
	// char buf[256];
	// sprintf(buf, "%d candidate matches\n", candidate_alignments.size());
	// addToBuffer(buf);
	// for (int i = 0; i < (int)(ems.size() - 1); ++i)
	// {	if (find(candidate_alignments.begin(), candidate_alignments.end(), i) != candidate_alignments.end())
	// 	{
	// 		sprintf(buf, "%8d%10d%10d\t****\n",
	// 		       ems[i].left_in_ref,
	// 		       ems[i].qrystartpos + 1,
	// 		       ems[i].matchlen);
	// 
	// 	}
	// 	else
	// 	{
	// 		sprintf(buf, "%8d%10d%10d\n",
	// 		       ems[i].left_in_ref,
	// 		       ems[i].qrystartpos + 1,
	// 		       ems[i].matchlen);
	// 	}
	// 	addToBuffer(buf);
	//}
	
	//flushOutput();
}

extern "C"
void mapQueriesEndToEnd(MatchContext* ctx,
                        ReferencePage* page,
                        MatchInfo* h_matches,
                        unsigned int numMatches,
                        Alignment* h_alignments,
                        unsigned int numAligments)
{
    int lastqry = -1;
	vector<ExactMatch> ems;
    for (int m = 0; m < numMatches; m++)
    {
        if (h_matches[m].queryid != lastqry)
        {
			if (lastqry != -1)
				mapQueryEndToEnd(ctx, ems, lastqry);
			ems.clear();
			
            lastqry = h_matches[m].queryid;
            // addToBuffer("> ");
            // addToBuffer(*(ctx->queries->h_names + lastqry));
            // addToBuffer("\n");
			if (string(*(ctx->queries->h_names + lastqry)) == "rid754")
			{
				int a = 5;
			}
        }
        
        int base = h_matches[m].resultsoffset;

        for (int i = 0; i < h_matches[m].numLeaves; i++)
        {
            // See if there are any more left maximal alignments for this match
            if (h_alignments[base+i].left_in_ref == 0)
            {
                break;
            }
            ems.push_back(ExactMatch(h_alignments[base+i].left_in_ref,
            					     h_matches[m].qrystartpos + 1,
									 h_alignments[base+i].matchlen));
			
        }
    }
}
#endif
