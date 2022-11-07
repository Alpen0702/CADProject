#include "Loop.h"

Loop::Loop(HalfEdge* firstEdge)
{
	this->firstEdge = firstEdge;
}

void Loop::print()
{
	HalfEdge* he = firstEdge;
	he->print();
	he = he->nextEdge;
	while (he != firstEdge)
	{
		he->print();
		he = he->nextEdge;
	}
}