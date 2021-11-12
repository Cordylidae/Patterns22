#pragma once

#include<iostream>

namespace ChainOfResponsibilityNamespace
{
	class Handler
	{
		public:
			virtual Handler* SetNext(Handler* handler) = 0;
			virtual std::string Handle(std::string request) = 0;
	};

	class AbstractHandler : public Handler
	{
		private:
			Handler* _nextHandler;

		public:
			AbstractHandler() : _nextHandler(nullptr) {}

			Handler* SetNext(Handler* handler) override;
			std::string Handle(std::string request) override;
	};

	class MonkeyHandler : public AbstractHandler
	{
		public:
			std::string Handle(std::string request) override;
	};

	class SquirrelHandler : public AbstractHandler
	{
		public:
			std::string Handle(std::string request) override;
	};

	class DogHandler : public AbstractHandler
	{
		public:
			std::string Handle(std::string request) override;
	};
}