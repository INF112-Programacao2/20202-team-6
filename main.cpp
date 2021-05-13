#include <iostream>
#include <string>
#include <vector>

#include "Funcao.h"
#include "Grafico.h"
#include "Calculo_Numerico.h"
#include "Calculo_Analitico.h"

int main(){
   
   // Todos os métodos que podemos usar em um objeto da classe Funcao.
   Funcao f1("0");
   f1.get_dominio();
   f1.get_imagem();
   f1.get_raizes(); 

   double F1_x0 = f1.retorna_valor(5.5);


   // Todos os métodos que podemos usar em um objeto da classe Calculo_Numerico.
   Calculo_Numerico f2("2/666 x ^ -7 - 12 x ^ (-4/55) + 2 x + 81/2");
   f2.get_dominio();
   f2.get_imagem();
   f2.get_raizes(); 
   f2.get_max_e_min(-100., 100);

   double   F2_x0  = f2.retorna_valor(11.);
   double d_F2_x0  = f2.retorna_valor("derivada", 13.1);
   double i_F2_ab  = f2.retorna_valor("integral", 0., 15.);


   // Todos os métodos que podemos usar em um objeto da classe Calculo_Analitico.
   Calculo_Analitico f3("3 x^(-5/558) -7x^3 +17x -77");
   f3.get_dominio();
   f3.get_imagem();
   f3.get_raizes(); 
   f3.get_max_e_min();

   double   F3_x0  = f3.retorna_valor(-5.);
   double d_F3_x0  = f3.retorna_valor("derivada", 13.1);
   double i_F3_x0  = f3.retorna_valor("integral", 5.);
   double i_F3_ab  = f3.retorna_valor("integral", -5., 5.);

   return 0;
}
