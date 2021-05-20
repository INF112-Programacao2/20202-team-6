#ifndef gnuplot_H
#define gnuplot_H

#include <iostream>
#include <string>

class gnuplot {
protected:
   FILE *gnuplotpipe;

public:
   gnuplot(); 
   ~gnuplot();
   void operator() (const std::string & command); // Functor que passa o comando para ser executado no gnuplot.
};

#endif

