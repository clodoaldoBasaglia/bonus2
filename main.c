#include <stdio.h>
#include <GL/freeglut.h>

float spin = 0;
float width = 800;
float height = 800;

void Loop(int value){
    spin += 1.0f;
    if (spin >= 360.0f){
        spin = 0.0f;
    }
    glutPostRedisplay();
    glutTimerFunc(40,Loop, 1);
}

int init(void){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-3.0, 3.0, -3.0, 3.0, 1.0, 50);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    bule1();
    bule2();
    bule3();
    bule4();

    glFlush();
}


void bule1(){
    glColor3f(0, 191, 255);
    glPushMatrix();
    glViewport(0, height/2, width/2, height/2);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 50.0, 1.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, .0);
    glutWireTeapot(1.5);
    glPopMatrix();
}


void bule2(){
    glColor3f(173,255,47);
    glPushMatrix();
    glViewport(width/2, height/2, width/2, height/2);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(-1.0, 0.0, 0.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);
    glutWireTeapot(1.5);
    glPopMatrix();
}


void bule3(){
    glColor3f(255, 0, 0);
    glPushMatrix();
    glViewport(0, 0, width/2, height/2);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 1.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);
    glutWireTeapot(1.5);
    glPopMatrix();
}

void bule4(){
    glColor3f(75,0,130);
    glPushMatrix();
    glViewport(width/2, 0, width/2, height/2);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluPerspective(70.0, 1.0, 1.0, 5.0);
    gluLookAt(0.0, 0.0, 1.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);
    glRotatef(45.0, 1, 0, 0);
    glRotatef(spin*1, 0, 0, 1);
    glutWireTeapot(0.6);
    glPopMatrix();
}

int main(int argc, char** argv){
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(width,height);
  glutCreateWindow("Bonus dois - bule - Clodoaldo 968692");
  init();
  glutDisplayFunc(display);
  glutTimerFunc(20,Loop,1);
  glutMainLoop();
  printf("oi ");
  return 0;
}
