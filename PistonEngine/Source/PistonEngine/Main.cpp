#include "GameEngine.h"


int _stdcall WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
		GameEngine gameEngine;
		if (!gameEngine.Initialize(hInstance, hPrevInstance, lpCmdLine, nCmdShow))
			
			return 0;
		
		//game engine intialize
		//game engine start
		//runs within the game engine

		
		//return gameEngine.Run();
}


