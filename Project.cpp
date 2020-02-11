#include <iostream>
#include "campo.hpp"

using namespace std;

Campo::Campo()
{
	inizializza();
	bordi();
}

void Campo::inizializza()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			campo[i][j] = ' ';
		}
	}
}

void Campo::bordi()
{
	for (int i = 0; i < row; i++)
	{
		campo[i][0] = '|';
		campo[i][col - 1] = '|';
	}
}

void Campo::stampa(int x, int y)
{
	for(int i = 0; i<row; i++)
    {
        for(int j = 0; j<col; j++)
        {
			if (i == x && j == y)
				cout << 'o';
			else
				cout << campo[i][j];
        }
        cout << endl;
    }
}

void Campo::inserisci(char s, int r, int c)
{
	campo[r][c] = s;
}

void Campo::aggiorna()
{
	for (int i = row - 1; i >= 0; i--)
	{
		for (int j = 0; j < col; j++)
		{
			if (i == 0)
			{
				if (j == 0 || j == col - 1)
				{
					campo[i][j] = '|';
				}
				else
					campo[i][j] = ' ';
			}
			else
				campo[i][j] = campo[i - 1][j];
		}
	}
}
