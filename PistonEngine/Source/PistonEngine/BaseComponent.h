#pragma once
#include "GameObject.h"
#include <string>

class BaseComponent
{
protected:
	std::string name;
	GameObject* owner;
};