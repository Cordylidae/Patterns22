#include"Memento.h"

namespace MementoNamespace
{
/// ConcreteMemento

	ConcreteMemento::ConcreteMemento(std::string state) : _state(state)
	{
		this->_state = state;

		std::time_t now = std::time(0);
		this->_date = std::ctime(&now);
	}

	std::string ConcreteMemento::GetName() const
	{
		return this->_date + " / (" + this->_state.substr(0, 9) + "...)";
	}

	std::string ConcreteMemento::Date() const
	{
		return this->_date;
	}

	std::string ConcreteMemento::State() const
	{
		return this->_state;
	}

/// Originator

	std::string Originator::GenerateRandomString(int length)
	{
		const char alphanum[] =
			"0123456789"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"abcdefghijklmnopqrstuvwxyz"
			;

		int stringLength = sizeof(alphanum) - 1;

		std::string randomString;

		for (int i = 0; i < length; i++)
		{
			randomString += alphanum[std::rand() % stringLength];
		}

		return randomString;
	}


	Originator::Originator(std::string state) : _state(state)
	{
		std::cout << "Originator: My initial state is: " << this->_state << "\n";
	}

	void Originator::DoSomething()
	{
		std::cout << "Originator: I'm doimg something important\n";

		this->_state = this->GenerateRandomString(30);

		std::cout << "Originator: and my state has changed to: " << this->_state << "\n";
	}

	Memento* Originator::Save()
	{
		return new ConcreteMemento(this->_state);
	}

	void Originator::Restore(Memento* memento)
	{
		this->_state = memento->State();

		std::cout << "Originator: My state has changed to: " << this->_state << "\n";
	}

/// Caretaker

	Caretaker::Caretaker(Originator* originator) : _originator(originator)
	{
		this->_originator = originator;
	}

	void Caretaker::Backup()
	{
		std::cout << "\nCaretaker: Saving Originator's state...\n";
		this->_mementos.push_back(this->_originator->Save());
	}

	void Caretaker::Undo()
	{
		if (!this->_mementos.size())
		{
			return;
		}

		Memento* memento = this->_mementos.back();
		this->_mementos.pop_back();

		std::cout << "Caretaker: Restoring state to: " << memento->GetName() << "\n";

		try
		{
			this->_originator->Restore(memento);
		}
		catch (...)
		{
			this->Undo();
		}
	}

	void Caretaker::ShowHistory()
	{
		std::cout << "Caretaker: Here's the list of mementos:\n";

		for (Memento* memento : this->_mementos)
		{
			std::cout << memento->GetName() << "\n";
		}
	}
}