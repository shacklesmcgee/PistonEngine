#pragma once

#include <SFML/Graphics/Transform.hpp>
#include "BaseComponent.h"
#include <vector>

class GameObject
{
public:
	GameObject() { parent = NULL; }
	~GameObject(void);

	virtual void Update(float msec);

	void AddChild(GameObject* s);

protected:
	GameObject* parent;
	std::vector<GameObject*> children;

	BaseComponent components[];
};
