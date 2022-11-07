#include<cstdio>
#include "Point.h"
#include "Vertex.h"
#include "Vector.h"
#include "EulerOperations.h"
#include "SweepOperation.h"
#include <iostream>
#include "Example.h"
#include "Draw.h"
#include <GL/glut.h>
using namespace std;

long Face::num = 0;
long Point::num = 0;

int main(int argc, char** argv)
{
	//在Example.cpp中构建了两个Solid，其中solid1是欧拉操作逐步建立的带通孔的长方体；solid2是欧拉操作建起底面后，用sweep操作扫掠而成的多孔多面体。
	Solid* solid1 = Example1();
	Solid* solid2 = Example2();
	solid1->nextSolid = solid2;
	//控制台输出
	Face* face = solid2->firstFace;
	while (face)
	{
		printf("Face No.%d\n", face->id);
		face->outerLoop->print();
		Loop* innerLoop = face->innerLoop;
		while (innerLoop)
		{
			printf("Innerloop:\n");
			innerLoop->print();
			innerLoop = innerLoop->nextLoop;
		}
		face = face->nextFace;
	}
	Draw(argc, argv, solid1);
}