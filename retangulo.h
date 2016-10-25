#ifndef RETANGULO_H
#define RETANGULO_H
#include "figurageometrica.h"

class Retangulo : public FiguraGeometrica
{
int larg, alt;
public:
    Retangulo(int xi, int yi, int larg, int alt);
    virtual ~Retangulo() {}
    virtual void draw(Screen & t);
};

#endif // RETANGULO_H
