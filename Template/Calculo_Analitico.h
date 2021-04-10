#ifndef Calculo_Analitico_H
#define Calculo_Analitico_H

#include <iostream>
#include <string>
#include <vector>

#include "Funcao.h"
#include "Grafico.h"

class Calculo_Analitico : public Funcao {
private:
   std::vector<double> _coeficientes_derivada;
   std::vector<double> _expoentes_derivada;
   std::vector<double> _coeficientes_integral;
   std::vector<double> _expoentes_integral;
   double _maximo;
   double _minimo;

   void get_parametros_derivada_integral(); // Carrega o vector _coeficientes_derivada, o vector _expoentes_derivada, o vector _coeficientes_integral e o vector _expoentes_integral (Usado no Construtor).

public:
    Calculo_Analitico(std::string input);// Carrega a string _input, o vector _coeficientes e o vector _expoentes (Usando o construtor de Funcoes)
    ~Calculo_Analitico();

   void get_max_e_min(); // Escreve os valores máximos e mínimos no terminal e carrega double _maximo e double _minimo.

   double retorna_valor(std::string parametro, double ponto); // Retorna o valor da função derivada no ponto ou o valor da função Primitiva de constante 0 no ponto.

   double retorna_valor(std::string integral, double limite_inf, double limite_sup); // Retorna o valor da integral definida da função dado os limites de integração.

};
#endif

