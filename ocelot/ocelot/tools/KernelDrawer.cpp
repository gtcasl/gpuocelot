#include <ocelot/ir/interface/PTXKernel.h>
#include <ocelot/transforms/interface/PassManager.h>
#include <ocelot/transforms/interface/KernelDrawerPass.h>
#include <set>
#ifndef _WIN32
#include <unistd.h>
#endif
/* This application generates control, data / divergence flow graphs on dot language for a input ptx file */
void help(const string name){
  cerr << endl << "Kernel Drawer Help" << endl
      << "Prints kernel graphs in dot format to output path, and csv results to console"
      << endl << endl << "\tProgram usage: "
      << name.substr(name.find_last_of('/') + 1, name.size()) << " -[arcfdv12DP] [-s SSA_FORM] [-i | (-o OUTPUT_PATH)] PTX_FILE1 [PTX_FILE2...N]"
      << endl << endl << "\tArguments:" << endl
      << "\t\t-a\t\tEnable all graphs and analysis options" << endl
      << "\t\t-r\t\tConsole printing of analysis results [comparison] in csv format" << endl
      << "\t\t-c\t\tPrints control flow graph" << endl
      << "\t\t-f\t\tPrints graph showing data & control flow" << endl
      << "\t\t-d\t\tPrints divergence analysis propagation graph, sets SSA to gssa" << endl
      << "\t\t-v\t\tPrints divergence analysis data dependency graph, sets SSA to gssa" << endl
      << "\t\t-1\t\tUse divergence analysis to print results and colors, sets SSA to gssa" << endl
      << "\t\t-1\t\tUse affine divergence analysis to print results and colors, sets SSA to gssa" << endl
      << "\t\t-D\t\tDisplay immediate dominator blocks informations on graphs" << endl
      << "\t\t-P\t\tDisplay immediate post-dominator blocks informations on graphs" << endl
      << "\t\t-o\t\tOutput directory of graphs of all dot graph files. If none is provided and -i not used, default is current path" << endl
      << "\t\t-i\t\tUse input path as output path" << endl
      << "\t\t-s\t\tSelects SSA form, options are:" << endl
      << "\t\t\t\t\t\tnone\t\tNot in SSA form" << endl
      << "\t\t\t\t\t\tssa\t\tDefault ocelot's SSA form" << endl
      << "\t\t\t\t\t\tmssa\t\tMinimalist SSA form" << endl
      << "\t\t\t\t\t\tgssa\t\tGated SSA form" << endl;
}

int main(int argc, char* argv[]) {
  using namespace std;
  using namespace analysis;
  using namespace transforms;

//  opterr = 0;

  std::set<string> ptxFilenames;
  string outPath;
  string ssa;

  char c;
  unsigned todo = 0;
  unsigned a = Analysis::Type::DataflowGraphAnalysis;
  bool i = false, o = false;
#ifdef _WIN32
  printf("Command line options not supported on Windows\n");
  // 'getopt' does not exist in regular Windows (VC) headers
#else
  while((c = getopt(argc, argv, "s:o:arcfdv12DPih")) != -1){
    switch(c){
      case 'o':
        outPath = string(optarg);
        o = true;
      break;
      case 'a':
        todo = KernelDrawerPass::TODO::all;
        a |= (unsigned) (Analysis::Type::DivergenceAnalysis) | (unsigned) (Analysis::Type::AffineAnalysis);
        ssa = "gssa";
      break;
      case 'r': todo |= KernelDrawerPass::TODO::results; break;
      case 'c': todo |= KernelDrawerPass::TODO::cfgGraph; break;
      case 'f': todo |= KernelDrawerPass::TODO::fullGraph; break;
      case 'd': todo |= KernelDrawerPass::TODO::divGraph; break;
      case 'v': todo |= KernelDrawerPass::TODO::varsGraph; break;
      case '1': a |= Analysis::Type::DivergenceAnalysis; break;
      case '2': a |= Analysis::Type::AffineAnalysis; break;
      case 'D': a |= Analysis::Type::DominatorTreeAnalysis; break;
      case 'P': a |= Analysis::Type::PostDominatorTreeAnalysis; break;
      case 's': ssa = string(optarg); break;
      case 'i': i = true; break;
      case 'h': help(argv[0]); return 0; break;
      default: break;
    }
  }
  while(optind < argc){
    ptxFilenames.insert((argv[optind]));
    optind++;
  }
#endif // #ifndef _WIN32

  if(i & o){
    help(argv[0]);
    cerr << "Error: Can't use -i and -o at the same time" << endl;
    return(EXIT_FAILURE);
  }

  if(!(i | o)){
    o = true;
    outPath = "";
  }else if(o && (outPath != "")){
    if(outPath.find_last_of('/') != outPath.size()){
      outPath += '/';
    }
  }

  if(ptxFilenames.empty()){
    help(argv[0]);
    cerr << "Error: No input ptx file(s)" << endl;
    return(EXIT_FAILURE);
  }

  if(!todo){
    help(argv[0]);
    cerr << "Error: No graph/results selected[arcfdv]" << endl;
    return(EXIT_FAILURE);
  }

  if(todo & (KernelDrawerPass::TODO::divGraph | KernelDrawerPass::TODO::varsGraph)){
    a |= Analysis::Type::DivergenceAnalysis;
  }

  if (a & (Analysis::Type::DivergenceAnalysis | Analysis::Type::AffineAnalysis)){
    ssa = "gssa";
  }

  if(ssa == "mssa"){
    a |= Analysis::Type::MinimalStaticSingleAssignment;
  }else if(ssa == "gssa"){
    a |= Analysis::Type::GatedStaticSingleAssignment;
  }else if(ssa == "ssa"){
    a |= Analysis::Type::StaticSingleAssignment;
  }

  while(!ptxFilenames.empty()){
    string ptxFile = *ptxFilenames.begin();
    if(i){
      if(ptxFile.find('/') != string::npos){
        outPath = ptxFile.substr(0, 1 + ptxFile.find_last_of('/'));
      }else{
        outPath = "./";
      }
    }

    ir::Module module(ptxFile);
    PassManager manager(&module);
    KernelDrawerPass kdp(outPath, todo, a);
    manager.addPass((Pass&) (kdp));
    manager.runOnModule();
    ptxFilenames.erase(ptxFilenames.begin());
  }
  return EXIT_SUCCESS;
}
