#pragma once
#include "Vertex.h"
#include "Solid.h"
#include "Edge.h"

Edge* mev(Vertex* oldVertex, Vertex* newVertex, Loop* loop);
Face* mef(Vertex* vertex1, Vertex* vertex2, Loop* loop);
Solid* mvsf(Vertex* vertex);
Loop* kemr(Edge* killEdge, Face* outerFace);
void kfmrh(Face* innerFace, Face* outerFace);