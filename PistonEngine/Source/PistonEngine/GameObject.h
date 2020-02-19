#pragma once

#include <SFML/Graphics/Transform.hpp>
#include "BaseComponent.h"
#include "GraphicsComponent.h"
#include "RigidBodyComponent.h"
#include "TransformComponent.h"
#include "AudioComponent.h"
#include "ScriptComponent.h"

#include <vector>
using namespace std;

class GameObject
{
public:
	GameObject() { parent = NULL; }
	~GameObject(void);

	virtual void Update(float msec);

	void SetParent(GameObject &p) { parent = &p; p.AddChild(this); }
	void AddChild(GameObject* s);

	void AddComponent(BaseComponent* componentToAdd);
	BaseComponent* GetComponent(string componentToGet);
  
	//void SetLocalTransform(const sf::Transform &matrix) { localTransform = matrix; };
	//sf::Transform GetLocalTransform() { return localTransform; }
	sf::Transform GetWorldTransform() { return worldTransform; }

	GraphicsComponent* Graphics;
	RigidBodyComponent* RigidBody;
	TransformComponent* Transform;
	AudioComponent* Audio;
	ScriptComponent* Script;

	string GetName() { return name; };
	void SetName(string _newName);

protected:

	GameObject* parent;
	vector<GameObject*> children;
	vector<BaseComponent*> components;

	//sf::Transform localTransform;
	sf::Transform worldTransform;

	string name;
};
