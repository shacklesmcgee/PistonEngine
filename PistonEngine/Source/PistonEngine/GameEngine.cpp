#include <chrono>
#include <thread>
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
	Lua.open_libraries(sol::lib::base);

	Lua.script_file("Assets/settings.lua");
	bool isfullscreen = Lua["config"]["fullscreen"];
	int xRes = Lua["config"]["resolution"]["x"];
	int yRes = Lua["config"]["resolution"]["y"];

	_mainWindow.create(sf::VideoMode(xRes, yRes, 32), "Piston Engine");

	SplashScreen _splash;
	if (_splash.Show(_mainWindow) == false)
	{
		_gameState = GameState::ShowingSplash;
	}


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

	
	//sleeping for x seconds to show off splash screen
	//std::this_thread::sleep_for(std::chrono::seconds(2));
	_gameState = GameState::Uninitialized;
	
	return true;

}

void GameEngine::Start(sf::RenderWindow& _mainWindow)
{
	if (_gameState != GameState::Uninitialized)
		return;

	_gameState = GameEngine::Playing;

	//// //// CREATE YOUR GAME HERE //// ////
	
	//// //// PLACE YOUR GAME START FUNCTION HERE //// ////

	Lua.set("GameEngine", this);

	_sceneManager.LoadScene();
	startDelegates();

	while (_mainWindow.isOpen())
	{
		sf::Event event;
		while (_mainWindow.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				_mainWindow.close();
				break;

			case sf::Event::KeyPressed:
				dispatcher.post(InputEvent(true, event));
				break;

			case sf::Event::KeyReleased:
				dispatcher.post(InputEvent(false, event));
				break;

			case sf::Event::MouseButtonPressed:
				dispatcher.post(InputEvent(true, event));
				break;

			case sf::Event::MouseButtonReleased:
				dispatcher.post(InputEvent(false, event));
				break;

			default:
				break;

			}
			//if (event.type == sf::Event::MouseButtonPressed || event.type == sf::Event::KeyPressed)
				//dispatcher.post(InputEvent(true, event));

		}
		Update(_mainWindow);
	}
}


void GameEngine::Update(sf::RenderWindow& _mainWindow)
{
	sf::Time dt = _clock.restart();
	_mainWindow.clear();

	_sceneManager.Update(dt.asMilliseconds());

	for (auto const& value : _sceneManager.GetAllGameObjects()) {
		if (value->Graphics)
		{
			_mainWindow.draw(value->Graphics->GetSprite(), value->GetWorldTransform());
		}
	}
	_mainWindow.display();
}


void GameEngine::startDelegates()
{
	ClassObserver classObserver;

	/*auto connection1 = dispatcher.subscribe(InputEvent::descriptor,
		std::bind(&ClassObserver::handle,
			classObserver,
			std::placeholders::_1));*/

	//auto connection = dispatcher.subscribe(InputEvent::descriptor, std::bind(&SceneManager::Input, _sceneManager));
	auto connection = dispatcher.subscribe(InputEvent::descriptor, 
		std::bind(&SceneManager::Input, 
			_sceneManager,
			std::placeholders::_1));
}

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

