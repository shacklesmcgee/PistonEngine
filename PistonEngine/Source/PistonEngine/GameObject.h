#pragma once

#include <SFML/Graphics/Transform.hpp>
#include "BaseComponent.h"
#include "GraphicsComponent.h"
#include "RigidBodyComponent.h"

#include <vector>
using namespace std;

class GameObject
{
public:
	GameObject() { parent = NULL; }
	~GameObject(void);

	virtual void Update(float msec);

	void AddChild(GameObject* s);
	void AddComponent(BaseComponent* componentToAdd);
	BaseComponent* GetComponent(string componentToGet);

	GraphicsComponent* Graphics;
	RigidBodyComponent* RigidBody;

	string name;

protected:

	GameObject* parent;
	vector<GameObject*> children;

	vector<BaseComponent*> components;

	
};
