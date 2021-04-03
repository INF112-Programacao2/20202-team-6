#ifndef PROTOTIPO_H_
#define PROTOTIPO_H_

#include <iostream>

class Funcao
{
protected:
    int _coef[10], _pot[10], _index;

public:
    //construtor e destrutor
    Funcao(char entrada[100]); //localizar e inlcuir no vetor os coeficientes
    ~Funcao();

    //funcoes metodos
    void determinaFX0(int input_x0);
    void derivada_em_X0(double input_x0);

};
#endif

