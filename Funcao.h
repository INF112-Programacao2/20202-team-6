#ifndef Funcao_H
#define Funcao_H

#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <math.h>
#include <algorithm>

class Funcao {
protected:
   std::vector<double> _coeficientes;
   std::vector<double> _expoentes;
   std::vector<double> _raizes;
   std::vector<double> _imagem;
   std::string _dominio;
   std::string _input;
   std::string _tipo;

private:
   void get_parametros(std::string input); // Carrega o vector _coeficientes e o vector _expoentes (Usado no Construtor).
   std::regex get_tipo(std::string input); // Funcão que determina o tipo da função de entrada

   // Funções auxiliares e get_imagem()

   double condicao_inf_maior(double &maior);
   double condicao_inf_menor(double &menor);

   // Funções auxiliares de get_parametro()
   int sign(std::string str);
   double get_denominador(std::string str);
   void c_remove(std::string &str, char char_to_remove);

public:
   Funcao(std::string input); // Carrega a string _input e chama o método get_parametros.

   void get_dominio(); // Escreve o dominio no terminal e carrega a string _dominio.
   void get_imagem();  // Escreve a  imagem no terminal e carrega a string _imagem.
   void imprime_tipo(); // Escreve o tipo da funcao

   bool get_tipo_Polinomio(); // Retorna true se o tipo da funcao for polinomio

   double retorna_valor(double ponto); // Retorna o valor da função aplicada no ponto.

   void plot(); // Chama o gráfico
};

#endif
