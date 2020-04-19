#pragma once
#include "BaseComponent.h"
#include "SFML/Graphics.hpp"
#include "Animation.h"

using namespace std;
class GameObject;

class GraphicsComponent : public BaseComponent
{

public:
	GraphicsComponent(sol::state &_lua);
	GraphicsComponent(string textureName, string textureLocation, sf::IntRect textureRect, bool animated, float frameTime, bool looping, sol::state &_lua);

	~GraphicsComponent(void);

	sf::Texture GetTexture()
	{ 
		return currentAnim.Texture;
	};

	void SetTexture(Animation &_animToSet);

	sf::Sprite GetSprite();
	void SetSprite(sf::Texture);
	
	sf::Vector2f GetOrigin() { return currentAnim.Sprite.getOrigin(); };
	float GetOriginX() { return currentAnim.Sprite.getOrigin().x; };
	float GetOriginY() { return currentAnim.Sprite.getOrigin().y; };
	void SetOrigin(string newOrigin);
	void SetOriginF(float x, float y);

	float GetWidth() { return currentAnim.SpriteRect.width; };
	float GetHeight() { return currentAnim.SpriteRect.height; };

	virtual void Update(float dt);

	void PlayAnim(sol::table newAnim);
	void PauseAnim();

	void CreateAnim(sol::table newAnim);

private:

	Animation currentAnim;
	Animation prevAnim;
	std::map<string, Animation> animations;

	sf::Clock clock;


};