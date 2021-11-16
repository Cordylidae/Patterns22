#pragma once

#include <iostream>
#include <list>
#include <string>

namespace ObserverNamespace
{

	class IObserver
	{
		public:
			virtual ~IObserver(){}
			virtual void Update(const std::string& massage_from_subject) = 0;
	};

	class ISubject
	{
		public:
			virtual ~ISubject(){}
			
			virtual void Attach(IObserver* observer) = 0;
			virtual void Detach(IObserver* observer) = 0;
			virtual void Notify() = 0;
	};

	class Subject : public ISubject
	{
		private:
			std::list<IObserver*> _listObserver;
			std::string _message;

		public:
			virtual ~Subject();

			void Attach(IObserver* observer) override;
			void Detach(IObserver* observer) override;

			void HowManyObserver();
			void Notify() override;

			void CreateMessage(std::string message = "Empty");
			void SomeBuisnessLogic();
	};

	class Observer : public IObserver
	{
		private:
			std::string _messageFromSubject;
			Subject& _subject;
			
			static int _staticNumber;
			int _number;

		public:

			Observer(Subject& subject);

			virtual ~Observer();

			void PrintInfo();

			void RenoveMeFromTheList();

			void Update(const std::string& messageFromSubject) override;
	};
}