#include <iostream>
#include <string>
#include <vector>

#include "Funcao.h"

// Carrega a string _input e chama o método get_parametros.
Funcao::Funcao(std::string input) {
   _input = input;
   get_parametros(_input);
}


// Carrega o vector _coeficientes e o vector _expoentes (Usado no Construtor).
void Funcao::get_parametros(std::string input){
   std::vector<double> coeficientes;
   std::vector<double> expoentes; 

   //...

   _coeficientes = coeficientes;
   _expoentes = expoentes;
}


// Escreve o dominio no terminal e carrega a string _dominio.
void Funcao::get_dominio(){
   std::string dominio;

   //...

   //std::cout << dominio << std::endl;
   _dominio = dominio;
} 


// Escreve a  imagem no terminal e carrega a string _imagem.
void Funcao::get_imagem(){
   std::string imagem;

   //...

   //std::cout << imagem << std::endl;
   _imagem = imagem;
} 


// Escreve as raizes no terminal e carrega o vector _raizes .
void Funcao::get_raizes(){
   std::vector<double> raizes;

   //...

   //std::cout << raizes << std::endl;
   _raizes = raizes;
} 


// Retorna o valor da função aplicada no ponto.
double Funcao::retorna_valor(double ponto){
   double fx0;

   //...

   return fx0;
} 

