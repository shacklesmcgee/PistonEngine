#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <direct.h>
#include <string>
#include <vector>
#include <tchar.h>
#include "InputComponentInterface.h"
#include "ClassObserver.h"
#include "Dispatcher.h"
#include "Connection.h"
#include "Windows.h"
#undef max
#undef min

class GameEngine {
public:
	GameEngine();
	~GameEngine();

	bool Initialize();
	void Start();

	Dispatcher dispatcher;
private:
	const float diskSpaceNeeded = 300;

	static bool IsExiting();
	static void GameLoop();

	enum GameState {Uninitialized, ShowingSplash, Paused, ShowingMenu, Playing, Exiting};
	GameState _gameState;

	//Problem seems to be here, i dunno
	//static sf::RenderWindow _mainWindow;

	//void CreateGameWindow(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);
	bool checksPassed = true;
	void ReadCPUSpeed();
	void ReadCPUArch();
	bool CheckStorage(const float diskSpaceNeeded);
	bool CheckMemory(const DWORDLONG physNeed, const DWORDLONG virtNeed);
	void testDelegates();
};