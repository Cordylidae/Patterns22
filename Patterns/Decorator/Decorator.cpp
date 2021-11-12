#include"Decorator.h"

namespace DecoratorNamespace
{
	// ConcreteComponent

	std::string ConcreteComponent::Operation() const
	{
		return "ConcreteComponent";
	}

	// Decorator

	std::string Decorator::Operation() const
	{
		return this->_component->Operation();
	}

	// ConcreteDecoratorA

	std::string ConcreteDecoratorA::Operation() const
	{
		return "ConcreteDecoratorA(" + Decorator::Operation() + ")";
	}

	// ConcreteDecoratorB

	std::string ConcreteDecoratorB::Operation() const
	{
		return "ConcreteDecoratorB(" + Decorator::Operation() + ")";
	}
}