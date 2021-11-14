#pragma once

#include<iostream>
#include<vector>
#pragma warning(disable : 4996)

namespace MementoNamespace
{
	class Memento
	{
		public:
			virtual std::string GetName() const = 0;
			virtual std::string Date() const = 0;
			virtual std::string State() const = 0;
	};

	class ConcreteMemento : public Memento
	{
		private:
			std::string _state;
			std::string _date;

		public:
			ConcreteMemento(std::string state);

			std::string GetName() const override;
			std::string Date() const override;
			std::string State() const override;
	};

	class Originator
	{
		private:
			std::string _state;

			std::string GenerateRandomString(int length = 10);

		public:
			Originator(std::string state);

			void DoSomething();

			Memento* Save();

			void Restore(Memento* memento);
	};

	class Caretaker
	{
		private:
			std::vector<Memento*> _mementos;

			Originator* _originator;

		public:
			Caretaker(Originator* originator);

			void Backup();

			void Undo();

			void ShowHistory();
	};
}