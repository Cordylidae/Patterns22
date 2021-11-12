#include"Flyweight.h"

namespace FlyweightNamespace
{
	std::ostream& operator<<(std::ostream& os, const SharedState& ss)
	{
		return os << "[ " << ss._brand << " , " << ss._model << " , " << ss._color << " ]";
	}

	std::ostream& operator<<(std::ostream& os, const UniqueState& us)
	{
		return os << "[ " << us._owner << " , " << us._plates << " ]";
	}

/// Flyweight
	
	Flyweight::~Flyweight()
	{
		delete _sharedState;
	}

	SharedState* Flyweight::sharedState() const
	{
		return _sharedState;
	}

	void Flyweight::Operation(const UniqueState& uniqueState) const
	{
		std::cout << "Flyweight: Displaying shared (" << *_sharedState << ") and unique (" << uniqueState << ") state.";
	}


/// FlyweightFactory

	std::string FlyweightFactory::GetKey(const SharedState& ss) const
	{
		return ss._brand + "_" + ss._model + "_" + ss._color;
	}

	FlyweightFactory::FlyweightFactory(std::initializer_list<SharedState> sharedStates)
	{
		for (const SharedState& ss : sharedStates)
		{
			this->_flyweights.insert(std::make_pair<std::string, Flyweight>(this->GetKey(ss), Flyweight(&ss)));
		}
	}

	Flyweight FlyweightFactory::GetFlyweight(const SharedState& sharedState)
	{
		std::string key = this->GetKey(sharedState);

		if (this->_flyweights.find(key) == this->_flyweights.end())
		{
			std::cout << "FlyweightFactory: Can't find a flyweight, creating new one.\n";

			this->_flyweights.insert(std::make_pair(key, Flyweight(&sharedState)));
		}
		else
		{
			std::cout << "FlyweightFactory: Reusing existing flyweight.\n";
		}

		return this->_flyweights.at(key);
	}

	void FlyweightFactory::ListFlyweights() const
	{
		int count = this->_flyweights.size();
		std::cout << "\nFlyweightFactory: I have " << count << " flyweights:\n";

		for (std::pair<std::string, Flyweight> pair : this->_flyweights)
		{
			std::cout << pair.first << "\n";
		}
	}
}