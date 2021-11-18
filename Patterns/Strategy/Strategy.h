#pragma once

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>


namespace StrategyNamespace
{
	class Strategy
	{
		public:
			virtual ~Strategy() {}
			virtual std::string DoAlgorithm(const std::vector<std::string>& data) const = 0;
	};

	class Context
	{
		private:
			Strategy* _strategy;

		public:
			Context(Strategy* strategy = nullptr);
			~Context();

			void setStrategy(Strategy* strategy);

			void DoSomeBusinessLogic() const;
	};

	class ConcreteStrategyA : public Strategy
	{
		public:
			std::string DoAlgorithm(const std::vector<std::string>& data) const override;
			
	};

	class ConcreteStrategyB : public Strategy
	{
		public:
			std::string DoAlgorithm(const std::vector<std::string>& data) const override;
	};
}