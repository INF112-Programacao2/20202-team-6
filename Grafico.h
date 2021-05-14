#ifndef Grafico_H
#define Grafico_H

#include <iostream>
#include <string>
#include <vector>


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

   void pl(std::vector<double> coef, std::vector<double> exp, std::string para_imprimir);

};

#endif

