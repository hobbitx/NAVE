#include "estrelas.h"
int aleatorio_x = 0 , aleatorio_y=0;


void criarEstrelas(){
   srand(time(0));

      glClearColor(0, 0, 0, 0);
  int estrelas;
  int i;
  estrelas = 100+rand()%185;
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glColor3f(1,1,1);

   // glSmooth_point_size_range(2);
    
    for (i = 0; i < estrelas;i++){
      glBegin(GL_POINTS);
      if (i%2==0){
          glColor3f(1,0,1);
          glPointSize(1);
      }
      else{
         glColor3f(1,1,1);
      glPointSize(1);
      }
      aleatorio_x = rand()%100;
      aleatorio_y = rand()%100;
      glVertex3f(aleatorio_x,aleatorio_y,1);
          glEnd();
    }

    
}