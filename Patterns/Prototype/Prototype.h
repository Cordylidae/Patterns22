#pragma once

#include<iostream>
#include<unordered_map>

namespace PrototypeNamespace {
	
	enum Type {
		PROTOTYPE_1 = 0,
		PROTOTYPE_2
	};

	class Prototype {
	protected:
		std::string _prototypeName;
		float _prototypeField;

	public:
		Prototype() {}
		Prototype(std::string prototypeName)
			: _prototypeName(prototypeName) {}
		
		virtual ~Prototype() {}
		virtual Prototype* Clone() const = 0;
		virtual void Method(float prototypeField);
	};

	class ConcretePrototype1 : public Prototype
	{
		private:
			float _concretePrototypeField1;
		
		public:
			ConcretePrototype1(std::string prototypeName, float concretePrototypeField)
				: Prototype(prototypeName), _concretePrototypeField1(concretePrototypeField) {}

			Prototype* Clone() const override;
	};

	class ConcretePrototype2 : public Prototype
	{
		private:
			float _concretePrototypeField2;
	
		public:
			ConcretePrototype2(std::string prototypeName, float concretePrortotypeField)
				: Prototype(prototypeName), _concretePrototypeField2(concretePrortotypeField) {}

			Prototype* Clone() const override;
	};

	class PrototypeFactory
	{
		private:
			std::unordered_map<Type, Prototype*, std::hash<int>> _prototypes;

		public:
			PrototypeFactory();

			~PrototypeFactory();

			Prototype* CreatePrototype(Type type);
	};
}