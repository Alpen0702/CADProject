#include "Vector.h"
#include "Solid.h"
#include "EulerOperations.h"

void sweep(Face* face, Vector vector)
{
	//first-��ԭ�����ϵ����ˣ�firstBuilt-���¹������ϵ�����
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
		//�������½���ǰ�ҵ�ԭ�����ϵ���һ����
		nextEdge = nextEdge->nextEdge;
		mev(nextVertex, nextBuiltVertex, outerLoop);
		mef(preBuiltVertex, nextBuiltVertex, outerLoop);
		preBuiltVertex = nextBuiltVertex;
		nextVertex = nextEdge->endVertex;
	}

	mef(preBuiltVertex, firstBuiltVertex, outerLoop);
}