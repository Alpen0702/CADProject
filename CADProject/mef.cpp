#include "Vertex.h"
#include "Loop.h"
#include "Face.h"

Face* mef(Vertex* vertex1, Vertex* vertex2, Loop* loop)
{
	//����vertex1��vertex2˳����뱣֤��loopһ�£�������loop�п����Ҳ�������ߡ��»���he2=v2->v1����
	Curve* curve = new Curve(vertex1->point, vertex2->point);
	HalfEdge* he1 = new HalfEdge(vertex1, vertex2, curve);
	HalfEdge* he2 = new HalfEdge(vertex2, vertex1, curve);
	Loop* newLoop = new Loop;
	
	//heTemp1�ҵ���vertex1Ϊ�յ�ıߣ�heTemp2�ҵ���vertex2Ϊ�յ�ı�
	HalfEdge* heTemp1 = loop->firstEdge;
	while (heTemp1->endVertex != vertex1)
		heTemp1 = heTemp1->nextEdge;
	HalfEdge* heTemp2 = heTemp1;
	while (heTemp2->endVertex != vertex2)
		heTemp2 = heTemp2->nextEdge;
	he1->loop = loop;
	he2->loop = newLoop;
	loop->firstEdge = he1;
	newLoop->firstEdge = he2;
	he2->nextEdge = heTemp1->nextEdge;
	heTemp1->nextEdge = he1;
	he1->nextEdge = heTemp2->nextEdge;
	heTemp2->nextEdge = he2;

	Face* face = new Face(newLoop);
	newLoop->face = face;
	Solid* solid = loop->face->solid;
	//Solid* solid = loop->solid;
	//newLoop->solid = solid;
	face->solid = solid;
	face->nextFace = solid->firstFace;
	solid->firstFace->preFace = face;
	solid->firstFace = face;
	return face;
}