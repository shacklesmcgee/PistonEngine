#pragma once
#include "BaseComponent.h"
#include "SFML/Graphics/Transform.hpp"
#include <SFML/System/Vector2.hpp>

class TransformComponent : public BaseComponent
{
public:
	TransformComponent();
	~TransformComponent();

	virtual void Update(float dt);

	sf::Vector2f getLocation() { return location; };
	float getRotation() { return rotation; };
	sf::Vector2f getScale() { return scale; };
	sf::Transform GetTransform() { return transform; };

	void setLocation(sf::Vector2f newLocation);
	void setLocation(float x, float y);
	void setRotation(float newRotation, sf::Vector2f newOrigin);
	void setScale(sf::Vector2f newScale);
	void setScale(float x, float y);

	void setTransform(sf::Transform newTransform);




protected:
	sf::Vector2f location;
	float rotation;
	sf::Vector2f scale;
	sf::Transform transform;

	sf::Vector2f origin;

};