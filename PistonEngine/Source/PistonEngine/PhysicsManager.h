#pragma once
#include "RigidBodyComponent.h"
#include "GameObject.h"

class CollisionManagementSystem
{
public:
public:
	CollisionManagementSystem(); //pass way for system to know which scene it should be loading from

	void Update(float deltaTime);
private:
	//should there be some sort of reference to the scene? 
};