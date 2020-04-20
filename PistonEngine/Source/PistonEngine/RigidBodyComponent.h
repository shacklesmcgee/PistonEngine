#pragma once
#include "BaseComponent.h"
#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/Rect.hpp"
#include <string>

using namespace std;

class RigidBodyComponent : public BaseComponent
{
public:
	RigidBodyComponent(sol::state &_lua);
	~RigidBodyComponent(void);

	virtual void Update(float dt);

	//Getters/settters
	float GetMass();
	float GetRestitution();
	bool GetObeysGravity();
	sf::Vector2f GetGravity();
	sf::Rect<float> GetBoundingBox();
	//sf::Vector2f GetVelocity();

	void SetMass(float newMass);
	void SetRestitution(float newRestitution);
	void SetObeysGravity(bool newObeysGravity);
	void SetGravity(sf::Vector2f newGravity);
	void SetBoundingBox(sf::Rect<float> newBoundingBox);
	//void SetVelocity(sf::Vector2f newVelocity);

	void handleCollision(GameObject* object1, GameObject* object2);

	std::function<void(string, string)> LuaCollision;

protected:

	float mass;
	float restitution;
	bool obeysGravity;
	sf::Vector2f gravity;
	sf::Rect<float> boundingBox;

};