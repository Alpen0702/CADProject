#include "Face.h"

void kfmrh(Face* innerFace, Face* outerFace)
{
	innerFace->outerLoop->nextLoop = outerFace->innerLoop;
	outerFace->innerLoop = innerFace->outerLoop;
	//É¾³ýinnerFace
	if (innerFace->preFace)
		innerFace->preFace->nextFace = innerFace->nextFace;
	else
		innerFace->solid->firstFace = innerFace->nextFace;
	if (innerFace->nextFace)
		innerFace->nextFace->preFace = innerFace->preFace;
	delete innerFace;
}
