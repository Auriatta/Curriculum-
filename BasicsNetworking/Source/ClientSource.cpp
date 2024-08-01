#include "Includes.h"

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
	memset(&service, 0, sizeof(service));
	
	service.sin_family = AF_INET;
	service.sin_addr.s_addr = inet_addr("IP");//127.0.0.1
	service.sin_port = htons(27015);

	if (connect(mainSocket, (SOCKADDR *)& service, sizeof(service)) == SOCKET_ERROR)
	{
		printf("Failed to connect.\n");
		WSACleanup();
		return 1;
	}
	cout << "Connected with host/" << service.sin_port << endl;

	int bytesSent;
	int bytesRecv = SOCKET_ERROR;
	char sendbuf[1];
	char recvbuf[1];

	
	WINDOWPLACEMENT status;
	memset(&status, 0, sizeof(WINDOWPLACEMENT));
	
	while (true)
	{
		memset(sendbuf, 0, sizeof sendbuf);
		if (bytesRecv == 0 || bytesRecv == WSAECONNRESET)
		{
			cout << "Connection closed" << endl;
			break;
		}

		GetWindowPlacement(GetConsoleWindow(), &status);
		if (status.showCmd != SW_SHOWMINIMIZED)
		{
			if (GetAsyncKeyState(VK_LEFT))
			{
				keybd_event(VK_LEFT, 0, KEYEVENTF_KEYUP, 0);
				sendbuf[0] = 'A'; bytesSent = 0;
				bytesSent = send(mainSocket, sendbuf, strlen(sendbuf), 0);
				cout << "Butes sent: " << bytesSent << endl << endl;
			}
			if (GetAsyncKeyState(VK_RIGHT))
			{
				keybd_event(VK_RIGHT, 0, KEYEVENTF_KEYUP, 0);
				sendbuf[0] = 'D'; bytesSent = 0;
				bytesSent = send(mainSocket, sendbuf, strlen(sendbuf), 0);
				cout << "Bytes sent: " << bytesSent << endl << endl;
			}
			if (GetAsyncKeyState(VK_DOWN))
			{
				keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);
				sendbuf[0] = 'S'; bytesSent = 0;
				bytesSent = send(mainSocket, sendbuf, strlen(sendbuf), 0);
				cout << "Bytes sent: " << bytesSent << endl << endl;
			}
			if (GetAsyncKeyState(VK_UP))
			{
				keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);
				sendbuf[0] = 'W'; bytesSent = 0;
				bytesSent = send(mainSocket, sendbuf, strlen(sendbuf), 0);
				cout << "Bytes sent: " << bytesSent << endl << endl;
			}
			if (GetAsyncKeyState(VK_SPACE))
			{
				keybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP, 0);
				sendbuf[0] = 'E'; bytesSent = 0;
				bytesSent = send(mainSocket, sendbuf, strlen(sendbuf), 0);
				cout << "Bytes sent: " << bytesSent << endl << endl;
			}
		}
		
	}

	_getch();
	closesocket(mainSocket);
	WSACleanup();
}