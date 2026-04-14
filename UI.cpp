
#include "Common.h"
#include <iostream>
using namespace std;
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void DrawWall(bool hasWall)
{
    if (!hasWall) return;
    for (int i = 0; i <= WIDTH; i++)
    {
        gotoxy(i, 0);
        cout << "#";
        gotoxy(i, HEIGHT);
        cout << "#";
    }
    for (int i = 0; i <= HEIGHT; i++)
    {
        gotoxy(0, i);
        cout << "#";
        gotoxy(WIDTH, i);
        cout << "#";
    }
}
