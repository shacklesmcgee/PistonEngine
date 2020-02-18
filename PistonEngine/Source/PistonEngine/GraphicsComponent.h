#pragma once
#include "BaseComponent.h"
#include "SFML/Graphics.hpp"

using namespace std;
class GameObject;

class GraphicsComponent : public BaseComponent
{

private:
	sf::Texture _texture;
	sf::Sprite _sprite;

public:
	GraphicsComponent();
	GraphicsComponent(string textureLocation);

	~GraphicsComponent(void);

	void SetTexture(string textureLocation);

	sf::Sprite GetSprite();
	
	sf::Vector2f getOrigin() { return _sprite.getOrigin(); };
	void setOrigin(sf::Vector2f newOrigin) { _sprite.setOrigin(newOrigin); };
	void setOrigin(float x, float y) { _sprite.setOrigin(x, y); };

	virtual void Update(float dt);
};


