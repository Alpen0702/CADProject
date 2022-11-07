#pragma once

class Point;
class Vector
{
public:
	double deltaX = 0;
	double deltaY = 0;
	double deltaZ = 0;
	Vector() {};
	Vector(double deltaX, double deltaY, double deltaZ);
	Point* PointAddVec(Point* oldPoint);
};