#include "setCursorPosition.hpp"
#include <windows.h>
#include <conio.h>
#include <iostream>
using namespace std;

int getInput()
{
	if (kbhit())
	{
		return getch();
	}
	return 0;
}

void setCursorPosition(int x, int y)
{
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    cout.flush();
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hOut, coord);
}