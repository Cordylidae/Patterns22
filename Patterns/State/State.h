#pragma once

#include <iostream>
#include <typeinfo>

namespace StateNamespace {

	class Context;

	class State
	{
		protected:
			Context* _context;

		public:
			virtual ~State(){}

			void SetContext(Context* context);

			virtual void Handle1() = 0;
			virtual void Handle2() = 0;
	};

	class Context
	{
		private:
			State* _state;

		public:
			Context(State* state);

			~Context();

			void TransitionTo(State* state);

			void Request1();
			void Request2();
	};


	class ConcreteStateA : public State
	{
		public:
			void Handle1() override;
			void Handle2() override;
	};


	class ConcreteStateB : public State
	{
		public:
			void Handle1() override;
			void Handle2() override;
	};

	
}