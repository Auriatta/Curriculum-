#pragma comment(lib, "Ws2_32.lib")
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <WinSock2.h>
#include <iostream>
#include <conio.h>
#include <string>

using namespace std;



int main()
{
	WSADATA wsaData;

	int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (result != NO_ERROR)
		cout << "Inicjalization Error\n";

	SOCKET mainSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (mainSocket == INVALID_SOCKET)
	{
		cout << "Error creating socket: " << WSAGetLastError() << endl;
		_getch();
		WSACleanup();
		return 0;
	}

	sockaddr_in service;
	memset(&service, 0, sizeof (service));
	service.sin_family = AF_INET;
	service.sin_addr.s_addr = inet_addr("IP");
	service.sin_port = htons(27015);

	if (bind(mainSocket, (SOCKADDR *)& service, sizeof(service)) == SOCKET_ERROR)
	{
		cout << "Bind() failed\n";
		_getch();
		closesocket(mainSocket);
		WSACleanup();
		return 0;
	}

	if (listen(mainSocket, 1) == SOCKET_ERROR)
		cout << "Error listening on socket\n";

	SOCKET acceptSocket = SOCKET_ERROR;
	cout << "Waiting for client to connect\n";

	while (acceptSocket == SOCKET_ERROR)
	{
		acceptSocket = accept(mainSocket, NULL, NULL);
	}

	cout << "Client Connected\n";
	mainSocket = acceptSocket;

	int bytesSent;
	int bytesRecv = SOCKET_ERROR;
	char sendbuf[1] = "";
	char recvbuf[1] = "";

	//bytesRecv = recv(mainSocket, recvbuf, 32, 0);
	//cout << "Bytes received: " << bytesRecv << endl;
	//cout << "Received text: " << recvbuf << endl;

	//bytesSent = send(mainSocket, sendbuf, strlen(sendbuf), 0);
	//cout << "Butes sent: " << bytesSent << endl << endl;

	/*while (true)
	{		
		memset(sendbuf, 0, sizeof sendbuf);
		cout << "//: ";
		
		cin.getline(sendbuf, sizeof(sendbuf));
		bytesSent = 0;
		bytesSent = send(mainSocket, sendbuf, strlen(sendbuf), 0);
		cout << "Butes sent: " << bytesSent << endl << endl;
	}
	*/
	INPUT key;
	while (true)
	{
		bytesRecv = recv(mainSocket, recvbuf, 32, 0);
		if (bytesRecv == 0 || bytesRecv == WSAECONNRESET)
		{
			cout << "Connection closed" << endl;
			break;
		}

		if (bytesRecv < 0)
			return 1;
		
		if (recvbuf[0] == 'A')
		{
			key.type = INPUT_KEYBOARD;
			key.ki.dwFlags = KEYEVENTF_EXTENDEDKEY;
			key.ki.wVk = VK_LEFT;
			SendInput(1, &key, sizeof(INPUT));
			Sleep(30);
			key.ki.dwFlags = KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP;
			SendInput(1, &key, sizeof(INPUT));
		}
		if (recvbuf[0] == 'D')
		{
			key.type = INPUT_KEYBOARD;
			key.ki.dwFlags = KEYEVENTF_EXTENDEDKEY;
			key.ki.wVk = VK_RIGHT;
			SendInput(1, &key, sizeof(INPUT));
			Sleep(30);
			key.ki.dwFlags = KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP;
			SendInput(1, &key, sizeof(INPUT));
		}
		if (recvbuf[0] == 'S')
		{
			key.type = INPUT_KEYBOARD;
			key.ki.dwFlags = KEYEVENTF_EXTENDEDKEY;
			key.ki.wVk = VK_DOWN;
			SendInput(1, &key, sizeof(INPUT));
			Sleep(30);
			key.ki.dwFlags = KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP;
			SendInput(1, &key, sizeof(INPUT));
		}
		if (recvbuf[0] == 'W')
		{
			key.type = INPUT_KEYBOARD;
			key.ki.dwFlags = KEYEVENTF_EXTENDEDKEY;
			key.ki.wVk = VK_UP;
			SendInput(1, &key, sizeof(INPUT));
			Sleep(30);
			key.ki.dwFlags = KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP;
			SendInput(1, &key, sizeof(INPUT));
		}
		if (recvbuf[0] == 'E')
		{
			key.type = INPUT_KEYBOARD;
			key.ki.dwFlags = KEYEVENTF_EXTENDEDKEY;
			key.ki.wVk = VK_SPACE;
			SendInput(1, &key, sizeof(INPUT));
			Sleep(30);
			key.ki.dwFlags = KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP;
			SendInput(1, &key, sizeof(INPUT));
		}
		cout << "Bytes received: " << bytesRecv << endl;
		cout << "Command: " << recvbuf << endl << endl;
		memset(&key, 0, sizeof(INPUT));
	}

	_getch();
	closesocket(mainSocket);
	WSACleanup();
}
