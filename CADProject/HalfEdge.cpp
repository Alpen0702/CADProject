#include "HalfEdge.h"
#include <cstdio>

HalfEdge::HalfEdge(Vertex* beginVertex, Vertex* endVertex, Curve* curve)
{
	this->beginVertex = beginVertex;
	this->endVertex = endVertex;
	this->curve = curve;
}

void HalfEdge::print()
{
	printf("Begin:\n");
	this->beginVertex->point->printPos();
	printf("End:\n");
	this->endVertex->point->printPos();
}