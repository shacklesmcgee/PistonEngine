#include <iostream>
#include "Windows.h"
//#include <stdio.h>
//#include <conio.h>
#include <direct.h>
//#include <stdlib.h>
//#include <ctype.h>

using namespace std;

bool isRunning = false;
const int diskSpaceNeeded = 1000000000000;

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
	}
}

void CheckStorage(const int diskSpaceNeeded)
{
	struct _diskfree_t diskfree = populateStruct();

	int neededClusters =
		(diskSpaceNeeded / (diskfree.sectors_per_cluster * diskfree.bytes_per_sector));
	
	if (diskfree.avail_clusters < neededClusters)
	{
		cout << "Not enough storage" << endl;
	}
	else
	{
		cout << diskfree.bytes_per_sector << endl;
		cout <
		cout << diskfree.avail_clusters << endl;
		cout << "Enough memory allocated." << endl;
	}
}

int main()
{
	CheckIsRunning();
	CheckStorage(diskSpaceNeeded);
	return 0;
}
