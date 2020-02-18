#pragma once
#include "BaseComponent.h"
#include "SFML/System/Vector2.hpp"

class RigidBodyComponent : public BaseComponent
{
public:
	float mass = 1.f;
	float bounciness = 1.f;
	bool obeysGravity = false;
	sf::Vector2f gravity;

	//RigidBodyComponent() { parent = NULL; }
	RigidBodyComponent();
	~RigidBodyComponent(void);

	virtual void Update(float dt);

protected:
	//GameObject* parent;
};

