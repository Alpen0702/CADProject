#pragma once
#include "Solid.h"
#include "Loop.h"

class Solid;
class Loop;
class Face
{
public:
	static long num;
	long id;
	Loop* outerLoop = nullptr;
	Loop* innerLoop = nullptr;
	Solid* solid = nullptr;
	Face* nextFace = nullptr;
	Face* preFace = nullptr;
	Face() { id = ++num; };
	Face(Loop* outerLoop);
};

