#pragma once
#include "BaseComponent.h"
//#include "GameObject.h"

class RigidBodyComponent : public BaseComponent
{
public:
	float mass = 1.f;
	float bounciness = 1.f;
	bool obeysGravity = false;
	Vector2 gravity;

	//RigidBodyComponent() { parent = NULL; }
	RigidBodyComponent();
	~RigidBodyComponent(void);

	virtual void Update(float msec);

protected:
	//GameObject* parent;
};

