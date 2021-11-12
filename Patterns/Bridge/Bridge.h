#pragma once

#include<iostream>

namespace BridgeNamespace
{
	class Implementation
	{
		public:
			virtual ~Implementation() {}
			virtual std::string OperationImplementation() const = 0;
	};

	class ConcreteImplementationA : public Implementation
	{
		public:
			std::string OperationImplementation() const override;
	};

	class ConcreteImplementationB : public Implementation
	{
		public:
			std::string OperationImplementation() const override;
	};


	class Abstraction
	{
		protected:
			Implementation* _implementation;
		
		public:

			Abstraction(Implementation* implementation) : _implementation(implementation) {}

			virtual ~Abstraction() {}

			virtual std::string Operation() const;
	};

	class ExtendAbstraction : public Abstraction
	{
		public:
			ExtendAbstraction(Implementation* implementation) : Abstraction(implementation) {}

			std::string Operation()const override;
	};
}