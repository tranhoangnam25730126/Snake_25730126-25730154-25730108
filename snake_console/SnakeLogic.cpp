#include <iostream>
#include <conio.h>
#include "Common.h"

void Setup(Snake& s) {
    s.dir = STOP;
    s.isGrowing = false;
    s.body.clear();

    int initialLength = 10;
    int startX = 15;
    int startY = 10;

    for (int i = 0; i < initialLength; i++) {
        s.body.push_back({ (short)(startX - i), (short)(startY) });
    }
}

void Move(Snake& s) {
    if (s.dir == STOP) return;

    COORD newHead = s.body[0];

    if (s.dir == LEFT) newHead.X--;
    if (s.dir == RIGHT) newHead.X++;
    if (s.dir == UP) newHead.Y--;
    if (s.dir == DOWN) newHead.Y++;

    if (!hasWall) {
        if (newHead.X < 1) newHead.X = WIDTH;
        else if (newHead.X > WIDTH) newHead.X = 1;

        if (newHead.Y < 1) newHead.Y = HEIGHT;
        else if (newHead.Y > HEIGHT) newHead.Y = 1;
    }

    s.body.insert(s.body.begin(), newHead);

    if (!s.isGrowing) {
        COORD tail = s.body.back();
        gotoxy(tail.X * 2, tail.Y);
        cout << "  ";
        s.body.pop_back();
    }
    else {
        s.isGrowing = false;
    }
}

void Input(Snake& s) {
    if (_kbhit()) {
        char key = _getch();
        if (key == 'p' || key == 'P') {
            isPaused = !isPaused;
            gotoxy((WIDTH + 5) * 2, 10);
            if (isPaused) cout << "PAUSED";
            else cout << "      ";
        }
        else if (key == 'x' || key == 'X')
            isGameOver = true;

        if (!isPaused) {
            switch (key) {
            case 'a': case 'A':
                if (s.dir != RIGHT) s.dir = LEFT; break;
            case 'd': case 'D':
                if (s.dir != LEFT) s.dir = RIGHT; break;
            case 'w': case 'W':
                if (s.dir != DOWN) s.dir = UP; break;
            case 's': case 'S':
                if (s.dir != UP) s.dir = DOWN; break;
            }
        }
    }
}