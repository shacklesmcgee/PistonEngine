#pragma once
#include "Windows.h"
#include "strsafe.h"
#include <string>
#include <cstring>
#include <iostream>
#include "conio.h"
#include "GameEngine.h"

class InputComponentInterface
{
public:
	InputComponentInterface();
	~InputComponentInterface();
	
	void KeyboardInput(_In_ HWND   hWnd, _In_ UINT   message, _In_ WPARAM wParam, _In_ LPARAM lParam);//keyboard key down

private:
	
	//bool OnKeyUp(unsigned int const keyCode);//keyboard key up


};

