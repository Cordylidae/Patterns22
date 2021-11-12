#include"Builder.h"

namespace BuilderNamespace
{
	void Product1::ListParts() const
	{
		std::cout << "Product parts: ";

		for (int i = 0; i < _parts.size(); i++)
		{
			if (_parts[i] == _parts.back())
			{
				std::cout << _parts[i];
			}
			else
			{
				std::cout << _parts[i] << ", ";
			}
		}

		std::cout << "\n\n";
	}

	ConcreteBuilder1::ConcreteBuilder1()
	{
		this->Reset();
	}

	ConcreteBuilder1::~ConcreteBuilder1()
	{
		delete product;
	}

	void ConcreteBuilder1::Reset()
	{
		this->product = new Product1();
	}

	void ConcreteBuilder1::ProducePartA() const
	{
		this->product->_parts.push_back("PartA1");
	}

	void ConcreteBuilder1::ProducePartB() const
	{
		this->product->_parts.push_back("PartB1");
	}

	void ConcreteBuilder1::ProducePartZ() const
	{
		this->product->_parts.push_back("PartZ1");
	}

	Product1* ConcreteBuilder1::GetProduct()
	{
		Product1* result = this->product;
		this->Reset();
		return result;
	}



	void Director::set_builder(Builder* builder)
	{
		this->_builder = builder;
	}

	void Director::BuildMinimalViableProduct()
	{
		this->_builder->ProducePartA();
	}

	void Director::BuildFullFeaturedProduct()
	{
		this->_builder->ProducePartA();
		this->_builder->ProducePartB();
		this->_builder->ProducePartZ();
	}

}