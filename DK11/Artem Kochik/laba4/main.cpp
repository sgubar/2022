// 14 варіант //
#include <GL/glut.h>
#define _USE_MATH_DEFINES
#include <math.h>
double zoom = 1; // вибираємо масштаб
double lr, ud;
void ZoomKeys(int key, int x, int y) { // регулювання стрілками (положення) та клавішами 9 і 3(масштаб) на NumLock
	switch (key) {
	case GLUT_KEY_PAGE_DOWN: // задаю наближення 
		zoom = zoom + 0.1;
		break;
	case GLUT_KEY_PAGE_UP: // задаю віддалення 
		zoom = zoom - 0.1;
		break;
	case GLUT_KEY_LEFT: // задаю зміщення вліво 
		lr = lr - 0.1;
		break;
	case GLUT_KEY_RIGHT:// задаю зміщення в право 
		lr = lr + 0.1;
		break;
	case GLUT_KEY_UP:// задаю зміщення в верх 
		ud = ud + 0.1;
		break;
	case GLUT_KEY_DOWN: // задаю зміщення вниз 
		ud = ud - 0.1;
		break;
	}
}
void Graf() {
	int a = 1;
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // фон - чорний 
	glBegin(GL_LINE_STRIP); 
	glColor3f(0.0f, 1.0f, 0.0f); // колір графіка - синій
	for (double t = -M_PI; t <= M_PI; t += 0.01) { // межі графіка
		float x = (2 * a * cos(t) * (1 - cos(t)) / M_PI);
		float y = (2 * a * sin(t) * (1 - cos(t)) / M_PI);
		glVertex2f(x / zoom + lr, y / zoom + ud);
	}
	glEnd();
}
void LineX() {
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // фон - чорний
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 0.0f); //колір лінії
	glVertex2f(-1, 0);
	glVertex2f(1, 0);
	glEnd();
}
void LineXY(double x) {
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // фон - чорний
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f); //колір поділок
	glVertex2f(x, 0.025);
	glVertex2f(x, -0.025);
	glEnd();
}
void LineY() {
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // фон - чорний
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 0.0f); //колір лінії
	glVertex2f(0, -1);
	glVertex2f(0, 1);
	glEnd();
}
void LineYX(double y) {
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // фон - чорний
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
	glutInit(&argc, argv);  // ініціалізація GLUT
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
	glutInitWindowPosition(50, 50); // відстань від графіка до лівого краю і до верху
	glutInitWindowSize(800, 800);//ширина і висота графіка
	glutCreateWindow("Malynok");
	glutSpecialFunc(ZoomKeys);
	glutDisplayFunc(display); // реєстрація функції зворотного
  glFlush();// виклик для малювання вікна
	glutMainLoop();// вхід у цикл обробки подій GLUT
	return 0;
}
