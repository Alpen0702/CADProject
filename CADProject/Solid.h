#pragma once
#include "Face.h"

class Face;
class Solid
{
public:
	Face* firstFace = nullptr;
	Solid* nextSolid = nullptr;
	Solid() {};
	Solid(Face* face);
};

