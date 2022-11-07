#include "Point.h"
#include "Vertex.h"
#include "Solid.h"
#include "EulerOperations.h"
#include "Vector.h"
#include "SweepOperation.h"
#include "Example.h"

Solid* Example1()
{
	Point* p1 = new Point(-4, 0, 0);
	Point* p2 = new Point(-4, 0, -3);
	Point* p3 = new Point(-1, 0, -3);
	Point* p4 = new Point(-1, 0, 0);
	Point* p5 = new Point(-4, 3, 0);
	Point* p6 = new Point(-4, 3, -3);
	Point* p7 = new Point(-1, 3, -3);
	Point* p8 = new Point(-1, 3, 0);
	Point* p9 = new Point(-3.5, 3, -0.5);
	Point* p10 = new Point(-3.5, 3, -2.5);
	Point* p11 = new Point(-1.5, 3, -2.5);
	Point* p12 = new Point(-1.5, 3, -0.5);
	Point* p13 = new Point(-3.5, 0, -0.5);
	Point* p14 = new Point(-3.5, 0, -2.5);
	Point* p15 = new Point(-1.5, 0, -2.5);
	Point* p16 = new Point(-1.5, 0, -0.5);
	Vertex* v1 = new Vertex(p1);
	Vertex* v2 = new Vertex(p2);
	Vertex* v3 = new Vertex(p3);
	Vertex* v4 = new Vertex(p4);
	Vertex* v5 = new Vertex(p5);
	Vertex* v6 = new Vertex(p6);
	Vertex* v7 = new Vertex(p7);
	Vertex* v8 = new Vertex(p8);
	Vertex* v9 = new Vertex(p9);
	Vertex* v10 = new Vertex(p10);
	Vertex* v11 = new Vertex(p11);
	Vertex* v12 = new Vertex(p12);
	Vertex* v13 = new Vertex(p13);
	Vertex* v14 = new Vertex(p14);
	Vertex* v15 = new Vertex(p15);
	Vertex* v16 = new Vertex(p16);

	Solid* solid1 = mvsf(v1);
	Face* fc1 = solid1->firstFace;
	Loop* lp1 = fc1->outerLoop;
	mev(v1, v2, lp1);
	mev(v2, v3, lp1);
	mev(v3, v4, lp1);
	Face* fc2 = mef(v4, v1, lp1);
	Loop* lp2 = fc2->outerLoop;
	mev(v1, v5, lp2);
	mev(v4, v8, lp2);
	//输入v5和v8不可倒序；若倒序，则后面应使用新loop而非lp2来传入mef
	Face* fc3 = mef(v5, v8, lp2);
	mev(v3, v7, lp2);
	Face* fc4 = mef(v8, v7, lp2);
	mev(v2, v6, lp2);
	Face* fc5 = mef(v7, v6, lp2);
	Face* fc6 = mef(v6, v5, lp2);

	Edge* killEdge1 = mev(v5, v9, lp2);
	mev(v9, v10, lp2);
	mev(v10, v11, lp2);
	mev(v11, v12, lp2);
	Face* fc7 = mef(v12, v9, lp2);
	Loop* lp7 = fc7->outerLoop;

	//lp8是一个内环
	Loop* lp8 = kemr(killEdge1, fc2);
	//用小面fc7向下建立通孔，而非用内环lp8
	mev(v9, v13, lp7);
	mev(v10, v14, lp7);
	//由于lp8不对应一个新面，故fc8对应的是lp9，fc9对应的是lp10...
	Face* fc8 = mef(v14, v13, lp7);
	mev(v11, v15, lp7);
	Face* fc9 = mef(v15, v14, lp7);
	mev(v12, v16, lp7);
	Face* fc10 = mef(v16, v15, lp7);
	Face* fc11 = mef(v13, v16, lp7);
	kfmrh(fc7, fc1);

	return solid1;
}

Solid* Example2()
{
	Point* p2_1 = new Point(1, 0, 3);
	Point* p2_2 = new Point(1, 0, -3);
	Point* p2_3 = new Point(5, 0, 0);
	//p2_4~p2_9是底面上的内点
	Point* p2_4 = new Point(1.5, 0, 2);
	Point* p2_5 = new Point(1.5, 0, 0.25);
	Point* p2_6 = new Point(4.5, 0, 0.25);
	Point* p2_7 = new Point(1.5, 0, -2);
	Point* p2_8 = new Point(1.5, 0, -0.25);
	Point* p2_9 = new Point(4.5, 0, -0.25);
	Vertex* v2_1 = new Vertex(p2_1);
	Vertex* v2_2 = new Vertex(p2_2);
	Vertex* v2_3 = new Vertex(p2_3);
	Vertex* v2_4 = new Vertex(p2_4);
	Vertex* v2_5 = new Vertex(p2_5);
	Vertex* v2_6 = new Vertex(p2_6);
	Vertex* v2_7 = new Vertex(p2_7);
	Vertex* v2_8 = new Vertex(p2_8);
	Vertex* v2_9 = new Vertex(p2_9);

	Solid* solid2 = mvsf(v2_1);
	Face* fc2_1 = solid2->firstFace;
	Loop* lp2_1 = fc2_1->outerLoop;
	mev(v2_1, v2_2, lp2_1);
	mev(v2_2, v2_3, lp2_1);
	Face* fc2_2 = mef(v2_3, v2_1, lp2_1);
	Loop* lp2_2 = fc2_2->outerLoop;

	Edge* killEdge2_1 = mev(v2_1, v2_4, lp2_2);
	mev(v2_4, v2_6, lp2_2);
	mev(v2_6, v2_5, lp2_2);
	Face* fc2_3 = mef(v2_5, v2_4, lp2_2);
	Loop* lp2_3 = fc2_3->outerLoop;
	//lp2_4是内环
	Loop* lp2_4 = kemr(killEdge2_1, fc2_1);

	Edge* killEdge2_2 = mev(v2_2, v2_7, lp2_2);
	mev(v2_7, v2_8, lp2_2);
	mev(v2_8, v2_9, lp2_2);
	Face* fc2_4 = mef(v2_9, v2_7, lp2_2);
	Loop* lp2_5 = fc2_4->outerLoop;
	//lp2_6是内环
	Loop* lp2_6 = kemr(killEdge2_2, fc2_1);

	Vector transVec(0, 3, 0);
	sweep(fc2_2, transVec);
	sweep(fc2_3, transVec);
	sweep(fc2_4, transVec);
	kfmrh(fc2_3, fc2_2);
	kfmrh(fc2_4, fc2_2);

	return solid2;
}