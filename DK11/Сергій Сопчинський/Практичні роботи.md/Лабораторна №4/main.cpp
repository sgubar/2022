#include <GL/glut.h>
#define _USE_MATH_DEFINES
#include <math.h>

double zoom = 1.5;
double l, u;
void ZoomKeys(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		l = l - 0.2;
		break;
	case GLUT_KEY_RIGHT:
		l = l + 0.2;
		break;
	case GLUT_KEY_UP:
		u = u + 0.2;
		break;
	case GLUT_KEY_DOWN:
		u = u - 0.2;
		break;
	case GLUT_KEY_PAGE_DOWN:
		zoom = zoom + 0.2;
		break;
	case GLUT_KEY_PAGE_UP:
		zoom = zoom - 0.2;
	}
}

void Graf()
{
    int a = 1;
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 1.0);
	for (double t = -2.5*M_PI; t <= 2.5*M_PI; t += 0.01)
	{
		float x = a *  cos(t / 5) * cos(t);
		float y = a *  cos(t / 5) * sin(t);
		glVertex2f(x / zoom + l, y / zoom + u);
	}
	glEnd();
}
void LineX()
{
	glBegin(GL_LINES);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(-1, 0);
	glVertex2f(1, 0);
	glEnd();
}
void LineXY(double x)
{
	glBegin(GL_LINES);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(x, 0.2);
	glVertex2f(x, -0.2);
	glEnd();
}
void LineY() {               // цвет оси Y
	glBegin(GL_LINES);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(0, -1);
	glVertex2f(0, 1);
	glEnd();
}

void LineYX(double y)
{
	glBegin(GL_LINES);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(0.2, y);
	glVertex2f(-0.2, y);
	glEnd();
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	Graf();
	LineX();
	for (double x = -1; x <= 1; x += 0.2)
	{
		LineXY(x);
	}
	LineY();
	for (double y = -1; y <= 1; y += 0.2)
	{
		LineYX(y);
	}
	glutSwapBuffers();
}
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
	glutInitWindowPosition(200, 50);
	glutInitWindowSize(700, 700);
	glutCreateWindow("Variant 15");
	glutSpecialFunc(ZoomKeys);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
