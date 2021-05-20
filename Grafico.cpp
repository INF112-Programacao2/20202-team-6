#include <iostream>
#include <fstream> 
#include <string>
#include <vector>

#include "Grafico.h"
#include "gnuplot.h"

Grafico::Grafico() {

}

void Grafico::pl(std::vector<double> coef, std::vector<double> exp,    std::string para_imprimir){

   std::string gnupleq;

   std::string output1 = "set output \"";
   std::string output2 = ".eps\" ";
   std::string output = output1 + para_imprimir + output2;

    FILE* arquivo = fopen("arquivo.txt", "w");
    if(arquivo == NULL) {
        fprintf(stderr, "Erro ao criar o arquivo.");
    }

   fprintf(arquivo, "pl ");
   for(unsigned int i = 0; i < coef.size(); i++)
   {
      fprintf(arquivo, "+(%f)*x**(%f)", coef[i], exp[i]);
   }
   fprintf(arquivo, " t\"");
   const char * c = para_imprimir.c_str();
   fprintf(arquivo, "%s", c);
   fprintf(arquivo, "\" \n");
   fflush(arquivo);
   fclose(arquivo);

   std::ifstream arquivor;
   arquivor.open("arquivo.txt");
   std::getline(arquivor, gnupleq);
   arquivor.close();

   remove("arquivo.txt");

   gnuplot p;
   p("set terminal pngcairo size 350,262 enhanced font \'Verdana,10\' ");
   p("set output \"output.png\" ");   
   p("set grid");
   p("set xrange[-10:10]");
   p("set yrange[-100:100]");
   p(gnupleq);

}



