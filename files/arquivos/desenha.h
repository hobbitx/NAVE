#ifndef _DESENHA_H_
#define _DESENHA_H_

#include "texturas.h"
#include "texto.h"
#include "variaveis.h"
#include "score.h"
#include "loja.h"
#define LIGADO 1
#define DESLIGADO 0


void desenhaNave(int draw_motor);
void jogo();
void menu();
void loja();
void explosao_textura();
void d_score();

#endif // _DESENHA_H_