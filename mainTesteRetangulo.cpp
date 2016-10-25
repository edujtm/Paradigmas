#include <QCoreApplication>
#include <screen.h>
#include "reta.h"
#include "retangulo.h"
#include "circulo.h"
#include <cstdlib>


int main(int argc, char *argv[])
{
    int x, y, xri, yri, alt, larg;
    cout << "Digite o valor de linhas e colunas da tela\n";
    cin >> x >> y;
    Screen tela = Screen(x , y);
    tela.setBrush('*');
    cout << "Desenhando tela vazia: \n";
    cout << tela;
    system("pause");
    system("cls");
    cout << "Digite as coordenadas do canto superior esquerdo do retangulo.\n";
    cin >> xri >> yri;
    cout << "Digite a altura e a largura do retangulo.\n";
    cin >> alt >> larg;
    Retangulo ret = Retangulo(xri, yri, alt, larg);
    ret.draw(tela);
    cout << "Desenhando retangulo na tela.\n";
    cout << tela;
}
