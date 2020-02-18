#pragma once
#include <string>
#include <vector>
#include <memory>

class GameObject;

class BaseComponent
{
public:

	BaseComponent() { name = ""; owner = NULL; };
	~BaseComponent() {};
	std::string name;

	virtual void Update(float dt) {};
	GameObject* GetOwner() { return owner;};
	void SetOwner(GameObject* objToSet) { owner = objToSet; };

	GameObject* owner;
};