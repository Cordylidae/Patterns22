#pragma once

#include<iostream>

namespace CommandNamespace
{
	class Command
	{
		public:
			virtual ~Command(){}

			virtual void Execute() const = 0;
	};
	
	class SimpleCommand : public Command
	{
		private:
			std::string _payLoad;

		public:
			explicit SimpleCommand(std::string payLoad) : _payLoad(payLoad) {}

			void Execute() const override;
	};

	class Receiver
	{
		public:
			void DoSomething(const std::string& a);
			void DoSomethingElse(const std::string& b);
	};

	class ComplexCommand : public Command
	{
		private:
			Receiver* _receiver;

			std::string _a;
			std::string _b;

		public:
			ComplexCommand(Receiver* receiver, std::string a, std::string b) : _receiver(receiver), _a(a), _b(b){}

			void Execute() const override;
	};

	class Invoker
	{
		private:
			Command* _onStart;
			Command* _onFinish;

		public:
			~Invoker();

			void SetOnStart(Command* command);
			void SetOnFinish(Command* command);
			void DoSomethingImportant();
	};

	
}