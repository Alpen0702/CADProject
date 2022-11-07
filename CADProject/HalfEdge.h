#pragma once
#include "Curve.h"
#include "Vertex.h"
#include "Loop.h"

class Loop;
class HalfEdge
{
public:
	Curve* curve = nullptr;
	Vertex* beginVertex = nullptr, * endVertex = nullptr;
	HalfEdge* nextEdge = nullptr;
	Loop* loop = nullptr;
	HalfEdge() {};
	HalfEdge(Vertex* beginVertex, Vertex* endVertex, Curve* curve);
	void print();
};

