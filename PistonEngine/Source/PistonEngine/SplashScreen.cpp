#include "SplashScreen.h"

bool SplashScreen::Show(sf::RenderWindow& _mainWindow) {
	sf::Texture _texture;

	if (!_texture.loadFromFile("Assets/SplashScreen.png"))
	{
		return false;
	}

	sf::Sprite _sprite;
	_sprite.setTexture(_texture);

	float texX = _sprite.getTexture()->getSize().x;
	float winX = _mainWindow.getSize().x;
	float scaleX = winX / texX;

	float texY = _sprite.getTexture()->getSize().y;
	float winY = _mainWindow.getSize().y;
	float scaleY = winY / texY;

	_sprite.scale(scaleX, scaleY);

	_mainWindow.draw(_sprite);
	_mainWindow.display();
	
	sf::Event event;
	while (_mainWindow.pollEvent(event)) {
		if (event.type == sf::Event::EventType::KeyPressed || event.type == sf::Event::EventType::MouseButtonPressed) {
			return false;
		}
	}
}