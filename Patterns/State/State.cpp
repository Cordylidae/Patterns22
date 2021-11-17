#include "State.h"

namespace StateNamespace
{

/// State

	void State::SetContext(Context* context)
	{
		this->_context = context;
	}

/// Context

	Context::Context(State* state) : _state(nullptr)
	{
		this->TransitionTo(state);
	}

	Context::~Context()
	{
		delete _state;
	}

	void Context::TransitionTo(State* state)
	{
		std::cout << "Context: Transition to " << typeid(*state).name() << ".\n";

		if (this->_state != nullptr)
			delete this->_state;

		this->_state = state;
		this->_state->SetContext(this);
	}

	void Context::Request1()
	{
		this->_state->Handle1();
	}

	void Context::Request2()
	{
		this->_state->Handle2();
	}

/// ConcreteStateA

	void ConcreteStateA::Handle1()
	{
		std::cout << "ConcreteStateA handles request1.\n";
		std::cout << "ConcreteStateA wants to change the state of the context.\n";

		this->_context->TransitionTo(new ConcreteStateB);
	}

	void ConcreteStateA::Handle2()
	{
		std::cout << "ConcreteStateA handles request2.\n";
	}

/// ConcreteStateB

	void ConcreteStateB::Handle1()
	{
		std::cout << "ConcreteStateB handles request1.\n";
	}

	void ConcreteStateB::Handle2()
	{
		std::cout << "ConcreteStateB handles request2.\n";
		std::cout << "ConcreteStateB wants to change the state of the context.\n";

		this->_context->TransitionTo(new ConcreteStateA);
	}
}