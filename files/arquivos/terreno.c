#include "terreno.h"


void desenhaterreno(){
  terreno_textura();
  base_textura();
  
    planetas();
      // Habilita o uso de texturas
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturaTerreno);
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glColor3f(1,1,1);
    glBegin(GL_TRIANGLE_FAN);  
        glTexCoord2f(0,0); glVertex2f( 0, 0); //
        glTexCoord2f(1,0); glVertex2f( largura_mundo, 0);
        glTexCoord2f(1,1); glVertex2f( largura_mundo, y_da_base); //
        glTexCoord2f(0,1); glVertex2f( 0, y_da_base);      
     glEnd();  
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturaBase);
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glColor3f(1,1,1);
    glBegin(GL_TRIANGLE_FAN);  
        glTexCoord2f(0,0); glVertex2f( x_da_base, (y_da_base-2)); //
        glTexCoord2f(1,0); glVertex2f( x_da_base+largura_base, (y_da_base-2));
        glTexCoord2f(1,1); glVertex2f( x_da_base+largura_base, y_da_base); //
        glTexCoord2f(0,1); glVertex2f( x_da_base, y_da_base);      
     glEnd();  
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturaBandeira);
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glColor3f(1,1,1);
    glBegin(GL_TRIANGLE_FAN);  
        glTexCoord2f(0,0); glVertex2f( x_da_base, y_da_base); //
        glTexCoord2f(1,0); glVertex2f( x_da_base+6, (y_da_base));
        glTexCoord2f(1,1); glVertex2f( x_da_base+6, y_da_base+5); //
        glTexCoord2f(0,1); glVertex2f( x_da_base, y_da_base+5);      
     glEnd();  
    glDisable(GL_TEXTURE_2D);

}
int pouso (float x_da_nave,float y_da_nave){
    if (x_da_nave >= x_da_base && (x_da_nave+6)<=(x_da_base+largura_base) && y_da_nave>=y_da_base-2 && y_da_nave<=y_da_base+2) {
        return 1;
    }
return 0;
}
int colide(float y_da_nave){
    if (y_da_nave<=y_da_base){
        return 1;
    }
return 0;
}

void planetas(){
    int texturaPlaneta;
    int op,x_planeta,y_planeta;
    int tamanho_planeta=10;
    srand(time(0));
    op = rand()%5;
    x_planeta=rand()%100;
    y_planeta=20+rand()%80;
    
    if (op==1){
        texturaPlaneta = SOIL_load_OGL_texture(
            "../files/imagens/planetas/1.png",
            SOIL_LOAD_AUTO,
            SOIL_CREATE_NEW_ID,
            SOIL_FLAG_INVERT_Y
        );

        if (texturaPlaneta == 0) {
            printf("Erro do SOIL 8 '%s'\n", SOIL_last_result());
        }
    }else if (op==2){
        texturaPlaneta = SOIL_load_OGL_texture(
            "../files/imagens/planetas/2.png",
            SOIL_LOAD_AUTO,
            SOIL_CREATE_NEW_ID,
            SOIL_FLAG_INVERT_Y
        );

        if (texturaPlaneta == 0) {
            printf("Erro do SOIL P2 '%s'\n", SOIL_last_result());
        }
    }else if (op==3){
        texturaPlaneta = SOIL_load_OGL_texture(
            "../files/imagens/planetas/3.png",
            SOIL_LOAD_AUTO,
            SOIL_CREATE_NEW_ID,
            SOIL_FLAG_INVERT_Y
        );

        if (texturaPlaneta == 0) {
            printf("Erro do SOIL P3 '%s'\n", SOIL_last_result());
        }
    }else if (op==4){
        texturaPlaneta = SOIL_load_OGL_texture(
            "../files/imagens/planetas/4.png",
            SOIL_LOAD_AUTO,
            SOIL_CREATE_NEW_ID,
            SOIL_FLAG_INVERT_Y
        );

        if (texturaPlaneta == 0) {
            printf("Erro do SOIL P4 '%s'\n", SOIL_last_result());
        }
     }else{
        texturaPlaneta = SOIL_load_OGL_texture(
            "../files/imagens/planetas/5.png",
            SOIL_LOAD_AUTO,
            SOIL_CREATE_NEW_ID,
            SOIL_FLAG_INVERT_Y
        );

        if (texturaPlaneta == 0) {
            printf("Erro do SOIL P5 '%s'\n", SOIL_last_result());
        }
     }   
  glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturaPlaneta);
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glColor3f(1,1,1);
    glBegin(GL_TRIANGLE_FAN);  
        glTexCoord2f(0,0); glVertex2f( x_planeta, y_planeta); //
        glTexCoord2f(1,0); glVertex2f( x_planeta+tamanho_planeta, y_planeta);
        glTexCoord2f(1,1); glVertex2f( x_planeta+tamanho_planeta, y_planeta+tamanho_planeta); //
        glTexCoord2f(0,1); glVertex2f( x_planeta, y_planeta+tamanho_planeta);      
     glEnd();  
    glDisable(GL_TEXTURE_2D);
  

}