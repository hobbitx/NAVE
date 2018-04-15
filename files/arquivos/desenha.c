#include "desenha.h"

void fundo(){
   
      glClearColor(1, 1, 1, 1);

    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0,0,0);
        // Associamos um canto da textura para cada vértice
         glVertex3f( 000, 000,  -1);
         glVertex3f( 100, 000,  -1);
         glVertex3f( 100, 100,  -1);
         glVertex3f( 000, 100,  -1);
    glEnd();
    
}
void menu (){

      glClearColor(0, 0, 0, 0);
      escreveTexto("N.A.V.E",45,90);
      escreveTexto("Nos Asteroides do Vasto Espaco",35,86);

    
   glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
   glColor3f(0.5,0.5,0.5);
   if (opcao_do_menu==JOGO)glColor3f(0,0,0.5);
    glBegin(GL_TRIANGLE_FAN);
              glVertex2f( 40, 70); //
              glVertex2f( 70, 70);
              glVertex2f( 70, 75); //
              glVertex2f( 40, 75);
    glEnd();
    glColor3f(1,1,1);
    escreveTexto("JOGAR",50,71);
/*-------------------------------------*/
     glColor3f(0.5,0.5,0.5);
    glBegin(GL_TRIANGLE_FAN);

   if (opcao_do_menu==AJUDA)glColor3f(0,0,0.5);
              glVertex2f( 40, 60); //
              glVertex2f( 70, 60);
              glVertex2f( 70, 65); //
              glVertex2f( 40, 65);
    glEnd();
    glColor3f(1,1,1);
    escreveTexto("AJUDA",50,61);
/*-------------------------------------*/
     glColor3f(0.5,0.5,0.5);
    glBegin(GL_TRIANGLE_FAN);

   if (opcao_do_menu==LOJA)glColor3f(0,0,0.5);
              glVertex2f( 40, 50); //
              glVertex2f( 70, 50);
              glVertex2f( 70, 55); //
              glVertex2f( 40, 55);
    glEnd();
    glColor3f(1,1,1);
    escreveTexto("LOJA",51,51);
/*-------------------------------------*/
     glColor3f(0.5,0.5,0.5);
    glBegin(GL_TRIANGLE_FAN);

   if (opcao_do_menu==SCORE)glColor3f(0,0,0.5);
              glVertex2f( 40, 40); //
              glVertex2f( 70, 40);
              glVertex2f( 70, 45); //
              glVertex2f( 40, 45);
    glEnd();
    glColor3f(1,1,1);
    escreveTexto("SCORE",51,41);
/*-------------------------------------*/
     glColor3f(0.5,0.5,0.5);
    glBegin(GL_TRIANGLE_FAN);
   if (opcao_do_menu==SAIR)glColor3f(0,0,0.5);
              glVertex2f( 40, 30); //
              glVertex2f( 70, 30);
              glVertex2f( 70, 35); //
              glVertex2f( 40, 35);
    glEnd();
    escreveTexto("SAIR",51,31);

    glCallList(lista_fundo);
}
void desenhaNave(int draw_motor){
  motor_textura(); 
    glEnable(GL_TEXTURE_2D);

    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

    // Começa a usar a textura que criamos
    glBindTexture(GL_TEXTURE_2D, texturaMotor);
	if (draw_motor == LIGADO){  
          glBegin(GL_TRIANGLE_FAN);
              glTexCoord2f(0,0); glVertex2f( 2, 0); //
              glTexCoord2f(1,0); glVertex2f( 4, 0);
              glTexCoord2f(1,1); glVertex2f( 4, -4); //
              glTexCoord2f(0,1); glVertex2f( 2, -4);            
          glEnd();
  }
         glColor3f(1,1,1);
         glBindTexture(GL_TEXTURE_2D, texturaNave);
        glBegin(GL_TRIANGLE_FAN); //principal
            glTexCoord2f(0,0); glVertex2f( 0, 0);
            glTexCoord2f(1,0); glVertex2f( 6, 0);
            glTexCoord2f(1,1); glVertex2f( 6, 6);
            glTexCoord2f(0,1); glVertex2f( 0, 6);
        glEnd();
        glDisable(GL_TEXTURE_2D);
}

