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
	//��Example.cpp�й���������Solid������solid1��ŷ�������𲽽����Ĵ�ͨ�׵ĳ����壻solid2��ŷ����������������sweep����ɨ�Ӷ��ɵĶ�׶����塣
	Solid* solid1 = Example1();
	Solid* solid2 = Example2();
	solid1->nextSolid = solid2;
	//����̨���
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