#include <iostream>
#include <string>
#include <vector>

#include "Funcao.h"
#include "Grafico.h"
#include "Calculo_Numerico.h"
#include "Calculo_Analitico.h"

int main(){
   
   // Todos os métodos que podemos usar em um objeto da classe Funcao.
   Funcao f1("4 x^(2/2) - 3 x");
   f1.get_dominio();
   f1.get_imagem();
   f1.get_raizes();
   f1.plot(); 

   double F1_x0 = f1.retorna_valor(5.5);


   // Todos os métodos que podemos usar em um objeto da classe Calculo_Numerico.
   Calculo_Numerico f2("-2 -1 x -6x^2 -12x^3 +4x^5");
   f2.get_dominio();
   f2.get_imagem();
   f2.get_raizes(); 
   f2.get_max_e_min(-100., 100);
   f2.plot(); 

   double   F2_x0  = f2.retorna_valor(11.);
   double d_F2_x0  = f2.retorna_valor("derivada", 13.1);
   double i_F2_ab  = f2.retorna_valor("integral", 0., 15.);


   // Todos os métodos que podemos usar em um objeto da classe Calculo_Analitico.
   Calculo_Analitico f3("24-14x-13x^2+2x^3+x^4");
   f3.get_dominio();
   f3.get_imagem();
   f3.get_raizes(); 
   f3.get_max_e_min();
   f3.plot(); 

   double   F3_x0  = f3.retorna_valor(-5.);
   double d_F3_x0  = f3.retorna_valor("derivada", 13.1);
   double i_F3_x0  = f3.retorna_valor("integral", 5.);
   double i_F3_ab  = f3.retorna_valor("integral", -5., 5.);

   return 0;
}
