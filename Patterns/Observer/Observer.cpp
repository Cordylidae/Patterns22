#include"Observer.h"

namespace ObserverNamespace
{
	int Observer::_staticNumber = 0;

/// Subject

	Subject::~Subject()
	{
		std::cout << "Goodbye, I was the Subject.\n";
	}

	void Subject::Attach(IObserver* observer)
	{
		_listObserver.push_back(observer);
	}

	void Subject::Detach(IObserver* observer)
	{
		_listObserver.remove(observer);
	}


	void Subject::HowManyObserver()
	{
		std::cout << "There are " << _listObserver.size() << " obsrevers in the list.\n";
	}

	void Subject::Notify()
	{
		std::list<IObserver*>::iterator iterator = _listObserver.begin();
		HowManyObserver();

		while (iterator != _listObserver.end())
		{

			(*iterator)->Update(_message);
			iterator++;
		}

	}

	void Subject::CreateMessage(std::string message)
	{
		this->_message = message;
		Notify();
	}

	void Subject::SomeBuisnessLogic()
	{
		this->_message = "change message message";
		Notify();
		std::cout << "I'm about to do some things importent\n";
	}

/// Observer

	Observer::Observer(Subject& subject) : _subject(subject) {

		this->_subject.Attach(this);

		std::cout << "Hi, I'm the Observer \"" << ++Observer::_staticNumber << "\".\n";

		this->_number = Observer::_staticNumber;
	}

	Observer::~Observer()
	{
		std::cout << "Goodbye, I was the Observer \"" << this->_number << "\".\n";
	}


	void Observer::PrintInfo()
	{
		std::cout << "Observe \"" << this->_number << "\" : a new message is abvaible --> "
			<< this->_messageFromSubject << "\n";
	}

	void Observer::RenoveMeFromTheList()
	{
		_subject.Detach(this);

		std::cout << "Observe \"" << this->_number << "\" removed from the list.\n";
	}

	void Observer::Update(const std::string& messageFromSubject)
	{
		_messageFromSubject = messageFromSubject;
		PrintInfo();
	}
}