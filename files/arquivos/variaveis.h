#ifndef _VARIAVEIS_H_
#define _VARIAVEIS_H_

#include "stdio.h"
/*---------------------------------------------*\
|                                               |
|                   CONSTANTES                  | 
|                                               |
\*---------------------------------------------*/
#define MENU  0
#define JOGO  1
#define AJUDA 2
#define LOJA  3
#define SCORE 4
#define SAIR  5
#define LIGADO 1
#define DESLIGADO 0
#define ANGULACAO_TOTAL 90
#define RAZAO_ASPECTO_DO_MUNDO = LARGURA_MUNDO/ALTURA_MUNDO
#define radianoParaGraus(radianos) (radianos * (180.0 / M_PI))
#define grausParaRadianos(graus) ((graus * M_PI) / 180.0)
#define VARIACAO_ANGULO 2
/*---------------------------------------------*\
|                                               |
|                   VARIAVEIS                   | 
|                                               |
\*---------------------------------------------*/
extern const int altura_mundo, largura_mundo;
extern const float aumento_velocidade_vertical, aumento_velocidade_horizontal; 
extern float velocidade_horizontal;
extern float velocidade_vertical;
extern float orientacaoEmGraus,velocidade_angular;
extern float x , y,altitude;
extern int qtd_itens;
extern int texturaBandeira;
extern int largura_nave,controle_score,ran;
extern int nave_atual,item_selecionado;
extern int pause ,saindo,perdeu ,venceu ;
extern int texturaFundo,texturaNave,texturaMotor,texturaTerreno,texturaItem;
extern int draw_motor,lista_fundo,lista_terreno,texturaBase;
extern int combustivel, teclaA  , teclaD;
extern int motor,x_da_base,y_da_base, largura_base ;
extern int tela,opcao_do_menu;
extern float pontuacao;
extern int segundos,minutos, vidas;
extern char s_spd[20],s_nome[20],s_price[10];
extern char s_velocidadeH[50],s_status[50],s_altura[10],s_base[10],s_combustivel[20],s_aceleracao[30];
extern char s_tempo[60],s_pontuacao[60],s_vidas[20],s_lugar[50];

#endif // _VARIAVEIS_H_