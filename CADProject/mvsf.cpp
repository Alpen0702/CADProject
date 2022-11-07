#include "EulerOperations.h"
#include "Vertex.h"
#include "Solid.h"
#include "Loop.h"

Solid* mvsf(Vertex* vertex)
{
	Face* face = new Face;
	Loop* loop = new Loop;
	Solid* solid = new Solid;
	solid->firstFace = face;
	face->solid = solid;
	face->outerLoop = loop;
	loop->face = face;
	//loop->solid = solid;
	return solid;
}