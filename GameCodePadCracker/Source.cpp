#include "Header.h"

void __cdecl getstatus(void *)
{
	int padstatus;
	DWORD processId;
	HANDLE hProcess = NULL;
	GetWindowThreadProcessId(hWnd, &processId);
	hProcess = OpenProcess(PROCESS_VM_READ, false, processId);
	for (;;)
	{
		ReadProcessMemory(hProcess, (LPVOID)adress, &padstatus, sizeof(long), 0);
		if (padstatus == 0)
			isCrack == false;
		if (isCrack == false)
			_endthread();
	}
}

void moveBase(int side)
{
	memset(&key, 0, sizeof(INPUT));

	switch (side)
	{
	case 1: // down
	{
		char ch = 's';
		key.type = INPUT_KEYBOARD;
		key.ki.dwExtraInfo = GetMessageExtraInfo();
		key.ki.wScan =
			static_cast<WORD>(MapVirtualKeyEx(VkKeyScanA(ch), MAPVK_VK_TO_VSC, GetKeyboardLayout(0)));
		key.ki.dwFlags = KEYEVENTF_SCANCODE;
		SendInput(1, &key, sizeof(INPUT));
		Sleep(time);
		key.ki.dwExtraInfo = GetMessageExtraInfo();
		key.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
		SendInput(1, &key, sizeof(INPUT));
		break;
	}
	case 2: // up
	{
		char ch = 'w';
		key.type = INPUT_KEYBOARD;
		key.ki.dwExtraInfo = GetMessageExtraInfo();
		key.ki.wScan =
			static_cast<WORD>(MapVirtualKeyEx(VkKeyScanA(ch), MAPVK_VK_TO_VSC, GetKeyboardLayout(0)));
		key.ki.dwFlags = KEYEVENTF_SCANCODE;
		SendInput(1, &key, sizeof(INPUT));
		Sleep(time);
		key.ki.dwExtraInfo = GetMessageExtraInfo();
		key.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
		SendInput(1, &key, sizeof(INPUT));
		break;
	}
	case 3: // right
	{
		char ch = 'd';
		key.type = INPUT_KEYBOARD;
		key.ki.dwExtraInfo = GetMessageExtraInfo();
		key.ki.wScan =
			static_cast<WORD>(MapVirtualKeyEx(VkKeyScanA(ch), MAPVK_VK_TO_VSC, GetKeyboardLayout(0)));
		key.ki.dwFlags = KEYEVENTF_SCANCODE;
		SendInput(1, &key, sizeof(INPUT));
		Sleep(time);
		key.ki.dwExtraInfo = GetMessageExtraInfo();
		key.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
		SendInput(1, &key, sizeof(INPUT));
		break;
	}
	case 4: // left
	{
		char ch = 'a';
		key.type = INPUT_KEYBOARD;
		key.ki.dwExtraInfo = GetMessageExtraInfo();
		key.ki.wScan =
			static_cast<WORD>(MapVirtualKeyEx(VkKeyScanA(ch), MAPVK_VK_TO_VSC, GetKeyboardLayout(0)));
		key.ki.dwFlags = KEYEVENTF_SCANCODE;
		SendInput(1, &key, sizeof(INPUT));
		Sleep(80);
		key.ki.dwExtraInfo = GetMessageExtraInfo();
		key.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
		SendInput(1, &key, sizeof(INPUT));
		break;
	}
	default:
		break;
	}

	
}

