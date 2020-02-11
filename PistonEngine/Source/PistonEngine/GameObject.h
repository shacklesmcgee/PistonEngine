#pragma once
#include "BaseComponent.h"
#include <vector>

class GameObject
{
public:
	GameObject();
	~GameObject();

	virtual void Update(float msec);

	void AddChild(GameObject* s);

protected:
	GameObject* parent;
	std::vector<GameObject*> children;

	BaseComponent components[];
};