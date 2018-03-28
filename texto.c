#include <GL/freeglut.h>
#include <string.h>

void escreveTexto(char *texto, float x, float y) {
    int i;
    glRasterPos2f(x, y);
     glColor3f(1, 1, 1);
        for (i = 0; i < strlen(texto); i++) {
       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, texto[i]);
    }
}
