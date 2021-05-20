#ifndef Grafico_H
#define Grafico_H

#include <iostream>
#include <string>
#include <vector>

#include "gnuplot.h"

class Grafico : public gnuplot {
private:

public:
   Grafico();

   void pl(std::vector<double> coef, std::vector<double> exp, std::string para_imprimir); // Pega os parametros da entrada e passa para a classe gnuplot

};

#endif

