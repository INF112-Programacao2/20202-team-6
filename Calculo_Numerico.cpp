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

   std::cout.precision(2);
   double maior = retorna_valor(limite_inf);
   double menor = retorna_valor(limite_sup);
   for(double i=limite_inf;i<limite_sup;i+=0.1)
   {
      if(retorna_valor(i)<menor) menor = retorna_valor(i); 
      if(retorna_valor(i)>maior) maior = retorna_valor(i);
   }

   if(menor >= -3e-10 && menor <= 3e-10) menor = 0;
   if(maior >= -3e-10 && maior <= 3e-10) maior = 0;


   std::cout << "O menor valor local eh: " << std::fixed << menor << "|| O maior valor loca eh" << std::fixed <<  maior << "\n";

   std::vector<double> max_min = {menor, maior};
   _max_min = max_min;

} 


// Retorna o valor da função aplicada no ponto.
double Calculo_Numerico::retorna_valor(double ponto){
   return Funcao::retorna_valor(ponto);
}  

// Retorna o valor da derivada da função aplicada no ponto.
double Calculo_Numerico::retorna_valor(std::string derivada, double ponto){
   if(derivada == "derivada"){
      double dfx0;

	   double h = 10e-7;
      double fmais = retorna_valor(ponto + h); 
      double fmenos = retorna_valor(ponto - h);

      dfx0 = (fmais - fmenos)/(2.*h);

      return dfx0;
   }else{
      std::cerr << "Erro: entrada invalida";
      return -1;
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
      return -1;
   }
} 
