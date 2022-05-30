/*
                    15 варіант

 ход деления - 0.1
 двигать график при помощи стрелок
 pageUp and pageDown выбор масштаба

*/

#include <GL/glut.h>
#define _USE_MATH_DEFINES
#include <math.h>

double zoom = 1.5; // выбор масштаба
double l, u;
void ZoomKeys(int key, int x, int y) { // управление масштабом и положением
	switch (key) {
	case GLUT_KEY_LEFT:
		l = l - 0.1;
		break;
	case GLUT_KEY_RIGHT:
		l = l + 0.1;
		break;
	case GLUT_KEY_UP:
		u = u + 0.1;
		break;
	case GLUT_KEY_DOWN:
		u = u - 0.1;
		break;
	case GLUT_KEY_PAGE_DOWN:
		zoom = zoom + 0.1;
		break;
	case GLUT_KEY_PAGE_UP:
		zoom = zoom - 0.1;
	}
}

void Graf() {
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 1.0, 1.0);       // цвет самого графика
	for (double t = -4*M_PI; t <= 4*M_PI; t += 0.01) {      // формула рассчета
		float x = (exp(cos(t)) - 2*cos(4*t) + pow(sin(t/4), 3)) * cos(t);
		float y = (exp(cos(t)) - 2*cos(4*t) + pow(sin(t/4), 3)) * sin(t);
		glVertex2f(x / zoom + l, y / zoom + u);
	}
	glEnd();
}

void LineX() {                // цвет оси X
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 1.0);
	glVertex2f(-1, 0);
	glVertex2f(1, 0);
	glEnd();
}

void LineXY(double x) {         // цвет делений на оси
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 1.0);
	glVertex2f(x, 0.025);
	glVertex2f(x, -0.025);
	glEnd();
}

void LineY() {               // цвет оси Y
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 1.0);
	glVertex2f(0, -1);
	glVertex2f(0, 1);
	glEnd();
}

void LineYX(double y) {          // цвет делений на оси
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 1.0);
	glVertex2f(0.025, y);
	glVertex2f(-0.025, y);
	glEnd();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	Graf();
	LineX();
	for (double x = -1; x <= 1; x += 0.1) {
		LineXY(x);
	}
	LineY();
	for (double y = -1; y <= 1; y += 0.1) {
		LineYX(y);
	}
	glutSwapBuffers();
}

int main(int argc, char* argv[]) {
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
