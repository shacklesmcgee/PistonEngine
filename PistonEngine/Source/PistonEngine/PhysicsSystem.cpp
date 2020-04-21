#include "PhysicsSystem.h"

PhysicsSystem::PhysicsSystem()
{
}

PhysicsSystem::~PhysicsSystem()
{
}

void PhysicsSystem::runPhysics(vector<GameObject*> gameObjects)
{
	for (int i = 0; i < gameObjects.size(); i++)
	{
		if (gameObjects[i]->RigidBody->GetObeysGravity() == true)
		{
			ApplyGravity(gameObjects[i]);
		}

		if (gameObjects[i]->RigidBody)
		{
			for (int k = 0; k < gameObjects.size(); k++)
			{
				if (gameObjects[k]->RigidBody)
				{
					checkCollision(gameObjects[i], gameObjects[k]);
				}
			}
		}
	}
}

void PhysicsSystem::ApplyGravity(GameObject* object)
{
	//this will accelerate every second, not apply gravity consistantly

	sf::Vector2f tempVelo(object->Transform->GetVelocity());
	sf::Vector2f tempGrav(object->RigidBody->GetGravity());
	object->Transform->SetVelocity(tempGrav + tempVelo);
}

void PhysicsSystem::checkCollision(GameObject* object1, GameObject* object2)
{
	if (object1->RigidBody->GetBoundingBox().intersects(object2->RigidBody->GetBoundingBox()))
	{
		//handleCollision(object1, object2);
	}
}

void PhysicsSystem::handleCollision(GameObject* object1, GameObject* object2)
{
	//calculate normals, add impulse away from each other
}
