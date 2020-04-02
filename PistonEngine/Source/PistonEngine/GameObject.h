#pragma once

#include <SFML/Graphics/Transform.hpp>
#include "BaseComponent.h"
#include "GraphicsComponent.h"
#include "RigidBodyComponent.h"
#include "TransformComponent.h"
#include "AudioComponent.h"
#include "ScriptComponent.h"
#include "InputComponent.h"
#include <string>
#include <iostream>

#include "sol.hpp"

#include <vector>
using namespace std;

class SceneManager;

class GameObject
{
public:
	GameObject();
	~GameObject(void);

	virtual void Update(float msec);

	void SetParent(GameObject &p);
	GameObject* GetParent();

	void AddChild(GameObject* s);
	vector<GameObject*> GetAllChildren();

	void AddComponent(BaseComponent* componentToAdd);
	BaseComponent* GetComponent(string componentToGet);
  
	sf::Transform GetWorldTransform() { return worldTransform; }

	GraphicsComponent* Graphics;
	RigidBodyComponent* RigidBody;
	TransformComponent* Transform;
	AudioComponent* Audio;
	ScriptComponent* Script;
	InputComponent* Input;
	sol::state Lua;

	string GetName();
	void SetName(string _newName);

	SceneManager* GetSceneManager();
	void SetSceneManager(SceneManager* _newSceneManager);

	sf::Transform worldTransform;

	void LuaCreate(sol::table gameObject);
	void LuaDestroy(string name);

protected:

	GameObject* parent;
	vector<GameObject*> children;
	vector<BaseComponent*> components;

	//sf::Transform localTransform;

	string name;
	SceneManager* _sceneManager;
};
