/*! \file LLVMWorkerThread.cpp
	\date Friday September 24, 2010
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The source file for the LLVMWorkerThread class.
*/

#ifndef LLVM_WORKER_THREAD_CPP_INCLUDED
#define LLVM_WORKER_THREAD_CPP_INCLUDED

// Ocelot Includes
#include <ocelot/executive/interface/LLVMWorkerThread.h>
#include <ocelot/executive/interface/LLVMCooperativeThreadArray.h>
#include <ocelot/executive/interface/LLVMModuleManager.h>
#include <ocelot/executive/interface/LLVMExecutableKernel.h>

// Hydrazine Includes
#include <hydrazine/implementation/debug.h>

// Preprocessor Defines
#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 1

namespace executive
{

class WorkerMessage
{
public:
	enum Type
	{
		Kill,
		SetupCta,
		LaunchCta,
		Invalid,
	};
	
public:
	Type type;

public:
	union
	{
		unsigned int ctaId;
		const LLVMExecutableKernel* kernel;
	};
};

LLVMWorkerThread::LLVMWorkerThread()
{
	report("Creating new LLVM Worker Thread");
	start();
}

LLVMWorkerThread::~LLVMWorkerThread()
{
	WorkerMessage message;
	message.type = WorkerMessage::Kill;
	send(&message);

	WorkerMessage* reply;
	receive(reply);
	assert(reply == &message);
	report("Tearing down LLVM Worker Thread " << id());
}

void LLVMWorkerThread::setupCta(const LLVMExecutableKernel& kernel)
{
	WorkerMessage message;
	message.type = WorkerMessage::SetupCta;
	message.kernel = &kernel;
	
	send(&message);
	
	WorkerMessage* reply;
	receive(reply);
	assert(reply == &message);
}

void LLVMWorkerThread::launchCta(unsigned int ctaId)
{
	WorkerMessage* message = new WorkerMessage;
	message->type = WorkerMessage::LaunchCta;
	message->ctaId = ctaId;
	
	send(message);
}

void LLVMWorkerThread::finishCta()
{
	WorkerMessage* message;
	receive(message);
	
	delete message;
}

void LLVMWorkerThread::execute()
{
	WorkerMessage*             message;
	LLVMCooperativeThreadArray cta;
	
	report("LLVMWorker thread is alive, waiting for command.");
	
	threadReceive(message);
	while(message->type != WorkerMessage::Kill)
	{
		switch(message->type)
		{
		case WorkerMessage::LaunchCta:
		{
			report(" Launching CTA " << message->ctaId 
				<< " on thread " << id() << ".");
			cta.executeCta(message->ctaId);
			threadSend(message);
		}
		break;
		case WorkerMessage::SetupCta:
		{
			report(" Setting up CTA for kernel '" << message->kernel->name 
				<< "' on thread " << id() << ".");
			cta.setup(*message->kernel);
			threadSend(message);
		}
		break;
		default: assertM(false, "Invalid message type.");
		}
		
		threadReceive(message);
	}

	report("Received kill command, joining.");
	threadSend(message);
}

}

#endif

