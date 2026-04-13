#pragma once
#include <vector>
#include <Windows.h>

using namespace std;

const int WIDTH = 40;
const int HEIGHT = 20;

extern bool hasWall;
extern int score;
extern bool isPaused;
extern bool isGameOver;

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };

struct Snake
{
    vector<COORD> body;
    Direction dir;
    bool isGrowing;
};

struct Food
{
    COORD pos;
};

void gotoxy(int x, int y);  

void Setup(Snake& s);

void DrawWall(bool hasWall);
void DrawSnake(Snake& s);

void Move(Snake& s);
void Input(Snake& s);

bool isCollision(Snake& s);

void GenerateFood(Food& f, const Snake& s);
void DrawFood(Food& f);

bool CheckEat(Snake& s, Food& f);

void DrawScore(int score);
void ShowMenu();