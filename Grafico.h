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
   //~Grafico();

   void pl(std::vector<double> coef, std::vector<double> exp, std::string para_imprimir);

};

#endif

