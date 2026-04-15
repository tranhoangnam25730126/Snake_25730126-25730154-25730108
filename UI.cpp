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
void DrawFood(Food& f) {
    gotoxy(f.pos.X * 2, f.pos.Y);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    cout << "$$";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void DrawScore(int score) {
    gotoxy((WIDTH + 5) * 2, 5);
    cout << "SCORE: " << score;
}
void ShowMenu() {
    system("cls");
    gotoxy(WIDTH / 2, HEIGHT / 2 - 3);
    cout << "  S N A K E  G A M E  ";

    gotoxy(WIDTH - 10, HEIGHT / 2 - 1);
    cout << "1. SOLID WALLS";

    gotoxy(WIDTH - 10, HEIGHT / 2);
    cout << "2. NO WALLS";

    gotoxy(WIDTH - 10, HEIGHT / 2 + 2);
    cout << "Select your mode (1 - 2): ";
}
