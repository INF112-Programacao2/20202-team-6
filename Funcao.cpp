#include <fstream>
#include <iostream>

#include "Funcao.h"
#include "Grafico.h"

// Carrega a string _input e chama o método get_parametros.
Funcao::Funcao(std::string input) {
   _input = input;
   get_parametros(_input);
}

// Retorna o sinal de um coeficiente
int Funcao::sign(std::string str)
{
   if(str.find('0') != std::string::npos)
      return 0;
    
   if(str.find('-') != std::string::npos)
      return -1;
        
   return 1;
}

// Retorna o denominador de um coeficiente ou expoente a/b
double Funcao::get_denominador(std::string str)
{
   try{
      if(str == "0")
         throw std::domain_error("<Coeficiente invalido> Divisao por 0 indeterminada.");
   }catch(std::domain_error &e){
      std::cerr << e.what() << std::endl;
      exit(1);
   }

   if(atof(str.c_str()) != 0)
      return atof(str.c_str());
   
   return 1;
}

// Função que remove um caractere da string (Caso o input haver espaços).
void Funcao::c_remove(std::string &str, char char_to_remove)
{
   int i = 0;
   std::string new_str;

   while(str[i])
   {
      if(str[i] != char_to_remove)
      {
         new_str.push_back(str[i]);
      }
      
      i++;
   }
   str = new_str;
}

// Funcão que determina o tipo da função de entrada
std::regex Funcao::get_tipo(std::string input)
{
   // Expressão Regular
   std::regex rgx("([+-]?\\d*(?:\\/(\\d+))?)(?:x(?:\\^(?:\\(?(\\-?\\d+)(?:\\/(\\d+)\\))?)?)?)?");
   int empty_matches = 0;
   
   // Iterador pos. Serve para salvar as cópias dos valores das Matches. Recebe o inicio e o final da string, além da Expressão regular
   std::sregex_iterator group(input.cbegin(), input.cend(), rgx);
   // É um iterador de fim de sequencia. Quando o std::sregex_iterator é incrementado após atingir a última Match, 'pos' fica igual 'end
   std::sregex_iterator end;
   
   // Define o tipo da função como Polinomio inicialmente
   this->_tipo = "Polinomio";

   // Verificando se a função de entrada é válida
   for( ; group!=end; group++){
      
      if(group->str(0).empty()) empty_matches++;
      //std::cout << group->str() << std::endl;
      //std::cout << empty_matches << std::endl;

      // Define a função como raiz n-ésima / racional
      if( (group->str(3)).find("-")!=std::string::npos || (group->str(0)).find("(")!= std::string::npos) 
         this->_tipo = "Raiz n-esima/racional";

      try{
         if(empty_matches > 2)
            throw std::invalid_argument("<Entrada invalida> Nao e um Polinomio ou Raiz n-esima ou racional.\nEntrada: ");
      }catch(std::invalid_argument &e){
         std::cerr << e.what() << input << std::endl;
         exit(1);
      }
   }
   
   std::cout<<empty_matches <<" "<<input.length()<<"\n";
   return rgx;
}

// Carrega o vector _coeficientes e o vector _expoentes (Usado no Construtor).
void Funcao::get_parametros(std::string input){

   double c, e;
   std::regex r;
   std::vector<double>coeficientes;
   std::vector<double>expoentes;
   c_remove(input, ' ');
   
   // r() é a regex do tipo da função de entrada 
   r.assign( get_tipo(input) );

   std::sregex_iterator group(input.cbegin(), input.cend(), r);
   std::sregex_iterator end;

   // == COLETANDO OS DADOS DE UM POLINÔMIO ==
   // Percorrendo todas as Matches encontradas até não ter mais nenhuma
   for( ; group!=end; group++)
   {
      // Assume o valor inicial dos coeficientes como (sinal) * 1 e para os expoentes 1 (casos x; -x; +x)
      c = 1 * sign(group->str(1));
      e = 1;
      
      // Checando se o coeficiente é um numero diferente de 1
      if(  !(group->str(1)).empty()  &&  !(group->str(1)).compare("+")==0  &&  !(group->str(1)).compare("-")==0)
         c = atof( (group->str(1)).c_str()) / get_denominador(group->str(2));
      
      // Checando se o expoente é um numero diferente de 1; caso contrário verifica se não existe a incógnita 'x' (se não existir é porque é 0)
      if(!(group->str(3)).empty()){
         e = atof( (group->str(3)).c_str()) / get_denominador( group->str(4) );
      }else if ( (group->str(0)).find('x') == std::string::npos){
         e = 0;
      }
      
      // Colocando os coeficientes e expoentes dentro dos vectors
      coeficientes.push_back(c);
      expoentes.push_back(e);
   }


   // Retirando matches vazios
   coeficientes.pop_back();
   expoentes.pop_back();

   _coeficientes = coeficientes;
   _expoentes = expoentes;
}

