#ifndef __BOTAO_H__
#define __BOTAO_H__

#include "gl_canvas2d.h"

class Botao{
  float altura, largura, x, y;
  char label[100];

public:
  int controla_cor = 0;

  Botao(float _x, float _y, float _larg, float _alt, char *_label)
  {
     altura  = _alt;
     largura = _larg;
     x = _x;
     y = _y;
     strcpy(label, _label);
  }

  void Render()
  {
      CV::color(0, 0, 0);
      CV::rectFill(x, y, x + largura, y + altura);
      if (controla_cor == 0){
        CV::color(1, 1, 1);
         CV::text(x+5, y+altura/2, label); //escreve o label do botao mais ou menos ao centro.
      }else if(controla_cor == 1){
          CV::color(1, 0, 0);
          CV::text(x+5, y+altura/2, label); //escreve o label do botao mais ou menos ao centro.
      }
      controla_cor =0;
  }

  //recebe as coordenadas do mouse para tratar clique ou detectar quando o mouse esta em cima do botao
  bool Colidiu(int mx, int my)
  {
      if( mx >= x && mx <= (x + largura) && my >= y && my <= (y + altura) )
      {
          return true;
      }
      return false;
  }

};

#endif
