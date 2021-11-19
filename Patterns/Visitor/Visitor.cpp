#include"Visitor.h"

namespace VisitorNamespace
{
/// ConcreteComponentA

	void ConcreteComponentA::Accept(Visitor* visitor) const
	{
		visitor->VisitConcreteComponentA(this);
	}

	std::string ConcreteComponentA::ExlusiveMethodConcreteComponentA() const
	{
		return "A";
	}

/// ConcreteComponentB

	void ConcreteComponentB::Accept(Visitor* visitor) const
	{
		visitor->VisitConcreteComponentB(this);
	}

	std::string ConcreteComponentB::SpecialMethodConcreteComponentB() const
	{
		return "B";
	}

/// ConcreteVisitor1

	void ConcreteVisitor1::VisitConcreteComponentA(const ConcreteComponentA* element) const
	{
		std::cout << element->ExlusiveMethodConcreteComponentA() << " + ConcreteVisitor1\n";
	}

	void ConcreteVisitor1::VisitConcreteComponentB(const ConcreteComponentB* element) const
	{
		std::cout << element->SpecialMethodConcreteComponentB() << " + ConcreteVisitor1\n";
	}

/// ConcreteVisitor2

	void ConcreteVisitor2::VisitConcreteComponentA(const ConcreteComponentA* element) const
	{
		std::cout << element->ExlusiveMethodConcreteComponentA() << " + ConcreteVisitor2\n";
	}

	void ConcreteVisitor2::VisitConcreteComponentB(const ConcreteComponentB* element) const
	{
		std::cout << element->SpecialMethodConcreteComponentB() << " + ConcreteVisitor2\n";
	}
}