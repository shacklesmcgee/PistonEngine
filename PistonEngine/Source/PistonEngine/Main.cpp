#include <iostream>
#include "Windows.h"
//#include <stdio.h>
//#include <conio.h>
#include <direct.h>
//#include <stdlib.h>
//#include <ctype.h>
#include <string>
#include <vector>

using namespace std;

bool isRunning = false;
const float diskSpaceNeeded = 300;

void ReadCPUSpeed();
void ReadCPUArch();
bool CheckMemory(const DWORDLONG physNeed, const DWORDLONG virtNeed);

bool CheckIsRunning()
{
	if (isRunning == true)
	{
		cout << "There is already an instance of the game." << endl;
		return true;
	}
	else
	{
		cout << "There is no instance of the game running. Generating instance." << endl;
		return false;
	}
};

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

void CheckStorage(const float diskSpaceNeeded)
{
	struct _diskfree_t diskfree = populateStruct();

	cout << diskfree.avail_clusters << endl;

	float neededClusters = (diskSpaceNeeded/ (diskfree.sectors_per_cluster * diskfree.bytes_per_sector));
	
	if (diskfree.avail_clusters < neededClusters)
	{
		cout << "Not enough storage" << endl;
	}
	else if(diskfree.avail_clusters >= neededClusters)
	{
		cout << "Enough memory allocated." << endl;
	}
}

void ReadCPUSpeed()
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

void ReadCPUArch()
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

bool CheckMemory(const DWORDLONG physNeed, const DWORDLONG virtNeed)
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

int main()
{
	if (CheckIsRunning())
	{
		return 0;
	}
	isRunning = true;
	//generate window, set is

	CheckStorage(diskSpaceNeeded);

	ReadCPUSpeed();
	ReadCPUArch();


	//Check Physical RAM error
	//if (CheckMemory(30000, 300))
	//{
	//	//Run Game
	//}

	//Check Virtual RAM error
	//if (CheckMemory(300, 300000000))
	//{
	//	//Run Game
	//}

	//Check Available RAM
	if (CheckMemory(300, 300))
	{
		//Run Game
	}

	system("PAUSE");
	return 0;
}
