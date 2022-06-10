#include <GL/glut.h>
#include <math.h>


//  ВАРІАНТ 3
//  Колір графіка білий
//  Колір  координатних  осей та поділок синій
//  Крок  поділок  осей 0.1
//  Переміщення 0,1

//Для переміщення графіка потрібно натиснути клавіші-стрілочки вниз та вверх,
//для зміщення вниз на 0,1 та вверх а 0,1, відповідно.

double zoom = 2.3;
double ox,oy;
void moveSchedule(int key, int x, int y);
void schedule();
void lineOX();
void lineOY();
void divisionsOX(double a);
void divisionsOY(double a);
void display();

int main(int argc, char* argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
  glutInitWindowPosition(300,50); // розміщення вікна програми на екрані
  glutInitWindowSize(800,800);// розміри вікна програми
  glutCreateWindow("Window"); // назва вікна програми
  glutSpecialFunc(moveSchedule); // використання функції переміщення графіка
  glutDisplayFunc(display); // реалізація графіка та декартової системи координат
  glutMainLoop();
  exit(0);
}

void moveSchedule(int key, int x, int y)
{
  switch(key)
  {
  case GLUT_KEY_UP: // переміщення вверх на 0.1
    zoom += 0.1;
    glutPostRedisplay();
    break;
  case GLUT_KEY_DOWN: // переміщення вниз на 0.1
    zoom -= 0.1;
    glutPostRedisplay();
    break;
  }
}

void schedule()
{
    int a=1;
    float b = 0.25;
  glBegin(GL_LINE_STRIP);
  glColor3f(1.0f,1.0f,1.0f); // колір графіка білий
  for(double t = -M_PI; t <= M_PI; t += 0.25)
    {
    float x = 2 * a * cos(t)* (1 - cos(t));
    float y = 2 * a * sin(t)* (1 - cos(t));
    glVertex2f(x / zoom + ox, y / zoom + oy); // вершина графіка
  }
  glEnd();
}

void lineOX()
{
  glBegin(GL_LINES);
  glColor3f(0.0f, 0.0f, 1.0f); // колір лінії осі OX(синя)
  glVertex2f(-1, 0);
  glVertex2f(1, 0);
  glEnd();
}

void divisionsOX(double a)
{
  glBegin(GL_LINES);
  glColor3f(0.0f, 0.0f, 1.0f); // колір поділок осі OX(синя)
  glVertex2f(a, 0.025);
  glVertex2f(a, -0.025);
  glEnd();
}

void lineOY()
{
  glBegin(GL_LINES);
  glColor3f(0.0f, 0.0f, 1.0f); // колір лінії осі OY(синя)
  glVertex2f(0, -1);
  glVertex2f(0, 1);
  glEnd();
}

void divisionsOY(double a)
{
  glBegin(GL_LINES);
  glColor3f(0.0f, 0.0f, 1.0f); // колір поділок осі OY(синя)
  glVertex2f(0.025, a);
  glVertex2f(-0.025, a);
  glEnd();
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  schedule(); // реалізація графіка
  lineOX(); // відтворення осі абсицса
  for(double x = -1; x <= 1; x += 0.1) //ціна поділки
    {
    divisionsOX(x); // відтворення поділок на осі OX
  }
  lineOY(); // відтворення осі ордината
  for(double y = -1; y <= 1; y += 0.1) //ціна поділки
  {
    divisionsOY(y); // відтворення поділок на осі OY
  }
  glutSwapBuffers();
}
