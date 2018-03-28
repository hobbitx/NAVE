#include <GL/freeglut.h>
#include <math.h>
#include <time.h>
int aleatorio_x = 0 , aleatorio_y=0;


void criarEstrelas(int qtd){
  srand(time(0));
  int i;
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    glColor3f(1,1,1);
    glBegin(GL_POINTS);
    for (i = 0; i < qtd;i++)
    {
      aleatorio_x = rand()%200;
      aleatorio_y = rand()%200;
      glVertex3f(aleatorio_x,aleatorio_y,0.1);
    }
    glEnd();
    glutSwapBuffers();
}