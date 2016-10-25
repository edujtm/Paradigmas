#include "interpretador.h"

//Este construtor assume que todos os parametros dentro do arquivo
//estarão de acordo com as definições da tabela
//Caso haja algum caracter fora de ordem, o código não funcionará corretamente
//por exemplo: uma linha com (dim 10 20 10) escrito possui mais parametros do que
//o necessário, então ocorreria um erro.
//Caso haja um caracter que não seja numero nos parametros, também ocorrerá erro.
//Ao terminar uma linha do arquivo, apertar enter (\n)sem colocar espaço.

Interpretador::Interpretador(string nomeArquivo)
{
    ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open())
    {
        cout << "Nao foi possivel abrir o arquivo de entrada: "
             << nomeArquivo << ". Saindo do programa.\n";
        exit(-1);
    }
    telanlin = 0;               //Se não houver parametro para as dims da tela, as variaveis são inicializadas com 0.
    telancol = 0;
    char ch;                    //Utilizado para receber os caracteres do arquivo.
    string tipo, tam;           // tipo é a primeira palavra de cada linha, que define o objeto. tam é o valor em string de cada parametro
    while (arquivo.get(ch))
    {
        if (ch != ' ')            //Irá pegar caracteres até chegar ao primeiro espaço da linha
        {
            tipo += ch;
        }
        else                      //Após encontrar o primeiro espaço da tela decide qual o objeto
        {
            int tamaux = 0;                 //irá receber o valor inteiro de tam
            if (!(tipo.compare("dim")))     //Caso seja dimensão da tela (As explicações desse caso também servem para os outros casos, exceto o de brush).
            {
                for(int j=0; j<2; j++)      //Repete para cada parametro de dimensão (nlin e ncol).
                {
                    tam = "";
                    do
                    {
                        arquivo.get(ch);
                        tam += ch;
                    }
                    while(ch != ' ' && ch != '\n' && !arquivo.eof()); //ao final de um parametro pode haver um espaço para outro parametro, uma quebra de linha ou o final do arquivo.
                    tam.pop_back();                                   //retira os espaços ou quebra de linha, caso seja final de arquivo get() irá retornar 0 para ch e este será o caractere retirado.
                    tamaux = this->stringToInt(tam, tam.length());    //Transforma os valores que estão na string tam em int. ex: "149" -> 149
                    if(j == 0)                                        //define os parametros
                    {
                        telanlin = tamaux;
                    }
                    else
                    {
                        telancol = tamaux;
                    }
                }
            }
            else if (!(tipo.compare("circle")))     //Caso seja um objeto do tipo circulo
            {
                int xc, yc, raio, pre;
                for(int j =0; j<4; j++)
                {
                    tam = "";
                    do
                    {
                        arquivo.get(ch);
                        tam += ch;
                    }
                    while(ch != ' ' && ch != '\n' && !arquivo.eof());
                    tam.pop_back();
                    tamaux = this->stringToInt(tam, tam.length());
                    switch (j) {
                    case 0:
                        xc = tamaux;
                        break;
                    case 1:
                        yc = tamaux;
                        break;
                    case 2:
                        raio = tamaux;
                        break;
                    case 3:
                        pre = tamaux;
                        break;
                    }
                }
                mat.push_back(new Circulo(xc, yc, raio, pre));
            }
            else if (!(tipo.compare("line")))       //Caso seja um objeto do tipo linha
            {
                int x0, y0, xf, yf;
                for(int j =0; j<4; j++)
                {
                    tam = "";
                    do
                    {
                        arquivo.get(ch);
                        tam += ch;
                    }
                    while(ch != ' ' && ch != '\n' && !arquivo.eof());
                    tam.pop_back();
                    tamaux = this->stringToInt(tam, tam.length());
                    switch (j) {
                    case 0:
                        x0 = tamaux;
                        break;
                    case 1:
                        y0 = tamaux;
                        break;
                    case 2:
                        xf = tamaux;
                        break;
                    case 3:
                        yf = tamaux;
                        break;
                    }
                }
                mat.push_back(new Reta(x0, y0, xf, yf));
            }
            else if (!(tipo.compare("rectangle")))  //Caso seja um objeto do tipo retangulo
            {
                int x0, y0, larg, alt;
                for(int j =0; j<4; j++)
                {
                    tam = "";
                    do
                    {
                        arquivo.get(ch);
                        tam += ch;
                    }
                    while(ch != ' ' && ch != '\n' && !arquivo.eof());
                    tam.pop_back();
                    tamaux = this->stringToInt(tam, tam.length());
                    switch (j) {
                    case 0:
                        x0 = tamaux;
                        break;
                    case 1:
                        y0 = tamaux;
                        break;
                    case 2:
                        larg = tamaux;
                        break;
                    case 3:
                        alt = tamaux;
                        break;
                    }
                }
                mat.push_back(new Retangulo(x0, y0, larg, alt));
            }
            else if (!(tipo.compare("brush")))      //Caso seja um pincel
            {
                arquivo.get(ch);
                brush = ch;
                arquivo.get(ch);//Pega o \n ao final da linha
            }
        tipo = "";
        }
    }
}

//Se os digitos não estiverem entre 0 e 9 irá causar erro.
int Interpretador::stringToInt(string numero, int tam)
{
    int valor = 0;
    for(int i=0; i<tam; i++)
    {
        valor += (numero[i] - '0') * pow(10, tam - (1+i));
    }
    return valor;
}
