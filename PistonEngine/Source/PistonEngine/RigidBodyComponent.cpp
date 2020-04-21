#include "RigidBodyComponent.h"
#include "GameObject.h"
#include "SceneManager.h"

RigidBodyComponent::RigidBodyComponent(sol::state &_lua)
{
	name = "RigidBodyComponent";

	mass = 0.f;
	restitution = 0.f;
	obeysGravity = false;
	gravity = sf::Vector2f(0, 0.0098);
	boundingBox = sf::Rect<float>(0,0,0,0);

	_lua.set("RigidBody", this);

	_lua["GetMass"] = &RigidBodyComponent::GetMass;
	_lua["GetRestitution"] = &RigidBodyComponent::GetRestitution;
	_lua["GetObeysGravity"] = &RigidBodyComponent::GetObeysGravity;
	_lua["GetGravity"] = &RigidBodyComponent::GetGravity;

	_lua["SetMass"] = &RigidBodyComponent::SetMass;
	_lua["SetRestitution"] = &RigidBodyComponent::SetRestitution;
	_lua["SetObeysGravity"] = &RigidBodyComponent::SetObeysGravity;
	_lua["SetGravity"] = &RigidBodyComponent::SetGravity;

	if (_lua["Collision"].valid())
		LuaCollision = _lua["Collision"];
}

RigidBodyComponent::~RigidBodyComponent(void)
{
}

void RigidBodyComponent::Update(float dt)
{
	if (GetObeysGravity() == true)
	{
		sf::Vector2f tempVelo(GetOwner()->Transform->GetVelocity());
		sf::Vector2f tempGrav(GetGravity());
		GetOwner()->Transform->SetVelocity(tempGrav + tempVelo);
	}

	for (auto const& value : GetOwner()->GetSceneManager()->GetAllGameObjects())
	{
		if (value->RigidBody)
		{
			if (value->RigidBody == this)
			{
				SetBoundingBox(sf::Rect<float>(GetOwner()->Transform->GetLocationX(),
					GetOwner()->Transform->GetLocationY(),
					GetOwner()->Graphics->GetWidth(),
					GetOwner()->Graphics->GetHeight()));

				continue;
			}

			else
			{
				if (GetBoundingBox().intersects(value->RigidBody->GetBoundingBox()))
				{
					handleCollision(GetOwner(), value);
				}
			}
		}
	}
}

void RigidBodyComponent::handleCollision(GameObject* object1, GameObject* object2)
{
	//calculate normals, add impulse away from each other
	//cout << object1->GetName() << " collided with " << object2->GetName() << endl;
	if (LuaCollision != NULL)
	{
		LuaCollision(object1->GetName(), object2->GetName());
	}
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
