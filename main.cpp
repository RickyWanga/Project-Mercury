#include <iostream>
#include <windows.h>
#include "Entity.hpp"
#include "Auto.hpp"
#include "Ostacolo.hpp"
#include "Partita.hpp"
#include "Coda.hpp"
#include "setCursorPosition.hpp"
#include <conio.h>
#include <chrono>

using namespace std;

// toglie l'underscore lampeggiante
void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

void setup()
{
	HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect);
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 1000, 700, TRUE);
	ShowConsoleCursor(false); //toglie l'underscore che flasha
	srand(static_cast<unsigned int>(time(NULL)));
}

int main(int argc, char const *argv[])
{
	setup();
	setCursorPosition(10, 10, 4);
	cout << R"(

  _____   ______  _____  _____ _______ _______ _______
 |_____] |_____/ |     |   |   |______ |          |   
 |       |    \_ |_____| __|   |______ |_____     |   
                                                      
      )            (                  (       )  
     /(  )       )\ )   (           )\ )  ( /(  
    )\))(\  (   (()/(   )\      (  (()/(  )\()) 
    ((_)()\  )\   /(_))(((_)     )\  /(_))((_)\  
    (_()((_)((_) (_))  )\___  _ ((_)(_)) __ ((_) 
    |  \/  || __|| _ \((/ __|| | | || _ \\ \ / / 
    | |\/| || _| |   / | (__ | |_| ||   / \ V /  
    |_|  |_||___||_|_\  \___| \___/ |_|_\  |_|   42
                                              
)";

	Sleep(3000);
	cls();

	Partita p(60,40);
	p.start();

	return 0;
}