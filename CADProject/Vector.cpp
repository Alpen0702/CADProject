#include "Point.h"
#include "Vector.h"

Vector::Vector(double deltaX, double deltaY, double deltaZ)
{
	this->deltaX = deltaX;
	this->deltaY = deltaY;
	this->deltaZ = deltaZ;
}

Point* Vector::PointAddVec(Point* oldPoint)
{
	Point* newPoint = new Point(oldPoint->posX+deltaX, oldPoint->posY+deltaY, oldPoint->posZ+deltaZ);
	return newPoint;
}
