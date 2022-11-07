#pragma once
#include "Point.h"
class Vertex
{
public:
	Point* point = nullptr;
	Vertex() {};
	Vertex(Point* point);
};

