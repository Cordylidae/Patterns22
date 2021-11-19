#pragma once

#include<iostream>

namespace TemplateMethodNamespace
{
	class AbstractClass
	{
		protected:
			void BaseOperation1() const;
			void BaseOperation2() const;
			void BaseOperation3() const;

			virtual void RequiredOperation1() const = 0;
			virtual void RequiredOperation2() const = 0;

			virtual void Hook1() const {}
			virtual void Hook2() const {}

		public:
			void TemplateMethod() const;
	};

	class ConcreteClass1 : public AbstractClass
	{
		protected:
			void RequiredOperation1() const override;
			void RequiredOperation2() const override;
	};

	class ConcreteClass2 : public AbstractClass
	{
	protected:
		void RequiredOperation1() const override;
		void RequiredOperation2() const override;
		void Hook1() const override;
	};
}