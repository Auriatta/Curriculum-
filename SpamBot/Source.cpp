#include <windows.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <process.h>

using namespace std;

bool special_key = 1;
char znaki[100];
string tekst;
char input[100];
stringstream tekst_part[100];
int enter = 1;
int entercen = 0;
int time_pause = 0;
int status = 3;
void spam();
int c = 0;


void __cdecl spam(void *)
{
	do{
		for (int loop = 0; loop<enter; loop++)
		{
			for (int i = 0; i<tekst.length(); i++)
			{
				if (special_key == 1)
				{
					if (znaki[i] == '!'){ keybd_event(VK_LSHIFT, 0, 0, 0); keybd_event(VkKeyScan('1'), 0, 0, 0); keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0); continue; }
					else
					if (znaki[i] == '@'){ keybd_event(VK_LSHIFT, 0, 0, 0); keybd_event(VkKeyScan('2'), 0, 0, 0); keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0); continue; }
					else
					if (znaki[i] == '#'){ keybd_event(VK_LSHIFT, 0, 0, 0); keybd_event(VkKeyScan('3'), 0, 0, 0); keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0); continue; }
					else
					if (znaki[i] == '$'){ keybd_event(VK_LSHIFT, 0, 0, 0); keybd_event(VkKeyScan('4'), 0, 0, 0); keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0); continue; }
					else
					if (znaki[i] == '%'){ keybd_event(VK_LSHIFT, 0, 0, 0); keybd_event(VkKeyScan('5'), 0, 0, 0); keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0); continue; }
					else
					if (znaki[i] == '^'){ keybd_event(VK_LSHIFT, 0, 0, 0); keybd_event(VkKeyScan('6'), 0, 0, 0); keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0); continue; }
					else
					if (znaki[i] == '&'){ keybd_event(VK_LSHIFT, 0, 0, 0); keybd_event(VkKeyScan('7'), 0, 0, 0); keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0); continue; }
					else
					if (znaki[i] == '*'){ keybd_event(VK_LSHIFT, 0, 0, 0); keybd_event(VkKeyScan('8'), 0, 0, 0); keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0); continue; }
					else
					if (znaki[i] == '('){ keybd_event(VK_LSHIFT, 0, 0, 0); keybd_event(VkKeyScan('9'), 0, 0, 0); keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0); continue; }
					else
					if (znaki[i] == ')'){ keybd_event(VK_LSHIFT, 0, 0, 0); keybd_event(VkKeyScan('0'), 0, 0, 0); keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0); continue; }
					else
					if (znaki[i] == '+'){ keybd_event(VK_LSHIFT, 0, 0, 0); keybd_event(VkKeyScan('='), 0, 0, 0); keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0); continue; }
					else
					if (znaki[i] == '|'){ keybd_event(VK_LSHIFT, 0, 0, 0); keybd_event(VkKeyScan('\\'), 0, 0, 0); keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0); continue; }
					else
					if (znaki[i] == '?'){ keybd_event(VK_LSHIFT, 0, 0, 0); keybd_event(VkKeyScan('/'), 0, 0, 0); keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0); continue; }
					else
					if (znaki[i] == ':'){ keybd_event(VK_LSHIFT, 0, 0, 0); keybd_event(VkKeyScan(';'), 0, 0, 0); keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0); continue; }
					else
					if (znaki[i] == '"'){ keybd_event(VK_LSHIFT, 0, 0, 0); keybd_event(VkKeyScan('\''), 0, 0, 0); keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0); continue; }
					else
					if (znaki[i] == '<'){ keybd_event(VK_LSHIFT, 0, 0, 0); keybd_event(VkKeyScan(','), 0, 0, 0); keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0); continue; }
					else
					if (znaki[i] == '>'){ keybd_event(VK_LSHIFT, 0, 0, 0); keybd_event(VkKeyScan('.'), 0, 0, 0); keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0); continue; }
					else
					if (znaki[i] == '{'){ keybd_event(VK_LSHIFT, 0, 0, 0); keybd_event(VkKeyScan('['), 0, 0, 0); keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0); continue; }
					else
					if (znaki[i] == '}'){ keybd_event(VK_LSHIFT, 0, 0, 0); keybd_event(VkKeyScan(']'), 0, 0, 0); keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0); continue; }
				}
				if (znaki[i] == '_'){ keybd_event(VK_SPACE, 0, 0, 0); }
				else
				if (znaki[i] == 'A'){ keybd_event(VK_LSHIFT, 0, 0, 0); keybd_event(VkKeyScan('A'), 0, 0, 0); keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0); }
				else
				if (znaki[i] == 'B'){ keybd_event(VK_LSHIFT, 0, 0, 0); keybd_event(VkKeyScan('B'), 0, 0, 0); keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0); }
				else
				if (znaki[i] == 'C'){ keybd_event(VK_LSHIFT, 0, 0, 0); keybd_event(VkKeyScan('C'), 0, 0, 0); keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0); }
				else
				if (znaki[i] == 'D'){ keybd_event(VK_LSHIFT, 0, 0, 0); keybd_event(VkKeyScan('D'), 0, 0, 0); keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0); }
				else
				if (znaki[i] == 'E'){ keybd_event(VK_LSHIFT, 0, 0, 0); keybd_event(VkKeyScan('E'), 0, 0, 0); keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0); }
				else
				if (znaki[i] == 'F'){ keybd_event(VK_LSHIFT, 0, 0, 0); keybd_event(VkKeyScan('F'), 0, 0, 0); keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0); }
				else
				if (znaki[i] == 'G'){ keybd_event(VK_LSHIFT, 0, 0, 0); keybd_event(VkKeyScan('G'), 0, 0, 0); keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0); }
				else
				if (znaki[i] == 'H'){ keybd_event(VK_LSHIFT, 0, 0, 0); keybd_event(VkKeyScan('H'), 0, 0, 0); keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0); }
				else
				if (znaki[i] == 'I'){ keybd_event(VK_LSHIFT, 0, 0, 0); keybd_event(VkKeyScan('I'), 0, 0, 0); keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0); }
				else
				if (znaki[i] == 'J'){ keybd_event(VK_LSHIFT, 0, 0, 0); keybd_event(VkKeyScan('J'), 0, 0, 0); keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0); }
				else
				if (znaki[i] == 'K'){ keybd_event(VK_LSHIFT, 0, 0, 0); keybd_event(VkKeyScan('K'), 0, 0, 0); keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0); }
				else
				if (znaki[i] == 'L'){ keybd_event(VK_LSHIFT, 0, 0, 0); keybd_event(VkKeyScan('L'), 0, 0, 0); keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0); }
				else
				if (znaki[i] == 'M'){ keybd_event(VK_LSHIFT, 0, 0, 0); keybd_event(VkKeyScan('M'), 0, 0, 0); keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0); }
				else
				if (znaki[i] == 'N'){ keybd_event(VK_LSHIFT, 0, 0, 0); keybd_event(VkKeyScan('N'), 0, 0, 0); keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0); }
				else
				if (znaki[i] == 'O'){ keybd_event(VK_LSHIFT, 0, 0, 0); keybd_event(VkKeyScan('O'), 0, 0, 0); keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0); }
				else
				if (znaki[i] == 'P'){ keybd_event(VK_LSHIFT, 0, 0, 0); keybd_event(VkKeyScan('P'), 0, 0, 0); keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0); }
				else
				if (znaki[i] == 'Q'){ keybd_event(VK_LSHIFT, 0, 0, 0); keybd_event(VkKeyScan('Q'), 0, 0, 0); keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0); }
				else
				if (znaki[i] == 'W'){ keybd_event(VK_LSHIFT, 0, 0, 0); keybd_event(VkKeyScan('W'), 0, 0, 0); keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0); }
				else
				if (znaki[i] == 'S'){ keybd_event(VK_LSHIFT, 0, 0, 0); keybd_event(VkKeyScan('S'), 0, 0, 0); keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0); }
				else
				if (znaki[i] == 'V'){ keybd_event(VK_LSHIFT, 0, 0, 0); keybd_event(VkKeyScan('V'), 0, 0, 0); keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0); }
				else
				if (znaki[i] == 'X'){ keybd_event(VK_LSHIFT, 0, 0, 0); keybd_event(VkKeyScan('X'), 0, 0, 0); keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0); }
				else
				if (znaki[i] == 'Z'){ keybd_event(VK_LSHIFT, 0, 0, 0); keybd_event(VkKeyScan('Z'), 0, 0, 0); keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0); }
				else
				if (znaki[i] == 'T'){ keybd_event(VK_LSHIFT, 0, 0, 0); keybd_event(VkKeyScan('T'), 0, 0, 0); keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0); }
				else
				if (znaki[i] == 'Y'){ keybd_event(VK_LSHIFT, 0, 0, 0); keybd_event(VkKeyScan('Y'), 0, 0, 0); keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0); }
				else
				if (znaki[i] == 'U'){ keybd_event(VK_LSHIFT, 0, 0, 0); keybd_event(VkKeyScan('U'), 0, 0, 0); keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0); }
				else
				if (znaki[i] == 'R'){ keybd_event(VK_LSHIFT, 0, 0, 0); keybd_event(VkKeyScan('R'), 0, 0, 0); keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0); }
				else
					keybd_event(VkKeyScan(znaki[i]), 0, 0, 0);
				Sleep(10);
				if (entercen == 1){ keybd_event(0x0D, 0, 0, 0); }
			}
			if (enter>1){ keybd_event(VK_SPACE, 0, 0, 0); }
			if (status == 0){ cin.sync(); _endthread(); }
			if (time_pause>0){ Sleep(time_pause); }
		}
		if (entercen == 0){ keybd_event(0x0D, 0, 0, 0); }
	} while (true);
	_endthread();
}

