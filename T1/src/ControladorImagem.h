#ifndef CONTROLAIMAGEM_H_INCLUDED
#define CONTROLAIMAGEM_H_INCLUDED
#include"bmp.h"
#include "gl_canvas2d.h"

class ControladorImagem
{
private:
    int r;
    int g;
    int b;
public:
    Bmp* img01;
    int screenWidth = 700, screenHeight = 700;
    int initial_x = 200, initial_y = 250;
    int print_x = 0, print_y = 0;
    int offsetx, offsety;
    bool imgSeguirMouse;
    int mouseX, mouseY, mouseState;
    void Render(int mouse_x, int mouse_y, int mouse_state);
    void verifica_clickImagem();
    void desenhaImagem();
    int getMouseState();
    int getMouseY();
    int getMouseX();
    void InitCanvas();
};



#endif // CONTROLAIMAGEM_H_INCLUDED
