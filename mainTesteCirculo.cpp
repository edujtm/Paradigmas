#include <QCoreApplication>
#include <screen.h>
#include "reta.h"
#include "retangulo.h"
#include "circulo.h"
#include <cstdlib>


int main(int argc, char *argv[])
{
    int x, y, xri, yri, xrf;
    cout << "Digite o valor de linhas e colunas da tela\n";
    cin >> x >> y;
    Screen tela = Screen(x , y);
    tela.setBrush('*');
    cout << "Desenhando tela vazia: \n";
    cout << tela;
    system("pause");
    system("cls");
    cout << "Digite as coordenadas do centro do circulo.\n";
    cin >> xri >> yri;
    cout << "Digite o raio do circulo.\n";
    cin >> xrf;
    Circulo circ = Circulo(xri, yri, xrf, true);
    circ.draw(tela);
    cout << "Desenhando circulo na tela.\n";
    cout << tela;
}
