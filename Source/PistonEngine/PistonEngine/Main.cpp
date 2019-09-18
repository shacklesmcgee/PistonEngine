#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

DWORD ReadCPUSpeed();
wstring ReadCPUArch();

int main(void) 
{

	cout << "CPU Speed is : " << ReadCPUSpeed() << " MHz" << endl;
	cout << "CPU Architechture is : " << ReadCPUArch(L"Identifier") << " MHz" << endl;


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

wstring ReadCPUArch(wstring name)
{
	DWORD BufSize = sizeof(DWORD);
	//wstring name = "Identifier";

	DWORD cbData;

	DWORD type;
	HKEY hKey;

	if (RegQueryValueEx(hKey, name.c_str(), NULL, &type, NULL, &cbData) != ERROR_SUCCESS)
	{
		RegCloseKey(hKey);
		throw "Could not read registry value";
	}

	if (type != REG_SZ)
	{
		RegCloseKey(hKey);
		throw "Incorrect registry value type";
	}

	wstring value(cbData / sizeof(wchar_t), L'\0');
	if (RegQueryValueEx(hKey, name.c_str(), NULL, NULL, reinterpret_cast<LPBYTE>(&value[0]), &cbData) != ERROR_SUCCESS)
	{
		RegCloseKey(hKey);
		throw "Could not read registry value";
	}

	RegCloseKey(hKey);

	size_t firstNull = value.find_first_of(L'\0');
	if (firstNull != string::npos)
		value.resize(firstNull);

	return value;
}

