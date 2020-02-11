#include "GameObject.h"

GameObject::~GameObject(void)
{
	for (unsigned int i = 0; i < children.size(); i++)
	{
		delete children[i];
	}
}

void GameObject::AddChild(GameObject * s)
{
	children.push_back(s);
	s->parent = this;
}

void GameObject::AddComponent(BaseComponent* componentToAdd)
{
	components.push_back(componentToAdd);

	if (static_cast<GraphicsComponent*>(componentToAdd))
	{
		Graphics = static_cast<GraphicsComponent*>(componentToAdd);
	}
}

BaseComponent* GameObject::GetComponent(string componentToGet)
{
	BaseComponent* comp = NULL;

	for (auto const& value : components) {
		if (value->name == componentToGet)
		{
			comp = value;
			break;
		}

	}
	return comp;
}

void GameObject::Update(float msec)
{
	if (parent)
	{
		//worldTransform = parent->worldTransform * transform;
	}
	else
	{
		//worldTransform = transform;
	}

	for (std::vector<GameObject*>::iterator i = children.begin(); i != children.end(); ++i)
	{
		(*i)->Update(msec);
	}
}
