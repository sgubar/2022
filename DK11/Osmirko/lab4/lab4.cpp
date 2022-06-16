// Варіант 12
// Колір графіка - зелений 
// Колір  координатних  осей та поділок - синій
// Крок  поділок осей - 0.25
// Масштабування - 0.25
// Щоб змінити масштаб потрібно натиснути на клавішах на стрілочки вниз та вверх

#include <GL/glut.h>
#include <math.h>

double zoom = 2;
double ox,oy;

void moveSchedule(int key, int x, int y)
{
  switch(key)
  {
  case GLUT_KEY_UP:
    zoom += 0.25;
    glutPostRedisplay();
    break;
  case GLUT_KEY_DOWN:
    zoom -= 0.25;
    glutPostRedisplay();
    break;
  }
}

void schedule()
{
  float a=0.5;
  glBegin(GL_LINE_STRIP);
  glColor3f(0.0f, 1.0f, 0.0f); 
  for(double t = 0; t <= 5*M_PI; t += 0.2)
    {
    float x = a * t * cos(t);
    float y = a * t * sin(t) ;
    glVertex2f(x / zoom + ox, y / zoom + oy); 
  }
  glEnd();
}

void lineOX()
{
  glBegin(GL_LINES);
  glColor3f(0.0f, 0.0f, 1.0f); 
  glVertex2f(-1, 0);
  glVertex2f(1, 0);
  glEnd();
}

void divisionsOX(double a)
{
  glBegin(GL_LINES);
  glColor3f(0.0f, 0.0f, 1.0f); 
  glVertex2f(a, 0.025);
  glVertex2f(a, -0.025);
  glEnd();
}

void lineOY()
{
  glBegin(GL_LINES);
  glColor3f(0.0f, 0.0f, 1.0f); 
  glVertex2f(0, -1);
  glVertex2f(0, 1);
  glEnd();
}

void divisionsOY(double a)
{
  glBegin(GL_LINES);
  glColor3f(0.0f, 0.0f, 1.0f); 
  glVertex2f(0.025, a);
  glVertex2f(-0.025, a);
  glEnd();
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  schedule(); 
  lineOX(); 
  for(double x = -1; x <= 1; x += 0.25) 
    {
    divisionsOX(x); 
  }
  lineOY(); 
  for(double y = -1; y <= 1; y += 0.25) 
  {
    divisionsOY(y);
  }
  glutSwapBuffers();
}

int main(int argc, char* argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
  glutInitWindowPosition(300,300); 
  glutInitWindowSize(850,850);
  glutCreateWindow("Lab4: Program Window"); 
  glutSpecialFunc(moveSchedule); 
  glutDisplayFunc(display); 
  glutMainLoop();
  exit(0);
}
