#include <Windows.h>
#include <iostream>

using namespace std;

bool CheckMemory(const DWORDLONG physNeed, const DWORDLONG virtNeed);
DWORD ReadCPUSpeed();

int main(void) 
{

	cout << "CPU Speed is : " << ReadCPUSpeed() << " MHz" << endl;

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
