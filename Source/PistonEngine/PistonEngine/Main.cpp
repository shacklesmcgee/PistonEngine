#include <Windows.h>
#include <iostream>

using namespace std;

bool CheckMemory(const DWORDLONG physNeed, const DWORDLONG virtNeed);
DWORD ReadCPUSpeed();

int main(void) 
{
	//Check for RAM Size Errors
	//if (CheckMemory(30000000, 30000000))
	//{
		//Run Game
	//}


	if (CheckMemory(300, 300))
	{
		cout << "CPU Speed is : " << ReadCPUSpeed() << " MHz" << endl;
	}
	system("PAUSE");
	return 0;

}

DWORD ReadCPUSpeed() 
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
			(LPBYTE)&dwMHz,
			&BufSize);
	}
	return dwMHz;
}

bool CheckMemory(const DWORDLONG physNeed, const DWORDLONG virtNeed)
{
	MEMORYSTATUSEX status;
	status.dwLength = sizeof(status);
	GlobalMemoryStatusEx(&status);

	if (status.ullAvailPhys < (physNeed * 1024))
	{
		cout << "Not enough physical memory!" << endl;
		return false;
	}

	if (status.ullAvailVirtual < (virtNeed * 1024))
	{
		//GCP_ERROR();

		cout << "Not enough virtual memory!" << endl;
		return false;
	}
	
	cout << "Available Physical RAM : " << status.ullAvailPhys / (1024) << " MB" << endl;
	cout << "Available Virtual RAM : " << status.ullAvailVirtual / (1024) << " MB" << endl;

	return true;
}