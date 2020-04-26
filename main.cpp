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

int x = 45;
int y = 17;

// toglie l'underscore lampeggiante
void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

//cls ma più veloce
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

uint64_t time()
{
  using namespace std::chrono;
  return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

int getInput()
{
	if (kbhit())
	{
		return getch();
	}
	return 0;
}

void processInput(int c)
{
		// cout << c;
		switch(c) {
			case 72:
				y--;
				break;
			case 80:
				y++;
				break;
			case 77:
				x++;
				break;
			case 75:
				x--;
				break;
		}
}

int getRandomX(int l)
{
	int r = rand()%l+10;
	setCursorPosition(30,0);
	cout << r;
	return r;
}

int main(int argc, char const *argv[])
{
	HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect);
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 1000, 700, TRUE);
	ShowConsoleCursor(false); //toglie l'underscore che flasha

	srand(static_cast<unsigned int>(time(NULL)));

	uint64_t t = time();
	uint64_t delay = 200;

	int input = 0;

	Partita p(20,20);
	setCursorPosition(0, p.getHeight());
	cout << "-----------------------------------------";
	Auto a(x,y);
	Coda coda(100);

	Ostacolo o1(2, 6);
	Ostacolo o2(20, 4);
	Ostacolo o3(12, 3);
	Ostacolo o4(4, 2);
	Ostacolo o5(10, 1);

	coda.enq(o1);
	coda.enq(o2);
	coda.enq(o3);
	coda.enq(o4);
	coda.enq(o5);

	while (1)
	{
		//Sleep(50);
		int newInput = getInput();
		if (newInput != 0)
		{
			input = newInput;
		}

		setCursorPosition(0,0); //toglie i flickering

		coda.stampa();
		a.stampa();

		processInput(input);
		input = 0;

		a.setPos(x,y);


		if(time() - t > delay)
		{
			t = time();
			coda.move();
			coda.checkLimite(p.getHeight());
		}

		setCursorPosition(60,0);
		cout << "dimensione coda: " << coda.getDim();
	}

	return 0;
}