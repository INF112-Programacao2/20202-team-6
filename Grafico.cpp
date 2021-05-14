#include <iostream>
#include <fstream> 
#include <string>
#include <vector>

#include "Grafico.h"

gnuplot::gnuplot() {
    // executando o comando gnuplot no terminal. persist mantém a janela do gnuplot aberta e w abre um arquivo de texto para gravação
    gnuplotpipe = popen("gnuplot -persist", "w");
    
    // caso não consiga gerar o arquivo
    if(!gnuplotpipe)
        std::cerr << ("Gnuplot nao encontrado.");
}

gnuplot::~gnuplot(){
    // Armazena a string no arquivo(sai do gnuplot)
    fprintf(gnuplotpipe, "exit\n");
    pclose(gnuplotpipe); // Fechando o fluxo de dados iniciado em _popen
}

void gnuplot::operator() (const std::string & command){
    // Armazena a string no arquivo
    fprintf(gnuplotpipe, "%s\n", command.c_str());
    fflush(gnuplotpipe); // limpando o buffer
}

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
   for(int i = 0; i < coef.size(); i++)
   {
      fprintf(arquivo, "+(%f)*x**(%f)", coef[i], exp[i]);
   }
   fprintf(arquivo, " t\"");
   const char * c = para_imprimir.c_str();
   fprintf(arquivo, c);
   fprintf(arquivo, "\" \n");
   fflush(arquivo);
   fclose(arquivo);

   std::ifstream arquivor;
   arquivor.open("arquivo.txt");
   std::getline(arquivor, gnupleq);
   arquivor.close();

   remove("arquivo.txt");

   gnuplot p;
   p("set term postscript eps enhanced color");
   p(output);
   p("set grid");
   p("set xrange[-5:5]");
   p("set yrange[-30:30]");
   p(gnupleq);

}



