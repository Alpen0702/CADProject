#pragma once
#include "Solid.h"
#define CALLBACK    __stdcall

void InitEnvironment();

//���̲�����wasd�ı��ӽ�
void KeyBoards(unsigned char key, int x, int y);

//���ֲ�����zoom in/out
void MouseWheel(int button, int dir, int x, int y);

void Display();
void Draw(int argc, char** argv, Solid* firstSolid);