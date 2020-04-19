#pragma once
#include "BaseComponent.h"
#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/Rect.hpp"

class RigidBodyComponent : public BaseComponent
{
public:
	RigidBodyComponent(sol::state &_lua);
	~RigidBodyComponent(void);

	//no implementation
	virtual void Update(float dt);

	//Getters/settters
	float GetMass();
	float GetRestitution();
	bool GetObeysGravity();
	sf::Vector2f GetGravity();
	sf::Rect<float> GetBoundingBox();
	sf::Vector2f GetVelocity();

	void SetMass(float newMass);
	void SetRestitution(float newRestitution);
	void SetObeysGravity(bool newObeysGravity);
	void SetGravity(sf::Vector2f newGravity);
	void SetBoundingBox(sf::Rect<float> newBoundingBox);
	void SetVelocity(sf::Vector2f newVelocity);

protected:
	float mass = 1.f;
	float restitution = 1.f;
	bool obeysGravity = false;
	sf::Vector2f gravity = sf::Vector2f(0, -3);
	sf::Rect<float> boundingBox;


	//should expose velocity to construction in lua
	//should velocity be in transform or rigidbody?
	sf::Vector2f velocity = sf::Vector2f(0, 0);
};