void __cdecl Symulacja(void *)
{
	int fload = false; int choice = 0;
	int sign[5]; int couter = 1;
	for (int i = 1; i < 5; i++)
		sign[i] = 0;
	cout << "################################\n"
		<< "#Code Pad Cracker for Zombi[PC]#\n"
		<< "################################\n";
	adress = 0x1FC21D5C;
	cout << "\nPoczatkowe wartosci: \n";
	for (int i = 1; i < 5; i++)
	{
		cout << i << ": "; cin >> sign[i];
	}
	cout << endl;
	cout << "[OK].." << endl;
	for (;;)
	{
		if (isCrack == true)
		{
			for (int i = 4; i > 0; i--)
			{
				if (sign[i] != 9)
				{
					sign[i] ++;
					break;
				}
				else
					for (int l = i; l > 0; l--)
					{
						if (sign[l] == 9)
						{
							if (l - 1 != 0)
							{
								sign[l] = 0;
								break;
							}

							{
								cout << "\nWszystkie kombinacje uzyte\n";
								cout << "Iloœæ kombinacji: " << couter << endl;
								isCrack = false;
								break;
							}
						}
					}
			}
			if (isCrack == false)
			{
				cout << "\nStop..\n";
				break;
			}
				
			for (int i = 1; i < 5; i++)
			{

				if (fload == false)
				{
					cout << sign[i] << " ";
					for (int j = 1; j < 10; j++)
					{
						if (number[sign[i]].muves[j][1] == NULL)
						{
							Sleep(time);
							break;
						}
						moveBase(number[sign[i]].muves[j][1]);
						Sleep(time);
					}
					memset(&key, 0, sizeof(INPUT));
					char ch = 'e';
					key.type = INPUT_KEYBOARD;
					key.ki.dwExtraInfo = GetMessageExtraInfo();
					key.ki.wScan =
						static_cast<WORD>(MapVirtualKeyEx(VkKeyScanA(ch), MAPVK_VK_TO_VSC, GetKeyboardLayout(0)));
					key.ki.dwFlags = KEYEVENTF_SCANCODE;
					SendInput(1, &key, sizeof(INPUT));
					Sleep(time);
					key.ki.dwExtraInfo = GetMessageExtraInfo();
					key.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
					SendInput(1, &key, sizeof(INPUT));
				}
				for (int k = 1; k < 5; k++)
				{
					
					if (number[sign[i]].nearn[k] == -1)
						break;
					if (sign[i + 1] == number[sign[i]].nearn[k] && i != 4)
					{
						cout << sign[i + 1] << "b" << number[sign[i]].nearm[k] << " ";
						moveBase(number[sign[i]].nearm[k]);
						Sleep(time);
						memset(&key, 0, sizeof(INPUT));
						char ch = 'e';
						key.type = INPUT_KEYBOARD;
						key.ki.dwExtraInfo = GetMessageExtraInfo();
						key.ki.wScan =
							static_cast<WORD>(MapVirtualKeyEx(VkKeyScanA(ch), MAPVK_VK_TO_VSC, GetKeyboardLayout(0)));
						key.ki.dwFlags = KEYEVENTF_SCANCODE;
						SendInput(1, &key, sizeof(INPUT));
						Sleep(time);
						key.ki.dwExtraInfo = GetMessageExtraInfo();
						key.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
						SendInput(1, &key, sizeof(INPUT));
						fload = true;
						break;
					}
					else
					{
						fload = false;
					}
				}

				if (fload == false)
					for (int j = 1; j < 10; j++)
					{
						if (number[sign[i]].muves[j][2] == NULL)
						{
							Sleep(time);
							break;
						}
						moveBase(number[sign[i]].muves[j][2]);
						Sleep(time);
					}
			}
			for (int j = 1; j < 10; j++)
			{
				if (number[10].muves[j][1] == NULL)
				{
					Sleep(time);
					break;
				}
				moveBase(number[10].muves[j][1]);
				Sleep(time);
			}
			memset(&key, 0, sizeof(INPUT));
			char ch = 'e';
			key.type = INPUT_KEYBOARD;
			key.ki.dwExtraInfo = GetMessageExtraInfo();
			key.ki.wScan =
				static_cast<WORD>(MapVirtualKeyEx(VkKeyScanA(ch), MAPVK_VK_TO_VSC, GetKeyboardLayout(0)));
			key.ki.dwFlags = KEYEVENTF_SCANCODE;
			SendInput(1, &key, sizeof(INPUT));
			Sleep(time);
			key.ki.dwExtraInfo = GetMessageExtraInfo();
			key.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
			SendInput(1, &key, sizeof(INPUT));
			for (int j = 1; j < 10; j++)
			{
				if (number[10].muves[j][2] == NULL)
				{
					Sleep(time);
					break;
				}
				moveBase(number[10].muves[j][2]);
				Sleep(time);
			}

			cout << endl;
			couter++;
		}
	}
}

