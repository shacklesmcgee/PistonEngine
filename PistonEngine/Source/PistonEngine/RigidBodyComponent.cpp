#include "RigidBodyComponent.h"

RigidBodyComponent::RigidBodyComponent(sol::state &_lua)
{
	name = "RigidBodyComponent";

	_lua.set("RigidBody", this);

	_lua["GetMass"] = &RigidBodyComponent::GetMass;
	_lua["GetRestitution"] = &RigidBodyComponent::GetRestitution;
	_lua["GetObeysGravity"] = &RigidBodyComponent::GetObeysGravity;
	_lua["GetGravity"] = &RigidBodyComponent::GetGravity;

	_lua["SetMass"] = &RigidBodyComponent::SetMass;
	_lua["SetRestitution"] = &RigidBodyComponent::SetRestitution;
	_lua["SetObeysGravity"] = &RigidBodyComponent::SetObeysGravity;
	_lua["SetGravity"] = &RigidBodyComponent::SetGravity;
}

RigidBodyComponent::~RigidBodyComponent(void)
{
}

void RigidBodyComponent::Update(float dt)
{
}

float RigidBodyComponent::GetMass()
{
	return mass;
}

float RigidBodyComponent::GetRestitution()
{
	return restitution;
}

bool RigidBodyComponent::GetObeysGravity()
{
	return obeysGravity;
}

sf::Vector2f RigidBodyComponent::GetGravity()
{
	return gravity;
}

sf::Rect<float> RigidBodyComponent::GetBoundingBox()
{
	return boundingBox;
}

void RigidBodyComponent::SetMass(float newMass)
{
	mass = newMass;
}

void RigidBodyComponent::SetRestitution(float newRestitution)
{
	restitution = newRestitution;
}

void RigidBodyComponent::SetObeysGravity(bool newObeysGravity)
{
	obeysGravity = newObeysGravity;
}

void RigidBodyComponent::SetGravity(sf::Vector2f newGravity)
{
	gravity = newGravity;
}

void RigidBodyComponent::SetBoundingBox(sf::Rect<float> newBoundingBox)
{
	boundingBox = newBoundingBox;
}
