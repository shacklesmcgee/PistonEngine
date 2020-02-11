#include "GraphicsComponent.h"

GraphicsComponent::GraphicsComponent()
{
	name = "GraphicsComponent";
	//_mainWindow.draw(_sprite);
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

void GraphicsComponent::Update(float msec)
{
}
