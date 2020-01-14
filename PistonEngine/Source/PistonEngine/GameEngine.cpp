#include "GameEngine.h"


using namespace std;

static TCHAR szWindowClass[] = _T("Piston Engine");
static TCHAR szTitle[] = _T("Piston Engine tester window");


GameEngine::GameEngine()
{

}

GameEngine::~GameEngine()
{
}

bool GameEngine::Initialize(sf::RenderWindow& _mainWindow)
{
	_gameState = GameEngine::Uninitialized;

	//sf::RenderWindow _mainWindow(sf::VideoMode(1024, 768, 32), "Piston Engine");
	_mainWindow.create(sf::VideoMode(1024, 768, 32), "Piston Engine");

	SplashScreen _splash;
	_splash.Show(_mainWindow);

	if (FindWindow("Piston Engine", 0))
	{
		cout << "There is already an instance of the game!" << endl;
		return false;
	}
	if (!CheckMemory(300, 300))
	{
		return false;
	}
	if (!CheckStorage(diskSpaceNeeded))
	{
		return false;
	}

	//maybe change to check cpu speed
	ReadCPUSpeed();
	ReadCPUArch();
	testDelegates();

	return true;

}


void GameEngine::Start(sf::RenderWindow& _mainWindow)
{
	if (_gameState != GameEngine::Uninitialized)
		return;

	_gameState = GameEngine::Playing;
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (_mainWindow.isOpen())
	{
		sf::Event event;
		while (_mainWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				_mainWindow.close();
		}

		_mainWindow.clear();
		_mainWindow.draw(shape);
		_mainWindow.display();
	}
}
void GameEngine::testDelegates()
{
	ClassObserver classObserver;

	//auto connection1 = dispatcher.subscribe(MouseEvent::descriptor, mouseObserver);
	auto connection1 = dispatcher.subscribe(MouseEvent::descriptor,
		std::bind(&ClassObserver::handle,
			classObserver,
			std::placeholders::_1));
}
//
//LRESULT CALLBACK WndProc(_In_ HWND   hWnd, _In_ UINT   message, _In_ WPARAM wParam, _In_ LPARAM lParam)
//{
//	return DefWindowProc(hWnd, message, wParam, lParam);
//}

//
//void GameEngine::CreateGameWindow(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
//{
//
//	HINSTANCE hInst;
//	HWND hWnd;
//
//	WNDCLASSEX wcex;
//
//	wcex.cbSize = sizeof(WNDCLASSEX);
//	wcex.style = CS_HREDRAW | CS_VREDRAW;
//	wcex.lpfnWndProc = WndProc;
//	wcex.cbClsExtra = 0;
//	wcex.cbWndExtra = 0;
//	wcex.hInstance = hInstance;
//	wcex.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
//	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
//	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
//	wcex.lpszMenuName = NULL;
//	wcex.lpszClassName = szWindowClass;
//	wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);
//
//	if (!RegisterClassEx(&wcex))
//	{
//		MessageBox(NULL,
//			_T("Call to RegisterClassEx failed!"),
//			_T("Windows Desktop Guided Tour"),
//			NULL);
//
//		//return 1;
//	}
//
//	// Store instance handle in a variable
//	hInst = hInstance;
//
//	// The parameters to CreateWindow explained:
//	// szWindowClass: the name of the application
//	// szTitle: the text that appears in the title bar
//	// WS_OVERLAPPEDWINDOW: the type of window to create
//	// CW_USEDEFAULT, CW_USEDEFAULT: initial position (x, y)
//	// 500, 100: initial size (width, length)
//	// NULL: the parent of this window
//	// NULL: this application dows not have a menu bar
//	// hInstance: the first parameter from WinMain
//	// NULL: not used in this application
//	hWnd = CreateWindow(
//		szWindowClass,
//		szTitle,
//		WS_OVERLAPPEDWINDOW,
//		CW_USEDEFAULT, CW_USEDEFAULT,
//		500, 500,
//		NULL,
//		NULL,
//		hInstance,
//		NULL
//	);
//
//	if (!hWnd)
//	{
//		MessageBox(NULL,
//			_T("Call to CreateWindow failed!"),
//			_T("Windows Desktop Guided Tour"),
//			NULL);
//
//		//return 1;
//	}
//
//	// The parameters to ShowWindow explained:
//	// hWnd: the value returned from CreateWindow
//	// nCmdShow: the fourth parameter from WinMain
//	ShowWindow(hWnd, nCmdShow);
//	UpdateWindow(hWnd);
//
//	InputComponentInterface in;
//
//	// Main message loop:
//	MSG msg;
//	while (GetMessage(&msg, NULL, 0, 0))
//	{
//		in.KeyboardInput(hWnd, msg.message, msg.wParam, msg.lParam, dispatcher);
//		TranslateMessage(&msg);
//		DispatchMessage(&msg);
//	}
//
//	//return (int)msg.wParam;
//}

