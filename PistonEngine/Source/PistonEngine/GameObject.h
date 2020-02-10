#pragma once

#include <SFML/Graphics/Transform.hpp>
#include <vector>

class GameObject
{
public:
	GameObject() { parent = NULL; }
	~GameObject(void);

	//void SetTransform(const sf::Transform &matrix) { transform = matrix; }
	//sf::Transform GetTransform() { return transform; }
	//sf::Transform GetWorldTransform() { return worldTransform; }

	void SetParent(GameObject* p) { parent = p; }
	void AddChild(GameObject* s);

	virtual void Update(float msec);
protected:
	GameObject* parent;
	//sf::Transform worldTransform;
	//sf::Transform transform;
	std::vector<GameObject*> children;
};

