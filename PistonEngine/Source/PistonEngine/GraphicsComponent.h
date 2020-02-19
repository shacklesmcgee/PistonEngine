#pragma once
#include "BaseComponent.h"
#include "SFML/Graphics.hpp"
#include "sol.hpp"

using namespace std;
class GameObject;

class GraphicsComponent : public BaseComponent
{

public:
	GraphicsComponent(sol::state &_lua);
	GraphicsComponent(string textureLocation, sol::state &_lua);

	~GraphicsComponent(void);

	sf::Texture GetTexture()
	{ 
		return texture; 
	};

	void SetTexture(string textureLocation);

	sf::Sprite GetSprite();
	void SetSprite(sf::Texture);
	
	sf::Vector2f GetOrigin() { return sprite.getOrigin(); };
	float GetOriginX() { return sprite.getOrigin().x; };
	float GetOriginY() { return sprite.getOrigin().y; };
	void SetOrigin(sf::Vector2f newOrigin);
	void SetOriginF(float x, float y);

	void CentreOrigin();

	float GetWidth() { return texture.getSize().x; };
	float GetHeight() { return texture.getSize().y; };

	virtual void Update(float dt);

private:
	sf::Texture texture;
	sf::Sprite sprite;

	float width;
	float height;


};


