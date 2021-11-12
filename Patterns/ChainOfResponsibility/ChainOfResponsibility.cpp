#include"ChainOfResponsibility.h"

namespace ChainOfResponsibilityNamespace
{



/// AbstractHandler

	Handler* AbstractHandler::SetNext(Handler* handler)
	{
		this->_nextHandler = handler;

		return handler;
	}

	std::string AbstractHandler::Handle(std::string request)
	{
		if (this->_nextHandler)
		{
			return this->_nextHandler->Handle(request);
		}

		return {};
	}

/// MonkeyHandler
	std::string MonkeyHandler::Handle(std::string request)
	{
		if (request == "Banana")
		{
			return "Monkey: I'll eat the " + request + ".\n";
		}
		else
		{
			return AbstractHandler::Handle(request);
		}
	}

/// SquirrelHandler

	std::string SquirrelHandler::Handle(std::string request)
	{
		if (request == "Nut")
		{
			return "Squirrel: I'll eat the " + request + ".\n";
		}
		else
		{
			return AbstractHandler::Handle(request);
		}
	}

/// DogHandler

	std::string DogHandler::Handle(std::string request)
	{
		if (request == "MeatBall")
		{
			return "Dog: I'll eat the " + request + ".\n";
		}
		else
		{
			return AbstractHandler::Handle(request);
		}
	}
}