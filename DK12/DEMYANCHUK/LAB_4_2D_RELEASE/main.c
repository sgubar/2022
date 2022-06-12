#include <GL/glut.h>
#define _USE_MATH_DEFINES
#include <math.h>

/*
    VARIANT - №4
*/

double zoom = 2.3;
double lr, ud;
void ZoomKeys(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_PAGE_DOWN:
		zoom = zoom + 0.5;
		break;
	case GLUT_KEY_PAGE_UP:
		zoom = zoom - 0.5;
		break;
	case GLUT_KEY_LEFT:
		//lr = lr - 0.5;
		break;
	case GLUT_KEY_RIGHT:
		//lr = lr + 0.5;
		break;
	case GLUT_KEY_UP:
		//ud = ud + 0.5;
		break;
	case GLUT_KEY_DOWN:
		//ud = ud - 0.5;
		break;
	}
}

void Graf() {
	int a = 1;
	int b = 0.25;
	glBegin(GL_LINE_STRIP);
	glColor3f(1.0f, 0.0f, 0.0f); // color
	for (double t = 0; t <= 5*M_PI; t += 0.01) {
		float x = a * exp(b * t) * cos(t);
		float y = a * exp(b * t) * sin(t);
		glVertex2f(x / zoom + lr, y / zoom + ud);
	}
	glEnd();
}

void LineX() {
	glBegin(GL_LINES);
	glColor3f(0.0f, 1.0f, 0.0f); //line color
	glVertex2f(-1, 0);
	glVertex2f(1, 0);
	glEnd();
}

void LineXY(double x) {
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f); //division color
	glVertex2f(x, 0.025);
	glVertex2f(x, -0.025);
	glEnd();
}

void LineY() {
	glBegin(GL_LINES);
	glColor3f(0.0f, 1.0f, 0.0f); //line color
	glVertex2f(0, -1);
	glVertex2f(0, 1);
	glEnd();
}

void LineYX(double y) {
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f); //division color
	glVertex2f(0.025, y);
	glVertex2f(-0.025, y);
	glEnd();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	Graf();
	LineX();
	for (double x = -1; x <= 1; x += 0.5) {
		LineXY(x);
	}
	LineY();
	for (double y = -1; y <= 1; y += 0.5) {
		LineYX(y);
	}
	glutSwapBuffers();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
	glutInitWindowPosition(300, 23); // from left side and top
	glutInitWindowSize(800, 800);// with and hight
	glutCreateWindow("function");
	glutSpecialFunc(ZoomKeys);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
