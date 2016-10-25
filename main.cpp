#include <QCoreApplication>
#include <screen.h>
#include "reta.h"
#include "retangulo.h"
#include "circulo.h"
#include "interpretador.h"
#include <cstdlib>

//Colocar o arquivo teste.txt na pasta que estiver indicada
//no working directory da aba projects -> run (na esquerda da tela do QtCreator)

int main()
{
    vector<FiguraGeometrica *> teste;                   //Cria vetor que irá receber as figuras do interpretador
    vector<FiguraGeometrica *>::iterator it;            //Cria iterador para acessar as figuras;
    Interpretador inter = Interpretador("teste.txt");   //O interpretador irá abrir o arquivo passado como parametro para seu construtor
    Screen tela = Screen(inter.getLinTela(), inter.getColTela());   //Inicializa um vetor com base nos parametros que foram recebidos do arquivo.
    cout << "Desenhando tela vazia.";                   //Desenha a tela vazia para mostrar o fundo.
    cout << tela;
    tela.setBrush(inter.getBrush());
    system("pause");
    system("cls");
    teste = inter.getFiguras();
    for(it = teste.begin(); it< teste.end(); it++)      //Mostra as figuras
    {
           (*it)->draw(tela);
           cout << tela;
           system("pause");
           system("cls");
           tela.clear();
    }
}
