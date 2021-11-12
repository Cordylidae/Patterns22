#pragma once

#include<iostream>
#include<unordered_map>

namespace FlyweightNamespace
{
	class SharedState
	{
		public:
			std::string _brand;
			std::string _model;
			std::string _color;

			SharedState(
				const std::string& brand,
				const std::string& model,
				const std::string& color
			) :	_brand(brand), _model(model), _color(color){}

			friend std::ostream& operator<<(std::ostream& os, const SharedState& ss);
	};

	class UniqueState
	{
		public:
			std::string _owner;
			std::string _plates;

			UniqueState(
				const std::string& owner,
				const std::string& plates
			) :	_owner(owner), _plates(plates) {}

			friend std::ostream& operator<<(std::ostream& os, const UniqueState& us);
	};

	class Flyweight
	{
		private:
			SharedState* _sharedState;

		public:
			
			Flyweight(const SharedState* sharedState)
				: _sharedState(new SharedState(*sharedState)) {}

			Flyweight(const Flyweight& other) 
				: _sharedState(new SharedState(*other._sharedState)) {}

			~Flyweight();

			SharedState* sharedState() const;

			void Operation(const UniqueState& uniqueState) const;
	};

	class FlyweightFactory
	{
		private:
			std::unordered_map<std::string, Flyweight> _flyweights;

			std::string GetKey(const SharedState& ss) const;

		public:
			FlyweightFactory(std::initializer_list<SharedState> sharedStates);

			Flyweight GetFlyweight(const SharedState& sharedState);

			void ListFlyweights() const;
	};
}