#include "retangulo.h"

//Assumi que o xi e yi são os pontos do canto superior esquerdo, então o retangulo
// sempre será desenhado para baixo e para direita.
//Não há como criar retangulos rotacionados.
Retangulo::Retangulo(int xi, int yi, int larg, int alt) : FiguraGeometrica(xi, yi)
{
    if(larg > 0 && alt > 0){
        this->larg = larg;
        this->alt = alt;
    } else {
        cout << "tamanho invalido para altura ou largura. Retangulo inicializado com largura 1 e altura 1.\n";
        this ->larg = 1;
        this ->alt = 1;
    }
}

void Retangulo::draw(Screen & t){
    int xtemp = this->getXCentro();
    int ytemp = this->getYCentro();
    for(int i=xtemp; i<xtemp+larg; i++)
    {
        t.setPixel(i, ytemp);
        t.setPixel(i, ytemp+alt-1);
    }
    for(int i=ytemp+1; i<ytemp+alt-1; i++)
    {
        t.setPixel(xtemp, i);
        t.setPixel(xtemp + larg-1, i);
    }
}
