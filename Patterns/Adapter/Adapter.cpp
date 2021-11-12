#include"Adapter.h"

namespace AdapterNamespace
{
	std::string Target::Request() const
	{
		return "Target: the defualt target's behaviour.";
	}

	std::string Adaptee::SpecificRequest() const
	{
		return ".eetpadA eht rof roivaheb laicepS";
	}

	std::string Adapter::Request() const
	{
		std::string to_reverse = this->_adaptee->SpecificRequest();
		std::reverse(to_reverse.begin(), to_reverse.end());

		return "Adapter: (TRANSLETED) " + to_reverse;
	}
}