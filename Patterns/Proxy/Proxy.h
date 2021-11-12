#pragma once

#include<iostream>

namespace ProxyNamespace
{
	class Subject 
	{
		public: 
			virtual void Request() const = 0;
	};

	class RealSubject : public Subject
	{
		public:
			void Request() const override;
	};

	class Proxy : public Subject
	{
		private:
			RealSubject* _realSubject;

			bool CheckAccess() const;

			void LogAccess() const;

		public:

			Proxy(RealSubject* realSubject) : _realSubject(new RealSubject(*realSubject)) {}

			~Proxy()
			{
				delete _realSubject;
			}

			void Request() const override;
	};
}