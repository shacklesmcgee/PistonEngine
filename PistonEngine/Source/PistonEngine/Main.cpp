#include "GameEngine.h"
#include "ArcheryGame.h"

int main()
{

	GameEngine gameEngine;
	static sf::RenderWindow mainWindow;

	//game engine intialize
	if (gameEngine.Initialize(mainWindow))
	{
		//game engine start
		gameEngine.Start(mainWindow);
	}

	////GameEngine gameEngine;
	//static sf::RenderWindow mainWindow;

	//ArcheryGame archeryGame;
	//if (archeryGame.Initialize(mainWindow))
	//{
	//	//game engine start
	//	archeryGame.Start(mainWindow);
	//}

	return 0;
}

