#include <GL/glut.h>
#include <math.h>

double zoom = 2.5;
double X,Y;

void moveGrafic(int key, int x, int y)
{
	switch(key)
	{
	case GLUT_KEY_LEFT:
    X = X - 0.05; // переміщення графіка вліво на 0.05
    glutPostRedisplay();
    break;
	case GLUT_KEY_RIGHT: // переміщення графіка вправо на 0.05
    X = X + 0.05;
    glutPostRedisplay();
    break;
	case GLUT_KEY_UP: // переміщення графіка вверх на 0.05
    Y = Y + 0.05;
    glutPostRedisplay();
    break;
	case GLUT_KEY_DOWN: // переміщення графіка вниз на 0.05
    Y = Y - 0.05;
    glutPostRedisplay();
    break;
	}
}

void Grafic()
{
	glBegin(GL_LINE_STRIP);
	glColor3f(1.0f,0.0f,0.0f); // колір графіка
	for(double t = -3*M_PI; t <= 3*M_PI; t += 0.25)
    {
    float x = t - sin(t);
    float y = 1 - cos(t);
    glVertex2f(x / zoom + X, y / zoom + Y); // вершина графіка
	}
	glEnd();
}

void lineX()
{
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f); // колір лінії осі X
	glVertex2f(-1, 0);
	glVertex2f(1, 0);
	glEnd();
}

void divisionsX(double a)
{
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f); // колір поділок осі X
	glVertex2f(a, 0.01);
	glVertex2f(a, -0.01);
	glEnd();
}

void lineY()
{
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f); // колір лінії осі Y
	glVertex2f(0, -1);
	glVertex2f(0, 1);
	glEnd();
}

void divisionsY(double a)
{
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f); // колір поділок осі Y
	glVertex2f(0.01, a);
	glVertex2f(-0.01, a);
	glEnd();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	Grafic(); // реалізація графіка
	lineX(); // відтворення осі абсицса
	for(double x = -1; x <= 1; x += 0.05) //ціна поділки
    {
    divisionsX(x); // відтворення поділок на осі X
	}
	lineY(); // відтворення осі ордината
	for(double y = -1; y <= 1; y += 0.05) //ціна поділки
	{
    divisionsY(y); // відтворення поділок на осі Y
	}
	glutSwapBuffers();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
	glutInitWindowPosition(500,50); // розміщення вікна програми на екрані користувача
	glutInitWindowSize(900,900);// розміри вікна програми
	glutCreateWindow("Grafic"); // назва програми "Grafic"
	glutSpecialFunc(moveGrafic); // використання функції переміщення графіка
	glutDisplayFunc(display); // реалізація графіка
	glutMainLoop();
	exit(0);
}
