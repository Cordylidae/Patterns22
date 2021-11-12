#include"Singleton.h"

namespace SingletonNamespace {
	
	//Static methods should be defined outside the class.
	Singleton* Singleton::_pointerInstance{ nullptr };
	std::mutex Singleton::_mutex;


	Singleton* Singleton::GetInctance(const std::string& value)
	{
		std::lock_guard<std::mutex> lock(_mutex);

		if (_pointerInstance == nullptr)
		{
			_pointerInstance = new Singleton(value);
		}

		return _pointerInstance;
	}

	void Singleton::SomeBusinessLogic()
	{
		std::cout << "Singleton Business Logic\n";
	}

	std::string Singleton::value() const
	{
		return _value;
	}
}