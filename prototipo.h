#ifndef PROTOTIPO_H_
#define PROTOTIPO_H_

#include <iostream>
#include <sstream>

class Funcao
{
private:
    int *raizes; //eh melhor ser protected?
    int tipo_funcao; // 1-10
    Grafico grafico_simples;
protected:
    int *coeficientes;
    int *indices;
    int dominio; 
    int imagem;
public:
    //construtor e destrutor
    Funcao(std::string funcao_input); //localizar e inlcuir no vetor os coeficientes
    ~Funcao();

    //funcoes metodos
    void determinaTipo();
    void determinaDominioEImagem();
    void determinaFX0(int input_x0);
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


#endif



/****
 * Essa classe cobre a parte de claculo integral e
 * diferencial, maximos e minimos
*/
class Calculo : public Funcao
{
private:
    int valor_derivada;
    int valor_integral;
    Grafico grafico_completo; //retorna um grafico com a area rachurada ou uma tangente de derivada
public:

    //funcoes metodos 
   void determinaDerivada(int x0);
   void determinaIntegral(int x0, int x1);
   void determinaMaxEMin();
   void determinaMaxEMin(int x0, int x1); //determina o max e min local [necessario]


   //funcoes gets
   int getDerivada();
   int getIntegral();
};


/******
 * Estava pensando em criar a classe Grafico para tirar 
 * um pouco de responsabilidade da classe Funcao e usar
 * o conceito de composição
 ******/
class Grafico
{
private:
    /* data */
public:
    Grafico(/* args */);
    ~Grafico();
};

Grafico::Grafico(/* args */)
{
}

Grafico::~Grafico()
{
}


