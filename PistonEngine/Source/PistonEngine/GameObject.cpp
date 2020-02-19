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

	if (componentToAdd->name == "GraphicsComponent")
	{
		Graphics = static_cast<GraphicsComponent*>(componentToAdd);
	}

	else if (componentToAdd->name == "TransformComponent")
	{
		Transform = static_cast<TransformComponent*>(componentToAdd);
	}

	else if (componentToAdd->name == "AudioComponent")
	{
		Audio = static_cast<AudioComponent*>(componentToAdd);
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

void GameObject::SetName(string _newName)
{
	name = _newName;
}

void GameObject::Update(float msec)
{
	
	for (auto const& value : components) {
		value->Update(msec);
	}

	if (parent)
	{
		worldTransform = parent->worldTransform * Transform->GetTransform();
	}

	else
	{
		worldTransform = Transform->GetTransform();
	}

	//for (auto const& value : children) {
	//	value->Update(msec);
	//}

	
}
