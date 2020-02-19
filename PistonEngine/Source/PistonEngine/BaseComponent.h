#pragma once
#include <string>
#include <vector>
#include <memory>

class GameObject;

class BaseComponent
{
public:

	BaseComponent() { name = ""; };
	~BaseComponent() {};
	std::string name;

	virtual void Update(float dt) {};

};