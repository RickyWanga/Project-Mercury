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

void cls()
{
    // Get the Win32 handle representing standard output.
    // This generally only has to be done once, so we make it static.
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    COORD topLeft = { 0, 0 };

    // std::cout uses a buffer to batch writes to the underlying console.
    // We need to flush that to the console because we're circumventing
    // std::cout entirely; after we clear the console, we don't want
    // stale buffered text to randomly be written out.
    std::cout.flush();

    // Figure out the current width and height of the console window
    if (!GetConsoleScreenBufferInfo(hOut, &csbi)) {
        // TODO: Handle failure!
        abort();
    }
    DWORD length = csbi.dwSize.X * csbi.dwSize.Y;

    DWORD written;

    // Flood-fill the console with spaces to clear it
    FillConsoleOutputCharacter(hOut, TEXT(' '), length, topLeft, &written);

    // Reset the attributes of every character to the default.
    // This clears all background colour formatting, if any.
    FillConsoleOutputAttribute(hOut, csbi.wAttributes, length, topLeft, &written);

    // Move the cursor back to the top left for the next sequence of writes
    SetConsoleCursorPosition(hOut, topLeft);
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

	setCursorPosition(10, 10);
	cout << R"(

        _  _                                                                
       | || |                                                               
 _   _ | || |_  _ __   __ _    __ _   __ _  _   _   _ __   __ _   ___   ___ 
| | | || || __|| '__| / _` |  / _` | / _` || | | | | '__| / _` | / __| / _ \
| |_| || || |_ | |   | (_| | | (_| || (_| || |_| | | |   | (_| || (__ |  __/
 \__,_||_| \__||_|    \__,_|  \__, | \__,_| \__, | |_|    \__,_| \___| \___|
                               __/ |         __/ |                          
                              |___/         |___/                           

)";

	Sleep(2000);
	cls();

	Partita p(60,40);
	p.start();

	return 0;
}