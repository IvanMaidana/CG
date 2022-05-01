#ifndef GERENCIADOR_H_INCLUDED
#define GERENCIADOR_H_INCLUDED

#include <iostream>  //equivale ao stdio.h
#include<stdio.h>

#include"botao.h"
#include "gl_canvas2d.h"
#include"bmp.h"
//#include "Mouse.h"

class Gerenciador
{
private:
    Bmp *img01;
    void desenhaBotoes();
    void verificaMouseEmCima_botoes();
    void verificaclick();
    int getMouseState();
    int getMouseY();
    int getMouseX();

    int opcao = 50;             // variavel para selecao do que sera exibido na canvas.
    // int mx, my;                //variaveis do mouse para poder exibir dentro da render().

public:
    Botao   *bt = NULL; //se a aplicacao tiver varios botoes, sugiro implementar um manager de botoes.
    Botao   *bt1 = NULL;
    Botao   *bt2 = NULL;
    Botao   *bt3 = NULL;
    int mouseX, mouseY, mouseState;
    // Bmp* img;                // imagem a ser manipulada
    int screenWidth, screenHeight;
    Gerenciador();
    void InitCanvas();
    void Render(int mouse_x, int mouse_y, int mouse_state);
    void Keyboard(int key);
    void Mouse(int x, int y, int state);
};
#endif // GERENCIADOR_H_INCLUDED
