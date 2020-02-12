#pragma once
#include <string>

class BaseComponent
{
public:
	std::string name;

	virtual void Update(float dt) {};
};