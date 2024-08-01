/*
Created at 2015
(2024 adnotation)
Code represent cheat app for the game called AssoultCube.


Quick highlight of use:
- Async data collection (Keyboard keys statement)
- Process memory editing using adressess (process.h)
- Standard Library calls
- Loops
- Statements
- Functions
*/

#include <Windows.h>
#include <iostream>
#include <process.h>

#define VK_F	0x046
#define VK_G	0x047
#define VK_H	0x048
#define VK_C	0x043
#define VK_V	0x056
#define VK_Z	0x05A
#define VK_SPACE 0x020

using namespace std;

bool isRunning = true;
bool key[7];

void help()
{
	cout << "Moder Tool\n" << endl;
	cout << "Key     | Description " << endl;
	cout << "'Z'     | Health Up " << endl;
	cout << "'C'     | Down" << endl;
	cout << "'Space' | UP" << endl;
	cout << "'F'     | Infinity mag clips" << endl;
	cout << "'G'     | Infinity ammo" << endl;
	cout << "'H'     | GodMode" << endl;
	cout << "'V'     | Help" << endl;
}

void __cdecl GetKeys(void * Args)
{
	while (isRunning == true)
		if (GetAsyncKeyState(VK_F) < 0)
		{
			keybd_event(VK_F, 0, KEYEVENTF_KEYUP, 0);
			if (key[1] == false)
			{
				cout << "Infinity Mags On.." << endl;
				key[1] = true;
			}
			else
				if (key[1] == true)
				{
					cout << "Infinity Mags Off.." << endl;
					key[1] = false;
				}
		}
		else
			if (GetAsyncKeyState(VK_G) < 0)
			{
				keybd_event(VK_G, 0, KEYEVENTF_KEYUP, 0);
				if (key[2] == false)
				{
					cout << "Infinity Ammo On.." << endl;
					key[2] = true;
				}
				else
					if (key[2] == true)
					{
						cout << "Infinity Ammo Off.." << endl;
						key[2] = false;
					}
			}
			else
				if (GetAsyncKeyState(VK_H) < 0)
				{
					keybd_event(VK_H, 0, KEYEVENTF_KEYUP, 0);
					if (key[3] == false)
					{
						cout << "Infinity Health On.." << endl;
						key[3] = true;
					}
					else
						if (key[3] == true)
						{
							cout << "Infinity Health Off.." << endl;
							key[3] = false;
						}
				}
				else
					if (GetAsyncKeyState(VK_C) < 0)
					{
						keybd_event(VK_C, 0, KEYEVENTF_KEYUP, 0);
						cout << "Teleport up.." << endl;
						key[4] = true;
					}
					else
						if (GetAsyncKeyState(VK_Z) < 0)
						{
							keybd_event(VK_Z, 0, KEYEVENTF_KEYUP, 0);
							cout << "Healed.." << endl;
							key[6] = true;
						}

						else
							if (GetAsyncKeyState(VK_V) < 0)
							{
								keybd_event(VK_V, 0, KEYEVENTF_KEYUP, 0);
								cout << "Teleport down.." << endl;
								key[5] = true;
							}
}
						



int main()
{
	long adress[5];
	adress[1] = 0x00B3A5F8; // health
	adress[2] = 0x00B3A624; // mags
	adress[3] = 0x00B3A64C; // ammo
	adress[4] = 0x00B3A53C; // Up Down
	DWORD processId;
	HANDLE hProcess = NULL;
	int health = 0, mags = 0, ammo = 0; float tel = 0;
	bool isGameDetect = false;
	help();
	_beginthread(GetKeys, 0, 0);
	while (isRunning == true)
	{
		if (HWND hGameWindow = FindWindow(0, L"AssaultCube"))
		{
			if (isGameDetect == false)
			{
				cout << "Game  Found!\n";
				isGameDetect = true;
			}
			GetWindowThreadProcessId(hGameWindow, &processId);
			hProcess = OpenProcess(PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_VM_OPERATION, false, processId);
			while (isRunning == true)
			{
				if (isRunning == false)
					CloseHandle(hProcess);
				if (key[1] == true)
				{
					ReadProcessMemory(hProcess, (LPVOID)adress[2], &mags, sizeof(long), 0);
					mags = 40;
					CloseHandle(hProcess);
					hProcess = OpenProcess(PROCESS_VM_WRITE | PROCESS_VM_OPERATION, false, processId);
					WriteProcessMemory(hProcess, (LPVOID)adress[2], &mags, sizeof(long), 0);
				}
				if (key[2] == true)
				{
					ReadProcessMemory(hProcess, (LPVOID)adress[3], &ammo, sizeof(long), 0);
					ammo = 666;
					CloseHandle(hProcess);
					hProcess = OpenProcess(PROCESS_VM_WRITE | PROCESS_VM_OPERATION, false, processId);
					WriteProcessMemory(hProcess, (LPVOID)adress[3], &ammo, sizeof(long), 0);
				}
				if (key[3] == true)
				{
					ReadProcessMemory(hProcess, (LPVOID)adress[1], &health, sizeof(long), 0);
					health = 100;
					CloseHandle(hProcess);
					hProcess = OpenProcess(PROCESS_VM_WRITE | PROCESS_VM_OPERATION, false, processId);
					WriteProcessMemory(hProcess, (LPVOID)adress[1], &health, sizeof(long), 0);
				}
				if (key[4] == true)
				{
					ReadProcessMemory(hProcess, (LPVOID)adress[4], &tel, sizeof(long), 0);
					tel = tel - 1.0;
					CloseHandle(hProcess);
					hProcess = OpenProcess(PROCESS_VM_WRITE | PROCESS_VM_OPERATION, false, processId);
					WriteProcessMemory(hProcess, (LPVOID)adress[4], &tel, sizeof(long), 0);
					key[4] = false;
				}
				if (key[5] == true)
				{
					ReadProcessMemory(hProcess, (LPVOID)adress[4], &tel, sizeof(long), 0);
					tel = tel + 1.0;
					CloseHandle(hProcess);
					hProcess = OpenProcess(PROCESS_VM_WRITE | PROCESS_VM_OPERATION, false, processId);
					WriteProcessMemory(hProcess, (LPVOID)adress[4], &tel, sizeof(long), 0);
					key[5] = false;
				}
				if (key[6] == true)
				{
					ReadProcessMemory(hProcess, (LPVOID)adress[1], &health, sizeof(long), 0);
					health = 100;
					CloseHandle(hProcess);
					hProcess = OpenProcess(PROCESS_VM_WRITE | PROCESS_VM_OPERATION, false, processId);
					WriteProcessMemory(hProcess, (LPVOID)adress[1], &health, sizeof(long), 0);
					key[6] = false;
				}
				
				


			}
		}
		else
		{
			if (isGameDetect == true)
			{
				cout << "Game Not Found\n";
				isGameDetect = false;
			}
		}
	}
	
}