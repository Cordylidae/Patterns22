#pragma once

#include<iostream>
#include<algorithm>
#include<list>
#include<string>

namespace CompositeNamespace
{
	class Component
	{
		protected:
			Component* _parent;

		public:
			virtual ~Component() {}
			
			void SetParent(Component* parent);
			Component* GetParent() const;

			virtual void Add(Component* component) {}
			virtual void Remove(Component* component) {}

			virtual bool IsComposite() const;

			virtual std::string Operation() const = 0;
	};

	class Leaf : public Component
	{
		public:
			std::string Operation() const override;
	};

	class Composite : public Component
	{
		protected:
			std::list<Component*> _children;

		public:
			void Add(Component* component) override;
			void Remove(Component* component) override;
			bool IsComposite() const override;
			std::string Operation() const override;
	};

}
