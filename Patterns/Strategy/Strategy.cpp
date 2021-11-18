#include"Strategy.h"

namespace StrategyNamespace
{
///	Context

	Context::Context(Strategy* strategy) : _strategy(strategy){}

	Context::~Context()
	{
		delete this->_strategy;
	}

	void Context::setStrategy(Strategy* strategy)
	{
		delete this->_strategy;
		this->_strategy = strategy;
	}

	void Context::DoSomeBusinessLogic() const
	{
		std::cout << "Context: Sorting data using the strategy (not sure how it'll do it)\n";
		std::string result = this->_strategy->DoAlgorithm(std::vector<std::string>{"a", "e", "c", "b", "d"});
		std::cout << result << "\n";
	}

/// Concrete Strategy A

	std::string ConcreteStrategyA::DoAlgorithm(const std::vector<std::string>& data) const
	{
		std::string result;

		std::for_each(std::begin(data), std::end(data),
			[&result](const std::string& letter)
		{
			result += letter;
		});

		std::sort(std::begin(result), std::end(result));

		return result;
	}

/// Concrete Strategy B

	std::string ConcreteStrategyB::DoAlgorithm(const std::vector<std::string>& data) const
	{
		std::string result;

		std::for_each(std::begin(data), std::end(data),
			[&result](const std::string& letter)
		{
			result += letter;
		});

		std::sort(std::begin(result), std::end(result));

		for (int i = 0; i < result.size() / 2; i++)
		{
			std::swap(result[i], result[result.size() - i - 1]);
		}

		return result;
	}
}