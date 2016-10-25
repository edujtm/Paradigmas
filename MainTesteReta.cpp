#include <QCoreApplication>
#include <screen.h>
#include "reta.h"
#include <cstdlib>


int main(int argc, char *argv[])
{
    int x, y, xri, yri, xrf, yrf;
    cout << "Digite o valor de linhas e colunas da tela\n";
    cin >> x >> y;
    Screen tela = Screen(x , y);
    cout << "Desenhando tela vazia: \n";
    cout << tela;
    system("pause");
    system("cls");
    cout << "Digite as coordenadas do inicio da reta.\n";
    cin >> xri >> yri;
    cout << "Digite as coordenadas do final da reta.\n";
    cin >> xrf >> yrf;
    Reta reta = Reta(xri, yri, xrf, yrf);
    reta.draw(tela);
    cout << "Desenhando reta na tela.\n";
    cout << tela;
}
