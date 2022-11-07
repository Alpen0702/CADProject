#pragma once
#include "HalfEdge.h"
#include "Solid.h"

class HalfEdge;
class Face;
class Loop
{
public:
	HalfEdge* firstEdge = nullptr;
	Loop* nextLoop = nullptr;
	Face* face = nullptr;
	Loop() {};
	Loop(HalfEdge* firstEdge);
	void print();
};

