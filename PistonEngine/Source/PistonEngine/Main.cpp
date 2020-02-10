#include "GameEngine.h"

int main()
{
	GameEngine gameEngine;
	static sf::RenderWindow mainWindow;

	if (gameEngine.Initialize(mainWindow))	
		gameEngine.Start(mainWindow);

	return 0;
}


