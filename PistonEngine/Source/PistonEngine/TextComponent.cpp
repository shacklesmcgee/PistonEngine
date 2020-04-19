#include "TextComponent.h"


TextComponent::TextComponent(string fontLocation, string newText, int charSize, sf::Color color, sol::state &_lua)
{
	name = "TextComponent";

	if (!font.loadFromFile(fontLocation))
	{
		cout << fontLocation << " Font missing!" << endl;
	}

	text.setFont(font);
	text.setString(newText);
	text.setCharacterSize(charSize);
	text.setFillColor(color);

	_lua.set("Text", this);

	_lua["GetTextWidth"] = &TextComponent::GetWidth;
	_lua["GetTextHeight"] = &TextComponent::GetHeight;

	_lua["GetTextOrigin"] = &TextComponent::GetOrigin;
	_lua["SetTextOrigin"] = &TextComponent::SetOrigin;
	_lua["SetText"] = &TextComponent::SetText;
}

TextComponent::~TextComponent(void)
{
}

void TextComponent::SetText(string newText)
{
	text.setString(newText);
}

void TextComponent::SetOrigin(string newOrigin)
{
	if (newOrigin == "TopLeft")
	{
		text.setOrigin(0.0f, 0.0f);
	}

	else if (newOrigin == "TopCenter")
	{
		text.setOrigin(0.5f * text.getGlobalBounds().width * text.getScale().x, 0.0f);
	}

	else if (newOrigin == "TopRight")
	{
		text.setOrigin(text.getGlobalBounds().width * text.getScale().x, 0.0f);
	}

	else if (newOrigin == "MiddleLeft")
	{
		text.setOrigin(0.0f, 0.5f * text.getGlobalBounds().height * text.getScale().y);
	}

	else if (newOrigin == "MiddleCenter")
	{
		text.setOrigin(0.5f * text.getGlobalBounds().width * text.getScale().x, 0.5f * text.getGlobalBounds().height * text.getScale().y);
	}

	else if (newOrigin == "MiddleRight")
	{
		text.setOrigin(text.getGlobalBounds().width * text.getScale().x, 0.5f * text.getGlobalBounds().height * text.getScale().y);
	}

	else if (newOrigin == "BottomLeft")
	{
		text.setOrigin(0.0f, text.getGlobalBounds().height * text.getScale().y);
	}

	else if (newOrigin == "BottomCenter")
	{
		text.setOrigin(0.5f * text.getGlobalBounds().width * text.getScale().x, text.getGlobalBounds().height * text.getScale().y);
	}

	else if (newOrigin == "BottomRight")
	{
		text.setOrigin(text.getGlobalBounds().width * text.getScale().x, text.getGlobalBounds().height * text.getScale().y);
	}
}

void TextComponent::SetOriginF(float x, float y)
{
	text.setOrigin(x, y);
}

void TextComponent::Update(float dt)
{

}
