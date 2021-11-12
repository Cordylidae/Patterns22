#pragma once

#include<iostream>
#include<vector>

namespace BuilderNamespace
{
	class Product1
	{
		public:
			std::vector<std::string> _parts;
			void ListParts() const;
	};

	class Builder
	{
		public:
			virtual ~Builder() {}
			virtual void ProducePartA() const = 0;
			virtual void ProducePartB() const = 0;
			virtual void ProducePartZ() const = 0;
	};

	class ConcreteBuilder1 : public Builder
	{
		private:
			Product1* product;
		
		public:
			ConcreteBuilder1();
			~ConcreteBuilder1();

			void Reset();

			void ProducePartA() const override;
			void ProducePartB() const override;
			void ProducePartZ() const override;

			Product1* GetProduct();
	};

	class Director
	{
		private:
			Builder* _builder;

		public:
			void set_builder(Builder* builder);
			void BuildMinimalViableProduct();
			void BuildFullFeaturedProduct();
	};
}