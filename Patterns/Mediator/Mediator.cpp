#include"Mediator.h"

namespace MediatorNamespace
{
/// BaseComponent

	void BaseComponent::SetMediator(Mediator* mediator)
	{
		this->_mediator = mediator;
	}

/// Component1

	void Component1::DoA()
	{
		std::cout << "Component 1 does A.\n";
		this->_mediator->Notify(this, "A");
	}

	void Component1::DoB()
	{
		std::cout << "Component 1 does B.\n";
		this->_mediator->Notify(this, "B");
	}

/// Component2

	void Component2::DoC()
	{
		std::cout << "Component 2 does C.\n";
		this->_mediator->Notify(this, "C");
	}

	void Component2::DoD()
	{
		std::cout << "Component 2 does D.\n";
		this->_mediator->Notify(this, "D");
	}

/// ConcreteMediator

	ConcreteMediator::ConcreteMediator(Component1* c1, Component2* c2) : _component1(c1), _component2(c2)
	{
		this->_component1->SetMediator(this);
		this->_component2->SetMediator(this);
	}

	void ConcreteMediator::Notify(BaseComponent* sender, std::string event) const
	{
		if (event == "A")
		{
			std::cout << "Mediator reacts on A and triggers following operations:\n";
			this->_component2->DoC();
		}
		if (event == "D")
		{
			std::cout << "Mediator reacts on D and triggers folowing operations:\n";
			this->_component1->DoB();
			this->_component2->DoC();
		}

	}
}