void movescombine()
{
	// start
	number[0].muves[1][1] = 1; // 0
	number[0].muves[2][1] = 1; // 0

	number[1].muves[1][1] = 2;
	number[1].muves[2][1] = 4;

	number[2].muves[1][1] = 2;

	number[3].muves[1][1] = 2;
	number[3].muves[2][1] = 3;

	number[4].muves[1][1] = 4;

	number[5].muves[1][1] = 0;

	number[6].muves[1][1] = 3;

	number[7].muves[1][1] = 4;
	number[7].muves[2][1] = 1;

	number[8].muves[1][1] = 1;

	number[9].muves[1][1] = 1;
	number[9].muves[2][1] = 3;

	number[10].muves[1][1] = 1; // e
	number[10].muves[2][1] = 3; // e
	number[10].muves[3][1] = 1; // e

	// powrot do 1

	number[0].muves[1][2] = 2; // 0
	number[0].muves[2][2] = 2; // 0

	number[1].muves[1][2] = 3;
	number[1].muves[2][2] = 1;

	number[2].muves[1][2] = 1;

	number[3].muves[1][2] = 4;
	number[3].muves[2][2] = 1;

	number[4].muves[1][2] = 3;

	number[5].muves[1][2] = 0;

	number[6].muves[1][2] = 4;

	number[7].muves[1][2] = 2;
	number[7].muves[2][2] = 3;

	number[8].muves[1][2] = 2;

	number[9].muves[1][2] = 4;
	number[9].muves[2][2] = 2;

	number[10].muves[1][2] = 2; // e
	number[10].muves[2][2] = 4; // e
	number[10].muves[3][2] = 2; // e

	// s¹siady
	number[0].nearn[1] = 8;
	number[0].nearm[1] = 2;
	number[0].nearn[2] = 0;
	number[0].nearn[3] = -1;

	number[1].nearn[1] = 2;
	number[1].nearm[1] = 3;
	number[1].nearn[2] = 4;
	number[1].nearm[2] = 1;
	number[1].nearn[3] = 1;
	number[1].nearn[4] = -1;

	number[2].nearn[1] = 1;
	number[2].nearm[1] = 4;
	number[2].nearn[2] = 5;
	number[2].nearm[2] = 1;
	number[2].nearn[3] = 3;
	number[2].nearm[3] = 3;
	number[2].nearn[4] = 2;
	number[2].nearn[5] = -1;
	
	number[3].nearn[1] = 2;
	number[3].nearm[1] = 4;
	number[3].nearn[2] = 6;
	number[3].nearm[2] = 1;
	number[3].nearn[3] = 3;
	number[3].nearn[4] = -1;

	number[4].nearn[1] = 1;
	number[4].nearm[1] = 2;
	number[4].nearn[2] = 5;
	number[4].nearm[2] = 3;
	number[4].nearn[3] = 7;
	number[4].nearm[3] = 1;
	number[4].nearn[4] = 4;
	number[4].nearn[5] = -1;

	number[5].nearn[1] = 4;
	number[5].nearm[1] = 4;
	number[5].nearn[2] = 2;
	number[5].nearm[2] = 2;
	number[5].nearn[3] = 8;
	number[5].nearm[3] = 1;
	number[5].nearn[4] = 6;
	number[5].nearm[4] = 3;
	number[5].nearn[5] = 5;
	number[5].nearn[6] = -1;

	number[6].nearn[1] = 5;
	number[6].nearm[1] = 4;
	number[6].nearn[2] = 3;
	number[6].nearm[2] = 2;
	number[6].nearn[3] = 9;
	number[6].nearm[3] = 1;
	number[6].nearn[4] = 6;
	number[6].nearn[5] = -1;
	
	number[7].nearn[1] = 4;
	number[7].nearm[1] = 2;
	number[7].nearn[2] = 8;
	number[7].nearm[2] = 3;
	number[7].nearn[3] = 7;
	number[7].nearn[4] = -1;

	number[8].nearn[1] = 5;
	number[8].nearm[1] = 2;
	number[8].nearn[2] = 0;
	number[8].nearm[2] = 1;
	number[8].nearn[3] = 9;
	number[8].nearm[3] = 3;
	number[8].nearn[4] = 8;
	number[8].nearn[5] = -1;

	number[9].nearn[1] = 8;
	number[9].nearm[1] = 4;
	number[9].nearn[2] = 6;
	number[9].nearm[2] = 2;
	number[9].nearn[3] = 9;
	number[9].nearn[4] = -1;

	number[10].nearn[1] = -1;

}

int main()
{
	movescombine();
	_beginthread(Symulacja, 0, 0);
	while (true)
	{
		if (GetAsyncKeyState(VK_F4) < 0)
		{
			keybd_event(VK_F4, 0, KEYEVENTF_KEYUP, 0);
			if (isCrack == true)
			{
				isCrack = false;
			}
			else
			{
				_beginthread(getstatus, 0, 0);
				cout << "\nCracking..\n" << endl;
				isCrack = true;
			}
		}
	}
}