#include <iostream>
#include "Common.h"

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void DrawWall(bool hasWall) {
    string wallChar = hasWall ? "##" : "::";

    for (int x = 0; x <= WIDTH + 1; x++) {
        gotoxy(x * 2, 0);
        cout << wallChar;
        gotoxy(x * 2, HEIGHT + 1);
        cout << wallChar;
    }

    for (int y = 1; y <= HEIGHT; y++) {
        gotoxy(0, y);
        cout << wallChar;
        gotoxy((WIDTH + 1) * 2, y);
        cout << wallChar;
    }
}

void DrawSnake(Snake& s) {
    for (int i = 0; i < s.body.size(); i++) {
        gotoxy(s.body[i].X * 2, s.body[i].Y);
        if (i == 0) cout << "@@";
        else cout << "()";
    }
}