void jogo(){

     //glClearColor(0, 0, 0, 0);
    glColor3f(.5, .5, 1);
    glPushMatrix();
        glTranslatef(x, y, 0);
        glRotatef(orientacaoEmGraus, 0, 0, 1);
        desenhaNave(draw_motor);
    glPopMatrix();
    
      glCallList(lista_terreno);
}
void ajuda(){

      glClearColor(0, 0, 0, 0);
  escreveTexto("HELP",50,90);
  escreveTexto("Seta pra cima-Liga os motores",20,75);
  escreveTexto("Seta para a esquerda-Inclina para a esquerda",20,70);
  escreveTexto("Seta para a Direita-Inclina para a Direita",20,65);
  escreveTexto("Esc- Volta ao menu principal",20,60);
  escreveTexto("P-Pausa o jogo ",20,55);
  escreveTexto("R-Reinicia o jogo ",20,50);

escreveTexto("O Objetivo do jogo e pousar a nave ,de forma que ela nao se destrua,",10,40);
escreveTexto(" na  base em baixa velocidade com menor tempo e",10,35); 
escreveTexto("gastando o minimo de combustível possivel,",10,30);
escreveTexto("assim voce marcara mais pontos.",10,25);
escreveTexto("Boa Sorte",20,20);

}
void loja(){

      glClearColor(0, 0, 0, 0);
  float pos_x_item=5, pos_y_item=70;
  float pos_x_escolha=40,pos_y_escolha=20;
  float tamanho_item=10;
  
    
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

    glColor3f(1,1,1);
  for (int i = 1; i <= qtd_itens; i++){
    glEnable(GL_TEXTURE_2D);

        sprintf(s_nome," ");
        sprintf(s_spd,"");
        sprintf(s_price,"");
    selecionaItem(i);
    naves_loja(i);
    if (item_selecionado==i){
      glColor3f(1,1,1);
      glBindTexture(GL_TEXTURE_2D, texturaNave);
      glBegin(GL_TRIANGLE_FAN);
      glTexCoord2f(0,0); glVertex2f(pos_x_escolha,pos_y_escolha+1);
      glTexCoord2f(1,0); glVertex2f(pos_x_escolha+tamanho_item,pos_y_escolha+1);
      glTexCoord2f(1,1); glVertex2f(pos_x_escolha+tamanho_item,pos_y_escolha+1+tamanho_item);
      glTexCoord2f(0,1); glVertex2f(pos_x_escolha,pos_y_escolha+tamanho_item+1);
      glEnd();  
    }
      glColor3f(1,1,1);
      glBindTexture(GL_TEXTURE_2D, texturaNave);
      glBegin(GL_TRIANGLE_FAN);
      glTexCoord2f(0,0); glVertex2f(pos_x_item,pos_y_item);
      glTexCoord2f(1,0); glVertex2f(pos_x_item+tamanho_item,pos_y_item);
      glTexCoord2f(1,1); glVertex2f(pos_x_item+tamanho_item,pos_y_item+tamanho_item);
      glTexCoord2f(0,1); glVertex2f(pos_x_item,pos_y_item+tamanho_item);
    
    glEnd();
    glDisable(GL_TEXTURE_2D);
    pos_x_item+=20;
    if (i%5==0){
      pos_y_item-=20;
      pos_x_item=5;
    }
    
  }
  naves_loja(item_selecionado);
    escreveTexto(s_nome,pos_x_escolha+11,pos_y_escolha+tamanho_item);
    escreveTexto(s_spd,pos_x_escolha+11,pos_y_escolha+tamanho_item-3);
    escreveTexto(s_price,pos_x_escolha+11,pos_y_escolha+tamanho_item-6);

}
void d_score(){
  if (controle_score==0){
   recuperar_scores();
   controle_score=1;
  }
  
  escreveTexto(s_lugar,40,90);
}
void textos(){
    sprintf(s_status," ");

    sprintf(s_pontuacao,"");
     if (pause==LIGADO){
        sprintf(s_status,"PAUSADO");
     } if (perdeu==LIGADO && vidas==0){
        sprintf(s_status,"GAME OVER");
        setRandons();
     }if (venceu==LIGADO){
        sprintf(s_status,"VOCE VENCEU");
        pontuacao=(combustivel*100)/((minutos*60)+segundos);
        sprintf(s_pontuacao,"Pontuacao: %f",pontuacao);
         if (controle_score==0){
          score();
          controle_score=1;
        }

     }

    sprintf(s_vidas,"Vidas: %d",vidas);
    sprintf(s_tempo,"Tempo: %d:%d",minutos,segundos);

      glColor3f(1,1,1);
      escreveTexto(s_velocidadeH,80,95);
      escreveTexto(s_aceleracao,80,93);
      escreveTexto(s_altura,80,91);

      escreveTexto(s_pontuacao,45,47);
      escreveTexto(s_status,45,50);
      /*---------------------*/
      escreveTexto(s_combustivel,0,95);
      escreveTexto(s_tempo,0,93);
      escreveTexto(s_vidas,0,91);
  
}