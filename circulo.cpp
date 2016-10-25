#include "circulo.h"
#include <cmath>

Circulo::Circulo(int xc, int yc, int raio, bool pre) : FiguraGeometrica(xc, yc)
{
    if(raio > 0)
    {
        this->raio = raio;
        this->pre = pre;
    }
    else
    {
        cout << "Tamanho do raio invalido, circulo iniciado com raio = 1.";
        this->raio = 1;
        this->pre = pre;
    }
}

void Circulo::draw(Screen & t){
    int xc = this->getXCentro();
    int yc = this->getYCentro();
    int xhorizontal;
    float k = M_PI/2;
    for(int i=yc-raio; i<=yc+raio; i++)
    {
        xhorizontal =  raio * cos(k);
        if(pre){
            for(int j=xc-xhorizontal; j<=xc+xhorizontal; j++)
            {
                 t.setPixel(j, i);
            }
        }
        else
        {
                t.setPixel(yc-xhorizontal, i);
                t.setPixel(yc+xhorizontal, i);
        }
        k -= M_PI/(2*raio);
    }
}
