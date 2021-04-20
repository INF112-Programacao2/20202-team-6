#ifndef Funcao_H
#define Funcao_H

#include <iostream>
#include <string>
#include <vector>

class Funcao {
protected:
   std::string _input;
   std::vector<double> _coeficientes;
   std::vector<double> _expoentes;
   std::vector<double> _raizes;
   std::string _dominio;
   std::string _imagem;

   std::string _tipo; // Por hora sem método: _tipo = "Polinomio".

private:
   void get_parametros(std::string input); // Carrega o vector _coeficientes e o vector _expoentes (Usado no Construtor).
   double retorna_derivada(double x0);
   std::vector<double> salva_inversao_sinal();
   std::vector<double> metodo_newton(std::vector<double> valores_elegiveis);

public:
   Funcao(std::string input); // Carrega a string _input e chama o método get_parametros.
   //~Funcao();

   void get_dominio(); // Escreve o dominio no terminal e carrega a string _dominio.
   void get_imagem();  // Escreve a  imagem no terminal e carrega a string _imagem.
   void get_raizes();  // Escreve as raizes no terminal e carrega o vector _raizes .

   double retorna_valor(double ponto); // Retorna o valor da função aplicada no ponto.
};

int sign(std::string t);
double get_denominador(std::string t);




#endif