int main()
{
	system("cls");
	char znak[7];
	znak[1] = 187;
	znak[2] = 188;
	znak[3] = 205;
	znak[4] = 186;
	znak[5] = 200;
	znak[6] = 201;
	cout << znak[6];
	for (int i = 0; i<24; i++)
		cout << znak[3];
	cout << znak[1] << endl;
	cout << znak[4] << "<<|Spam Bot|>>" << znak[4] << "                                v. 1.0.3 ";
	cout << endl << znak[5];
	for (int i = 0; i<24; i++)
		cout << znak[3];
	cout << znak[2] << endl << endl;
	cout << "* ----------------------------------------------------------------------------\n";
	cout << "* (Revision 42):\n";
	cout << "* U can do whatever you want with this stuff.\n";
	cout << "* |\n";
	cout << "* ----------------------------------------------------------------------------\n\n\n";
	cout << "Write something: [instead spacebar let put \"_\" char]\n";
	//getline(cin, tekst);
	(cin >> tekst).get();
	for (int i = 0; i < tekst.length(); i++){ tekst_part[i] << tekst[i]; tekst_part[i] >> znaki[i]; cout << znaki[i]; }
	cout << "\nWrite a time distance in ms between messages: \n";
	cout << "Write \"0\", if you don't want a time pause between messages.\n";
	cin >> time_pause;
	do{
		cout << "\nAfter how many messages I should go to new line?\n";
		cout << "[1] After one messages\n";
		cout << "[2] After each\n";
		cout << "[3] Own value\n";
		string choice; choice = _getch();
		if (choice == "1"){ break; }
		if (choice == "2"){ entercen = 1; break; }
		if (choice == "3"){ system("cls"); cout << "Write after how many messages I should go to new line.\n"; cin >> enter; break; }
	} while (true);
	do
	{
		cout << "\nShould I detect special chars e.g. \"@\" or \"&\" ?\n";
		cout << "[1] yes\n";
		cout << "[2] no\n";
		string choice=""; choice = _getch();
		if (choice == "1"){ special_key = 1; break; }
		if (choice == "2"){ special_key = 0; break; }
	} while (true);
	do{
		if (GetKeyState(MOUSEEVENTF_LEFTDOWN) == 0)
		{
			if (status == 0){ system("cls"); cout << "\n\n\nStatus: ACTIVE  [right pause] _/|" << endl; }
			if (status == 0){ _beginthread(spam, 0, 0); status = 1; }
		}
		else
		{
			if (status > 0){ system("cls"); cout << "\n\n\nStatus: DISABLE  [right resume] _/|\n"; }
			status = 0;
		}
		Sleep(10);
	} while (true);
	_getch();
}
