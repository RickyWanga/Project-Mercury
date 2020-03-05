#include <iostream>
#include <windows.h>
#include "campo.hpp"
#include <conio.h>
#include <chrono>

using namespace std;

int x = 24;
int y = 7;

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

//toglie il flash
void setCursorPosition(int x, int y)
{
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout.flush();
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hOut, coord);
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



int main(int argc, char const *argv[])
{
	ShowConsoleCursor(false); //toglie l'underscore che flasha
	Campo c;

	int last = time();
	int input = 0;

	while (1)
	{
		int newInput = getInput();
		if (newInput != 0)
		{
			input = newInput;
		}

		if (time() - last >= 50)
		{
			last = time();

			processInput(input);
			input = 0;

			setCursorPosition(0,0); //toglie i flickering
			c.inserisci('o', x, y);

			//TODO: scegliere se mettere prima lo stampa o l'aggiorna
			c.aggiorna();
			c.stampa();
		}
	}



	return 0;
}