// Escreve o dominio no terminal e carrega a string _dominio.
void Funcao::get_dominio(){
   std::string dominio;

   //'e' indica 'pertence à' e 'R' numeros reais(como e' polinomio x sempre pertence a R);
   dominio="{x e R}";

        std::ofstream outfile;	
        outfile.open("RELATORIO.txt",  std::ios::app);
        outfile << "\nDominio: " << dominio << std::endl;
        outfile.close();



   _dominio = dominio;
} 

// Escreve a  imagem no terminal e carrega a string _imagem.
void Funcao::get_imagem(){

   std::ofstream outfile;	
   outfile.open("RELATORIO.txt",  std::ios::app);
   outfile.precision(3);
   double maior = retorna_valor(-1000);
   double menor = retorna_valor(-1000);
   for(double i=-1000;i<1001;i+=0.1)
   {
      if(retorna_valor(i)<menor) menor = retorna_valor(i); 
      if(retorna_valor(i)>maior) maior = retorna_valor(i);
   }


   condicao_inf_menor(menor);
   condicao_inf_maior(maior);

   if(menor >= -3e-10 && menor <= 3e-10) menor = 0;
   if(maior >= -3e-10 && maior <= 3e-10) maior = 0;


        outfile << "Imagem: {y e R/ " << menor << " <= y <= " << maior << "} \n\n";

        outfile.close();

   std::vector<double> imagem = {menor, maior};
   _imagem = imagem;

}

void Funcao::imprime_tipo()
{
   std::ofstream outfile;	
   outfile.open("RELATORIO.txt",  std::ios::app);
   outfile << "\n Tipo da Funcao: " <<  this->_tipo  << std::endl;
   outfile.close();
      
}

// Retorna infinito se não há limite superior
double Funcao::condicao_inf_maior(double &maior)
{
    if((retorna_valor(-1001) >= maior && retorna_valor(-1000) <= maior) ||
        ((retorna_valor(1001) >= maior && retorna_valor(1000) <= maior))) {return maior = INFINITY;}

    return maior;
}

// Retorna infinito se não há limite inferior
double Funcao::condicao_inf_menor(double &menor)
{
        if((retorna_valor(-1001) <= menor && retorna_valor(-1000) >= menor) ||
        ((retorna_valor(1001) <= menor && retorna_valor(1000) >= menor))) {return menor = INFINITY;}

    return menor;
}

// Retorna o valor da função aplicada no ponto.
double Funcao::retorna_valor(double ponto){
   double valor_fx=0;

	for(unsigned int i=0;i<_expoentes.size();i++)
		valor_fx += _coeficientes[i]*pow(ponto,_expoentes[i]);

	return valor_fx;
}

bool Funcao::get_tipo_Polinomio(){
   if (_tipo == "Polinomio")
     return true;
   else
     return false;
}

//================ Grafico ===================

void Funcao::plot(){
   std::vector<double> coef = _coeficientes;
   std::vector<double> exp = _expoentes;
   std::string para_imprimir  = _input;
   Grafico g;
   g.Grafico::pl(coef, exp, para_imprimir);
}




























