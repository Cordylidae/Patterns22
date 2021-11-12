#pragma once

#include<iostream>

namespace FacadeNamespace
{
	class Subsystem1
	{
		public:
			std::string Operation1() const;
			std::string OperationN() const;
	};

	class Subsystem2
	{
		public:
			std::string Operation1() const;
			std::string OperationZ() const;
	};

	class Facade
	{
		protected:
			Subsystem1* _subsystem1;
			Subsystem2* _subsystem2;

		public:
			Facade(
				Subsystem1* subsystem1 = nullptr,
				Subsystem2* subsystem2 = nullptr);

			~Facade();

			std::string Operation();
	};

}