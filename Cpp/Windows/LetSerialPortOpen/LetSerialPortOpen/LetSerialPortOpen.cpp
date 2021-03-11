// LetSerialPortOpen.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<windows.h>
#include<stdio.h>

int _tmain(int argc, _TCHAR* argv[])
{
	HANDLE hComm;

	hComm = CreateFile(_T("\\\\.\\COM1"),                //port name
		GENERIC_READ | GENERIC_WRITE, //Read/Write
		0,                            // No Sharing
		NULL,                         // No Security
		OPEN_EXISTING,// Open existing port only
		0,            // Non Overlapped I/O
		NULL);        // Null for Comm Devices

	if (hComm == INVALID_HANDLE_VALUE)
		printf("Error in opening serial port\n");
	else
		printf("opening serial port successful\n");

	system("pause");
	CloseHandle(hComm);//Closing the Serial Port

	return 0;
}


