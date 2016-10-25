#include "reta.h"

Reta::Reta(int x, int y, int xf, int yf) : FiguraGeometrica(x, y)
{
    xfinal = xf;
    yfinal = yf;
}

//como implementar isso???
void Reta::draw(Screen & t)
{
    int xabs, yabs, xtemp, ytemp, vaux;
    xtemp = this->getXCentro();
    ytemp = this->getYCentro();
    xfinal - xtemp >= 0? xabs = xfinal - xtemp : xabs = xtemp - xfinal;
    yfinal - ytemp >= 0? yabs = yfinal - ytemp : yabs = ytemp - yfinal;
    if (xabs >= yabs && xabs != 0 && yabs != 0)
    {
        if(xabs == yabs){
            vaux = 1;
        }
        else
        {
            vaux = (xabs+1)/(yabs+1);
        }
        int j = ytemp, cont = 1;
        for(int i = xtemp; xfinal > xtemp? i<=xfinal : i>=xfinal; xfinal > xtemp? i++ : i--)
        {
            t.setPixel(i, j);
            if(i%vaux == 0 && cont*vaux < xabs)
            {
                yfinal > ytemp? j++ : j--;
                cont++;
            }
        }
    }
    else if (xabs < yabs && xabs != 0 && yabs !=0)
    {
        vaux = (yabs+1)/(xabs+1);
        int i = xtemp, cont = 1;
        for(int j = ytemp; yfinal > ytemp? j<=yfinal : j>=yfinal; yfinal > ytemp? j++ : j--)
        {
            t.setPixel(i, j);
            if(j%vaux == 0 && cont*vaux < yabs)
            {
                xfinal > xtemp? i++ : i--;
                cont++;
            }
        }
    }
    else if (xabs != 0 && yabs == 0)
    {
        for(int i = xtemp; xfinal > xtemp? i<=xfinal : i>=xfinal; xfinal > xtemp? i++ : i--){
            t.setPixel(i, ytemp);
        }
    }
    else if (yabs != 0 && xabs == 0)
    {
        for(int j = ytemp; yfinal > ytemp? j<=yfinal : j>=yfinal; yfinal > ytemp? j++ : j--){
            t.setPixel(xtemp, j);
        }
    }
    else
    {
        t.setPixel(xtemp, ytemp);
    }
}
