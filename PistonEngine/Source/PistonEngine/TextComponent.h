#pragma once
#include "BaseComponent.h"
#include "SFML/Graphics.hpp"

using namespace std;

class TextComponent : public BaseComponent
{

public:
	//TextComponent(string fontLocation, string newText, sol::state &_lua);
	TextComponent(string fontLocation, string newText, int charSize, sf::Color color, sol::state &_lua);

	~TextComponent(void);

	sf::Text GetText() { return text; };
	void SetText(string newText);

	sf::Vector2f GetOrigin() { return text.getOrigin(); };
	float GetOriginX() { return text.getOrigin().x; };
	float GetOriginY() { return text.getOrigin().y; };
	void SetOrigin(string newOrigin);
	void SetOriginF(float x, float y);

	float GetWidth() { return text.getLocalBounds().width; };
	float GetHeight() { return text.getLocalBounds().height; };

	virtual void Update(float dt);

private:
	sf::Font font;
	sf::Text text;

	sf::Clock clock;


};