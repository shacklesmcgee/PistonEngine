#pragma once
#include "BaseComponent.h"
#include "SFML/System/Vector2.hpp"

class RigidBodyComponent : public BaseComponent
{
public:
	float mass = 1.f;
	float bounciness = 1.f;
	bool obeysGravity = false;
	sf::Vector2f gravity = sf::Vector2f(0, -9.8);

	sf::Vector2f currentVelocity;
	sf::Vector2f maxVelocity = sf::Vector2f(10.f, 10.f);

	bool grounded = false;

	//RigidBodyComponent() { parent = NULL; }
	RigidBodyComponent();
	~RigidBodyComponent(void);

	virtual void Update(float dt);
	void addForce(sf::Vector2f force);
	void stop();
	void setAABB();
	void integrate(float dt);

protected:
	//GameObject* parent;

private:
	sf::Vector2f totalForces;

	struct AABB
	{
		sf::Vector2f bLeft;
		sf::Vector2f tRight;
	};

public:
	AABB aabb;
};