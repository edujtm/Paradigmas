#ifndef CIRCULO_H
#define CIRCULO_H
#include "figurageometrica.h"

class Circulo : public FiguraGeometrica
{
    int raio;
    bool pre;
public:
    Circulo(int xc, int yc, int raio, bool pre);
    virtual ~Circulo() {}
    virtual void draw(Screen & t);
};

#endif // CIRCULO_H
