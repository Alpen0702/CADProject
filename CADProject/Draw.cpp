#include "Draw.h"
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#include <iostream>

//����һ��wasd�ı��ӽ�angle��
GLfloat angle = 5.0f * 3.14159 / 180;
GLfloat sinA = sin(angle);
GLfloat cosA = cos(angle);
GLfloat xDirection = 0.0f;
GLfloat yDirection = 0.0f;
GLfloat zDirection = 10.0f;
GLfloat upDirection = 1.0f;
GLfloat mini = 0.000001f;
Solid* solid = nullptr;
Solid* solidtmp = nullptr;

void InitEnvironment()
{
	glEnable(GL_DEPTH);
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor4f(0, 0, 1, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90, 1, 0, 1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(xDirection, yDirection, zDirection, 0, 0, 0, 0, 1, 0);
}

void KeyBoards(unsigned char key, int x, int y)
{
	GLfloat oldX = xDirection;
	GLfloat oldY = yDirection;
	GLfloat oldZ = zDirection;
	//�ӵ㵽ԭ������ƽ��
	GLfloat dist2 = oldX * oldX + oldY * oldY + oldZ * oldZ;
	GLfloat maxY = sqrtf(0.99 * dist2);

	switch (key)
	{
	case 'w':
	{
		//newDirection��¼�����µ�x2+z2�������ظ����㣻���ｫ�����µ�x2+z2��Ϊһ���·�����y���򹹳ɶ�άƽ�棻����w���Ÿ��·���ľ����򱱼�ǰ����s�����ϼ�ǰ����
		GLfloat newDirection = sqrtf(oldX * oldX + oldZ * oldZ);
		yDirection = newDirection * sinA + oldY * cosA;
		//�м����tmp�����ظ�����
		GLfloat tmp;
		//�ϱ������Ǹò������������㣬��Խ������ӽǻ��ƱȽ��鷳��������������maxY = sqrtf(0.99*dist2) < dist2������Ұ������Խ����
		if (oldY + mini >= maxY)
		{
			yDirection = maxY + mini;
			tmp = 0.01 * dist2;
		}
		else
			tmp = newDirection * newDirection * cosA * cosA + oldY * oldY * sinA * sinA - 2 * newDirection * cosA * oldY * sinA;

		if (abs(oldZ) < mini)
			xDirection = sqrtf(tmp) * abs(oldX) / oldX;
		else if (abs(oldX) < mini)
			zDirection = sqrtf(tmp) * abs(oldZ) / oldZ;
		else
		{
			xDirection = sqrtf(tmp / (1 + oldZ * oldZ / oldX / oldX)) * abs(oldX) / oldX;
			zDirection = sqrtf(tmp / (1 + oldX * oldX / oldZ / oldZ)) * abs(oldZ) / oldZ;
		}
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(xDirection, yDirection, zDirection, 0, 0, 0, 0, 1, 0);
		glutPostRedisplay();
		break;
	}
	case 'a':
		xDirection = -oldZ * sinA + oldX * cosA;
		zDirection = oldZ * cosA + oldX * sinA;
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(xDirection, yDirection, zDirection, 0, 0, 0, 0, 1, 0);
		glutPostRedisplay();
		break;
	case 's':
	{
		GLfloat newDirection = sqrtf(oldX * oldX + oldZ * oldZ);
		yDirection = -newDirection * sinA + oldY * cosA;
		GLfloat tmp;
		if (oldY - mini <= -maxY)
		{
			yDirection = -maxY - mini;
			tmp = 0.01 * dist2;
		}
		else
			tmp = newDirection * newDirection * cosA * cosA + oldY * oldY * sinA * sinA + 2 * newDirection * cosA * oldY * sinA;

		if (abs(oldZ) < mini)
			xDirection = sqrtf(tmp) * abs(oldX) / oldX;
		else if (abs(oldX) < mini)
			zDirection = sqrtf(tmp) * abs(oldZ) / oldZ;
		else
		{
			xDirection = sqrtf(tmp / (1 + oldZ * oldZ / oldX / oldX)) * abs(oldX) / oldX;
			zDirection = sqrtf(tmp / (1 + oldX * oldX / oldZ / oldZ)) * abs(oldZ) / oldZ;
		}
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(xDirection, yDirection, zDirection, 0, 0, 0, 0, 1, 0);
		glutPostRedisplay();
		break;
	}
	case 'd':
		xDirection = oldZ * sinA + oldX * cosA;
		zDirection = oldZ * cosA - oldX * sinA;
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(xDirection, yDirection, zDirection, 0, 0, 0, 0, 1, 0);
		glutPostRedisplay();
		break;
	case 27:
		exit(0);
		break;
	}
}

void MouseWheel(int button, int dir, int x, int y)
{
	//zoom in
	if (dir > 0)
	{
		xDirection *= 0.8;
		yDirection *= 0.8;
		zDirection *= 0.8;
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(xDirection, yDirection, zDirection, 0, 0, 0, 0, 1, 0);
		glutPostRedisplay();
	}
	//zoom out
	else
	{
		xDirection *= 1.25;
		yDirection *= 1.25;
		zDirection *= 1.25;
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(xDirection, yDirection, zDirection, 0, 0, 0, 0, 1, 0);
		glutPostRedisplay();
	}
}

void CALLBACK tessBeginCB(GLenum which){glBegin(which);}

void CALLBACK tessEndCB(){glEnd();}

void CALLBACK tessVertexCB(const GLvoid* data)
{
	const GLdouble* ptr = (const GLdouble*)data;
	glVertex3dv(ptr);
}

void CALLBACK tessErrorCB(GLenum errorCode)
{
	const GLubyte* errorStr;
	errorStr = gluErrorString(errorCode);
}

void DrawLoop(GLUtesselator* tess, Loop* loop)
{
	GLdouble* pos;
	gluTessBeginContour(tess);
	HalfEdge* he = loop->firstEdge;
	Vertex* firstVertex = he->beginVertex;
	pos = new GLdouble[3]{ he->beginVertex->point->posX, he->beginVertex->point->posY, he->beginVertex->point->posZ };
	gluTessVertex(tess, pos, pos);
	printf("Drawing pos = %.2lf,%.2lf,%.2lf\n", pos[0], pos[1], pos[2]);
	while (he->endVertex != firstVertex)
	{
		he = he->nextEdge;
		pos = new GLdouble[3]{ he->beginVertex->point->posX, he->beginVertex->point->posY, he->beginVertex->point->posZ };
		gluTessVertex(tess, pos, pos);
		printf("Drawing pos = %.2lf,%.2lf,%.2lf\n", pos[0], pos[1], pos[2]);
	}
	gluTessEndContour(tess);
}

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	GLUtesselator* tess = gluNewTess();
	gluTessCallback(tess, GLU_TESS_BEGIN, (void (CALLBACK*)())tessBeginCB);
	gluTessCallback(tess, GLU_TESS_END, (void (CALLBACK*)())tessEndCB);
	gluTessCallback(tess, GLU_TESS_VERTEX, (void (CALLBACK*)())tessVertexCB);
	gluTessCallback(tess, GLU_TESS_ERROR, (void (CALLBACK*)())tessErrorCB);
	solid = solidtmp;
	while (solid)
	{
		Face* face = solid->firstFace;
		while (face)
		{
			gluTessBeginPolygon(tess, 0);
			//���⻷
			Loop* loop = face->outerLoop;
			DrawLoop(tess, loop);
			//���ڻ�
			loop = face->innerLoop;
			while (loop)
			{
				DrawLoop(tess, loop);
				loop = loop->nextLoop;
			}
			gluTessEndPolygon(tess);
			face = face->nextFace;
		}
		solid = solid->nextSolid;
	}
	gluDeleteTess(tess);
	glFlush();
	glutSwapBuffers();
}

void Draw(int argc, char** argv, Solid* firstSolid)
{
	solid = firstSolid;
	solidtmp = solid;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(1024, 768);
	glutCreateWindow("CADProject");
	InitEnvironment();
	glutKeyboardFunc(KeyBoards);
	glutMouseWheelFunc(MouseWheel);
	glutDisplayFunc(Display);
	glutMainLoop();
}
