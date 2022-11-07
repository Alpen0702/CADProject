#include "Face.h"
#include "Loop.h"

Face::Face(Loop* outerLoop)
{
	this->outerLoop = outerLoop;
	id = ++num;
}
