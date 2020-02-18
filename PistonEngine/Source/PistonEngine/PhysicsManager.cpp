#include "CollisionManager.h"

CollisionManagementSystem::CollisionManagementSystem()
{
}

void CollisionManagementSystem::Update(float deltaTime)
{
	//Get all game objects with rigidbodies
	auto collidables = GameObject(); // this should initialize to the list of game objects that can collide

	for (int i = 0; i < 5; i++) //for list above
	{

	}

	//if colliding, go to physics system and apply impulse
}
