#include <iostream>
#include <string>
#include <vector>

#include "Funcao.h"
#include "Calculo_Numerico.h"
#include "Calculo_Analitico.h"
#include "Grafico.h"

gnuplot::gnuplot() {
    // executando o comando gnuplot no terminal. persist mantém a janela do gnuplot aberta e w abre um arquivo de texto para gravação
    gnuplotpipe = _popen("gnuplot -persist", "w");
    
    // caso não consiga gerar o arquivo
    if(!gnuplotpipe)
        std::cerr << ("Gnuplot nao encontrado.");
}

gnuplot::~gnuplot(){
    // Armazena a string no arquivo(sai do gnuplot)
    fprintf(gnuplotpipe, "exit\n");
    _pclose(gnuplotpipe); // Fechando o fluxo de dados iniciado em _popen
}

void gnuplot::operator() (const std::string & command){
    // Armazena a string no arquivo
    fprintf(gnuplotpipe, "%s\n", command.c_str());
    fflush(gnuplotpipe); // limpando o buffer
}

Grafico::Grafico() {

}
