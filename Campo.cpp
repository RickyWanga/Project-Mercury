#include <iostream>
#include "Campo.hpp"
using namespace std;

void Campo::stampa()
{
    for(int i = 0; i<row; i++)
    {
        for(int j = 0; j<col; j++)
        {
            cout << campo[i][j];
        }
        cout << endl;
    }
}

void Campo::inizializza()
{
    for(int i = 0; i<row; i++)
    {
        for(int j = 0; j<col; j++)
        {
           campo[i][j] = ' ';
        }
    }
}

void Campo::bordi()
{
    for(int i = 0; i<row; i++)
    {
        campo[i][0] = '|';
        campo[i][col-1] = '|';
    }
}

Campo::Campo()
{
    inizializza();
    bordi();
}