#include <iostream>
#include <conio.h>
#include <ctime>
#include <Windows.h>
#include "Common.h"

bool isGameOver = false;

int main(){

    srand((unsigned int)time(NULL));

    Snake s;
    Food f;

    bool isKeepPlaying = true;

    while (isKeepPlaying) {
        ShowMenu();
        char choice = _getch();
        while (choice != '1' && choice != '2')
            choice = _getch();

        if (choice == '1') hasWall = true;
        else hasWall = false;

        system("cls");
        Setup(s);
        DrawWall(hasWall);
        DrawSnake(s);
        GenerateFood(f, s);
        DrawFood(f);
        score = 0;
        DrawScore(score);
        isGameOver = false;
        isPaused = false;

        while (!isGameOver) {
            Input(s);
            if (!isPaused) {
            Move(s);

                if (CheckEat(s, f)) {
                    Beep(800, 50);
                    GenerateFood(f, s);
                    DrawFood(f);
                    DrawScore(score);
                }

            if (isCollision(s)) {
                    isGameOver = true;
                    break;
                }

                DrawSnake(s);

                Sleep(100);
            }
        }

        gotoxy(0, HEIGHT + 2);
        cout << "===========================" << endl;
        cout << "   GAME OVER! SCORE: " << score << endl;
        cout << "===========================" << endl;

        gotoxy(0, HEIGHT + 5);
        cout << "Press 'R' to Play Again or 'X' to Exit!";

        bool waitingForInput = true;
        while (waitingForInput) {
            char choice1 = _getch();
            if (choice1 == 'r' || choice1 == 'R') {
                waitingForInput = false;
            }
            else if (choice1 == 'x' || choice1 == 'X') {
                isKeepPlaying = false;
                waitingForInput = false;
            }
        }
    }

    gotoxy(0, HEIGHT + 6);
    cout << "Press any key to exit...";

    _getch();
}