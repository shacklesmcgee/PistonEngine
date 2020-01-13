#include "GameEngine.h"

int main()
{
	GameEngine gameEngine;

	if (gameEngine.Initialize())	
		gameEngine.Start();

	return 0;
}


