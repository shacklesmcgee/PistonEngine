#pragma once
#include "Windows.h"
#undef max
#undef min
#include "strsafe.h"
#include <string>
#include <cstring>
#include <iostream>
#include "conio.h"
#include "GameEngine.h"
#include "Dispatcher.h"
#include "MouseEvent.h"

class InputComponentInterface
{
public:
	InputComponentInterface();
	~InputComponentInterface();
	
	void KeyboardInput(_In_ HWND   hWnd, _In_ UINT   message, _In_ WPARAM wParam, _In_ LPARAM lParam, Dispatcher dispatcher);//keyboard key down
	
private:

};

