#include "HalfEdge.h"
#include "Edge.h"

Loop* kemr(Edge* killEdge, Face* outerFace)
{
	HalfEdge* he1 = killEdge->he1;
	HalfEdge* he2 = killEdge->he2;
	//Face* face = he1->loop->face;
	//he1��he2�Ļ�
	HalfEdge* firstEdge = he1->nextEdge;
	HalfEdge* lastEdge = he1->nextEdge;
	while (lastEdge->nextEdge != he2)
		lastEdge = lastEdge->nextEdge;
	lastEdge->nextEdge = firstEdge;
	firstEdge->loop->firstEdge = firstEdge;
	//���ص��»��Ǵ�he1��he2�Ļ�
	Loop* newLoop = new Loop(firstEdge);
	newLoop->face = outerFace;
	//�󶨵�����ڻ�
	newLoop->nextLoop = outerFace->innerLoop;
	outerFace->innerLoop = newLoop;
	//he2��he1�Ļ�
	firstEdge = he2->nextEdge;
	lastEdge = he2->nextEdge;
	while (lastEdge->nextEdge != he1)
		lastEdge = lastEdge->nextEdge;
	lastEdge->nextEdge = firstEdge;
	//���þɻ�ָ���firstEdge������ɵ�firstEdge�������»��϶������Ҳ����ɻ�
	Loop* oldLoop = he1->loop;
	oldLoop->firstEdge = firstEdge;
	delete killEdge;
	return newLoop;
}
