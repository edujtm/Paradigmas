#ifndef SCREEN_H
#define SCREEN_H

#include <vector>
#include <iostream>

using namespace std;

class Screen
{
    int nlin, ncol;
    char brush;
    vector< vector<char> > mat;

public:
    //Construtor da tela com nlin linhas e ncol colunas
    Screen(int nlin, int ncol);
    //Altera um pixel da tela para o valor de brush;
    void setPixel(int x, int y);
    //Limpa a tela
    void clear();
    //Altera o tipo de pincel que está sendo utilizado(Qual o char que é utilizado)
    void setBrush(char brush);
    friend ostream & operator<<(ostream & os, Screen & t );
};

#endif // SCREEN_H
