#pragma once
#include "BaseComponent.h"
#include "SFML/Graphics.hpp"

using namespace std;

class GraphicsComponent : public BaseComponent
{

private:
	sf::Texture _texture;
	sf::Sprite _sprite;

public:
	GraphicsComponent();
	~GraphicsComponent(void);

	void SetTexture(string textureLocation);

	sf::Sprite GetSprite();
	virtual void Update(float msec);

};


