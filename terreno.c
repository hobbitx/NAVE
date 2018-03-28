#include <GL/freeglut.h>
#include <math.h>
#include <time.h>
#include "texto.h"
#include <stdio.h>
int posi[110];
int basex,basey=20;
int aleatoriot,aleatoriob;
int raio = 40;
int larguratela = 200;
char base[50];
void desenhaterreno(int largurabase,int bx)
{
  srand(time(0));
  int x,y,maior,i;
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    glColor3f(1,1,0);
    glBegin(GL_LINE_LOOP);
          basex=bx;
            
        
           glVertex3f(0,0,0);
            for(x = 0; x <= basex; x++){
               aleatoriot=rand()%400;
               if(aleatoriot>100){
                  if(y>70){
                   y=50;
                  }
                  y++;
                }
                else{
                   if(y<0){
                      y=10;
                    }
                  y--;
                }

                glVertex3f(x,y,0);
                posi[x]=y;
            }
      basey=y;
            glColor3f(1,0,0);
           glVertex3f(basex,basey,0.1);
           glVertex3f(basex+largurabase,basey,0.1);
          
            sprintf(base,"x da base:%d y da base:%d ",basex,basey);
            escreveTexto(base,150,190);
      for(x = (basex+largurabase); x <= larguratela; x++){
              aleatoriot=rand()%400;
                glColor3f(1,1,0);
               if(aleatoriot>100){
                  if(y>70){
                   y=50;
                  }
                  y++;
                }
                else{
                   if(y<0){
                      y=10;
                    }
                  y--;
                }

                glVertex3f(x,y,0);
                posi[x]=y;
            }
            glVertex3f(200,0,0);
    glEnd();
    glutSwapBuffers();
}
int returnbasey(){

  return basey;
}