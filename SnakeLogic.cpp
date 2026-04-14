#include <iostream>
#include <conio.h>
#include <ctime>
#include "Common.h"

bool hasWall = false;
int score;
bool isPaused = false;

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

bool isCollision(Snake& s) {
    COORD head = s.body[0];

    if (hasWall)
        if (head.X < 1 || head.X > WIDTH || head.Y < 1 || head.Y > HEIGHT) return true;

    for (size_t i = 1; i < s.body.size(); i++)
        if (head.X == s.body[i].X && head.Y == s.body[i].Y) return true;

    return false;
}

void GenerateFood(Food& f, const Snake& s) {
    bool redo;
    do {
        redo = false;

        f.pos.X = rand() % WIDTH + 1;
        f.pos.Y = rand() % HEIGHT + 1;

        for (auto p : s.body) {
            if (p.X == f.pos.X && p.Y == f.pos.Y) {
                redo = true;
                break;
            }
        }
    } while (redo);
}

bool CheckEat(Snake& s, Food& f) {
    if (s.body[0].X == f.pos.X && s.body[0].Y == f.pos.Y) {
        s.isGrowing = true;
        score += 10;
        return true;
    }
    return false;
}