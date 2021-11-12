#include"Proxy.h"

namespace ProxyNamespace
{

/// RealSubject

	void RealSubject::Request() const
	{
		std::cout << "RealSubject: Handling request.\n";
	}

/// Proxy

	bool Proxy::CheckAccess() const
	{
		std::cout << "Proxy: Checking access proir to firing a real request.\n";
		return true;
	}

	void Proxy::LogAccess() const
	{
		std::cout << "Proxy: Logging the time of request.\n";
	}


	void Proxy::Request() const
	{
		if (this->CheckAccess())
		{
			this->_realSubject->Request();
			this->LogAccess();
		}
	}
}