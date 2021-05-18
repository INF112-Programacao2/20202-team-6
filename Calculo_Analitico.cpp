#include <fstream>
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
   for(int i=0;i<expoentes.size();i++)
   {
      if(expoentes[i]>0)
      {
         expoentes_derivada.push_back(expoentes[i]-1);
         coeficientes_derivada.push_back(coeficientes[i] * expoentes[i]);
      }
         expoentes_integral.push_back(expoentes[i]+1);
         coeficientes_integral.push_back(coeficientes[i] / expoentes_integral[i]);
   }

   _coeficientes_derivada = coeficientes_derivada;
   _expoentes_derivada = expoentes_derivada;

   _coeficientes_integral = coeficientes_integral;
   _expoentes_integral = expoentes_integral;
}


// Escreve os valores máximos e mínimos no terminal e carrega double _maximo e double _minimo.
void Calculo_Analitico::get_max_e_min(){
   std::cout.precision(3);
   double maior = retorna_valor(-1000);
   double menor = retorna_valor(-1000);
   for(double i=-1000;i<1001;i+=0.1)
   {
      if(retorna_valor(i)<menor) menor = retorna_valor(i); 
      if(retorna_valor(i)>maior) maior = retorna_valor(i);
   }

   condicao_inf_menor(menor);
   condicao_inf_maior(maior);

   if(menor >= -3e-10 && menor <= 3e-10) menor = 0;
   if(maior >= -3e-10 && maior <= 3e-10) maior = 0;
   
        std::ofstream outfile;	
        outfile.open("RELATORIO.txt",  std::ios::app);
        outfile << "O minimo: " << menor << " & o maximo: " << maior << "\n";
        outfile.close();

   _maximo = maior;
   _minimo = menor;
} 

// Retorna infinito se não há limite superior
double Calculo_Analitico::condicao_inf_maior(double &maior)
{
    if((retorna_valor(-1001) >= maior && retorna_valor(-1000) <= maior) ||
        ((retorna_valor(1001) >= maior && retorna_valor(1000) <= maior))) {return maior = INFINITY;}

    return maior;
}

// Retorna infinito se não há limite inferior
double Calculo_Analitico::condicao_inf_menor(double &menor)
{
        if((retorna_valor(-1001) <= menor && retorna_valor(-1000) >= menor) ||
        ((retorna_valor(1001) <= menor && retorna_valor(1000) >= menor))) {return menor = INFINITY;}

    return menor;
}


// Retorna o valor da função aplicada no ponto.
double Calculo_Analitico::retorna_valor(double ponto){
   return Funcao::retorna_valor(ponto);
}  


// Retorna o valor da função derivada no ponto ou o valor da função Primitiva de constante 0 no ponto.
double Calculo_Analitico::retorna_valor(std::string parametro, double ponto){
   if(parametro == "derivada"){
      double dfx0=0;    //inicia =0 para evitar erro no calculo

      for(int i=0; i<_coeficientes_derivada.size(); i++)
         dfx0+=_coeficientes_derivada[i]*(pow(ponto, _expoentes_derivada[i]));

      return dfx0;
   }else{
      if(parametro == "integral"){
         double int_f=0;   //inicia =0 para evitar erro no calculo

         for(int i=0; i<_coeficientes_integral.size(); i++)
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










