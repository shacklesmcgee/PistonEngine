#include "GraphicsComponent.h"
#include "GameObject.h"

GraphicsComponent::GraphicsComponent(sol::state &_lua)
{
	name = "GraphicsComponent";
}

GraphicsComponent::GraphicsComponent(string _name, string _location, sf::IntRect _rect, bool _animated, float _frameTime, bool _looping, sol::state &_lua)
{
	name = "GraphicsComponent";

	currentAnim = Animation(_name, _location, _rect, _animated, _frameTime, _looping);
	SetTexture(currentAnim);
	animations.emplace(std::pair<string, Animation>(currentAnim.Name, currentAnim));	



	_lua.set("Graphics", this);

	_lua["GetWidth"] = &GraphicsComponent::GetWidth; 
	_lua["GetHeight"] = &GraphicsComponent::GetHeight;

	_lua["GetOrigin"] = &GraphicsComponent::GetOrigin;
	_lua["SetOrigin"] = &GraphicsComponent::SetOrigin;

	_lua["PlayAnim"] = &GraphicsComponent::PlayAnim;
	_lua["PauseAnim"] = &GraphicsComponent::PauseAnim;
	_lua["CreateAnim"] = &GraphicsComponent::CreateAnim;
}

GraphicsComponent::~GraphicsComponent(void)
{
}

void GraphicsComponent::SetTexture(Animation &_animToSet) //string textureLocation, sf::IntRect textureRect)
{
	if (!_animToSet.Texture.loadFromFile(_animToSet.TextureLocation))
	{
		return;
	}

	else
	{
		_animToSet.Sprite.setTexture(_animToSet.Texture);
		_animToSet.Sprite.setTextureRect(_animToSet.SpriteRect);
	}
}

sf::Sprite GraphicsComponent::GetSprite()
{
	return currentAnim.Sprite;
}

void GraphicsComponent::SetSprite(sf::Texture texture)
{
	currentAnim.Sprite.setTexture(texture);
}

void GraphicsComponent::SetOrigin(string newOrigin)
{
	if (newOrigin == "TopLeft")
	{
		currentAnim.Sprite.setOrigin(0.0f, 0.0f);
	}

	else if (newOrigin == "TopCenter")
	{
		currentAnim.Sprite.setOrigin(0.5f * currentAnim.Sprite.getTextureRect().width * currentAnim.Sprite.getScale().x, 0.0f);
	}

	else if (newOrigin == "TopRight")
	{
		currentAnim.Sprite.setOrigin(currentAnim.Sprite.getTextureRect().width * currentAnim.Sprite.getScale().x, 0.0f);
	}

	else if (newOrigin == "MiddleLeft")
	{
		currentAnim.Sprite.setOrigin(0.0f, 0.5f * currentAnim.Sprite.getTextureRect().height * currentAnim.Sprite.getScale().y);
	}

	else if (newOrigin == "MiddleCenter")
	{
		currentAnim.Sprite.setOrigin(0.5f * currentAnim.Sprite.getTextureRect().width * currentAnim.Sprite.getScale().x, 0.5f * currentAnim.Sprite.getTextureRect().height * currentAnim.Sprite.getScale().y);
	}

	else if (newOrigin == "MiddleRight")
	{
		currentAnim.Sprite.setOrigin(currentAnim.Sprite.getTextureRect().width * currentAnim.Sprite.getScale().x, 0.5f * currentAnim.Sprite.getTextureRect().height * currentAnim.Sprite.getScale().y);
	}

	else if (newOrigin == "BottomLeft")
	{
		currentAnim.Sprite.setOrigin(0.0f, currentAnim.Sprite.getTextureRect().height * currentAnim.Sprite.getScale().y);
	}

	else if (newOrigin == "BottomCenter")
	{
		currentAnim.Sprite.setOrigin(0.5f * currentAnim.Sprite.getTextureRect().width * currentAnim.Sprite.getScale().x, currentAnim.Sprite.getTextureRect().height * currentAnim.Sprite.getScale().y);
	}

	else if (newOrigin == "BottomRight")
	{
		currentAnim.Sprite.setOrigin(currentAnim.Sprite.getTextureRect().width * currentAnim.Sprite.getScale().x, currentAnim.Sprite.getTextureRect().height * currentAnim.Sprite.getScale().y);
	}
}

void GraphicsComponent::SetOriginF(float x, float y)
{
	currentAnim.Sprite.setOrigin(x, y);
}

void GraphicsComponent::Update(float dt)
{
	if (currentAnim.Playing)
	{
		if (clock.getElapsedTime().asSeconds() > currentAnim.FrameTime) 
		{
			if (currentAnim.SpriteRect.left == (currentAnim.Sprite.getTexture()->getSize().x - currentAnim.SpriteRect.width))
			{
				currentAnim.SpriteRect.left = currentAnim.StartX;

				if (!currentAnim.Looping)
				{
					currentAnim.Playing = false;
					currentAnim.SpriteRect.left = (currentAnim.Sprite.getTexture()->getSize().x - currentAnim.SpriteRect.width);
				}	
			}
			else
				currentAnim.SpriteRect.left += currentAnim.SpriteRect.width;

			currentAnim.Sprite.setTextureRect(currentAnim.SpriteRect);
			clock.restart();
		}
	}
}

void GraphicsComponent::PlayAnim(sol::table newAnim)
{
	Animation playAnim = animations.at(newAnim["name"]);
	if (currentAnim.Name != playAnim.Name)
	{
		PauseAnim();
		currentAnim = playAnim;
	}
	currentAnim.Playing = true;
}

void GraphicsComponent::PauseAnim()
{
	currentAnim.Playing = false;
}

void GraphicsComponent::CreateAnim(sol::table newAnim)
{
	if (!newAnim["name"].valid())
	{
		cout << "Error Missing Animation Name!" << endl;
		return;
	}

	else if (!newAnim["texture"].valid())
	{
		cout << "Error Missing Texture Location!" << endl;
		return;
	}

	else if (!newAnim["textureX"].valid() || !newAnim["textureY"].valid() || !newAnim["textureWidth"].valid() || !newAnim["textureHeight"].valid())
	{
		cout << "Error Missing Texture Rect!" << endl;
		return;
	}

	else if (!newAnim["frameTime"].valid())
	{
		cout << "Error Missing Frame Times!" << endl;
		return;
	}

	else if (!newAnim["looping"].valid())
	{
		cout << "Error Missing Looping Bool!" << endl;
		return;
	}

	currentAnim = Animation(newAnim["name"],
		newAnim["texture"],
		sf::IntRect(newAnim["textureX"], newAnim["textureY"], newAnim["textureWidth"], newAnim["textureHeight"]),
		newAnim["animated"],
		newAnim["frameTime"],
		newAnim["looping"]);

	SetTexture(currentAnim);
	animations.emplace(std::pair<string, Animation>(currentAnim.Name, currentAnim));


}
