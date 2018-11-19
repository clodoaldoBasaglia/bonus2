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
    glClearColor(0.0, 0.0, 0.0, 0.0);       //define a cor de fundo
    glEnable(GL_DEPTH_TEST);                //remoção de superficie oculta
    glMatrixMode(GL_PROJECTION);            //define que a matriz eh a de projeção
    glLoadIdentity();                       //carrega a matriz de identidade
    glOrtho(-3.0, 3.0, -3.0, 3.0, 1.0, 50); //define uma projeção ortografica
}

void display(){
    //limpa o buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    desenha_buleCSE(); // bule azul claro
    desenha_buleCSD(); // bule amarelo
    desenha_buleCIE(); // bule roxo
    desenha_buleCID(); // bule verde

    glFlush();
}

// bule azul claro
void desenha_buleCSE(){
    glColor3f(0, 1, 1);
    glPushMatrix();             //armazena a matriz corrente
    glViewport(0, height/2, width/2, height/2);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(0.0, 50.0, 1.0,   //posição da camera - topo
              0.0, 0.0, 0.0,    //para onde a camera aponta
              0.0, 1.0, .0);   //vetor view-up
    glutWireTeapot(1.5);
    glPopMatrix();              //restaura a matriz anterior
}

// bule amarelo
void desenha_buleCSD(){
    glColor3f(1, 1, 0);
    glPushMatrix();             //armazena a matriz corrente
    glViewport(width/2, height/2, width/2, height/2);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(-1.0, 0.0, 0.0,   //posição da camera - lateral direita
              0.0, 0.0, 0.0,    //para onde a camera aponta
              0.0, 1.0, 0.0);   //vetor view-up
    glutWireTeapot(1.5);
    glPopMatrix();              //restaura a matriz anterior
}

// bule roxo
void desenha_buleCIE(){
    glColor3f(1, 0, 1);
    glPushMatrix();             //armazena a matriz corrente
    glViewport(0, 0, width/2, height/2);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(0.0, 0.0, 1.0,    //posição da camera - visão frontal
              0.0, 0.0, 0.0,    //para onde a camera aponta
              0.0, 1.0, 0.0);   //vetor view-up
    glutWireTeapot(1.5);
    glPopMatrix();              //restaura a matriz anterior
}

// bule verde
void desenha_buleCID(){
    glColor3f(0, 1, 0);
    glPushMatrix();             //armazena a matriz corrente
    glViewport(width/2, 0, width/2, height/2);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluPerspective(70.0, 1.0, 1.0, 5.0);
    gluLookAt(0.0, 0.0, 1.0,   //posição da camera - visão frontal
              0.0, 0.0, 0.0,    //para onde a camera aponta
              0.0, 1.0, 0.0);   //vetor view-up

    glRotatef(45.0, 1, 0, 0);
    glRotatef(spin*1, 0, 0, 1);

    glutWireTeapot(0.6);
    glPopMatrix();              //restaura a matriz anterior
}
int main(int argc, char** argv){
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(width,height);
  glutCreateWindow("Bonus dois - bule - Clodoaldo 968692");
  init();
  glubDisplayFunc(display);
  glutTimeFunc(20,Loop,1);
  glutMainLoop();
  printf("oi ");
  return 0;
}
