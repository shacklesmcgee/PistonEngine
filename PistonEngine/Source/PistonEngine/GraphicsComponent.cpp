#include "GraphicsComponent.h"

GraphicsComponent::GraphicsComponent()
{
	name = "GraphicsComponent";
}

GraphicsComponent::~GraphicsComponent(void)
{
}

void GraphicsComponent::SetTexture(string textureLocation)
{
	if (!_texture.loadFromFile(textureLocation))
	{
		return;
	}

	else
		_sprite.setTexture(_texture);
}

sf::Sprite GraphicsComponent::GetSprite()
{
	return _sprite;
}

void GraphicsComponent::Update(float dt)
{
	_sprite.move(sf::Vector2f(0.1f, 0.1f));
}
