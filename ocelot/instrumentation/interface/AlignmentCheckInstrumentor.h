/*! \file AlignmentCheckInstrumentor.h
    \date Monday Sept 26, 2011
    \author Si Li
    \brief The header file for AlignmentCheckInstrumentor
*/

#ifndef ALIGNMENT_CHECK_INSTRUMENTOR_H_INCLUDED
#define ALIGNMENT_CHECK_INSTRUMENTOR_H_INCLUDED

#include <string>
#include <ocelot/ir/interface/Module.h>
#include <ocelot/instrumentation/interface/PTXInstrumentor.h>
#include <ocelot/transforms/interface/Pass.h>

namespace instrumentation
{
    /*! \brief Able to run the alignment check instrumentation passes over PTX modules */
    class AlignmentCheckInstrumentor : public PTXInstrumentor
    {
        public:
            
            enum InstrumentationType {
                alignmentCheck,
                raceDetection
            };        

            InstrumentationType type;

            /*! \brief The counter */
            size_t *counter;        

            /*! \brief The description of the specified pass */
            std::string description;
            
            //unsigned int threads;
            
            unsigned int entries;
            
        public:
            /*! \brief The default constructor */
            AlignmentCheckInstrumentor();

            /*! \brief The checkConditions method verifies that the defined conditions are met for this instrumentation */
            void checkConditions();

            /*! \brief The analyze method performs any necessary static analysis */
            virtual void analyze(ir::Module &module){}
            
            virtual void analyze(ir::Module &module, const executive::Device &device);
            
            /*! \brief The initialize method performs any necessary CUDA runtime initialization prior to instrumentation */
            void initialize();

            /*! \brief The createPasses method instantiates the instrumentation passes */
            void createPasses();

            /*! \brief The finalize method performs any necessary CUDA runtime actions after instrumentation */
            void finalize();    

            /*! \brief extracts results for the instrumentation */
            void extractResults(std::ostream *out);
    };

}

#endif
