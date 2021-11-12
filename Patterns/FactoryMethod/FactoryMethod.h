#pragma once

#include<iostream>

namespace FactoryMethodNamespace {

	class Product
	{
		public: 
			virtual ~Product() {}
			virtual std::string Operation() const = 0;
	};

	class ConcreteProduct1 : public Product
	{
		public:
			std::string Operation() const override;
	};

	class ConcreteProduct2 : public Product
	{
		public:
			std::string Operation() const override;
	};
	
	class Creator
	{
		public:
			virtual ~Creator() {}
			virtual Product* FactoryMethod() const = 0;

			std::string SomeOperation() const;
	};

	class ConcreteCreator1 : public Creator
	{
		public:
			Product* FactoryMethod() const override;
	};

	class ConcreteCreator2 : public Creator
	{
	public:
		Product* FactoryMethod() const override;
	};
}