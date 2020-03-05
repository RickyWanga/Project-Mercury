#include <iostream>
#include <windows.h>
#include "campo.hpp"
#include <conio.h>
#include <chrono>

using namespace std;

int x = 24;
int y = 7;

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

			c.aggiorna();

			system("cls");
			c.inserisci('o', y, x);

			//TODO: scegliere se mettere prima lo stampa o l'aggiorna
			c.stampa();
			c.aggiorna();
		}
	}

	return 0;
}
