/*********************************************************************
// Canvas para desenho, criada sobre a API OpenGL. Nao eh necessario conhecimentos de OpenGL para usar.
//  Autor: Cesar Tadeu Pozzer
//         05/2020
//
//  Pode ser utilizada para fazer desenhos, animacoes, e jogos simples.
//  Tem tratamento de mouse e teclado
//  Estude o OpenGL antes de tentar compreender o arquivo gl_canvas.cpp
//
//  Versao 2.0
//
//  Instruções:
//	  Para alterar a animacao, digite numeros entre 1 e 3
// *********************************************************************/

#include <GL/glut.h>
#include <GL/freeglut_ext.h> //callback da wheel do mouse.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "gl_canvas2d.h"
#include "bmp.h"

#include "Botao.h"
#include "controladorBotoes.h"
#include "ControladorImagem.h"

Bmp* img01;

//variavel global para selecao do que sera exibido na canvas.
int opcao  = 50;
int screenWidth = 700, screenHeight = 700; //largura e altura inicial da tela . Alteram com o redimensionamento de tela.

ControladorImagem *imagem = new ControladorImagem;
GerenciadorBotoes *botao = new GerenciadorBotoes;
int mouseX = 0;  //variaveis globais do mouse para poder exibir dentro da render().
int mouseY = 0;
int state1; // clicou
int initial_x = 200, initial_y = 250; //possicao da imagem
int print_x = 0, print_y = 0;
bool imgSeguirMouse = false;
int offsetx, offsety; //faz com que a imagem não seja desenhada sempre partindo da coordenada do mouse

/*void desenhaImagem()
{
    // int print_x = 0;
    //int print_y = 0;
    if( imgSeguirMouse == true)
    {
        //initial_x = mouseX;
        initial_y = mouseX  - offsety;
        initial_x = mouseY  - offsetx;
    }

    uchar* data = img01->getImage();
    int height = img01->height;
    int width = img01->width;
    int bytesPerLine = img01->bytesPerLine;*/

    // FLIP X
   /* for(int y=0; y<height; y++)
    {
        for(int x=width*3; x>=0; x-=3)
        {
            int pos = y*bytesPerLine + x;
            CV::color(data[pos]/255.0, data[pos+1]/255.0, data[pos+2]/255.0);
            CV::point(initial_x+ print_x, initial_y + y);
            print_x++;
        }
        print_x = 0;
    }*/

   // int print_y = height;

    // FLIP Y
   /*for(int y=0; y<height; y++)
    {
        for(int x=0; x<width*3; x+=3)
        {
            int pos = y*bytesPerLine + x;
            CV::color(data[pos]/255.0, data[pos+1]/255.0, data[pos+2]/255.0);
            CV::point(initial_x+ print_x, initial_y + print_y);
            print_x++;

        }
        print_x = 0;
        print_y--;
    }*/

    //print_y = 0;
/* // ESCALA 1/2
    for(int y=0; y<height; y+=2)
    {
        for(int x=0; x<width*3; x+=6)
        {
            int pos = y*bytesPerLine + x;
            CV::color(data[pos]/255.0, data[pos+1]/255.0, data[pos+2]/255.0);
            CV::point(initial_x+ print_x, initial_y + print_y);
            print_x++;
        }
        print_x = 0;
        print_y++;
    }*/

    /*for(int y=0; y<height; y++)
    {
        for(int x=0; x<width*3; x+=3)
        {
            int pos = y*bytesPerLine + x;
            CV::color(data[pos]/255.0, data[pos+1]/255.0, data[pos+2]/255.0);
            CV::point(initial_x+ print_x, initial_y + y);
            print_x++;
        }
        print_x = 0;
    }
}*/

/*void verifica_clickImagem()
{
    if(state1  == 0)
    {
        if(mouseX  >=  initial_x && mouseX <= ( initial_x + img01->width) )
            if(mouseY  >=   initial_y && mouseY <= (  initial_y + img01->height ) )
            {
                offsetx =  mouseX - initial_x;
                offsety =  mouseY  - initial_y;
                imgSeguirMouse = true;
                puts("Seguir");
            }
    }

    if(state1 == 1)
    {
        imgSeguirMouse = false;
        puts("Soltar");
    }
}*/

void render()
{
    imagem->Render(mouseX, mouseY, state1);
    botao->Render(mouseX, mouseY, state1);
}

//funcao chamada toda vez que uma tecla for pressionada.
void keyboard(int key)
{
    switch(key)
    {
    case 27:
        exit(0);
        break;
    }
}

//funcao chamada toda vez que uma tecla for liberada
void keyboardUp(int key)
{
    printf("\nLiberou: %d", key);
}

//funcao para tratamento de mouse: cliques, movimentos e arrastos
void mouse(int button, int state, int wheel, int direction, int x, int y)
{
    mouseX = x; //guarda as coordenadas do mouse para exibir dentro da render() dos controladores
    mouseY = y;
    state1 = state;
}

int main()
{
    imagem->InitCanvas();
    botao->InitCanvas();

    CV::run();
}
