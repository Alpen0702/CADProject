#include "Point.h"
#include <cstdio>

Point::Point(double posX, double posY, double posZ)
{
	this->posX = posX;
	this->posY = posY;
	this->posZ = posZ;
	id = ++num;
}

void Point::printPos()
{
	printf("Point id = %d, Point position = (%.2lf, %.2lf, %.2lf)\n", id, posX, posY, posZ);
}
