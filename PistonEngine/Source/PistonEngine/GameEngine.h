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
#include "SplashScreen.h"
#include "GameObjectManager.h"
#include "GameObject.h"
#include "RigidBodyComponent.h"
#include "GraphicsComponent.h"
#include "TransformComponent.h"
#include "AudioComponent.h"
#include "ScriptComponent.h"

#include <lua.hpp>
#define SOL_ALL_SAFETIES_ON 1
#include <sol.hpp>




#include "Windows.h"
#undef max
#undef min

class GameEngine {
public:
	GameEngine();
	~GameEngine();

	bool Initialize(sf::RenderWindow& _mainWindow);
	virtual void Start(sf::RenderWindow& _mainWindow);
	virtual void Update(sf::RenderWindow& _mainWindow);

	enum GameState { Uninitialized, ShowingSplash, Paused, ShowingMenu, Playing, Exiting };
	GameState _gameState;

	Dispatcher dispatcher;

	GameObjectManager _gameObjectManager;
	sf::Clock _clock;
	
	sol::state lua;

	void PrintInt(int value);
private:
	const float diskSpaceNeeded = 300;

	bool checksPassed = true;
	void ReadCPUSpeed();
	void ReadCPUArch();
	bool CheckStorage(const float diskSpaceNeeded);
	bool CheckMemory(const DWORDLONG physNeed, const DWORDLONG virtNeed);
	void startDelegates();

	//sf::RenderWindow mainWindow;
	
};