#include "GameEngine.h"

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
		gameEngine.Start(mainWindow);

	//if (!gameEngine.Initialize(hInstance, hPrevInstance, lpCmdLine, nCmdShow))

	return 0;
}


