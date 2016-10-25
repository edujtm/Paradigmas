#include "screen.h"

Screen::Screen(int nlin, int ncol)
{
    if(nlin < 0 || ncol < 0){
        cout << "Tamanho de tela invalido, matriz iniciada com 0 linhas e 0 colunas\n";
        this->nlin = 0;
        this->ncol = 0;
    } else {
        this->nlin = nlin;
        this->ncol = ncol;
    }
    brush = '#';
    mat = vector<vector<char>> (this->nlin, vector<char> (this->ncol, ' '));
}

void Screen::setPixel(int x, int y){
    if(x >= 0 && y>=0 && x<nlin && y<ncol){
        mat[x][y] = brush;
    }
}

void Screen::clear(){
    for(int i =0; i < nlin; i++){
        for(int j = 0; j<ncol; j++){
            mat[i][j] = ' ';
        }
    }
}

void Screen::setBrush(char brush){
    this->brush = brush;
}

ostream & operator<<(ostream & os, Screen & t){
    for(int i = 0; i< t.nlin; i++){
        for(int j = 0; j < t.ncol; j++){
            os << t.mat[j][i];
        }
        os << endl;
    }
    return os;
}
