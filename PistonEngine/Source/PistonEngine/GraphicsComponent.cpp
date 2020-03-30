#include "GraphicsComponent.h"
#include "GameObject.h"

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
	_lua["SetOrigin"] = &GraphicsComponent::SetOrigin;
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

void GraphicsComponent::SetOrigin(string newOrigin)
{
	if (newOrigin == "TopLeft")
	{
		sprite.setOrigin(0.0f, 0.0f);
	}

	else if (newOrigin == "TopCenter")
	{
		sprite.setOrigin(0.5f * sprite.getTexture()->getSize().x * sprite.getScale().x, 0.0f);
	}

	else if (newOrigin == "TopRight")
	{
		sprite.setOrigin(sprite.getTexture()->getSize().x * sprite.getScale().x, 0.0f);
	}

	else if (newOrigin == "MiddleLeft")
	{
		sprite.setOrigin(0.0f, 0.5f * sprite.getTexture()->getSize().y * sprite.getScale().y);
	}

	else if (newOrigin == "MiddleCenter")
	{
		sprite.setOrigin(0.5f * sprite.getTexture()->getSize().x * sprite.getScale().x, 0.5f * sprite.getTexture()->getSize().y * sprite.getScale().y);
	}

	else if (newOrigin == "MiddleRight")
	{
		sprite.setOrigin(sprite.getTexture()->getSize().x * sprite.getScale().x, 0.5f * sprite.getTexture()->getSize().y * sprite.getScale().y);
	}

	else if (newOrigin == "BottomLeft")
	{
		sprite.setOrigin(0.0f, sprite.getTexture()->getSize().y * sprite.getScale().y);
	}

	else if (newOrigin == "BottomCenter")
	{
		sprite.setOrigin(0.5f * sprite.getTexture()->getSize().x * sprite.getScale().x, sprite.getTexture()->getSize().y * sprite.getScale().y);
	}

	else if (newOrigin == "BottomRight")
	{
		sprite.setOrigin(sprite.getTexture()->getSize().x * sprite.getScale().x, sprite.getTexture()->getSize().y * sprite.getScale().y);
	}
}

void GraphicsComponent::SetOriginF(float x, float y)
{
	sprite.setOrigin(x, y);
}

void GraphicsComponent::Update(float dt)
{
}