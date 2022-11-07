#pragma once
#include "Point.h"
class Curve
{
public:
	Point* beginPoint, * endPoint;
	Curve() {};
	Curve(Point* beginPoint, Point* endPoint);
};

