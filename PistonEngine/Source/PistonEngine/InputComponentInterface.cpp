#include "InputComponentInterface.h"


using namespace std;
string debugString; 
LPCSTR debugOutput;
InputComponentInterface::InputComponentInterface()
{
	
}

InputComponentInterface::~InputComponentInterface()
{

}


void InputComponentInterface::KeyboardInput(_In_ HWND   hWnd, _In_ UINT   message, _In_ WPARAM wParam, _In_ LPARAM lParam, Dispatcher dispatcher)
{

	switch (message)
	{
	case WM_KEYDOWN:
		debugString = to_string(wParam) + " down \n";
		debugOutput = debugString.c_str();
		OutputDebugString(debugOutput);
		break;
	case WM_KEYUP:
		debugString = to_string(wParam) + " up \n";
		debugOutput = debugString.c_str();
		OutputDebugString(debugOutput);
		break;
	case WM_LBUTTONDOWN:
		debugString = to_string(wParam) + " down \n";
		debugOutput = debugString.c_str();
		OutputDebugString(debugOutput);
		dispatcher.post(MouseEvent());
		break;
	case WM_LBUTTONUP:
		debugString = to_string(wParam) + " up \n";
		debugOutput = debugString.c_str();
		OutputDebugString(debugOutput);
		break;
	case WM_RBUTTONDOWN:
		debugString = to_string(wParam) + " down \n";
		debugOutput = debugString.c_str();
		OutputDebugString(debugOutput);
		break;
	case WM_RBUTTONUP:
		debugString = to_string(wParam) + " up \n";
		debugOutput = debugString.c_str();
		OutputDebugString(debugOutput);
		break;

	// the window is being destroyed, so terminate the application
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
}



