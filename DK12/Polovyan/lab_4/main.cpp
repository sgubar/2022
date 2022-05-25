#include <GL/glut.h>
#define _USE_MATH_DEFINES
#include <math.h>

////////////////////////
//                    //
//    14-й варіант    //
//                    //
////////////////////////

double zoom = 1.5; // вибираємо масштаб
double lr, ud;
void ZoomKeys(int key, int x, int y) { // регулювання стрілками (положення) та клавішами 9 і 3(масштаб) на NumLock
	switch (key) {
	case GLUT_KEY_PAGE_DOWN:
		zoom = zoom + 0.1;
		break;
	case GLUT_KEY_PAGE_UP:
		zoom = zoom - 0.1;
		break;
	case GLUT_KEY_LEFT:
		lr = lr - 0.1;
		break;
	case GLUT_KEY_RIGHT:
		lr = lr + 0.1;
		break;
	case GLUT_KEY_UP:
		ud = ud + 0.1;
		break;
	case GLUT_KEY_DOWN:
		ud = ud - 0.1;
		break;
	}
}
void Graf() {
	int a = 1;
	glBegin(GL_LINE_STRIP);
	glColor3f(1.0f, 1.0f, 1.0f); // колір графіка
	for (double t = -2.5*M_PI; t <= 2.5*M_PI; t += 0.01) { // графік
		float x = a *  cos(t / 5) * cos(t);
		float y = a *  cos(t / 5) * sin(t);
		glVertex2f(x / zoom + lr, y / zoom + ud);
	}
	glEnd();
}
void LineX() {
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 0.0f); //колір лінії
	glVertex2f(-1, 0);
	glVertex2f(1, 0);
	glEnd();
}
void LineXY(double x) {
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f); //колір поділок
	glVertex2f(x, 0.025);
	glVertex2f(x, -0.025);
	glEnd();
}
void LineY() {
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 0.0f); //колір лінії
	glVertex2f(0, -1);
	glVertex2f(0, 1);
	glEnd();
}
void LineYX(double y) {
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f); //колір поділок
	glVertex2f(0.025, y);
	glVertex2f(-0.025, y);
	glEnd();
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	Graf();
	LineX();
	for (double x = -1; x <= 1; x += 0.1) {
		LineXY(x);
	}
	LineY();
	for (double y = -1; y <= 1; y += 0.1) {
		LineYX(y);
	}
	glutSwapBuffers();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
	glutInitWindowPosition(200, 50); // відстань від графіка до лівого краю і до верху
	glutInitWindowSize(700, 700);//ширина і висота графіка
	glutCreateWindow("function");
	glutSpecialFunc(ZoomKeys);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

// переміщуємо графік за допомогою стрілок (звичайних або з NumLock) 
// масштаб регулюємо кнопками 3 і з  або PgUp i PgDn
// в нашій програмі ми малювали графік x = a *  cos(t / 5) * cos(t);
//				       y = a *  cos(t / 5) * sin(t);
// з межами від -2.5pi до 2.5pi
// ціна поділки - 0.1
