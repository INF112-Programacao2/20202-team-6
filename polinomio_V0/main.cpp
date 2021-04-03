#include <iostream>
#include <sstream>
#include <math.h>
#include <cstring>
#include <iomanip>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <string>
#include "funcao.h"

using namespace std;

int main()
{
   cout << " Comporta polinomios de até 20 termos com coeficientes inteiros e potências inteiras e positivas"<< endl;
   cout << " Todos os coeficientes devem possuir sinal" << endl;
   cout << " Os únicos simbolos aceitos além dos númeoros são, +- (sinais), x (variável), * (multiplicação), **(potência) e não deve haver espaços" << endl;
   cout << " EX: -2*x**3-5*x**2+7*x+9 ou +2*x**7-12*x**4+2*x+81" << endl;
   cout << ".............................................................."<<endl;
   cout << "Escreva sua função abaixo:"<< endl;

   char entrada[100];

   cin.getline(entrada, 100, '\n');

   Funcao f1(entrada);

   cout << ".............................................................."<<endl;
   cout << "Escreva o x desejado para obter f(x):"<< endl;
   cout << "x = ";

   int x0;

   cin >> x0;

   f1.determinaFX0(x0);

   cout << ".............................................................."<<endl;
   cout << "Escreva o x0 desejado para obter f'(x0) (derivada de f em relação a x no ponto x0):"<< endl;
   cout << "x0 = ";

   double dx0;

   cin >> dx0;

   f1.derivada_em_X0(dx0);

   return 0;
}
















