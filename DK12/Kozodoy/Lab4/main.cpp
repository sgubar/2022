#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <GL/glut.h> 
#include <math.h>

double offsetX, offsetY;

void moveKeys(int key, int x, int y)
{ // ������� ��������(���, �����, �����, ����)
	switch (key)
	{
	case GLUT_KEY_LEFT: // ������� ����
		offsetX = offsetX - 0.25;
		glutPostRedisplay();
		break;
	case GLUT_KEY_RIGHT: // ������� ������
		offsetX = offsetX + 0.25;
		glutPostRedisplay();
		break;
	case GLUT_KEY_UP: // ������� �����
		offsetY = offsetY + 0.25;
		glutPostRedisplay();
		break;
	case GLUT_KEY_DOWN: // ������� ����
		offsetY = offsetY - 0.25;
		glutPostRedisplay();
		break;
	}
}

void printGraf()
{
	int a = 1;
	glBegin(GL_LINE_STRIP);
	glColor3f(1.0f, 1.0f, 1.0f); // ���� �������
	for (double t = -M_PI; t <= M_PI; t += 0.01) // ��������� �������
	{
		float x = (a * (cos(t)/ t));
		float y = (a * (sin(t) / t));
		glVertex2f(x / 5 + offsetX, y / 5 + offsetY);
	}
	glEnd();
}

void printAxes()
{
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f); // ���� �� X
	glVertex2f(-1, 0);
	glVertex2f(1, 0);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f); // ���� �� Y
	glVertex2f(0, 1);
	glVertex2f(0, -1);
	glEnd();
}

void printDivisions()
{
	for (double x = -1; x <= 1; x += 0.25)
	{
		glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 1.0f); // ���� ������
		glVertex2f(x, 0.025);
		glVertex2f(x, -0.025);
		glEnd();
	}
	for (double y = -1; y <= 1; y += 0.25)
	{
		glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 1.0f); // ���� ������
		glVertex2f(0.025, y);
		glVertex2f(-0.025, y);
		glEnd();
	}
}

void display() // ��������� �� �����
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	printGraf();
	printAxes();
	printDivisions();
	glutSwapBuffers();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv); // ����������� GLUT
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
	glutInitWindowPosition(100, 100); // ��������� ����
	glutInitWindowSize(600, 600);// ������ �� ������ ����
	glutCreateWindow("Graf"); // ��������� ����
	glutSpecialFunc(moveKeys);
	glutDisplayFunc(display); 
	glFlush(); // ������ ��� ��������� ����
	glutMainLoop(); // ���� � ���� ������� ���� GLUT
	return 0;
}