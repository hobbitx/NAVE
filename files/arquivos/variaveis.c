#include "variaveis.h"


const int altura_mundo=100, largura_mundo=100; 
const float aumento_velocidade_vertical=0.01,aumento_velocidade_horizontal=0.03;
float velocidade_horizontal=0.2;
float velocidade_vertical;
float orientacaoEmGraus = 0,velocidade_angular = 0;
float x , y ,altitude;
float pontuacao=0;
int texturaFundo,texturaNave,texturaMotor,texturaTerreno;
int pause = DESLIGADO,saindo =DESLIGADO,perdeu = DESLIGADO,venceu=DESLIGADO ;
int draw_motor= DESLIGADO,lista_fundo,lista_terreno,texturaBase;
int combustivel = 1000, teclaA = DESLIGADO , teclaD=DESLIGADO;
int motor=0,x_da_base=0,y_da_base=5, largura_base = 20;
int segundos=0,minutos=0, vidas=3;
int controle_score=0,ran=0;
int qtd_itens=10;
int texturaBandeira;
int nave_atual=0,item_selecionado=1;
int tela = MENU ,opcao_do_menu=1; 
char s_spd[20],s_nome[20],s_price[10];
char s_velocidadeH[50],s_status[50],s_altura[10],s_base[10],s_combustivel[20],s_aceleracao[30];
char s_tempo[60],s_pontuacao[60],s_vidas[20],s_lugar[50];
