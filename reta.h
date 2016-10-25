#ifndef RETA_H
#define RETA_H
#include "figurageometrica.h"

class Reta : public FiguraGeometrica
{
 int xfinal;
 int yfinal;
public:
    Reta(int x, int y, int xf, int yf);
    virtual ~Reta() {}
    virtual void draw(Screen & t);
};

#endif // RETA_H
