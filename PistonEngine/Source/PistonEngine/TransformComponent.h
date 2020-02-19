#pragma once
#include "BaseComponent.h"
#include "SFML/Graphics/Transform.hpp"
#include <SFML/System/Vector2.hpp>
#include "sol.hpp"

class TransformComponent : public BaseComponent
{
public:
	TransformComponent(sol::state &_lua);
	~TransformComponent();

	virtual void Update(float dt);

	sf::Vector2f* GetLocation() { return &location; };
	void SetLocation(sf::Vector2f newLocation);
	void SetLocationF(float x, float y);
	void Move(sf::Vector2f direction);
	void MoveF(float x, float y);

	float GetRotation() { return rotation; };
	void SetRotation(float newRotation, sf::Vector2f newOrigin);
	void Rotate(float newRotation);

	sf::Vector2f GetScale() { return scale; };
	void SetScale(sf::Vector2f newScale);
	void SetScaleF(float x, float y);
	void Scale(sf::Vector2f newScale);
	void ScaleF(float x, float y);

	sf::Vector2f GetOrigin() { return origin; };
	float GetOriginX() { return origin.x; };
	float GetOriginY() { return origin.y; };
	void SetOrigin(sf::Vector2f newOrigin);
	void SetOriginF(float x, float y);

	sf::Transform GetTransform() { return transform; };
	void SetTransform(sf::Transform newTransform);

protected:
	sf::Vector2f location;
	sol::table locationTable;
	float rotation;
	sf::Vector2f scale;
	sf::Transform transform;

	sf::Vector2f origin;

};