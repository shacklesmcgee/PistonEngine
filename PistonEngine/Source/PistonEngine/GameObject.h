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
	void AddComponent(BaseComponent* c);

	void draw();

protected:
	GameObject* parent;
	std::vector<GameObject*> children;

	std::vector<BaseComponent*> components[];
};
