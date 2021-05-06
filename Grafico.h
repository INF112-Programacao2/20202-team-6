#ifndef Grafico_H
#define Grafico_H

#include <iostream>
#include <string>
#include <vector>

#include "Funcao.h"
#include "Calculo_Numerico.h"
#include "Calculo_Analitico.h"

class gnuplot {
protected:
   FILE *gnuplotpipe;

public:
   gnuplot(); 
   ~gnuplot();
   void operator() (const std::string & command); // Functor que pega os comandos do gnuplot.
};

class Grafico : public gnuplot {
private:

public:
   Grafico(); 
   //~Grafico();

};

#endif

