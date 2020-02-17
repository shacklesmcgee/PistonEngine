#include "TransformComponent.h"

TransformComponent::TransformComponent()
{
	//add the reference to the parent actor
	for (int i = 0; i < 3; i++)
	{
		position[i] = 0.0f;
	}
	name = "TransformComponent";
}

TransformComponent::~TransformComponent()
{
}

std::vector<float> TransformComponent::getPosition()
{
	return position;
}

void TransformComponent::setPosition(std::vector<float> newLocation)
{
	position = newLocation;
}