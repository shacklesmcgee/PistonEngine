#pragma once
#include "GameObject.h"
#include "RigidBodyComponent.h"
#include "TransformComponent.h"

class PhysicsSystem
{
public:
	PhysicsSystem();
	~PhysicsSystem();

	void runPhysics(vector<GameObject*> gameObjects);

private:
	void ApplyGravity(GameObject* object);
	void checkCollision(GameObject* object1, GameObject* object2);

	void handleCollision(GameObject* object1, GameObject* object2);
};

