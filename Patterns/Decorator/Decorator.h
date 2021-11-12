#pragma once

#include<iostream>

namespace DecoratorNamespace
{
	class Component
	{
		public:
			virtual ~Component() {}
			virtual std::string Operation() const = 0;
	};

	class ConcreteComponent : public Component
	{
		public:
			std::string Operation() const override;
	};

	class Decorator : public Component
	{
		protected:
			Component* _component;

		public:
			Decorator(Component* component) : _component(component) {}

			std::string Operation() const override;
	};

	class ConcreteDecoratorA : public Decorator
	{
		public:
			ConcreteDecoratorA(Component* component) : Decorator(component) {}

			std::string Operation() const override;
	};

	class ConcreteDecoratorB : public Decorator
	{
		public:
			ConcreteDecoratorB(Component* component) : Decorator(component) {}

			std::string Operation() const override;
	};
}