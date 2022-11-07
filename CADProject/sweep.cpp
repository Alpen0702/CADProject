#include "Vector.h"
#include "Solid.h"
#include "EulerOperations.h"

void sweep(Face* face, Vector vector)
{
	//first-是原底面上的拓扑，firstBuilt-是新构成面上的拓扑
	Loop* outerLoop = face->outerLoop;
	HalfEdge* firstEdge = outerLoop->firstEdge;
	Vertex* firstVertex = firstEdge->beginVertex;
	Vertex* nextVertex = firstEdge->endVertex;

	Point* firstBuiltPoint = vector.PointAddVec(firstVertex->point);
	Vertex* firstBuiltVertex = new Vertex(firstBuiltPoint);
	mev(firstVertex, firstBuiltVertex, outerLoop);
	
	Vertex* preBuiltVertex = firstBuiltVertex;
	HalfEdge* nextEdge = firstEdge;
	while (nextVertex != firstVertex)
	{
		Point* nextBuiltPoint = vector.PointAddVec(nextVertex->point);
		Vertex* nextBuiltVertex = new Vertex(nextBuiltPoint);
		//必须在新建边前找到原底面上的下一条边
		nextEdge = nextEdge->nextEdge;
		mev(nextVertex, nextBuiltVertex, outerLoop);
		mef(preBuiltVertex, nextBuiltVertex, outerLoop);
		preBuiltVertex = nextBuiltVertex;
		nextVertex = nextEdge->endVertex;
	}

	mef(preBuiltVertex, firstBuiltVertex, outerLoop);
}