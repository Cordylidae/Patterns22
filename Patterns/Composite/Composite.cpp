#include"Composite.h"

namespace CompositeNamespace
{
	///Component

	void Component::SetParent(Component* parent)
	{
		this->_parent = parent;
	}

	Component* Component::GetParent() const
	{
		return this->_parent;
	}

	bool Component::IsComposite() const
	{
		return false;
	}

	///Leaf

	std::string Leaf::Operation() const
	{
		return "Leaf";
	}

	///Composite

	void Composite::Add(Component* component)
	{
		this->_children.push_back(component);
		component->SetParent(this);
	}

	void Composite::Remove(Component* component)
	{
		_children.remove(component);
		component->SetParent(nullptr);
	}

	bool Composite::IsComposite() const
	{
		return true;
	}

	std::string Composite::Operation() const
	{
		std::string result;

		for (const Component* c : _children)
		{
			if (c == _children.back())
			{
				result += c->Operation();
			}
			else
			{
				result += c->Operation() + "+";
			}
		}
		return "Branch(" + result + ")";
	}
}