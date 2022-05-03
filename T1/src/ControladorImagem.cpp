#include"ControladorImagem.h"

/*void Bmp::initPixel2dArray()
{
    int tempX = 0;

    for(int y=0; y<height; y++)
    {
        for(int x=0; x<width*3; x+=3)
        {
            int pos = y*bytesPerLine + x;
            imageData[tempX][y] = new Pixel(data[pos]/255.0, data[pos+1]/255.0, data[pos+2]/255.0);
            tempX++;
        }
        tempX = 0;
    }
}*/

void ControladorImagem::Render(int mouse_x, int mouse_y, int mouse_state)
{
    mouseX = mouse_x;
    mouseY = mouse_y;
    mouseState = mouse_state;

    desenhaImagem();
    verifica_clickImagem();
}

void ControladorImagem::desenhaImagem()
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
    int bytesPerLine = img01->bytesPerLine;

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

    print_y = 0;
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

    for(int y=0; y<height; y++)
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
}

void ControladorImagem::desenhaImagemFlipX()
{
    printf("entrou aquii flip x\n");
    uchar* data = img01->getImage();
    int height = img01->height;
    int width = img01->width;
    int bytesPerLine = img01->bytesPerLine;
      // FLIP X
   for(int y=0; y<height; y++)
    {
        for(int x=width*3; x>=0; x-=3)
        {
            int pos = y*bytesPerLine + x;
            CV::color(data[pos]/255.0, data[pos+1]/255.0, data[pos+2]/255.0);
            CV::point(initial_x+ print_x, initial_y + y);
            print_x++;
        }
        print_x = 0;
    }
    print_y = height;
}

void ControladorImagem::verifica_clickImagem()
{
    if(mouseState  == 0)
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

    if(mouseState == 1)
    {
        imgSeguirMouse = false;
        puts("Soltar");
    }
}

int ControladorImagem::getMouseState()
{
    return mouseState;
}

int ControladorImagem::getMouseY()
{
    return mouseY;
}

int ControladorImagem::getMouseX()
{
    return mouseX;
}

void ControladorImagem::InitCanvas()
{
    CV::init(&screenWidth, &screenHeight, "Titulo da Janela: Canvas 2D - Pressione 1, 2, 3");
    img01= new Bmp(".\\T1\\resources\\img01.bmp");
    img01->convertBGRtoRGB();
}
