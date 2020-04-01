#pragma once
#include "BaseComponent.h"
#include "SFML/Graphics/Transform.hpp"
#include <SFML/System/Vector2.hpp>

class GameObject;

class TransformComponent : public BaseComponent
{
public:
	TransformComponent(sol::state &_lua);
	~TransformComponent();

	virtual void Update(float dt);

	void SetByParent();

	sf::Vector2f GetLocation();
	void SetLocation(sf::Vector2f newLocation);
	void SetLocationF(float x, float y);
	void Move(sf::Vector2f direction);
	void MoveF(float x, float y);

	float GetRotation();
	void SetRotation(float newRotation, sf::Vector2f newOrigin);
	void SetRotationF(float newRotation);

	void Rotate(float newRotation);
	void RotateAroundPoint(float newRotation, float x, float y);

	sf::Vector2f GetScale();
	void SetScale(sf::Vector2f newScale);
	void SetScaleF(float x, float y);
	void ScaleF(float x, float y);

	sf::Transform GetTransform() { return transform; };
	void SetTransform(sf::Transform newTransform);

protected:
	sf::Vector2f location;
	sf::Vector2f move;

	float rotationAngle;
	sf::Vector2f rotationPoint;

	sf::Vector2f scale;

	sf::Transform transform;

};