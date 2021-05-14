#ifndef Funcao_H
#define Funcao_H

#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <math.h>

class Funcao {
protected:
   std::string _input;
   std::vector<double> _coeficientes;
   std::vector<double> _expoentes;
   std::vector<double> _raizes;
   std::string _dominio;
   std::string _imagem;

   char _tipo; // Por hora sem método: _tipo = "Polinomio".

private:
   void get_parametros(std::string input); // Carrega o vector _coeficientes e o vector _expoentes (Usado no Construtor).
   std::regex get_tipo(std::string input); // Funcão que determina o tipo da função de entrada
   double retorna_derivada(double x0);
   std::vector<double> salva_inversao_sinal();
   std::vector<double> metodo_newton(std::vector<double> valores_elegiveis);

   // Funções auxiliares de get_parametro()
   int sign(std::string str);
   double get_denominador(std::string str);
   void c_remove(std::string &str, char char_to_remove);

public:
   Funcao(std::string input); // Carrega a string _input e chama o método get_parametros.
   //~Funcao();

   void get_dominio(); // Escreve o dominio no terminal e carrega a string _dominio.
   void get_imagem();  // Escreve a  imagem no terminal e carrega a string _imagem.
   void get_raizes();  // Escreve as raizes no terminal e carrega o vector _raizes .

   double retorna_valor(double ponto); // Retorna o valor da função aplicada no ponto.

   void plot(); // Chama o gráfico
};

#endif
