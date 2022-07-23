#include <GL/freeglut.h>
#include <cmath>
double scaleX = 0.1;
double scaleY = 0.1;
//поділка шкали
#define scaleStep 0.02
void DrawAxis(double angle=0) {
    //розмір стрілок
    static double d = 0.02;
    //мож поворот 
    glPushMatrix();
    glRotatef(angle,0,0,1);
    //визн стрілок
    glBegin(GL_LINES);
        glVertex2f(-1,0);
        glVertex2f(1,0);
        glVertex2f(1,0);
        glVertex2f(1-d,0+d);
        glVertex2f(1,0);
        glVertex2f(1-d,0-d);
    glEnd();
    glPopMatrix();
}

void DrawGraph(int n=100/*кількість точок на графіку*/) {
    //graph scalling
    glScalef(scaleX,scaleY,1);
    glBegin(GL_LINE_STRIP);
    for(int i =0; i<=n; i++) {
        double t = 4*M_PI/n*i;// i - число у циклі, t - неск парам
        glVertex2f((2+cos(5/2.*t))*cos(t),(2+cos(5/2.*t))*sin(t));
    }
    glEnd();
}

void DrawDivisions(double angle=0) {
    //розмір ділення
    static double d = 0.05;
    //можливий поворот
    glPushMatrix();
    glRotatef(angle,0,0,1);
    glBegin(GL_LINES);
    //визн ліній
    for(int i=-10;i<=10;i+=2) {
        glVertex2f(scaleX*i,-1*d);
        glVertex2f(scaleX*i,d);
    }
    glEnd();
    glPopMatrix();
}

void display() {
    //чорний колір фону
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    //осі
    glLineWidth(2);
    glColor3f(1,1,1);//білий
    DrawAxis();
    DrawDivisions();
    DrawAxis(90);
    DrawDivisions(90);
    glColor3f(0,0,1);//синій
    //малюєм графік
    DrawGraph();

    glutSwapBuffers();
}

void mouseFunc(int button, int state, int x, int y) {
    //скролл
    if (state == GLUT_DOWN) {
        switch(button) {
            case 3:
                scaleX += scaleStep;
                scaleY += scaleStep;
                break;
            case 4:
                scaleX -= scaleStep;
                scaleY -= scaleStep;
                break;
            default:
                break;
        }
    } 
    glutPostRedisplay();
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Graph of function");
    glutDisplayFunc(display);
    glutMouseFunc(mouseFunc);
    glutMainLoop();
    return 0;
}
