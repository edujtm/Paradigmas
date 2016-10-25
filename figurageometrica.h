#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include "screen.h"

class FiguraGeometrica
{
    int xcentro;
    int ycentro;
public:
    FiguraGeometrica(int x, int y): xcentro(x), ycentro(y) {}
    virtual ~FiguraGeometrica() {}
    virtual void draw(Screen & t) = 0;
    int getXCentro() { return xcentro;}
    int getYCentro() { return ycentro;}
};

#endif // FIGURAGEOMETRICA_H
