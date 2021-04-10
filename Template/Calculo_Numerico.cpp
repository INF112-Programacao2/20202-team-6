#include <iostream>
#include <string>
#include <vector>

#include "Funcao.h"
#include "Calculo_Numerico.h"

// Carrega a string _input, o vector _coeficientes e o vector _expoentes (Usando o construtor de Funcoes).
Calculo_Numerico::Calculo_Numerico(std::string input):
   Funcao(input) {}


// Escreve o dominio no terminal (Como depende da entrada não guardei a informação).
void Calculo_Numerico::get_max_e_min(double limite_inf, double limite_sup){
   double maximo;
   double minimo;

   //...

   //std::cout << maximo << " & " << minimo << std::endl;
} 


// Retorna o valor da função aplicada no ponto.
double Calculo_Numerico::retorna_valor(double ponto){
   return Funcao::retorna_valor(ponto);
}  

// Retorna o valor da derivada da função aplicada no ponto.
double Calculo_Numerico::retorna_valor(std::string derivada, double ponto){
   if(derivada == "derivada"){
      double dfx0;

      double h = 0.0001;
      double fmais = retorna_valor(ponto + h); 
      double fmenos = retorna_valor(ponto - h);

      dfx0 = (fmais - fmenos)/(2.*h);

      return dfx0;
   }else{
      std::cerr << "Erro: entrada invalida";
   }
}  


// Retorna o valor da integral da função dado os limites de integração.
double Calculo_Numerico::retorna_valor(std::string integral, double limite_inf, double limite_sup){
   if(integral == "integral"){
      double int_f;

      //...

      return int_f;
   }else{
      std::cerr << "Erro: entrada invalida";
   }
} 
