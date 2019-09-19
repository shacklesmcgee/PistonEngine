#include <iostream>
#include "Windows.h"
//#include <stdio.h>
//#include <conio.h>
#include <direct.h>
//#include <stdlib.h>
//#include <ctype.h>

using namespace std;

bool isRunning = false;
const float diskSpaceNeeded = 300;

bool CheckMemory(const DWORDLONG physNeed, const DWORDLONG virtNeed);

void CheckIsRunning()
{
	if (isRunning == true)
	{
		cout << "There is already an instance of the game." << endl;
	}
	else
	{
		isRunning = true;
		cout << "There is no instance of the game running. Generating instance." << endl;
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
	CheckIsRunning();
	CheckStorage(diskSpaceNeeded);

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
