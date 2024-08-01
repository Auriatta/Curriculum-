#include"stdafx.h"
#include "CustomProcessMenager.h"


CustomProcessMenager::CustomProcessMenager()
{
}


CustomProcessMenager::~CustomProcessMenager()
{
}

void CustomProcessMenager::setWindowParams(LPCWSTR wName, int x, int y, int width, int hight, bool *loopOn, bool showUp, bool borderOff)
{
	HWND Window = FindWindow(NULL, wName);
	
	RECT rect;
	while (*loopOn)
	{
		GetWindowRect(Window, &rect);
		if (rect.left == x && rect.top == y)
			break;
		else
		{
			MoveWindow(Window, x, y, width, hight, 1);
		}
	}

	if (borderOff==true)
	{
		SetWindowLong(Window, GWL_STYLE, GetWindowLong(Window, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX & ~WS_CAPTION);
		SetWindowPos(Window, HWND_TOPMOST, x, y, width, hight, SWP_FRAMECHANGED | SWP_NOZORDER);
	}

	if (showUp == true)
		ShowWindow(Window, SW_SHOW);
}

void CustomProcessMenager::startProcess(LPCWSTR path, LPCWSTR name, LPCWSTR parameters, bool hided)
{
	SHELLEXECUTEINFO shExecInfo;

	shExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	shExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
	shExecInfo.hwnd = NULL;
	shExecInfo.lpVerb = NULL;
	shExecInfo.lpFile = name;
	shExecInfo.lpParameters = parameters;
	shExecInfo.lpDirectory = path;
	if (hided == true)
		shExecInfo.nShow = SW_HIDE;
	else
		shExecInfo.nShow = SW_SHOW;
	shExecInfo.hInstApp = NULL;

	ShellExecuteEx(&shExecInfo);
}

void CustomProcessMenager::killProcess(LPCWSTR wName)
{
	DWORD processId;

	GetWindowThreadProcessId(FindWindow(NULL, wName), &processId);
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, processId);
	TerminateProcess(hProcess, 1);
	CloseHandle(hProcess);
}
