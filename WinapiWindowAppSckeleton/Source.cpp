#include "Includes.h"

bool DrawInterface(HWND hMapWindow, WPARAM wpar, LPARAM lpar);

void InitialInterface()
{
	const int ScreenX = (GetSystemMetrics(SM_CXSCREEN) - 850) / 2, ScreenY = (GetSystemMetrics(SM_CYSCREEN) - 600) / 2; // Variable to set window on the midle of the desctop

	// Creating a Windows..
}

int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nMode)
{
	MSG msg;
	WNDCLASS WindowClass;
	HBRUSH BGTrans = CreateSolidBrush(RGB(176, 140, 74)); // Background

	// Console
	AllocConsole();
	SetConsoleTitle(L"debug console");
	freopen("CONIN$", "r", stdin);
	freopen("CONOUT$", "w", stdout);
	freopen("CONOUT$", "w", stderr);
	
	// Window Class Data
	WindowClass.hInstance = hinstance;
	WindowClass.lpszClassName = L"Main Class";
	WindowClass.lpfnWndProc = MainWindowProcedure;
	WindowClass.lpszMenuName = NULL;
	WindowClass.style = 0;
	WindowClass.hIcon = NULL;
	WindowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WindowClass.hbrBackground = BGTrans;
	WindowClass.cbClsExtra = 0;
	WindowClass.cbWndExtra = 0;

	// Register Class
	if (!RegisterClass(&WindowClass)) return 0;

	InitialInterface();

	msg.message = WM_NULL;

	MainLoop(msg);
}

void MainLoop(MSG message)
{
	// No depends if Window is actice or not
	while (message.message != WM_QUIT)
	{
		if (PeekMessage(&message, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&message);
			DispatchMessage(&message);
		}
		else
		{
			// here other events
		}
	}

	// Only Geting when window is active
	while (GetMessage(&message, NULL, 0, 0))
	{

		TranslateMessage(&message);
		DispatchMessage(&message);
	}
}

LRESULT CALLBACK MainWindowProcedure(HWND hWindow, UINT message, WPARAM wpar, LPARAM lpar)
{
	switch (message)
	{
	case WM_QUIT:
	{
		PostQuitMessage(0);
		break;
	}

	case WM_DRAWITEM:
	{
		DrawInterface(hWindow, wpar, lpar); // for visual costomize a control
		break;
	}

	switch (wpar)
	{

	default:
		break;
	}


	default:
		break;
	}
}

bool DrawInterface(HWND hMapWindow, WPARAM wpar, LPARAM lpar)
{
	// if you want upload bitmap to control
	HWND hDefault;
	const DRAWITEMSTRUCT* pDIS = reinterpret_cast<DRAWITEMSTRUCT*>(lpar);
	HBITMAP hBmp;
	/*
	if (pDIS->hwndItem == hDefault)
	{
		hBmp = LoadBitmap(WindowClass.hInstance, MAKEINTRESOURCE(ID));
		bool isEnabled = (pDIS->itemState & ODS_DISABLED) == 0;
		DrawState(pDIS->hDC, nullptr, nullptr, reinterpret_cast<LPARAM>(hBmp), 0, 0, 0, 0, 0, DST_BITMAP | (isEnabled ? DSS_NORMAL : DSS_DISABLED));
		DeleteObject(hBmp);
	}
	*/
}

void EqualWideChar(LPWSTR FromText, LPWSTR ToText)
{
	char conv[256];
	WideCharToMultiByte(CP_ACP, 0, FromText, -1, conv, sizeof(conv), 0, 0);
	MultiByteToWideChar(CP_UTF8, 0, conv, -1, ToText, sizeof(conv));
}