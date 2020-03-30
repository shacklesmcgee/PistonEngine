#include "TransformComponent.h"
#include "GameObject.h"

TransformComponent::TransformComponent(sol::state &_lua)
{
	location = sf::Vector2f(0.0f, 0.0f);
	
	rotationAngle = 0.0f;
	rotationPoint = sf::Vector2f(0.0f, 0.0f);


	scale = sf::Vector2f(1.0f, 1.0f);

	transform.translate(location);
	transform.rotate(rotationAngle, rotationPoint);
	transform.scale(scale);

	name = "TransformComponent";	

	_lua.set("Transform", this);

	_lua["GetLocation"] = &TransformComponent::GetLocation;
	_lua["SetLocation"] = &TransformComponent::SetLocationF;
	_lua["Move"] = &TransformComponent::MoveF;

	_lua["GetRotation"] = &TransformComponent::GetRotation;
	_lua["SetRotation"] = &TransformComponent::SetRotationF;
	_lua["Rotate"] = &TransformComponent::Rotate;
	_lua["RotateAroundPoint"] = &TransformComponent::RotateAroundPoint;

	_lua["GetScale"] = &TransformComponent::GetScale;
	_lua["SetScale"] = &TransformComponent::SetScaleF;
	_lua["Scale"] = &TransformComponent::ScaleF;
}

TransformComponent::~TransformComponent()
{
}

sf::Vector2f TransformComponent::GetLocation()
{
	return location;
}

void TransformComponent::SetByParent()
{
	location = GetOwner()->GetParent()->Transform->GetLocation();
}

void TransformComponent::SetLocation(sf::Vector2f newLocation)
{
	transform.translate(newLocation);
	location = newLocation;
}

void TransformComponent::SetLocationF(float x, float y)
{
	transform.translate(x, y);
	location = sf::Vector2f(x, y);
}

void TransformComponent::Move(sf::Vector2f direction)
{
	move = direction;
}

void TransformComponent::MoveF(float x, float y)
{
	move.x = x / 1000.f;
	move.y = y / 1000.f;
}

float TransformComponent::GetRotation()
{
	return rotationAngle;
}

void TransformComponent::SetRotation(float newRotation, sf::Vector2f newOrigin)
{
	transform.rotate(newRotation, newOrigin);
}

void TransformComponent::SetRotationF(float newRotation)
{
	transform.rotate(newRotation, 0.0f, 0.0f);
}

void TransformComponent::Rotate(float newRotation)
{
	rotationAngle = newRotation / 1000.f;
	rotationPoint = sf::Vector2f(0.f, 0.f);
}

void TransformComponent::RotateAroundPoint(float newRotation, float x, float y)
{
	rotationAngle = newRotation / 1000.f;
	rotationPoint.x = x;
	rotationPoint.y = y;
}

sf::Vector2f TransformComponent::GetScale()
{
	return scale;
}

void TransformComponent::SetScale(sf::Vector2f newScale)
{
	transform.scale(scale);
}

void TransformComponent::SetScaleF(float x, float y)
{
	transform.scale(x, y);
}

void TransformComponent::ScaleF(float x, float y)
{
	scale.x = x / 1.09999;
	scale.y = y / 1.09999;
}

void TransformComponent::SetTransform(sf::Transform newTransform)
{
	transform = newTransform;
}

void TransformComponent::Update(float dt)
{
	transform.scale(scale);
	transform.rotate(rotationAngle, rotationPoint);
	transform.translate(move);	

}