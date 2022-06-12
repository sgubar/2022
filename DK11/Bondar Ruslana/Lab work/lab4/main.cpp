#include <GL/glut.h>
#include <math.h>

double zoom = 2.3;
double ox,oy;


//  ВАРІАНТ 2
//  Колір графіка зелений
//  Колір  координатних  осей та поділок чероний
//  Крок  поділок  осей 0.2
//  Масштабування 0.2

//Щоб змінити масштаб потрібно натиснути на клавішах на стрілочки вниз та вверх


void moveSchedule(int key, int x, int y)
{
	switch(key)
	{
	case GLUT_KEY_UP:
    zoom += 0.2;
    glutPostRedisplay();
    break;
	case GLUT_KEY_DOWN:
    zoom -= 0.2;
    glutPostRedisplay();
    break;
	}
}

void schedule()
{
    int a=1;
    float b = 0.25;
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0f,1.0f,0.0f); // колір графіка
	for(double t = -M_PI; t <= M_PI; t += 0.2)
    {
    float x = a * cos(t)* cos(t) - b * cos(t);
    float y = a * sin(t) * cos(t) - b * cos(t);
    glVertex2f(x / zoom + ox, y / zoom + oy); // вершина графіка
	}
	glEnd();
}

void lineOX()
{
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f); // колір лінії осі OX
	glVertex2f(-1, 0);
	glVertex2f(1, 0);
	glEnd();
}

void divisionsOX(double a)
{
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f); // колір поділок осі OX
	glVertex2f(a, 0.025);
	glVertex2f(a, -0.025);
	glEnd();
}

void lineOY()
{
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f); // колір лінії осі OY
	glVertex2f(0, -1);
	glVertex2f(0, 1);
	glEnd();
}

void divisionsOY(double a)
{
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f); // колір поділок осі OY
	glVertex2f(0.02, a);
	glVertex2f(-0.02, a);
	glEnd();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	schedule(); // реалізація графіка
	lineOX(); // відтворення осі абсицса
	for(double x = -1; x <= 1; x += 0.2) //ціна поділки
    {
    divisionsOX(x); // відтворення поділок на осі OX
	}
	lineOY(); // відтворення осі ордината
	for(double y = -1; y <= 1; y += 0.2) //ціна поділки
	{
    divisionsOY(y); // відтворення поділок на осі OY
	}
	glutSwapBuffers();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
	glutInitWindowPosition(400,23); // розміщення вікна програми на екрані
	glutInitWindowSize(900,900);// розміри вікна програми
	glutCreateWindow("Program window"); // назва вікна програми
	glutSpecialFunc(moveSchedule); // використання функції переміщення графіка
	glutDisplayFunc(display); // реалізація графіка та декартової системи координат
	glutMainLoop();
	exit(0);
}
