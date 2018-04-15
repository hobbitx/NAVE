/*---------------------------------------------*\
|                                               |
|                   BIBIOTLECAS                 | 
|                                               |
\*---------------------------------------------*/
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <SOIL/SOIL.h>
#include <stdlib.h>
#include "texto.h"
#include "desenha.h"
#include "terreno.h"
#include "estrelas.h"
#include "variaveis.h"
#include "loja.h"
/*---------------------------------------------*\
|                                               |
|               lISTAS  & FUNÇÕES               | 
|                                               |
\*---------------------------------------------*/
void setRandons(){
  pontuacao=0;
  minutos=0;
  segundos=0;
  venceu=DESLIGADO;
  perdeu=DESLIGADO;
 srand(time(0));
  x = (random() %50) ;
  velocidade_horizontal = (1+rand()%10);
  velocidade_horizontal/=20;
  velocidade_vertical=0;
  y = altura_mundo;
  ran=rand()%50;
  x_da_base = 10+rand()%65;
 
}
void criaListaFundo(){
  lista_fundo = glGenLists(2);
  glNewList(lista_fundo,
    GL_COMPILE);  
    criarEstrelas();
  glEndList();
}

void criaListaTerreno(){
  lista_terreno = glGenLists(1);
  glNewList(lista_terreno,
    GL_COMPILE);  
    desenhaterreno();

  glEndList();
}  
/*---------------------------------------------*\
|                                               |
|                   MOTORES                     | 
|                                               |
\*---------------------------------------------*/
  void motores(){ //FUNÇÃO RESPONSAVEL POR TODA FISICA DA NAVE

  if (teclaA==LIGADO){ // se tecla A pressionada , aumenta o algulo 
     velocidade_angular += VARIACAO_ANGULO;
     if (velocidade_angular>ANGULACAO_TOTAL){ // se angulo maior que 90ª angulo 
       velocidade_angular=ANGULACAO_TOTAL;
     }
     teclaA=DESLIGADO;
    }
    else if (teclaD==LIGADO){
      velocidade_angular -= VARIACAO_ANGULO;
      if (velocidade_angular< -ANGULACAO_TOTAL){
       velocidade_angular= -ANGULACAO_TOTAL;
     }
      teclaD=DESLIGADO;
    }
    if(motor == LIGADO && combustivel >0 && perdeu==DESLIGADO){
      draw_motor = LIGADO;
      combustivel--;
     GLfloat orientacaoEmRadianos = grausParaRadianos(orientacaoEmGraus);
     orientacaoEmRadianos=orientacaoEmRadianos*(-1);
     velocidade_vertical+=aumento_velocidade_vertical;
     if (orientacaoEmGraus<-(ANGULACAO_TOTAL/2)){
     velocidade_horizontal+=aumento_velocidade_horizontal;
     }else if(orientacaoEmGraus>(ANGULACAO_TOTAL/2)){
     velocidade_horizontal-=aumento_velocidade_horizontal;
     }
      y+=cos(orientacaoEmRadianos)*velocidade_vertical;
      if(velocidade_vertical<0){
      x+=sin(orientacaoEmRadianos)*velocidade_vertical*(-1);
      }
      x+=sin(orientacaoEmRadianos)*velocidade_vertical;
     
    }else if (perdeu == DESLIGADO){
      if (velocidade_horizontal>1 || velocidade_horizontal<-1){
        velocidade_horizontal /= 10;
      
    }
    draw_motor = DESLIGADO; 
      if (velocidade_vertical>0)
      {
        velocidade_vertical=0;
      }
      y+= velocidade_vertical;
      x+= velocidade_horizontal;
      velocidade_vertical-=aumento_velocidade_vertical;
    }
    if (combustivel<=0){
      combustivel=0;
    }
}
/*---------------------------------------------*\
|                                               |
|               FUNÇÕES DO GLUT                 | 
|                                               |
\*---------------------------------------------*/
void desenhaCena(void){
    glClear(GL_COLOR_BUFFER_BIT);
    fundo();
    glColor3f(1,1,1);
      
      glCallList(lista_fundo);
     if (tela == JOGO){
      glCallList(lista_terreno);
      jogo();
      textos();
    }else if (tela == MENU){
      menu();
    }else if (tela == AJUDA){
      ajuda();
    }else if (tela == LOJA){
      loja();
    }else if (tela == SCORE){
      d_score();
    }

    glutSwapBuffers();
}
// Inicia algumas variáveis de estado
void inicializa(void){
    glClearColor(0, 0, 0, 0);      // 
    nave_textura();
}

void seleciona(){
  if(opcao_do_menu==SAIR){
      exit(0);
  }else{
    controle_score=0;
    sprintf(s_lugar," ");
    tela = opcao_do_menu;
    criaListaTerreno();
    glutPostRedisplay();
  }

}
// Callback de redimensionamento
void redimensiona(int w, int h){
   glViewport(0, 0, w, h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0, largura_mundo, 0, altura_mundo, -1, 1);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}
