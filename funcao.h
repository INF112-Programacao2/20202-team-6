#ifndef PROTOTIPO_H_
#define PROTOTIPO_H_

#include <iostream>
#include <sstream>
#include <vector>
#include<math.h>
#include "grafico.h"

class Funcao
{
private:
    int *raizes; //eh melhor ser protected?
    int tipo_funcao; // 1-10
    Grafico grafico_simples;
protected:
    std::vector<double> coeficientes;
    std::vector<double> indices;
    int dominio; 
    int imagem;
public:
    //construtor e destrutor
    Funcao(std::string funcao_input); //localizar e inlcuir no vetor os coeficientes
    ~Funcao();

    //funcoes metodos
    void determinaTipo();
    void determinaDominioEImagem();
    int determinaFX0(int input_x0);
    void determinaRaiz();

    //metodos get
    int getTipo();
    int getDominio();
    int getImagem();
    int* getRaizes();

};

Funcao::Funcao(std::string funcao_input)
{
}

Funcao::~Funcao()
{
}


int Funcao::determinaFX0(double input_X0)
{
    std::vector<double> X0_elevado_aos_indices;
    std::vector<double> X0_multiplicando_aos_coeficientes;
    double valor_fX0=0;
    
    /* elevando input_x0 aos seus respectivos indices
    ** multiplicando input_x0 aos seus respectivos coeficientes
    ** somando todos os seus valores
    */
    for(int i=0;i<indices.size();i++)
    {
        X0_elevado_aos_indices.push_back(pow(input_X0,indices[i]));
        X0_multiplicando_aos_coeficientes.push_back(X0_elevado_aos_indices[i]*coeficientes[i]);
        valor_fX0 += X0_multiplicando_aos_coeficientes[i];
    }
    
    return valor_fX0;

}

int Funcao::derteminaRaiz()
{

}


#endif