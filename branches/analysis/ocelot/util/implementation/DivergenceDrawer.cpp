/*
 * DivergenceDrawer.cpp
 *
 *  Created on: Jul 1, 2010
 *      Author: Diogo Sampaio
 */

#include <fstream>
#include <assert.h>
#include <ocelot/graphs/interface/DivergenceDrawer.h>
#include <ocelot/graphs/interface/DirectionalGraph.h>

namespace graph_utils {
static const string FULLGRAPH_ALIVE_OUT = "aliveOut";
static const string FULLGRAPH_PHI = "phi";
static const string FULLGRAPH_INSTRUCTION = "instruction";

using analysis::DataflowGraph;
using analysis::DivergenceAnalysis;

/*!\brief Tests divAnalysis pointer for avoir null access and if the kernel name is not empty, for knowing prefix for output files */
inline void DivergenceDrawer::_sanityTest() const{
	assert(!_kernelName.empty() && (divAnalysis != NULL));
}

/*!\brief Draw edges from the block predecessor to it, and in the (D+C)FG edges inside the block from aliveIn to phis or instructions, and isntructions to aliveOut */
inline string DivergenceDrawer::_edges( const analysis::DataflowGraph::Block &block, const bool isFullGraph ) const{
	stringstream buff;
	const DataflowGraph::BlockPointerSet predecessors = block.predecessors();
	DataflowGraph::BlockPointerSet::const_iterator predecessor = predecessors.begin();
	DataflowGraph::BlockPointerSet::const_iterator endPredecessor = predecessors.end();
	string thisBlockName, predecessorName;

	thisBlockName = block.label();
	if( thisBlockName[0] == '$' ){
		thisBlockName = &thisBlockName[1];
	}

	for( ; predecessor != endPredecessor; predecessor++ ){
		predecessorName = (*predecessor)->label();
		if( predecessorName[0] == '$' ){
			predecessorName = &predecessorName[1];
		}

		if( isFullGraph ){
			if( predecessorName != "entry" ){
				predecessorName += FULLGRAPH_ALIVE_OUT;
			}
		}

		buff << predecessorName << "->" << thisBlockName;

		if( ((*predecessor)->block()->has_fallthrough_edge()) && ((*predecessor)->fallthrough()->label() == block.label()) ){
			buff << " [color = \"blue\"]";
		}

		buff << ';';
	}

	if( isFullGraph && ((thisBlockName != "entry") && (thisBlockName != "exit")) ){
		if( block.phis().empty() ){
			buff << thisBlockName << "->" << thisBlockName << FULLGRAPH_INSTRUCTION << ":in;";
		}else{
			buff << thisBlockName << FULLGRAPH_PHI << ":out->" << thisBlockName << FULLGRAPH_INSTRUCTION << ":in;";
		}
		buff << thisBlockName << FULLGRAPH_INSTRUCTION << "->" << thisBlockName << FULLGRAPH_ALIVE_OUT << ';';
	}

	return buff.str();
}
/*!\brief Draw the variables dependency graph */
void DivergenceDrawer::drawVariablesGraph() const{
	_sanityTest();
	string fileName = _path + "prof." + _kernelName + "_dataFlow.dot";
	std::ofstream file(fileName.c_str());

	if( file.is_open() != true ){
		cerr << "Coldn't open file " + fileName + " for writing.";
		return;
	}

	file << (DirectionalGraph)(divAnalysis->getDivergenceGraph());
	file.close();
}

/*!\brief Draw the divergence spread graph */
void DivergenceDrawer::drawDivergenceGraph() const{
	_sanityTest();
	const string fileName = _path + "prof." + _kernelName + "_divergenceFlow.dot";
	std::ofstream file(fileName.c_str());

	if( file.is_open() != true ){
		cerr << "Coldn't open file " + fileName + " for writing.";
		return;
	}

	file << divAnalysis->getDivergenceGraph();
	file.close();
}

/*!\brief Draw the CFG, can draw comparison statistics to profiling results */
void DivergenceDrawer::drawControlFlowGraph() const{
	_sanityTest();
	map<DataflowGraph::RegisterId, string> registersLocations;

	DataflowGraph::const_iterator block = divAnalysis->getDFG()->begin();
	DataflowGraph::const_iterator endBlock = divAnalysis->getDFG()->end();

	std::ofstream file(_path + "prof." + _kernelName + "_controlFlow.dot");

	if( !file.is_open() ){
		cerr << "Couldn't open file '" + _path + "prof." + _kernelName + "_controlFlow.dot' for writing";
		return;
	}

	file << "digraph ControlGraphDivergenceAnalysis{";
	stringstream edgesDot;
	for( ; block != endBlock; block++ ){

		string blockLabel = block->label();

		if( blockLabel == "entry" ){
			file << blockLabel << "[shape=Mdiamond,style=\"filled\",color=\"white\",fillcolor=\"black\",fontcolor=\"white\",label=\"Entry\"];";
			continue;
		}

		if( blockLabel == "exit" ){
			file << blockLabel << "[shape=Mdiamond,style=\"filled\",color=\"white\",fillcolor=\"black\",fontcolor=\"white\",label=\"Exit\"];";
			edgesDot << _edges(*block);
			continue;
		}

		const DataflowGraph::InstructionVector instructions = block->instructions();
		DataflowGraph::InstructionVector::const_iterator instruction = instructions.begin();
		DataflowGraph::InstructionVector::const_iterator endInstruction = instructions.end();

		if( instruction == endInstruction ){
			cerr << "*****************Empty Block: " << block->label() << " N:" << block->id() << endl;
			continue;
		}

		string bgcolor = "white";
		bool predDivergence = divAnalysis->isDivBlock(block);

		if( predDivergence ){
			bgcolor = "tomato";
		}

		if( blockLabel[0] == '$' ){
			blockLabel = &blockLabel[1];
		}

		file << blockLabel
		    << "[shape=none, margin=0, label=<<TABLE BORDER=\"0\" CELLBORDER=\"1\" CELLSPACING=\"0\" CELLPADDING=\"1\" WIDTH=\"600\"><TR><TD COLSPAN=\"2\" BGCOLOR=\"" << bgcolor
		    << "\">" << block->label() << "</TD></TR>";

		for( ; instruction != endInstruction; instruction++ ){
			file << "<TR><TD COLSPAN=\"2\" WIDTH=\"600\"";

			if( divAnalysis->isDivInstruction(*instruction) ){
				file << " BGCOLOR=\"tomato\"";
			}

			file << ">" << instruction->label << "</TD></TR>" << endl;
		}
		file << "</TABLE>>];" << endl;

		edgesDot << _edges(*block);
	}
	file << edgesDot.str() << "legend [shape=none, margin=0, label=<<TABLE BORDER=\"0\" CELLBORDER=\"1\" CELLSPACING=\"0\" CELLPADDING=\"1\">"
	    << "<TR><TD COLSPAN=\"3\"><B>LEGEND</B></TD></TR>" << "<TR><TD><FONT COLOR=\"blue\">blue edges</FONT></TD><TD COLSPAN=\"2\">fallthrough path</TD></TR>"
	    << "<TR><TD>black edges</TD><TD COLSPAN=\"2\">branch path</TD></TR>"
	    << "<TR><TD BGCOLOR=\"tomato\">light red instruction</TD><TD COLSPAN=\"2\">divergent instruction</TD></TR>"
	    << "<TR><TD BGCOLOR=\"tomato\">block label</TD><TD COLSPAN=\"2\">Divergent block prediction"
	    << "</TD></TR></TABLE>>];};";
	file.close();
}

/*!\brief Draw the (D+C)FG, can draw comparison statistics to profiling results */
void DivergenceDrawer::drawFullGraph() const{
	_sanityTest();
	map<DataflowGraph::RegisterId, string> registersLocations;
	DataflowGraph::const_iterator block = divAnalysis->getDFG()->begin();
	DataflowGraph::const_iterator endBlock = divAnalysis->getDFG()->end();
	const graph_utils::DivergenceGraph &divergenceGraph = divAnalysis->getDivergenceGraph();

	std::ofstream file(std::string(_path + "prof." + _kernelName + "_fullDFG.dot").c_str());
	if( !file.is_open() ){
		cerr << "Couldn't open file '" + _path + "prof." + _kernelName + "_fullDFG.dot' for writing";
		return;
	}

	file << "digraph fullDFG{";

	stringstream edgesDot;
	string blockName = "";
	for( ; block != endBlock; block++ ){
		string blockLabel = block->label();
		if( blockLabel[0] == '$' ){
			blockLabel = blockLabel.substr(1, blockLabel.size());
		}

		if( blockLabel == "entry" ){
			file << block->label()
			    << "[shape=Mdiamond,style=\"filled\",color=\"white\",fillcolor=\"black\",fontcolor=\"white\",label=\"Entry\"];";
			continue;
		}

		if( blockLabel == "exit" ){

			file << block->label()
			    << "[shape=Mdiamond,style=\"filled\",color=\"white\",fillcolor=\"black\",fontcolor=\"white\",label=\"Exit\"];";
			edgesDot << _edges(*block, true);
			continue;
		}

		stringstream blockLabelCOLSPAN;

		/* Print blocklabel + alive in table */
		if( block->aliveIn().size() > 1 ){
			blockLabelCOLSPAN << " COLSPAN=\"" << block->aliveIn().size() << '"';
		}

		file << "subgraph cluster" << blockLabel << "{" << blockLabel
		    << "[shape=none,margin=0,label=<<TABLE BORDER=\"0\" CELLBORDER=\"1\" CELLSPACING=\"0\" CELLPADDING=\"1\"><TR><TD" << blockLabelCOLSPAN.str();

		if( divAnalysis->isDivBlock(block) ){
			file << " BGCOLOR=\"tomato\"";
		}

		file << '>' << block->label() << "</TD></TR>";

		if( block->aliveIn().size() > 0 ){
			file << "<TR><TD" << blockLabelCOLSPAN.str() << ">AliveIn</TD></TR>";

			set<DataflowGraph::RegisterId> orderedAliveIn;
			{
				DataflowGraph::Block::RegisterSet::const_iterator aliveIn = block->aliveIn().begin();
				DataflowGraph::Block::RegisterSet::const_iterator endAliveIn = block->aliveIn().end();

				for( ; aliveIn != endAliveIn; aliveIn++ ){
					orderedAliveIn.insert(aliveIn->id);
				}
			}

			file << "<TR>";
			/* Print alive in in same order of phi sources */
			if( block->phis().size() > 0 ){
				DataflowGraph::PhiInstructionVector::const_iterator phi = block->phis().begin();
				DataflowGraph::PhiInstructionVector::const_iterator endPhi = block->phis().end();

				for( ; phi != endPhi; phi++ ){
					DataflowGraph::RegisterVector::const_iterator phiS = phi->s.begin();
					DataflowGraph::RegisterVector::const_iterator endPhiS = phi->s.end();

					for( ; phiS != endPhiS; phiS++ ){
						assert(orderedAliveIn.find(phiS->id) != orderedAliveIn.end());
						file << "<TD PORT=\"" << phiS->id << '"';

						if( divergenceGraph.isDivNode(phiS->id) ){
							file << " BGCOLOR=\"tomato\"";
						}

						file << '>' << phiS->id << "</TD>";

						orderedAliveIn.erase(phiS->id);
					}
				}
			}
			/* Print the remaining alive in */
			set<DataflowGraph::RegisterId>::const_iterator aliveIn = orderedAliveIn.begin();
			set<DataflowGraph::RegisterId>::const_iterator endAliveIn = orderedAliveIn.end();
			for( ; aliveIn != endAliveIn; aliveIn++ ){
				file << "<TD PORT=\"" << *aliveIn << '"';

				if( divergenceGraph.isDivNode(*aliveIn) ){
					file << " BGCOLOR=\"tomato\"";
				}

				file << '>' << *aliveIn << "</TD>";
			}
			file << "</TR>";

		}

		/* Print alive out table */
		file << "</TABLE>>];" << blockLabel << FULLGRAPH_ALIVE_OUT << "[shape=none,margin=0,label=<<TABLE BORDER=\"0\" CELLBORDER=\"1\" CELLSPACING=\"0\" CELLPADDING=\"1\">";
		if( block->aliveOut().size() > 0 ){

			set<DataflowGraph::RegisterId> orderedAliveOut;
			{
				DataflowGraph::Block::RegisterSet::const_iterator aliveOut = block->aliveOut().begin();
				DataflowGraph::Block::RegisterSet::const_iterator endAliveOut = block->aliveOut().end();

				for( ; aliveOut != endAliveOut; aliveOut++ ){
					orderedAliveOut.insert(aliveOut->id);
				}
			}

			set<DataflowGraph::RegisterId>::const_iterator aliveOut = orderedAliveOut.begin();
			set<DataflowGraph::RegisterId>::const_iterator endAliveOut = orderedAliveOut.end();

			file << "<TR>";
			for( ; aliveOut != endAliveOut; aliveOut++ ){
				string bgColor = "";
				file << "<TD";

				const DataflowGraph::Block::RegisterSet& aliveIn = block->aliveIn();
				const DataflowGraph::Block::RegisterSet::const_iterator ai = aliveIn.find(*aliveOut);

				if( divergenceGraph.isDivNode(*aliveOut) ){
					file << " BGCOLOR=\"tomato\"";
				}else if( ai != aliveIn.end() ){
					file << " BGCOLOR=\"lightgreen\"";
				}

				file << '>' << *aliveOut << "</TD>";
			}
			file << "</TR>";
		}

		file << "<TR><TD";

		if( block->aliveOut().size() > 1 ){
			file << " COLSPAN=\"" << block->aliveOut().size() << '"';
		}

		file << ">AliveOut</TD></TR></TABLE>>];";

		/* Print instructions */
		const DataflowGraph::InstructionVector instructions = block->instructions();
		DataflowGraph::InstructionVector::const_iterator instruction = instructions.begin();
		DataflowGraph::InstructionVector::const_iterator endInstruction = instructions.end();

		file << blockLabel << FULLGRAPH_INSTRUCTION
		    << "[shape=none,margin=0,label=<<TABLE BORDER=\"0\" CELLBORDER=\"1\" CELLSPACING=\"0\" CELLPADDING=\"1\"><TR><TD WIDTH=\"60px\">Out<br/>Regs</TD><TD WIDTH=\"580px\" PORT=\"in\">Instruction</TD><TD WIDTH=\"60px\">In<br/>Regs</TD></TR>";

		for( ; instruction != endInstruction; instruction++ ){
			unsigned int totalLines = 1;
			unsigned int insColSpan = 1;
			stringstream sRowSpan;
			stringstream dRowSpan;
			stringstream insSpan;

			DataflowGraph::RegisterPointerVector::const_iterator sReg = instruction->s.begin();
			DataflowGraph::RegisterPointerVector::const_iterator endSReg = instruction->s.end();

			DataflowGraph::RegisterPointerVector::const_iterator dReg = instruction->d.begin();
			DataflowGraph::RegisterPointerVector::const_iterator endDReg = instruction->d.end();

			if( instruction->d.size() > 1 ){
				totalLines = instruction->d.size();
			}

			if( (instruction->s.size() > 1) && (instruction->s.size() != totalLines) ){
				totalLines *= instruction->s.size();
			}

			if( dReg != endDReg ){
				if( (instruction->d.size() != totalLines) && (totalLines > 1) ){
					dRowSpan << " ROWSPAN=\"" << totalLines / instruction->d.size() << '"';
				}
			}else{
				insColSpan++;
			}

			if( sReg != endSReg ){
				if( (instruction->s.size() != totalLines) && (totalLines > 1) ){
					sRowSpan << " ROWSPAN=\"" << totalLines / instruction->s.size() << '"';
				}
			}else{
				insColSpan++;
			}

			if( totalLines > 1 ){
				insSpan << " ROWSPAN=\"" << totalLines << '"';
			}

			if( insColSpan > 1 ){
				insSpan << " COLSPAN=\"" << insColSpan << '"';
			}

			/* Print the first instruction line, with the instruction label */
			file << "<TR>";
			if( dReg != endDReg ){
				file << "<TD" << dRowSpan.str();

				if( divergenceGraph.isDivNode(*dReg->pointer) ){
					file << " BGCOLOR=\"tomato\"";
				}

				file << '>' << *dReg->pointer << "</TD>";
				dReg++;
			}

			file << "<TD" << insSpan.str();

			if( divAnalysis->isDivInstruction(*instruction) ){
				file << " BGCOLOR=\"tomato\"";
			}

			file << '>' << instruction->label << "</TD>";

			if( sReg != endSReg ){
				file << "<TD" << sRowSpan.str();

				if( divergenceGraph.isDivNode(*sReg->pointer) ){
					file << " BGCOLOR=\"tomato\"";
				}

				file << '>' << *sReg->pointer << "</TD>";
				sReg++;
			}

			file << "</TR>";
			/* print lines with destiny or source register */
			while( (sReg != endSReg) || (dReg != endDReg) ){
				file << "<TR>";
				if( dReg != endDReg ){
					file << "<TD" << dRowSpan.str();

					if( divergenceGraph.isDivNode(*dReg->pointer) ){
						file << " BGCOLOR=\"tomato\"";
					}

					file << '>' << *dReg->pointer << "</TD>";
					dReg++;
				}

				if( sReg != endSReg ){
					file << "<TD" << sRowSpan.str();

					if( divergenceGraph.isDivNode(*sReg->pointer) ){
						file << " BGCOLOR=\"tomato\"";
					}

					file << '>' << *sReg->pointer << "</TD>";
					sReg++;
				}

				file << "</TR>";
			}
		}

		file << "</TABLE>>];";

		/* Print phi instructions */
		if( block->phis().size() > 0 ){
			unsigned int totalSources = 0;
			stringstream secondLine;

			file << blockLabel << FULLGRAPH_PHI << "[shape=none,margin=0,label=<<TABLE BORDER=\"0\" CELLBORDER=\"1\" CELLSPACING=\"0\" CELLPADDING=\"1\"><TR>";

			DataflowGraph::PhiInstructionVector::const_iterator phi = block->phis().begin();
			DataflowGraph::PhiInstructionVector::const_iterator endPhi = block->phis().end();

			for( ; phi != endPhi; phi++ ){
				DataflowGraph::RegisterVector::const_iterator phiS = phi->s.begin();
				DataflowGraph::RegisterVector::const_iterator endPhiS = phi->s.end();

				for( ; phiS != endPhiS; phiS++ ){
					file << "<TD PORT=\"" << phiS->id << "\"";

					edgesDot << blockLabel << ":" << phiS->id << "->" << blockLabel << FULLGRAPH_PHI << ":" << phiS->id;
					if( divergenceGraph.isDivNode(phiS->id) ){
						file << " BGCOLOR=\"tomato\"";
						edgesDot << "[color=tomato]";
					}
					edgesDot << ';';
					file << '>' << phiS->id << "</TD>";
				}
				secondLine << "<TD COLSPAN=\"" << phi->s.size() << '"';

				if( divergenceGraph.isDivNode(phi->d.id) ){
					secondLine << " BGCOLOR=\"tomato\"";
				}
				secondLine << '>' << phi->d.id << "</TD>";
				totalSources += phi->s.size();
			}

			file << "</TR><TR>" << secondLine.str() << "</TR><TR><TD COLSPAN=\"" << totalSources << "\" PORT=\"out\">Phis</TD></TR></TABLE>>];";

		}
		/*subgraph end*/
		file << '}';

		edgesDot << _edges(*block, true);
	}
	file << endl << edgesDot.str();
	file << "}";
	file.close();
}

/* Draws every graph to be printed */
void DivergenceDrawer::draw() const{
	_sanityTest();

	if( _divergence ){
		drawDivergenceGraph();
	}

	if( _vars ){
		drawVariablesGraph();
	}

	if( _cfg ){
		drawControlFlowGraph();
	}

	if( _dfg ){
		drawFullGraph();
	}
}

/* Constructor that sets everything and make it ready to draw, sets profiling on being able to read the profiling results */
DivergenceDrawer::DivergenceDrawer( const string &kernelName, const string &path, analysis::DivergenceAnalysis *divergenceAnalysis,
		const bool &allGraphs, const bool &divergenceGraph, const bool &varsGraph, const bool &dfgGraph, const bool &cfgGraph) :
		_kernelName(kernelName), _path(path), divAnalysis(divergenceAnalysis), _all(allGraphs), _divergence(divergenceGraph), _vars(varsGraph), _dfg(dfgGraph),
		_cfg(cfgGraph)
{
	if( _all ){
		_divergence = true;
		_vars = true;
		_dfg = true;
		_cfg = true;
	}
}

/* Constructor that accepts less variables, and sets profiling on being able to read the profiling results */
DivergenceDrawer::DivergenceDrawer( const string &kernelName, const string &path, analysis::DivergenceAnalysis *divergenceAnalysis, const bool &allGraphs ){
	if( _all ){
		_divergence = true;
		_vars = true;
		_dfg = true;
		_cfg = true;
	}
}
}
