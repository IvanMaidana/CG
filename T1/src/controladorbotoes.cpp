#include"controladorBotoes.h"

// Funçao contrutora da class Gerenciador responsavel por inicializar parametros
void GerenciadorBotoes::Render(int mouse_x, int mouse_y, int mouse_state)
{
    mouseX = mouse_x;
    mouseY = mouse_y;
    mouseState = mouse_state;

    desenhaBotoes();
    verificaMouseEmCima_botoes();
    verificaclick();
}

void GerenciadorBotoes::desenhaBotoes()
{
    bt->Render();
    bt1->Render();
    bt2->Render();
    bt3->Render();
}

int GerenciadorBotoes::getMouseState()
{
    return mouseState;
}

int GerenciadorBotoes::getMouseY()
{
    return mouseY;
}

int GerenciadorBotoes::getMouseX()
{
    return mouseX;
}

void GerenciadorBotoes::verificaMouseEmCima_botoes()
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

void GerenciadorBotoes::verificaclick()
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

void GerenciadorBotoes::InitCanvas()
{
    bt = new Botao(500, 580,  180, 80, "teste illuminati");
    bt1 = new Botao(500, 480,  180, 80, "Sou um botao 2");
    bt2 = new Botao(500, 380,  180, 80, "Sou um botao 3");
    bt3 = new Botao(500, 280,  180, 80, "Sou um botao 4");
}
