#pragma once

#include <iostream>
#include "Windows.h"
#include <direct.h>
#include <string>
#include <vector>
#include <tchar.h>
#include "InputComponentInterface.h"

class GameEngine {
public:
	GameEngine();
	~GameEngine();

	bool Initialize(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);

private:
	const float diskSpaceNeeded = 300;


	void CreateGameWindow(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);
	bool checksPassed = true;
	void ReadCPUSpeed();
	void ReadCPUArch();
	bool CheckStorage(const float diskSpaceNeeded);
	bool CheckMemory(const DWORDLONG physNeed, const DWORDLONG virtNeed);
};