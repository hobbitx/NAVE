#include "texto.h"

void escreveTexto(char *texto, float x, float y) {
    int i;
     glColor3f(1, 1, 1);
        if (tela==SCORE){
          glRasterPos2f(x, y);
          for (i = 0; i < strlen(texto); i++) {
            if (texto[i]=='\n'){
              y-=5;
              glRasterPos2f(x, y);
            
            }
              glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, texto[i]);      
          }
        }
        else{
          glRasterPos2f(x, y);
          for (i = 0; i < strlen(texto); i++) {
          	if (tela==MENU || tela== AJUDA){
         		 	   glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, texto[i]);     
            	}else{
         			    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, texto[i]);
		        }
	       }
      }
  }
