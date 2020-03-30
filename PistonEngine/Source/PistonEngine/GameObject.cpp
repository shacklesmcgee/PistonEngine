#include "GameObject.h"

GameObject::GameObject(sol::state &_lua)
{
	parent = NULL;

	_lua.set("GameObject", this);

	_lua["GetParent"] = &GameObject::GetParent;
	_lua["GetName"] = &GameObject::GetName;
}

GameObject::~GameObject(void)
{
	for (unsigned int i = 0; i < children.size(); i++)
	{
		delete children[i];
	}
}


void GameObject::SetParent(GameObject & p)
{
	parent = &p; 
	p.AddChild(this);

	this->Transform->SetByParent();
}

GameObject* GameObject::GetParent()
{
	return parent;
}

string GameObject::GetName()
{
	return name;
}

void GameObject::AddChild(GameObject * s)
{
	children.push_back(s);
	s->parent = this;
}

vector<GameObject*> GameObject::GetAllChildren()
{
	return children;
}

void GameObject::AddComponent(BaseComponent* componentToAdd)
{
	componentToAdd->owner = this;
	components.push_back(componentToAdd);

	if (componentToAdd->name == "GraphicsComponent")
	{
		Graphics = static_cast<GraphicsComponent*>(componentToAdd);
		Graphics->owner = this;
	}

	else if (componentToAdd->name == "TransformComponent")
	{
		Transform = static_cast<TransformComponent*>(componentToAdd);
		Transform->owner = this;
	}

	else if (componentToAdd->name == "AudioComponent")
	{
		Audio = static_cast<AudioComponent*>(componentToAdd);
		Audio->owner = this;
	}

	else if (componentToAdd->name == "ScriptComponent")
	{
		Script = static_cast<ScriptComponent*>(componentToAdd);
		Script->owner = this;
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
}
