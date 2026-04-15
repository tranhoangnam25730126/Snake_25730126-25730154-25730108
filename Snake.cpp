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
        else hasWall = false;}

}