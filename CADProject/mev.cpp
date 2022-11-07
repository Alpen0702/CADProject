#include "Vertex.h"
#include "HalfEdge.h"
#include "Edge.h"

Edge* mev(Vertex* oldVertex, Vertex* newVertex, Loop* loop)
{
	HalfEdge* he1 = new HalfEdge,* he2 = new HalfEdge;
	//Curve curve(vertex1->point, vertex2->point);
	//HalfEdge halfedge(vertex1, vertex2, &curve);
	he1->beginVertex = oldVertex;
	he1->endVertex = newVertex;
	he2->beginVertex = newVertex;
	he2->endVertex = oldVertex;
	he1->nextEdge = he2;
	he1->loop = loop;
	he2->loop = loop;
	//edge²Ù×÷ÂÔ
	if (!loop->firstEdge)
	{
		he2->nextEdge = he1;
		loop->firstEdge = he1;
	}
	else
	{
		HalfEdge* heTemp = loop->firstEdge;
		while (heTemp->endVertex != oldVertex)
			heTemp = heTemp->nextEdge;
		he2->nextEdge = heTemp->nextEdge;
		heTemp->nextEdge = he1;
	} 
	Edge* edge = new Edge;
	edge->he1 = he1;
	edge->he2 = he2;
	return edge;
}