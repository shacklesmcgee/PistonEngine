#include "SplashScreen.h"

void SplashScreen::Show(sf::RenderWindow& _mainWindow) {
	sf::Texture _texture;

	if (!_texture.loadFromFile("images/SplashScreen.png"))
	{
		return;
	}

	sf::Sprite _sprite;
	_sprite.setTexture(_texture);

	_mainWindow.draw(_sprite);
	_mainWindow.display();
	sf::Event event;
	while (_mainWindow.pollEvent(event)) {
		if (event.type == sf::Event::EventType::KeyPressed || event.type == sf::Event::EventType::MouseButtonPressed) {
				return;
		}
	}
}