#pragma once
#include <string>
#include <vector>

class BaseComponent
{
public:
	std::string name;

  virtual void Update(float dt) {};
};