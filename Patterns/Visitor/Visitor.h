#pragma once

#include<iostream>
#include<string>

namespace VisitorNamespace
{
	class ConcreteComponentA;
	class ConcreteComponentB;

	class Visitor
	{
		public:
			virtual void VisitConcreteComponentA(const ConcreteComponentA* element) const = 0;
			virtual void VisitConcreteComponentB(const ConcreteComponentB* element) const = 0;
	};

	class Component
	{
		public:
			virtual ~Component() {}
			virtual void Accept(Visitor* vivstor) const = 0;
	};

	class ConcreteComponentA : public Component
	{
		public:
			void Accept(Visitor* visitor) const override;
			std::string ExlusiveMethodConcreteComponentA() const;
	};

	class ConcreteComponentB : public Component
	{
	public:
		void Accept(Visitor* visitor) const override;
		std::string SpecialMethodConcreteComponentB() const;
	};

	class ConcreteVisitor1 : public Visitor
	{
		public:
			void VisitConcreteComponentA(const ConcreteComponentA* element) const override;
			void VisitConcreteComponentB(const ConcreteComponentB* element) const override;
	};

	class ConcreteVisitor2 : public Visitor
	{
	public:
		void VisitConcreteComponentA(const ConcreteComponentA* element) const override;
		void VisitConcreteComponentB(const ConcreteComponentB* element) const override;
	};
}
