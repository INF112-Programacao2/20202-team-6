#ifndef Calculo_Numerico_H
#define Calculo_Numerico_H

#include <iostream>
#include <string>
#include <vector>

#include "Funcao.h"

class Calculo_Numerico : public Funcao {

protected:
   std::vector<double> _max_min;

public:
   Calculo_Numerico(std::string input); // Carrega a string _input, o vector _coeficientes e o vector _expoentes (Usando o construtor de Funcoes).
   //~Calculo_Numerico();

   void get_max_e_min(double limite_inf, double limite_sup); // Escreve os valores máximos e mínimos no terminal (Como depende da entrada não guardei a informação).

   double retorna_valor(double ponto); // Retorna o valor da função aplicada no ponto.
   double retorna_valor(std::string derivada, double ponto); // Retorna o valor da derivada da função aplicada no ponto.
   double retorna_valor(std::string integral, double limite_inf, double limite_sup); // Retorna o valor da integral da função dado os limites de integração.

};
#endif

