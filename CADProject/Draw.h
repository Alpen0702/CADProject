#pragma once
#include "Solid.h"
#define CALLBACK    __stdcall

void InitEnvironment();

//键盘操作，wasd改变视角
void KeyBoards(unsigned char key, int x, int y);

//滚轮操作，zoom in/out
void MouseWheel(int button, int dir, int x, int y);

void Display();
void Draw(int argc, char** argv, Solid* firstSolid);