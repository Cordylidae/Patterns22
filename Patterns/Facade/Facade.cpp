#include"Facade.h"

namespace FacadeNamespace
{

/// Subsystem1

	std::string Subsystem1::Operation1() const
	{
		return "Subsystem1 : Ready!\n";
	}

	std::string Subsystem1::OperationN() const
	{
		return "Subsystem1 : Go!\n";
	}

/// Subsystem2

	std::string Subsystem2::Operation1() const
	{
		return "Subsystem2 : Get ready!\n";
	}

	std::string Subsystem2::OperationZ() const
	{
		return "Subsystem2 : Fire!\n";
	}

/// Facade

	Facade::Facade(Subsystem1* subsystem1, Subsystem2* subsystem2) {

		this->_subsystem1 = subsystem1 ? new Subsystem1 : subsystem1;
		this->_subsystem2 = subsystem2 ? new Subsystem2 : subsystem2;

	}

	Facade::~Facade()
	{
		delete _subsystem1;
		delete _subsystem2;
	}

	std::string Facade::Operation()
	{
		std::string result = "Facade initializes subsystems: \n";

		result += this->_subsystem1->Operation1();
		result += this->_subsystem2->Operation1();

		result += "Facade orders subsystem to perform the action:\n";

		result += this->_subsystem1->OperationN();
		result += this->_subsystem2->OperationZ();

		return result;
	}
}