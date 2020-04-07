#pragma once
#include <string>
#include <vector>
#include <memory>
#include "sol.hpp"

class GameObject;

class BaseComponent
{
public:

	BaseComponent() { name = ""; };
	~BaseComponent() {};
	std::string name;

	virtual void Update(float dt) {};
	GameObject* GetOwner() { return owner; };
	GameObject* owner;

};