#include <iostream>
#include <Windows.h>
#include <process.h>

using namespace std;

long adress = 0x10CEA360; // 1EEE66E4 // 6DC93990
HWND hWnd = FindWindow(0, L"Zombi");
bool isCrack = false;

INPUT key;

int time =90;


struct moves
{
	int muves[11][3];
	int nearn[5];
	int nearm[5];
}number[11];

#define VK_A	0x041
#define VK_B	0x042
#define VK_C	0x043
#define VK_D	0x044
#define VK_E	0x045
#define VK_F	0x046
#define VK_G	0x047
#define VK_H	0x048
#define VK_I	0x049
#define VK_J	0x04A
#define VK_K	0x04B
#define VK_L	0x04C
#define VK_M	0x04D
#define VK_N	0x04E
#define VK_O	0x04F
#define VK_P	0x050
#define VK_Q	0x051
#define VK_R	0x052
#define VK_S	0x053
#define VK_T	0x054
#define VK_U	0x055
#define VK_W	0x057
#define VK_V	0x056
#define VK_X	0x058
#define VK_Y	0x059
#define VK_Z	0x05A