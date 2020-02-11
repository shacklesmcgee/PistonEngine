#pragma once
#include "BaseComponent.h"

class TransformComponent : BaseComponent
{
public:
	TransformComponent();
	~TransformComponent();

protected:
	std::vector <float> position;

public:
	std::vector<float> getPosition();
	void setPosition(std::vector<float> newLocation);
};
