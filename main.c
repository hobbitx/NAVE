#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <SOIL/SOIL.h>
#include <stdlib.h>
#include "texto.h"
#include "estrelas.h"
#include "terreno.h"

GLuint texturaNave;

#define LIGADO 1
#define DESLIGADO 0

int teclaA = DESLIGADO , teclaD=DESLIGADO;
char eixos[50],angulo[10],base[10];
char string_gravidade[30];
GLfloat orientacaoEmGraus = 0;
GLfloat velocidadeAngular = 0;
GLfloat x =6, y = 190;
float gravidade;
GLfloat motor=0;
float velociade=0.5;
int listaTerreno,listaEstrelas;
int basx=100;
int largurabase = 15;

#define radianoParaGraus(radianos) (radianos * (180.0 / M_PI))
#define grausParaRadianos(graus) ((graus * M_PI) / 180.0)

void criaListaEstrelas(){
  srand(time(0));
  int qtd = rand()%85+50;

  listaEstrelas = glGenLists(2);
  glNewList(listaEstrelas,
    GL_COMPILE);  
    criarEstrelas(qtd);
  glEndList();

}
void setRandons(){
 srand(time(NULL));
  x = (rand() %50) ;
  gravidade = 3+(rand()%10);
  gravidade = gravidade/10.0;
  basx = rand()%85 +100;
}

void criaListaTerreno() {
  srand(time(0));
  //basx = rand()%85 +100;
  int altura=0;
  listaTerreno = glGenLists(1);
   sprintf(base,"x:%d y:%d ",basx,returnbasey());
  glNewList(listaTerreno,
    GL_COMPILE);  
    desenhaterreno(largurabase,basx);
  glEndList();
  }
  void verificabase(){
    if ( y==returnbasey())
    {
      gravidade = 0;
      velociade = 0;
      y=y;
   
    }
  }

void desenhaCena(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    

    glColor3f(1, 1, 1);
        
    escreveTexto(eixos,180,170);
    escreveTexto(string_gravidade,180,165);
    escreveTexto(angulo,180,160);
            escreveTexto(base,basx,returnbasey());
 glColor3f(.5, .5, 1);

    glCallList(listaTerreno);

    glCallList(listaEstrelas);
    glPushMatrix();
        // Move o sistema de coordenadas para a posição onde deseja-se desenhar
        glTranslatef(x, y, 0);
      
        glRotatef(orientacaoEmGraus, 0, 0, 1);

        // Desenha um triângulo na origem

        glColor3f(1,1,1);
        glBegin(GL_LINE_LOOP);
            glVertex2f(-4, -3); //
            glVertex2f(-2, -3);
            glVertex2f(-3,  1);

        glEnd();
         glColor3f(1,1,0);
        glBegin(GL_LINE_LOOP);
            glVertex2f(-2, -3);
            glVertex2f( 2, -3);
            glVertex2f( 0,  4);
        glEnd();
        glColor3f(1,1,1);
        glBegin(GL_LINE_LOOP);
            glVertex2f( 2, -3);
            glVertex2f( 4, -3);
            glVertex2f( 3,  1);
        glEnd();
    glPopMatrix();

    // Diz ao OpenGL para colocar o que desenhamos na tela
    glutSwapBuffers();
}

// Inicia algumas variáveis de estado
void inicializa(void)
{
    // cor para limpar a tela
    glClearColor(0, 0, 0, 0);      // 
    setRandons();
    
   
}

// Callback de redimensionamento
void redimensiona(int w, int h)
{
   glViewport(0, 0, w, h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0, 200, 0, 200, -1, 1);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void atualiza(int idx) {
    // O ângulo esperado pelas funções "cos" e "sin" da math.h devem
    // estar em radianos
    verificabase();
    orientacaoEmGraus = velocidadeAngular;
    
    if (x>basx && x<(basx+largurabase) && y<=returnbasey())
    {
      gravidade = 0;
      velociade = 0;
      x=(basx+largurabase/2);
      y=returnbasey()+3;
   
    }else if (x>200){
      x=0;

    }else if (y<=3)
    {
      y=3;
      x=x;
    }
    else if (teclaA==LIGADO){
     velocidadeAngular += 1;
     teclaA=DESLIGADO;
    }
    else if (teclaD==LIGADO){
      velocidadeAngular -= 1;
      teclaD=DESLIGADO;
    }
     if(motor == LIGADO){
      y-=gravidade/4;
      x+=velociade;
      motor = DESLIGADO;
    }else{ 
      y-= gravidade;
      x+=velociade;

    }
    
    sprintf(angulo,"Angulo: %2.f",orientacaoEmGraus);
    sprintf(eixos,"X: %2.f Y: %2.f",x,y);
    sprintf(string_gravidade,"gravidade: %2.f",gravidade);
    glutPostRedisplay();
    glutTimerFunc(60, atualiza, 0);
}

// Callback de evento de teclado
void teclado(unsigned char key, int x, int y)
{
    switch(key)
    {
        // Tecla ESC
        case 27:
            exit(0);
            break;
        case 'A':
        case 'a':
            teclaA=LIGADO;
            break;
        case 'D':
        case 'd':
            
            teclaD=LIGADO;
            break;
        case 'W':
        case 'w':
          motor = LIGADO;
        default:
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
    glutCreateWindow("Triângulo em movimento e orientado");
    criaListaTerreno();
    criaListaEstrelas();
    
    
    // Registra callbacks para alguns eventos
    glutDisplayFunc(desenhaCena);
    glutReshapeFunc(redimensiona);
    glutKeyboardFunc(teclado);
    glutTimerFunc(0, atualiza, 0);
    inicializa();

    // Entra em loop e nunca sai
    glutMainLoop();
    return 0;
}
