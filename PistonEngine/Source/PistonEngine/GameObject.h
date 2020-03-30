#pragma once

#include <SFML/Graphics/Transform.hpp>
#include "BaseComponent.h"
#include "GraphicsComponent.h"
#include "RigidBodyComponent.h"
#include "TransformComponent.h"
#include "AudioComponent.h"
#include "ScriptComponent.h"
#include "sol.hpp"

#include <vector>
using namespace std;

class GameObject
{
public:
	GameObject(sol::state &_lua);
	~GameObject(void);

	virtual void Update(float msec);

	void SetParent(GameObject &p);
	GameObject* GetParent();

	void AddChild(GameObject* s);
	vector<GameObject*> GetAllChildren();

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

	string GetName();
	void SetName(string _newName);

	sf::Transform worldTransform;
protected:

	GameObject* parent;
	vector<GameObject*> children;
	vector<BaseComponent*> components;

	//sf::Transform localTransform;


	string name;
};
