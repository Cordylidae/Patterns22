#include"TemplateMethod.h"

namespace TemplateMethodNamespace
{

/// AbstractClass

	void AbstractClass::BaseOperation1() const
	{
		std::cout << "AbstractClass says: I am doing the bulk of the work\n";
	}

	void AbstractClass::BaseOperation2() const
	{
		std::cout << "AbstractClass says: But I let subclasses override some operations\n";
	}

	void AbstractClass::BaseOperation3() const
	{
		std::cout << "AbstractClass says: But I am doing the bulk of the work anyway\n";
	}

	void AbstractClass::TemplateMethod() const
	{
		this->BaseOperation1();

		this->RequiredOperation1();

		this->BaseOperation2();

		this->Hook1();

		this->RequiredOperation2();

		this->BaseOperation3();

		this->Hook2();
	}

/// Concrete Class 1

	void ConcreteClass1::RequiredOperation1() const
	{
		std::cout << "ConcreteClass1 says: Implemented Operation1\n";
	}

	void ConcreteClass1::RequiredOperation2() const
	{
		std::cout << "ConcreteClass1 says: Implemented Operation2\n";
	}

/// Concrete Class 2

	void ConcreteClass2::RequiredOperation1() const
	{
		std::cout << "ConcreteClass2 says: Implemented Operation1\n";
	}

	void ConcreteClass2::RequiredOperation2() const
	{
		std::cout << "ConcreteClass2 says: Implemented Operation2\n";
	}

	void ConcreteClass2::Hook1() const
	{
		std::cout << "ConcreteClass2 says: Overridden Hook1\n";
	}
}