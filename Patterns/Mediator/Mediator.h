#pragma once


#include<iostream>
#include<string>

namespace MediatorNamespace
{
	class BaseComponent;

	class Mediator
	{
		public:
			virtual void Notify(BaseComponent* sender, std::string event) const = 0;
	};

	class BaseComponent
	{
		protected:
			Mediator* _mediator;

		public:
			BaseComponent(Mediator* mediator = nullptr) : _mediator(mediator) {}

			void SetMediator(Mediator* mediator);
	};

	class Component1 : public BaseComponent
	{
		public:
			void DoA();
			void DoB();
	};

	class Component2 : public BaseComponent
	{
		public:
			void DoC();
			void DoD();
	};

	class ConcreteMediator : public Mediator
	{
		private:
			Component1* _component1;
			Component2* _component2;

		public:
			ConcreteMediator(Component1* c1, Component2* c2);
			void Notify(BaseComponent* sender, std::string event) const override;

	};
}