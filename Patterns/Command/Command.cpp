#include"Command.h"

namespace CommandNamespace
{

/// SimpleCommand
	void SimpleCommand::Execute() const
	{
		std::cout << "SimpleCommand: See, I can do simple things like printing (" << this->_payLoad << ")\n";
	}

/// Receiver
	void Receiver::DoSomething(const std::string& a)
	{
		std::cout << "Receiver: Working on (" << a << ".)\n";
	}

	void Receiver::DoSomethingElse(const std::string& b)
	{
		std::cout << "Receiver: Also working on (" << b << ".)\n";
	}


/// ComplexCommand
	void ComplexCommand::Execute() const
	{
		std::cout << "ComplexCommand: Complex stuff should be done by a receiver object.\n";
		this->_receiver->DoSomething(this->_a);
		this->_receiver->DoSomethingElse(this->_b);
	}


/// Invoker
	Invoker::~Invoker()
	{
		delete _onStart;
		delete _onFinish;
	}

	void Invoker::SetOnStart(Command* command)
	{
		this->_onStart = command;
	}

	void Invoker::SetOnFinish(Command* command)
	{
		this->_onFinish = command;
	}

	void Invoker::DoSomethingImportant()
	{
		std::cout << "Invoker: Does anybody want someting done before I begin?\n";

		if (this->_onStart)
		{
			this->_onStart->Execute();
		}

		std::cout << "Invoker ...doing something really important...\n";
		std::cout << "Invoker: Does anybody want something done after I finish?\n";

		if (this->_onFinish)
		{
			this->_onFinish->Execute();
		}
	}
}