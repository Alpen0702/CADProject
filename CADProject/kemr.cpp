#include "HalfEdge.h"
#include "Edge.h"

Loop* kemr(Edge* killEdge, Face* outerFace)
{
	HalfEdge* he1 = killEdge->he1;
	HalfEdge* he2 = killEdge->he2;
	//Face* face = he1->loop->face;
	//he1到he2的环
	HalfEdge* firstEdge = he1->nextEdge;
	HalfEdge* lastEdge = he1->nextEdge;
	while (lastEdge->nextEdge != he2)
		lastEdge = lastEdge->nextEdge;
	lastEdge->nextEdge = firstEdge;
	firstEdge->loop->firstEdge = firstEdge;
	//返回的新环是从he1到he2的环
	Loop* newLoop = new Loop(firstEdge);
	newLoop->face = outerFace;
	//绑定到面的内环
	newLoop->nextLoop = outerFace->innerLoop;
	outerFace->innerLoop = newLoop;
	//he2到he1的环
	firstEdge = he2->nextEdge;
	lastEdge = he2->nextEdge;
	while (lastEdge->nextEdge != he1)
		lastEdge = lastEdge->nextEdge;
	lastEdge->nextEdge = firstEdge;
	//重置旧环指向的firstEdge，避免旧的firstEdge出现在新环上而导致找不到旧环
	Loop* oldLoop = he1->loop;
	oldLoop->firstEdge = firstEdge;
	delete killEdge;
	return newLoop;
}
