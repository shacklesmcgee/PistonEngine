#include "GameEngine.h"

int _stdcall WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	/*GameEngine gameEngine;
	if (!gameEngine.Initialize(hInstance, hPrevInstance, lpCmdLine, nCmdShow))	
		return 0;*/


	//Works here but not in game engine class
	sf::RenderWindow _mainWindow(sf::VideoMode(1024, 768, 32), "GameName");

	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (_mainWindow.isOpen())
	{
		sf::Event event;

		while (_mainWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				_mainWindow.close();
		}

		_mainWindow.clear();
		_mainWindow.draw(shape);
		_mainWindow.display();
	}

	
}

bool IsExiting(sf::RenderWindow _window)
{
	

	return false;
}



