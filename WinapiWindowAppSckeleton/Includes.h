
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include <Windows.h>
#include <iostream>

using namespace std;



LRESULT CALLBACK MainWindowProcedure(HWND hWindow, UINT message, WPARAM wpar, LPARAM lpar, WNDCLASS WindowClass);

void MainLoop(MSG message);


// TOOLS
// To put value from one LPWSTR to another
void EqualWideChar(LPWSTR FromText, LPWSTR ToText);









#define VK_LBUTTON 0x001
#define VK_RBUTTON 0x002
#define VK_RETURN 0x0D
#define VK_LBUTTON 0x001
#define VK_OEM_PERIOD 0x0BE
#define VK_SPACE 0x020
#define VK_BACK 0x008
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