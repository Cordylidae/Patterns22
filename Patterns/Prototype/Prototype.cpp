#include"Prototype.h"

namespace PrototypeNamespace {
	
	void Prototype::Method(float prototypeField) 
	{
			this->_prototypeField = prototypeField;

			std::cout << "Call Method from" << _prototypeName
				<< " with field : " << _prototypeField << std::endl;
	}

	Prototype* ConcretePrototype1::Clone() const
	{
		return new ConcretePrototype1(*this);
	}

	Prototype* ConcretePrototype2::Clone() const
	{
		return new ConcretePrototype2(*this);
	}


	PrototypeFactory::PrototypeFactory()
	{
		_prototypes[Type::PROTOTYPE_1] = new ConcretePrototype1("Prototype_1", 40.0f);
		_prototypes[Type::PROTOTYPE_2] = new ConcretePrototype2("Prrtotype_2", 70.0f);
	}

	PrototypeFactory::~PrototypeFactory() 
	{
		delete _prototypes[Type::PROTOTYPE_1];
		delete _prototypes[Type::PROTOTYPE_2];
	}

	Prototype* PrototypeFactory::CreatePrototype(Type type) 
	{
		return _prototypes[type]->Clone();
	}
}