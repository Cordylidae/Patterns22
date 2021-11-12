#include"AbstractFactory.h"

namespace AbstractFactoryNamespace
{
	std::string ConcreteProductA1::UsefulFunctionA() const
	{
		return "The result of the product A1.";
	}

	std::string ConcreteProductA2::UsefulFunctionA() const
	{
		return "The result of the product A2.";
	}

	std::string ConcreteProductB1::UsefulFunctionB() const
	{
		return "The result of the product B1.";
	}

	std::string ConcreteProductB1::AnotherUsefulFunctionB(const AbstractProductA& collaborator) const
	{
		const std::string result = collaborator.UsefulFunctionA();
		return "The result of the B1 collaborating with ( " + result + " )";
	}

	std::string ConcreteProductB2::UsefulFunctionB() const
	{
		return "The result of the product B2.";
	}

	std::string ConcreteProductB2::AnotherUsefulFunctionB(const AbstractProductA& collaborator) const
	{
		const std::string result = collaborator.UsefulFunctionA();
		return "The result of the B2 collaborating with ( " + result + " )";
	}

	AbstractProductA* ConcreteFactory1::CreateProductA() const
	{
		return new ConcreteProductA1();
	}

	AbstractProductB* ConcreteFactory1::CreateProductB() const
	{
		return new ConcreteProductB1();
	}

	AbstractProductA* ConcreteFactory2::CreateProductA() const
	{
		return new ConcreteProductA2();
	}

	AbstractProductB* ConcreteFactory2::CreateProductB() const
	{
		return new ConcreteProductB2();
	}
}