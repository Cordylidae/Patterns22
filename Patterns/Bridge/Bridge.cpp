#include"Bridge.h"

namespace BridgeNamespace
{
	
	std::string ConcreteImplementationA::OperationImplementation() const
	{
		return "ConcreteImplementationA : Here's the result on the platform A. \n";
	}

	std::string ConcreteImplementationB::OperationImplementation() const
	{
		return "ConcreteImplementationB : Here's the result on the platform B. \n";
	}

	std::string Abstraction::Operation() const
	{
		return "Abstaction: Base operation with: \n" + this->_implementation->OperationImplementation();

	}

	std::string ExtendAbstraction::Operation() const
	{
		return "ExtendAbstraction: Extended operation with: \n" + this->_implementation->OperationImplementation();
	}
}