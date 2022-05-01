#include"controladorBotoes.h"

// Funçao contrutora da class Gerenciador responsavel por inicializar parametros
Gerenciador :: Gerenciador()
{
    screenWidth = 700;
    screenHeight = 700;
}
void Gerenciador::Render(int mouse_x, int mouse_y, int mouse_state)
{
    mouseX = mouse_x;
    mouseY = mouse_y;
    mouseState = mouse_state;

    desenhaBotoes();
    verificaMouseEmCima_botoes();
    verificaclick();
}

void Gerenciador::desenhaBotoes()
{
    bt->Render();
    bt1->Render();
    bt2->Render();
    bt3->Render();
}

int Gerenciador::getMouseState()
{
    return mouseState;
}

int Gerenciador::getMouseY()
{
    return mouseY;
}

int Gerenciador::getMouseX()
{
    return mouseX;
}

void Gerenciador::verificaMouseEmCima_botoes()
{
    if(bt->Colidiu( getMouseX(),  getMouseY()))
    {
        bt->controla_cor = 1;
    }
    else if(bt1->Colidiu( getMouseX(),  getMouseY()))
    {
        bt1->controla_cor = 1;
    }
    else if(bt2->Colidiu( getMouseX(),  getMouseY()))
    {
        bt2->controla_cor = 1;
    }
    else if(bt3->Colidiu( getMouseX(),  getMouseY()))
    {
        bt3->controla_cor = 1;
    }
}

void Gerenciador::verificaclick()
{
    if(bt->Colidiu( getMouseX(),  getMouseY()) && getMouseState() == 0)
    {
        printf("clicou no primeiro botao\n");
    }
    else if(bt1->Colidiu( getMouseX(),  getMouseY()) && getMouseState()== 0)
    {
        printf("clicou no segundo botao\n");
    }
    else if(bt2->Colidiu( getMouseX(),  getMouseY()) && getMouseState() == 0)
    {
        printf("clicou no terceiro botao\n");
    }
    else if(bt3->Colidiu( getMouseX(),  getMouseY()) && getMouseState() == 0)
    {
        printf("clicou no quarto botao\n");
    }
}

void Gerenciador::InitCanvas()
{

    //CV::init(&screenWidth, &screenHeight, "Titulo da Janela: Canvas 2D - Pressione 1, 2, 3");
    //img01= new Bmp(".\\gl_1_canvasGlut\\resources\\img01.bmp");*
    //img01->convertBGRtoRGB();

    bt = new Botao(200, 400,  180, 80, "teste illuminati");
    bt1 = new Botao(500, 480,  180, 80, "Sou um botao 2");
    bt2 = new Botao(500, 380,  180, 80, "Sou um botao 3");
    bt3 = new Botao(500, 280,  180, 80, "Sou um botao 4");

    //CV::run();
}
