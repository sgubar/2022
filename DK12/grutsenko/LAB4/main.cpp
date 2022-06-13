#include <iostream>
#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#define _USE_MATH_DEFINES
#include <math.h>

float a = 1, b = 1;
float scale = 3;

void scaling(int input, int x, int y) {

   if(input == GLUT_KEY_UP) { 
      if(scale > 0.2)      
      scale -= 0.2;
   }
   if(input == GLUT_KEY_DOWN) {
      scale += 0.2;      
   }
}

void axis(float alpha) {
   static float d = 0.05;
   glPushMatrix();
   glRotatef(alpha, 0, 0, 1);
   glBegin(GL_LINES);
      glVertex2f(-1, 0);
      glVertex2f(1, 0);     
      glVertex2f(1, 0); 
      glVertex2f(1-d, 0+d);
      glVertex2f(1, 0);
      glVertex2f(1-d, 0-d);
   glEnd();
   glFlush();
   glPopMatrix();  
}

void Xmarks(float x) {
	glBegin(GL_LINES);
	glVertex2f(x, 0.02);
	glVertex2f(x, -0.02);
	glEnd();
}
void Ymarks(float y) {
	glBegin(GL_LINES);
	glVertex2f(0.02, y);
	glVertex2f(-0.02, y);
	glEnd();
}


void functionGraph() {
   glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
   glBegin(GL_LINE_STRIP);
  
      for (float t = -M_PI; t < M_PI; t += 0.01) {
         float x = a * pow(cos(t), 2) - b * cos(t);
         float y = a * sin(t) * cos(t) - b * cos(t);
         glVertex2f(x/scale, y/scale);         
      }

   glEnd();
   glFlush();
}

void timer(int value) {
	glutPostRedisplay(); 
	glutTimerFunc(30, timer, 0); 
}

 
/* DISPLAY */
void display() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color 
   
   glLoadIdentity();

   glLineWidth(2);

   /* axis */
   glColor3f(1.0, 0.0, 0.0); // red
   axis(0);
   axis(90); 
   
   for (float i = -1; i <= 1; i += 0.2/scale) {
		Xmarks(i);
      Ymarks(i);
	}
   

   /* Graphic */
   glColor3f(0.0, 1.0, 0.0);
   functionGraph(); 

   Sleep(1);   
}

 
/* main */
int main(int argc, char** argv) {
   glutInit(&argc, argv);  
   
   glutCreateWindow("Function graph");
   glutInitWindowSize(600, 600);    
   glutInitWindowPosition(500, 500);
   glutSpecialFunc(scaling);
   glutDisplayFunc(display);

   glutTimerFunc(0, timer, 0);
   glFlush();

   glutMainLoop();  

   return 0;
}