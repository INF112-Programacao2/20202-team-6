#include <iostream>
#include <string>
#include <vector>

#include "Funcao.h"
#include "Calculo_Analitico.h"


// Carrega a string _input e chama o método get_parametros da classe Funcao e chama os métodos get_parametros_derivada_integral.
Calculo_Analitico::Calculo_Analitico(std::string input): Funcao(input){
   get_parametros_derivada_integral();
 }


// Carrega o vector _coeficientes_derivada, o vector _expoentes_derivada, o vector _coeficientes_integral e o vector _expoentes_integral (Usado no Construtor).
void Calculo_Analitico::get_parametros_derivada_integral(){

   std::vector<double> coeficientes = _coeficientes;
   std::vector<double> expoentes = _expoentes; 

   std::vector<double> coeficientes_derivada;
   std::vector<double> expoentes_derivada; 

   std::vector<double> coeficientes_integral;
   std::vector<double> expoentes_integral; 

   //Visto que um valor constante em uma função tenha expoente=0 na saída do terminal, realizei apenas um for com if else para calcular os valores dos coeficientes e expoentes da derivada e integral
   for(int i=0; i<coeficientes.size(); i++){
      
      expoentes_derivada[i]=expoentes[i]-1;  //valor do expoente da derivada

      if(expoentes[i]==0){
         coeficientes_derivada[i]=0;    //derivada de uma constante=0;
         expoentes_derivada[i]=1;  //o expoente do coef da constante da derivada sera 1 devido a formula para o calculo da derivada no ponto, pois se o ponto=0, 0^-1 e 0^0=indefinido e 0^1=0
         break;
      }
      else if((expoentes[i])>=1){ 
         coeficientes_derivada[i]=expoentes[i]*coeficientes[i]; //valor coeficiente da derivada=(valor do expoente)*(a)
         break;
      }
   }

   for(int i=0; i<coeficientes.size(); i++){
      
      expoentes_integral[i]=expoentes[i]+1;  //valor expoente da integral

      if(expoentes[i]==0){ 
         coeficientes_integral[i]=coeficientes[i]; //integral de uma constante=ela mesma (ex: integral de 2=2x)
         break;
      }  

      else if((expoentes[i])>=1){ 
         coeficientes_integral[i]=coeficientes[i]/expoentes_integral[i]; //valor coeficiente da integral=(a)/(expoente+1)
         break;
      }
   }


   _coeficientes_derivada = coeficientes_derivada;
   _expoentes_derivada = expoentes_derivada;

   _coeficientes_integral = coeficientes_integral;
   _expoentes_integral = expoentes_integral;
}


// Escreve os valores máximos e mínimos no terminal e carrega double _maximo e double _minimo.
void Calculo_Analitico::get_max_e_min(){
   double maximo;
   double minimo;

   //...

   //std::cout << maximo << " & " << minimo << std::endl;
   _maximo = maximo;
   _minimo = minimo;
} 


// Retorna o valor da função aplicada no ponto.
double Calculo_Analitico::retorna_valor(double ponto){
   return Funcao::retorna_valor(ponto);
}  


// Retorna o valor da função derivada no ponto ou o valor da função Primitiva de constante 0 no ponto.
double Calculo_Analitico::retorna_valor(std::string parametro, double ponto){
   if(parametro == "derivada"){
      double dfx0;

      for(int i=0; i<_coeficientes.size(); i++)
         dfx0+=_coeficientes_derivada[i]*(pow(ponto, _expoentes_derivada[i]));

      return dfx0;
   }else{
      if(parametro == "integral"){
         double int_f;

         for(int i=0; i<_coeficientes.size(); i++)
            int_f+=_coeficientes_integral[i]*(pow(ponto, _expoentes_integral[i]));

         return int_f;
      }else{
         std::cerr << "Erro: entrada invalida";
         return -1;
      }
   }
}  


// Retorna o valor da integral definida da função dado os limites de integração.
double Calculo_Analitico::retorna_valor(std::string integral, double limite_inf, double limite_sup){
   if(integral == "integral"){
      double int_f;

      double F_sup = retorna_valor("integral", limite_sup);
      double F_inf = retorna_valor("integral", limite_inf);

      int_f = F_sup - F_inf;

      return int_f;
   }else{
      std::cerr << "Erro: entrada invalida";
      return -1;
   }
}










