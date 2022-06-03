#if defined(linux) || defined(_WIN32)
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif

#define _USE_MATH_DEFINES
#include <math.h>

//
// Варіант 13
//
// ESC - закрити вікно
// ← ліворуч, → праворуч, ↑ вверх, ↓ вниз
//
// компіляція g++ -framework OpenGL -framework GLUT -o main main.cpp
//

double static zoom = 0.5;
double leftRigth, upDown;

void shutdown(unsigned char key, int x, int y) {
	switch (key) {
	case 27: // Escape
		exit(0);
		break;
	}
}

void controlKeys(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_LEFT:
		leftRigth = leftRigth - 0.1;
		break;
	case GLUT_KEY_RIGHT:
		leftRigth = leftRigth + 0.1;
		break;
	case GLUT_KEY_UP:
		upDown = upDown + 0.1;
		break;
	case GLUT_KEY_DOWN:
		upDown = upDown - 0.1;
		break;  
	}
}

void graf() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_STRIP);
	glColor3f(1.0f, 1.0f, 0.0f);
    int a = 1;
	for (double t = -M_PI; t <= M_PI; t += 0.01) {
		float y = (a*sin(t) / M_PI);
		float x = (a*cos(t) / M_PI);
		glVertex2f(x/zoom + leftRigth, y/zoom + upDown);
	}
	glEnd();
}

void lineX() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(-1, 0);
		glVertex2f(1, 0);
	glEnd();
}

void lineXY(double x ) {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(x, 0.025);
	glVertex2f(x,-0.025);
	glEnd();
}

void lineY() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(0,-1 );
	glVertex2f(0,1 );
	glEnd();
}

void lineYX(double y) {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f( 0.025, y);
	glVertex2f(-0.025, y);
	glEnd();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	graf();
	lineX();
	for (double x = -1; x <= 1; x += 0.1) {
		lineXY(x);
	}
	lineY();
	for (double y = -1; y <= 1; y += 0.1) {
		lineYX(y);
	}
	glutSwapBuffers();
}

void timer(int value) {
	glutPostRedisplay(); 
	glutTimerFunc(30, timer, 0); 
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Lab 4");
	glutSpecialFunc(controlKeys);
	glutDisplayFunc(display);
	glutKeyboardFunc(shutdown);
	glutTimerFunc(0, timer, 0);
	glFlush();
	glutMainLoop();
	return 0;
}