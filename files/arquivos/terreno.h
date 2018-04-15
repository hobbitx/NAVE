#ifndef _TERRENO_H_
#define _TERRENO_H_

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <math.h>
#include <time.h>
#include "texto.h"
#include <stdio.h>
#include "variaveis.h"
#include "texturas.h"


int pouso (float x_da_nave,float y_da_nave);
int colide(float y_da_nave);
void desenhaterreno();

#endif // _TERREENO_H_
