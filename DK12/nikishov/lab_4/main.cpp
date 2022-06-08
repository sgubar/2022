/*
 * var: 11
 *
 * g++ main.cpp -o main -lGL -lglut -lm
 *
 */

#include <GL/glut.h>

#define _USE_MATH_DEFINES
#include <cmath>

double static zoom = 5;
double leftRigth, upDown;

void shutdown(unsigned char key, int x, int y) {
	switch (key) {
	case 27: 
		exit(0);
		break;
	default:
		;
	}
}

void controlKeys(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_LEFT:
		leftRigth = leftRigth - 0.5;
		break;
	case GLUT_KEY_RIGHT:
		leftRigth = leftRigth + 0.5;
		break;
	case GLUT_KEY_UP:
		upDown = upDown + 0.5;
		break;
	case GLUT_KEY_DOWN:
		upDown = upDown - 0.5;
		break;  
	}
}

void grafBuilder(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	
	glBegin(GL_LINE_STRIP);
	glColor3f(1.0f, 1.0f, 1.0f);
    int a = 1;
    float k = 19/5;
	for (double t = 0; t <= M_PI*5; t += 0.05) {
		float x = (k + 1) * (cos(t) - (cos((k+1)*t) / k + 1));
		float y = (k + 1) * (sin(t) - (sin((k+1)*t) / k + 1));

		glVertex2f(x/zoom + leftRigth, y/zoom + upDown);
	}
	glEnd();
}

void lineX(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(-1, 0);
		glVertex2f(1, 0);
	glEnd();
}

void lineXY(double x)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(x, 0.025);
	glVertex2f(x,-0.025);
	glEnd();
}

void lineY(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(0,-1 );
	glVertex2f(0,1 );
	glEnd();
}

void lineYX(double y)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f( 0.025, y);
	glVertex2f(-0.025, y);
	glEnd();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	grafBuilder();
	lineX();
	for (double x = -1; x <= 1; x += 0.5) {
		lineXY(x);
	}
	lineY();
	for (double y = -1; y <= 1; y += 0.5) {
		lineYX(y);
	}
	glutSwapBuffers();
}

void timer(int value)
{
	glutPostRedisplay(); 
	glutTimerFunc(30, timer, 0); 
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Graph");
	glutSpecialFunc(controlKeys);
	glutDisplayFunc(display);
	glutKeyboardFunc(shutdown);
	glutTimerFunc(0, timer, 0);
	glFlush();
	glutMainLoop();

	return 0;
}
