#include "TransformComponent.h"

TransformComponent::TransformComponent()
{

	location.x = 0.f;
	location.y = 0.f;
	
	rotation = 0.0f;

	scale.x = 1.f;
	scale.y = 1.f;

	transform.translate(location);
	transform.rotate(rotation, 0.0f, 0.0f);
	transform.scale(scale);

	name = "TransformComponent";
	owner = NULL;
}

TransformComponent::~TransformComponent()
{
}

void TransformComponent::setLocation(sf::Vector2f newLocation)
{
	location = newLocation;
}

void TransformComponent::setLocation(float x, float y)
{
	location.x = x;
	location.y = y;
}

void TransformComponent::setRotation(float newRotation, sf::Vector2f newOrigin)
{
	rotation = newRotation;
	origin = newOrigin;
}

void TransformComponent::setScale(sf::Vector2f newScale)
{
	scale = newScale;
}

void TransformComponent::setScale(float x, float y)
{
	scale.x = x;
	scale.y = y;
}

void TransformComponent::setTransform(sf::Transform newTransform)
{
	transform = newTransform;
}

void TransformComponent::Update(float dt)
{
	transform.scale(scale);
	transform.rotate(rotation, origin);
	transform.translate(location);	

}