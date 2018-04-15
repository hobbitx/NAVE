#include "texturas.h"

void terreno_textura(void) {
    glClearColor( 1, 1, 1, 1);
    glEnable(GL_BLEND );
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    texturaTerreno = SOIL_load_OGL_texture(
        "../files/imagens/terreno.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
    );

    if (texturaTerreno == 0) {
        printf("Erro do SOIL: '%s'\n", SOIL_last_result());
    }
}
void base_textura(void) {
    glClearColor( 1, 1, 1, 1);
    glEnable(GL_BLEND );
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    texturaBase = SOIL_load_OGL_texture(
        "../files/imagens/base.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
    );

    if (texturaBase == 0) {
        printf("Erro do SOIL: '%s'\n", SOIL_last_result());
    }
    texturaBandeira = SOIL_load_OGL_texture(
        "../files/imagens/bandeira.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
    );

    if (texturaBandeira == 0) {
        printf("Erro do SOIL: '%s'\n", SOIL_last_result());
    }
}
void fundo_textura(void) {
    
    glClearColor(1, 1, 1, 1);
    // habilita mesclagem de cores, para termos suporte a texturas (semi-)transparentes
    glEnable(GL_BLEND );
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    if (ran%2==0){
           texturaFundo = SOIL_load_OGL_texture(
            "../files/imagens/fundo/1.jpg",
            SOIL_LOAD_AUTO,
            SOIL_CREATE_NEW_ID,
            SOIL_FLAG_INVERT_Y
        );
        
    }else if (ran%3==0){
           texturaFundo = SOIL_load_OGL_texture(
            "../files/imagens/fundo/2.jpg",
            SOIL_LOAD_AUTO,
            SOIL_CREATE_NEW_ID,
            SOIL_FLAG_INVERT_Y
        );
        
    }else{
        texturaFundo = SOIL_load_OGL_texture(
            "../files/imagens/fundo/3.jpg",
            SOIL_LOAD_AUTO,
            SOIL_CREATE_NEW_ID,
    		SOIL_FLAG_INVERT_Y
    	);
    }
    if (texturaFundo == 0) {
        printf("Erro do SOIL: '%s'\n", SOIL_last_result());
    }
}
void nave_textura(void) {
glClearColor(1, 1, 1, 1);

    // habilita mesclagem de cores, para termos suporte a texturas (semi-)transparentes
    glEnable(GL_BLEND );
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
        texturaNave= SOIL_load_OGL_texture(
            "../files/imagens/naves/0.png",
            SOIL_LOAD_AUTO,
            SOIL_CREATE_NEW_ID,
            SOIL_FLAG_INVERT_Y
        );

        if (texturaNave == 0) {
            printf("Erro do SOIL 0: '%s'\n", SOIL_last_result());
        }
    
}
void explosao_textura(void) {
glClearColor(1, 1, 1, 1);

    // habilita mesclagem de cores, para termos suporte a texturas (semi-)transparentes
    glEnable(GL_BLEND );
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    texturaNave= SOIL_load_OGL_texture(
        "../files/imagens/explosao.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
    );

    if (texturaNave == 0) {
        printf("Erro do SOIL: '%s'\n", SOIL_last_result());
    }
}
void motor_textura(void) {
glClearColor(1, 1, 1, 1);
    
    // habilita mesclagem de cores, para termos suporte a texturas (semi-)transparentes
    glEnable(GL_BLEND );
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    texturaMotor= SOIL_load_OGL_texture(
        "../files/imagens/motor.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
    );

    if (texturaMotor == 0) {
        printf("Erro do SOIL: '%s'\n", SOIL_last_result());
    }
}
void naves_loja(int op){
    
glClearColor(1, 1, 1, 1);
    

    // habilita mesclagem de cores, para termos suporte a texturas (semi-)transparentes
    glEnable(GL_BLEND );
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor3f(1,1,1);
    if (op==1){
        texturaNave= SOIL_load_OGL_texture(
            "../files/imagens/naves/0.png",
            SOIL_LOAD_AUTO,
            SOIL_CREATE_NEW_ID,
            SOIL_FLAG_INVERT_Y
        );

        if (texturaNave == 0) {
            printf("Erro do SOIL 0: '%s'\n", SOIL_last_result());
        }
        sprintf(s_nome,"Nome: StarShip Ultra-X 67 ");
        sprintf(s_spd,"Velocidade: 30 Parsecs/min");
        sprintf(s_price,"Preco 2 Coutinhos Points");
    }else if (op==2){
        texturaNave= SOIL_load_OGL_texture(
            "../files/imagens/naves/1.png",
            SOIL_LOAD_AUTO,
            SOIL_CREATE_NEW_ID,
            SOIL_FLAG_INVERT_Y
        );

        if (texturaNave == 0) {
            printf("Erro do SOIL 1:  '%s'\n", SOIL_last_result());
        }
        sprintf(s_nome,"Nome: MacxPro  2 ");
        sprintf(s_spd,"Velocidade: 21 Parsecs/min");
        sprintf(s_price,"Preco: 1 Coutinhos Points");
    }else if (op==3){
        texturaNave= SOIL_load_OGL_texture(
            "../files/imagens/naves/2.png",
            SOIL_LOAD_AUTO,
            SOIL_CREATE_NEW_ID,
            SOIL_FLAG_INVERT_Y
        );

        if (texturaNave == 0) {
            printf("Erro do SOIL 2: '%s'\n", SOIL_last_result());
        }
        sprintf(s_nome,"Nome: Aliance 2518");
        sprintf(s_spd,"Velocidade: 222 Parsecs/min");
        sprintf(s_price,"Preco: 1/3 Coutinhos Points");
    }else if (op==4){
        texturaNave= SOIL_load_OGL_texture(
            "../files/imagens/naves/3.png",
            SOIL_LOAD_AUTO,
            SOIL_CREATE_NEW_ID,
            SOIL_FLAG_INVERT_Y
        );

        if (texturaNave == 0) {
            printf("Erro do SOIL 3: '%s'\n", SOIL_last_result());
        }
        sprintf(s_nome,"Nome: LavaGun 37");
        sprintf(s_spd,"Velocidade: 1/2 Parsecs/min");
        sprintf(s_price,"Preco: 2 Coutinhos Points");
    }else if (op==5){
        texturaNave= SOIL_load_OGL_texture(
            "../files/imagens/naves/4.png",
            SOIL_LOAD_AUTO,
            SOIL_CREATE_NEW_ID,
            SOIL_FLAG_INVERT_Y
        );

        if (texturaNave == 0) {
            printf("Erro do SOIL 4: '%s'\n", SOIL_last_result());
        }
        sprintf(s_nome,"Nome: Marcelinhos Ultra Sum ");
        sprintf(s_spd,"Velocidade: 120 Parsecs/min");
        sprintf(s_price,"Preco: 3 Coutinhos Points");
    }else if (op==6){
        texturaNave= SOIL_load_OGL_texture(
            "../files/imagens/naves/5.png",
            SOIL_LOAD_AUTO,
            SOIL_CREATE_NEW_ID,
            SOIL_FLAG_INVERT_Y
        );

        if (texturaNave == 0) {
            printf("Erro do SOIL 5: '%s'\n", SOIL_last_result());
        }
        sprintf(s_nome,"Nome: Spnnier Ships ");
        sprintf(s_spd,"Velocidade: 0 Parsecs/min");
        sprintf(s_price,"preco: -1 Coutinhos Points");
    }else if (op==7){
        texturaNave= SOIL_load_OGL_texture(
            "../files/imagens/naves/6.png",
            SOIL_LOAD_AUTO,
            SOIL_CREATE_NEW_ID,
            SOIL_FLAG_INVERT_Y
        );

        if (texturaNave == 0) {
            printf("Erro do SOIL 6: '%s'\n", SOIL_last_result());
        }
        sprintf(s_nome,"Nome: White Killer ");
        sprintf(s_spd,"Velocidade: 100 Parsecs/min");
        sprintf(s_price,"preco: 6 Coutinhos Points");
    }else if (op==8){
        texturaNave= SOIL_load_OGL_texture(
            "../files/imagens/naves/7.png",
            SOIL_LOAD_AUTO,
            SOIL_CREATE_NEW_ID,
            SOIL_FLAG_INVERT_Y
        );

        if (texturaNave == 0) {
            printf("Erro do SOIL 7: '%s'\n", SOIL_last_result());
        }
        sprintf(s_nome,"Nome: BlueStar-X");
        sprintf(s_spd,"Velocidade: 90 Parsecs/min");
        sprintf(s_price,"Preco: 5 Coutinhos Points");
    }else if (op==9){
        texturaNave= SOIL_load_OGL_texture(
            "../files/imagens/naves/8.png",
            SOIL_LOAD_AUTO,
            SOIL_CREATE_NEW_ID,
            SOIL_FLAG_INVERT_Y
        );

        if (texturaNave == 0) {
            printf("Erro do SOIL 8 '%s'\n", SOIL_last_result());
        }
        sprintf(s_nome,"Nome: BlueStar-Y");
        sprintf(s_spd,"Velocidade: 89 Parsecs/min");
        sprintf(s_price,"Preco 4 Coutinhos Points");
    }else {
        texturaNave= SOIL_load_OGL_texture(
            "../files/imagens/naves/9.png",
            SOIL_LOAD_AUTO,
            SOIL_CREATE_NEW_ID,
            SOIL_FLAG_INVERT_Y
        );

        if (texturaNave == 0) {
            printf("Erro do SOIL 9 '%s'\n", SOIL_last_result());
        }
        sprintf(s_nome,"Nome: Vikings");
        sprintf(s_spd,"Velocidade: 3000 Parsecs/min");
        sprintf(s_price,"preco: Aprovacao em CG");
    }
}