#include <GL/glut.h>
#include <math.h>

double zoom = 2;
double ox,oy;


/*
Варіант 12
Колір графіка зелений
Колір  координатних  осей та поділок синій
Крок  поділок  осей 0.25
Масштабування 0.25

Зміна маштабу відбуваєтся стрілочками вниз та вверх
*/

/*
    Зміна zoom для зміни маштабу
*/
void ZoomeSchedule(int key, int x, int y){
    switch(key){
        case GLUT_KEY_UP:
            zoom -= 0.25;
            glutPostRedisplay();
            break;
        case GLUT_KEY_DOWN:
            zoom += 0.25;
            glutPostRedisplay();
            break;
    }
}
/*
Реалізація графіка по точка та з'єдання їх відрізками
40 - колір графіка
*/
void schedule(){
    int a=1;
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f,1.0f,0.0f);
    for(double t = 0; t <= 5 * M_PI; t += 0.25){
        float x = a * t * cos(t);
        float y = a * t * sin(t);
        glVertex2f(x / zoom + ox, y / zoom + oy);
    }
    glEnd();
}
/*
51-65 ось ОХ та поділки на ній
*/
void lineOX(){
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(-1, 0);
    glVertex2f(1, 0);
    glEnd();
}

void divisionsOX(double a){
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(a, 0.02);
    glVertex2f(a, -0.02);
    glEnd();
}
/*
69-83 ось ОУ та поділки на ній
*/
void lineOY(){
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0, -1);
    glVertex2f(0, 1);
    glEnd();
}

void divisionsOY(double a){
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.02, a);
    glVertex2f(-0.02, a);
    glEnd();
}
/*
Вивід графіку та осей ОХ та ОУ, поділки виводятся з інтервалом у 0,25
*/
void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    schedule();
    lineOX();

    for(double x = -1; x <= 1; x += 0.25){
        divisionsOX(x);
    }

    lineOY();

    for(double y = -1; y <= 1; y += 0.25){
        divisionsOY(y);
    }
    glutSwapBuffers();
}
/*
 Розміщення вікна програми на екрані та розміри вікна програми
 Назва вікна програми lab_4
 функція маштабування та реалізація графіка та системи координат
*/
int main(int argc, char* argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
    glutInitWindowPosition(400,23);
    glutInitWindowSize(800,800);
    glutCreateWindow("lab_4");
    glutSpecialFunc(ZoomeSchedule);
    glutDisplayFunc(display);
    glutMainLoop();
    exit(0);
}
