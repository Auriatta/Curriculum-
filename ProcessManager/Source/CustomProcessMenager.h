#pragma once


#include <Windows.h>
#include <shellapi.h>

class CustomProcessMenager
{
public:
	CustomProcessMenager();
	~CustomProcessMenager();
	void setWindowParams(LPCWSTR wName, int x, int y, int width, int hight, bool *loopOn, bool showUp, bool borderOff);
	void startProcess(LPCWSTR path, LPCWSTR name, LPCWSTR parameters, bool hided);
	void killProcess(LPCWSTR wName);
};