void atualiza(int idx) {
  if(tela == JOGO){
    if (vidas<=0){
      setRandons();
      velocidade_vertical=0;
      perdeu=DESLIGADO;
      
    }
    if(pouso(x,y)==LIGADO && perdeu == DESLIGADO && velocidade_vertical>-1 && velocidade_vertical<1 
      && velocidade_angular > -(ANGULACAO_TOTAL/2) && velocidade_angular<ANGULACAO_TOTAL/2 ){
      venceu=LIGADO;
    }else if(colide(y)==LIGADO && perdeu==DESLIGADO){
      explosao_textura();
      draw_motor=DESLIGADO;
      pause = LIGADO;
      perdeu = LIGADO;
      vidas--;
      velocidade_vertical=0;
      }
   if (pause==DESLIGADO && perdeu==DESLIGADO && venceu == DESLIGADO){
      
      altitude=y;
      segundos++;
      if (segundos==60){
      minutos++;
      segundos=0;
    }else if (perdeu == DESLIGADO)
    {
      if (y>altura_mundo)
       {
         y=altura_mundo;
       } 
      orientacaoEmGraus = velocidade_angular;
      if (x>largura_mundo ){
         x=0;
      }
      else if (x<0 ){
        x=largura_mundo;
      }
      else{
        motores();
      }
   
    }
    sprintf(s_altura,"Altura: %.2f",altitude);
    sprintf(s_velocidadeH,"velocidade horizontal: %.2f",velocidade_horizontal);
    sprintf(s_aceleracao,"Aceleracao: %.2f",velocidade_vertical);
    sprintf(s_combustivel,"Combustivel: %d",combustivel);
    }else{
       escreveTexto("PAUSADO",50,50);

    }
  }else if(tela == MENU){


  }
    glutPostRedisplay();
    glutTimerFunc(30, atualiza, 0);
}
/*---------------------------------------------*\
|                                               |
|               FUNÇÕES DE CONTROLE             | 
|                                               |
\*---------------------------------------------*/
void teclado(unsigned char key, int x, int y){
    switch(key){
        // Tecla ESC
        case 27:
          tela = MENU;
              break;
        case 'P':
        case 'p':
            if (pause == DESLIGADO ){
              pause = LIGADO;
            }else{
              if (perdeu==LIGADO && vidas>0){
                perdeu = DESLIGADO;
              }
              naves_loja(item_selecionado);
              criaListaTerreno();
              pause = DESLIGADO;
            }
            break;
        case 'R':
        case 'r':
        setRandons();
        vidas=3;
        perdeu=DESLIGADO;
         criaListaTerreno();
          break;
       case 13:
         if (tela==MENU){
          seleciona();
         }else if (tela==LOJA){
          naves_loja(item_selecionado);
          setRandons();
          tela=MENU;
          glutPostRedisplay();
         } 
        break;   
        default:
          break;
    }
}
void SpecialKeys(int key, int x, int y){
  if (tela == JOGO){
    switch (key) {
      case GLUT_KEY_LEFT : 
             teclaA = LIGADO;
              break;
      case GLUT_KEY_RIGHT : 
             teclaD=LIGADO;
              break;
      case GLUT_KEY_UP : 
              motor=LIGADO;
              break;
    }
  }else if (tela == MENU){
    switch (key) {
      case GLUT_KEY_DOWN:

       opcao_do_menu++;
        if (opcao_do_menu>SAIR){
           opcao_do_menu=SAIR;
        } 
      break;
      case GLUT_KEY_UP : 
           
            opcao_do_menu--;
        if (opcao_do_menu<JOGO){
           opcao_do_menu=JOGO;
        }
      break;
    }
  }else if (tela == LOJA){
    switch (key) {
      case GLUT_KEY_DOWN:
        if (item_selecionado+5<=qtd_itens)item_selecionado+=5;
        break;
      case GLUT_KEY_LEFT:
        if (item_selecionado-1>0)item_selecionado-=1;
        break;
      case GLUT_KEY_UP: 
        if (item_selecionado-5>0)item_selecionado-=5;
        break;
      case GLUT_KEY_RIGHT:
        if (item_selecionado+1<=qtd_itens)item_selecionado+=1;
        break;
    }
  }
}
    

  void SpecialKeysUP(int key, int x, int y)
        {
    switch (key) {
      case GLUT_KEY_LEFT : 
             teclaA = DESLIGADO;
              break;
      case GLUT_KEY_RIGHT : 
             teclaD=DESLIGADO;
              break;
      case GLUT_KEY_UP : 
              motor=DESLIGADO;
              break;
    }
  }
// Rotina principal
int main(int argc, char **argv)
{
    // Configuração inicial da janela do GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);

    // Abre a janela
    setRandons();
    glutCreateWindow("Lunar Lander");
    criaListaTerreno();
    criaListaFundo();
    
    // Registra callbacks para alguns eventos
    glutDisplayFunc(desenhaCena);
    glutReshapeFunc(redimensiona);
    glutKeyboardFunc(teclado);
    glutSpecialFunc(SpecialKeys);
    glutSpecialUpFunc(SpecialKeysUP);
    glutTimerFunc(0, atualiza, 0);
    inicializa();

    // Entra em loop e nunca sai
    glutMainLoop();
    return 0;
}
