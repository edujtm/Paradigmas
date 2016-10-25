#ifndef INTERPRETADOR_H
#define INTERPRETADOR_H
#include <string.h>
#include "figurageometrica.h"
#include "circulo.h"
#include "reta.h"
#include "retangulo.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

class Interpretador
{
    vector<FiguraGeometrica *> mat;
    int telanlin, telancol;
    char brush;
    int stringToInt(string numero, int tam);
public:
    Interpretador(string nomeArquivo);
    vector<FiguraGeometrica *> getFiguras() {return mat;}
    int getLinTela() {return telanlin;}
    int getColTela() {return telancol;}
    char getBrush() {return brush;}
};

#endif // INTERPRETADOR_H
