#pragma once

#include<iostream>

namespace AdapterNamespace
{
	class Target
	{
		public:
			virtual ~Target() = default;

			virtual std::string Request() const;
	};

	class Adaptee 
	{
		public:
			std::string SpecificRequest() const;
	};

	class Adapter : public Target
	{
		private:
			Adaptee* _adaptee;

		public:

			Adapter(Adaptee* adaptee) : _adaptee(adaptee){}

			std::string Request() const override;
	};
}