#pragma once

#include<mutex>
#include<iostream>

namespace SingletonNamespace {

	// MultiThread Singleton

	class Singleton
	{
	private:
		static Singleton* _pointerInstance;
		static std::mutex _mutex;

	protected:

		Singleton(const std::string value) : _value(value)
		{
		}

		~Singleton() {}
		std::string _value;

	public:

		// Singelton should not be cloned.
		Singleton(Singleton& other) = delete;

		//Singletons should not be assignable.
		void operator=(const Singleton&) = delete;

		static Singleton* GetInctance(const std::string& value);

		void SomeBusinessLogic();

		std::string value() const;
	};

}