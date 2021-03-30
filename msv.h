#ifndef MSV_H_
#define MSV_H_

#include <iostream>

class Funcao
{
protected:
    int *coeficientes;
    int *i;
public:
    Funcao(/* args */); //localizar e inlcuir no vetor os coeficientes
    ~Funcao();
    void determinaTipo();
    void determinaDominioEImagem();
    void determinaFXO();
    void determinaRaiz(); 
    
};

Funcao::Funcao(/* args */)
{
}

Funcao::~Funcao()
{
}


#endif

class Calculo : public Funcao
{
private:
    int valor_derivada;
public:
   void derivada(int x0);
   void integral(int x0, int x1);


};

Derivada::Derivada(/* args */)
{
}

Derivada::~Derivada()
{
}
