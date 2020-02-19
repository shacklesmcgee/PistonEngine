#include "TransformComponent.h"

TransformComponent::TransformComponent(sol::state &_lua)
{
	location.x = 0.f;
	location.y = 0.f;
	
	rotation = 0.0f;

	scale.x = 1.f;
	scale.y = 1.f;

	origin.x = 0.0f;
	origin.y = 0.0f;

	transform.translate(location);
	transform.rotate(rotation, 0.0f, 0.0f);
	transform.scale(scale);

	name = "TransformComponent";	

	_lua.set("Transform", this);

	_lua["GetLocation"] = &TransformComponent::GetLocation;
	_lua["SetLocation"] = &TransformComponent::SetLocationF;
	_lua["Move"] = &TransformComponent::MoveF;

	_lua["GetRotation"] = &TransformComponent::GetRotation;
	_lua["SetRotation"] = &TransformComponent::SetRotation;
	_lua["Rotate"] = &TransformComponent::Rotate;

	_lua["GetScale"] = &TransformComponent::GetScale;
	_lua["SetScale"] = &TransformComponent::SetScaleF;
	_lua["Scale"] = &TransformComponent::Scale;

	//_lua.set_function("SetLocation", &TransformComponent::SetLocationF, this);

	////_lua.set_function("GetOrigin", &TransformComponent::GetOrigin, this);
	//_lua["GetOriginX"] = &TransformComponent::GetOriginX;
	//_lua["GetOriginY"] = &TransformComponent::GetOriginY;
	////_lua["SetOrigin"] = &TransformComponent::SetOrigin;

	////_lua.set_function("GetOriginX", &TransformComponent::GetOriginX, this);
	////_lua.set_function("GetOriginY", &TransformComponent::GetOriginY, this);
	////_lua.set_function("SetOrigin", &TransformComponent::SetOriginF, this);

}

TransformComponent::~TransformComponent()
{
}

void TransformComponent::SetLocation(sf::Vector2f newLocation)
{
	location = newLocation;
}

void TransformComponent::SetLocationF(float x, float y)
{
	transform.translate(x, y);
}

void TransformComponent::Move(sf::Vector2f direction)
{
	location = direction;
}

void TransformComponent::MoveF(float x, float y)
{
	location.x = x / 1000.f;
	location.y = y / 1000.f;
}

void TransformComponent::SetRotation(float newRotation, sf::Vector2f newOrigin)
{
	transform.rotate(newRotation, newOrigin);
}

void TransformComponent::Rotate(float newRotation)
{
	rotation = newRotation / 1000.f;
}
//
//void TransformComponent::RotateAroundPoint(float newRotation, sf::Vector2f point)
//{
//	rotation = newRotation / 1000.f;
//	origin = point;
//}
void TransformComponent::SetScale(sf::Vector2f newScale)
{
	transform.scale(scale);
}

void TransformComponent::SetScaleF(float x, float y)
{
	transform.scale(x, y);
}

void TransformComponent::Scale(sf::Vector2f newScale)
{
	scale = newScale;
}

void TransformComponent::ScaleF(float x, float y)
{
	scale.x = x;
	scale.y = y;
}

void TransformComponent::SetOrigin(sf::Vector2f newOrigin)
{
	origin = newOrigin;
}

void TransformComponent::SetOriginF(float x, float y)
{
	origin.x = x;
	origin.y = y;
}

void TransformComponent::SetTransform(sf::Transform newTransform)
{
	transform = newTransform;
}

void TransformComponent::Update(float dt)
{
	transform.scale(scale);
	transform.rotate(rotation, origin);
	transform.translate(location);	
}