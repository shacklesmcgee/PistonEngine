#include "GraphicsComponent.h"

GraphicsComponent::GraphicsComponent(sol::state &_lua)
{
	name = "GraphicsComponent";
}

GraphicsComponent::GraphicsComponent(string textureLocation, sol::state &_lua)
{
	name = "GraphicsComponent";
	SetTexture(textureLocation);

	_lua.set("Graphics", this);

	_lua["GetWidth"] = &GraphicsComponent::GetWidth; 
	_lua["GetHeight"] = &GraphicsComponent::GetHeight;
	_lua["GetOrigin"] = &GraphicsComponent::GetOrigin;
	_lua["GetOriginX"] = &GraphicsComponent::GetOriginX;
	_lua["CentreOrigin"] = &GraphicsComponent::CentreOrigin;
}

GraphicsComponent::~GraphicsComponent(void)
{
}

void GraphicsComponent::SetTexture(string textureLocation)
{
	if (!texture.loadFromFile(textureLocation))
	{
		return;
	}

	else
		sprite.setTexture(texture);
}

sf::Sprite GraphicsComponent::GetSprite()
{
	return sprite;
}

void GraphicsComponent::SetSprite(sf::Texture texture)
{
	sprite.setTexture(texture);
}

void GraphicsComponent::SetOrigin(sf::Vector2f newOrigin)
{
	sprite.setOrigin(newOrigin);
}

void GraphicsComponent::SetOriginF(float x, float y)
{
	sprite.setOrigin(x, y);
}

void GraphicsComponent::CentreOrigin()
{
	sprite.setOrigin(sprite.getTexture()->getSize().x / 2.f, sprite.getTexture()->getSize().y / 2.f);
}

void GraphicsComponent::Update(float dt)
{
}