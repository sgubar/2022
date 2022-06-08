#include <GL/glut.h>
#define _USE_MATH_DEFINES
#include <math.h>

// Option 14
// keys - ↑ scale up, ↓ scale down

double zoom = 1.5;
void keys(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_UP:
        zoom = zoom + 0.2;
        break;
    case GLUT_KEY_DOWN:
        zoom = zoom - 0.2;
        break;
    }
}
void Graf()
{
    int a = 1;
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 1.0f);
    for (double t = -2.5 * M_PI; t <= 2.5 * M_PI; t += 0.01)
    {
        float x = a * cos(t / 5) * cos(t);
        float y = a * cos(t / 5) * sin(t);
        glVertex2f(x / zoom, y / zoom);
    }
    glEnd();
}
void LineX()
{
    glBegin(GL_LINES);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(-1, 0);
    glVertex2f(1, 0);
    glEnd();
}
void LineXY(double x)
{
    glBegin(GL_LINES);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(x, 0.025);
    glVertex2f(x, -0.025);
    glEnd();
}
void LineY()
{
    glBegin(GL_LINES);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0, -1);
    glVertex2f(0, 1);
    glEnd();
}
void LineYX(double y)
{
    glBegin(GL_LINES);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.025, y);
    glVertex2f(-0.025, y);
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

void timer(int value)
{
    glutPostRedisplay();
    glutTimerFunc(30, timer, 0);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Lab4");
    glutSpecialFunc(keys);
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
    glFlush();
    glutMainLoop();
    return 0;
}
