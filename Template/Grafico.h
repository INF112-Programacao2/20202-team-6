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

public:
   gnuplot(); 
   ~gnuplot();
};

class Grafico : public gnuplot {
private:

public:
   Grafico(); 
   ~Grafico();
};

#endif

