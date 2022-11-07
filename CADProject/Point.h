#pragma once
class Point
{
public:
	static long num;
	long id;
	double posX, posY, posZ;
	Point() { id = ++num; };
	Point(double posX, double posY, double posZ);
	void printPos();
};