#include "GameEngine.h"


int main()
{

	GameEngine gameEngine;
	static sf::RenderWindow mainWindow;

	if (gameEngine.Initialize(mainWindow))	
		gameEngine.Start(mainWindow);

	//if (!gameEngine.Initialize(hInstance, hPrevInstance, lpCmdLine, nCmdShow))
			
			return 0;
		
		//game engine intialize
		//game engine start
		//runs within the game engine

	return 0;
}