_diskfree_t populateStruct()
{
	int const drive = _getdrive();
	struct _diskfree_t diskfree;

	if (_getdiskfree(drive, &diskfree) == 0)
	{
		return diskfree;
	}
	else
	{
		cout << "Struct was not populated correctly." << endl;
		return diskfree;
	}
}

bool GameEngine::CheckStorage(const float diskSpaceNeeded)
{
	struct _diskfree_t diskfree = populateStruct();

	cout << diskfree.avail_clusters << endl;

	float neededClusters = (diskSpaceNeeded / (diskfree.sectors_per_cluster * diskfree.bytes_per_sector));

	if (diskfree.avail_clusters < neededClusters)
	{
		cout << "Not enough storage" << endl;
		return false;
	}
	else if (diskfree.avail_clusters >= neededClusters)
	{
		cout << "Enough memory allocated." << endl;
		return true;
	}
}

void GameEngine::ReadCPUSpeed()
{
	DWORD BufSize = sizeof(DWORD);
	DWORD dwMHz = 0;
	DWORD type = REG_DWORD;
	HKEY hKey;

	long lError = RegOpenKeyEx(HKEY_LOCAL_MACHINE,
		"HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0",
		0,
		KEY_READ,
		&hKey);

	if (lError == ERROR_SUCCESS)
	{
		RegQueryValueEx(hKey,
			"~MHZ",
			NULL,
			&type,
			(LPBYTE)& dwMHz,
			&BufSize);
	}

	cout << "CPU Speed is : " << dwMHz << " MHz" << endl;
}

void GameEngine::ReadCPUArch()
{
	char buf[255];
	DWORD BufSize = sizeof(buf);
	DWORD type = REG_SZ;
	HKEY hKey;



	long lError = RegOpenKeyEx(HKEY_LOCAL_MACHINE,
		"HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0",
		0,
		KEY_READ,
		&hKey);

	if (lError == ERROR_SUCCESS)
	{
		RegQueryValueEx(hKey,
			"Identifier",
			NULL,
			&type,
			(unsigned char*)buf,
			&BufSize);
	}
	RegCloseKey(hKey);

	cout << "CPU Architechture is : " << buf << endl;
}

bool GameEngine::CheckMemory(const DWORDLONG physNeed, const DWORDLONG virtNeed)
{
	MEMORYSTATUSEX status;
	status.dwLength = sizeof(status);
	GlobalMemoryStatusEx(&status);

	if (status.ullAvailPhys < (physNeed * (1024 * 1024)))
	{
		cout << "Not enough physical memory!" << endl;
		return false;
	}

	if (status.ullAvailVirtual < (virtNeed * (1024 * 1024)))
	{
		cout << "Not enough virtual memory!" << endl;
		return false;
	}

	cout << "Available Physical RAM : " << status.ullAvailPhys / (1024 * 1024) << " MB" << endl;
	cout << "Available Virtual RAM : " << status.ullAvailVirtual / (1024 * 1024) << " MB" << endl;

	return true;
}

