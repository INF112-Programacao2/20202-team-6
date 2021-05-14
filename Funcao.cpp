#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <math.h>

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

// Carrega o vector _coeficientes e o vector _expoentes (Usado no Construtor).
void Funcao::get_parametros(std::string input){

   // Expressão Regular
   std::regex r("([+-]?\\d*(?:\\/(\\d+))?)(?:x(?:\\^(?:\\(?(\\-?\\d+)(?:\\/(\\d+)\\))?)?)?)?");
   std::vector<double>coeficientes;
   std::vector<double>expoentes;
   c_remove(input, ' ');
   
   // Iterador pos. Serve para salvar as cópias dos valores das Matches. Recebe o inicio e o final da string, além da Expressão regular
   std::sregex_iterator pos(input.cbegin(), input.cend(), r);
   std::sregex_iterator end; // É um iterador de fim de sequencia. Quando o std::sregex_iterator é incrementado após atingir a última Match, pos fica igual end
   
   // Percorrendo todas as Matches encontradas até não ter mais nenhuma
   for( ; pos!=end; pos++)
   {
      //  == COEFICIENTES ==
      // Se no retorno de pos com o Grupo 1 vazio(não armazenou nenhum valor do grupo) OU o valor armazenado não é um numero (sinal de + ou -)  
      if((pos->str(1)).empty() || atof((pos->str(1)).c_str()) == 0)
      {
         // Isso é para os casos onde se tem a entrada de x ou +x ou -x
         coeficientes.push_back(1 * sign(pos->str(1))); // Multiplica um pelo sinal do coeficiente
      }
      else
      {
         // Caso seja um retorno numérico, armazena esse valor: (Numerador / 1) ou (Numerador / Denominador)
         coeficientes.push_back(atof( (pos->str(1)).c_str()) / get_denominador(pos->str(2)) );
      }
      
      // == EXPOENTES ==
      // Se no retorno de pos com o Grupo 3 vazio. Isso é para os casos onde o expoente é 1 ou 0
      if((pos->str(3)).empty())
      {
         // Se eu não encontrei um caracter 'x' na string da Match atual 
         if ((pos->str(0)).find('x') == std::string::npos)
         {
            expoentes.push_back(0);
            continue;
         }
         // Encontrei o x, logo, armazeno 1
         expoentes.push_back(1);
      }
      else
      {
         // Caso seja um retorno numérico, armazena esse valor: (Numerador / 1) ou (Numerador / Denominador)
         expoentes.push_back(atof( (pos->str(3)).c_str()) / get_denominador( pos->str(4) ) );
      }
   }
   
   // Por causa do jeito que eu escrevi a Expressão Regular r() Ta sempre ocorrendo uma Match vazia. Ai eu só to tirando ela do vetor
   coeficientes.pop_back();
   expoentes.pop_back();
   
   _coeficientes = coeficientes;
   _expoentes = expoentes;

   // TIRAR ESSES PRINTS DOS EXPOENTES E DOS COEFICIENTES DEPOIS
   static int I = 1;
   std::cout << "\nFUNCAO " << I++ << "\n"; 

   for(int i = 0; i < _coeficientes.size(); i++)
   {
      std::cout << "\ncoeficientes: " << _coeficientes[i] << "\n";
      std::cout << "expoentes: " << _expoentes[i] << "\n";
   }
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
   std::vector<double> valores_elegiveis;


   valores_elegiveis = salva_inversao_sinal();
	raizes = metodo_newton(valores_elegiveis);


   //std::cout << raizes << std::endl;
   _raizes = raizes;

   // TIRAR ESSES PRINTS DAS RAIZES DEPOIS
   static int II = 1;
   std::cout << "\nFUNCAO " << II++ << "\n"; 

   for(int i = 0; i <_raizes.size(); i++)
   {
      std::cout << "\nraizes: " << _raizes[i] << "\n";
   }

   std::cout << "======================================\n";
} 


// Retorna a derivada númerica de uma função
double Funcao::retorna_derivada(double x0)
{
	//metodo das secantes

	double valor_derivada=0;
	double h = 0.0001;


    double fmais = retorna_valor(x0 + h); 
    double fmenos = retorna_valor(x0 - h);

    valor_derivada = (fmais - fmenos)/(2.*h);

    return valor_derivada;
}

// Retorna um vetor com os valores de x0 limitrofes a troca de sinal, ou seja, as possíveis raizes da função dada
std::vector<double> Funcao::salva_inversao_sinal()
{
	std::vector<double> _elegiveis;


	for(double i=-100;i<=100;i+=0.1)
	{
		double x0 = i-0.1;
		double x1 = i;

		double valor_a = retorna_valor(x0);
		double valor_b = retorna_valor(x1);

		if((valor_a <= 0 && valor_b >= 0) || (valor_a >= 0 && valor_b <= 0))
			_elegiveis.push_back(x0);

	}

	return _elegiveis;
}

// Retorna um vetor com as raizes da função dada
std::vector<double> Funcao::metodo_newton(std::vector<double> valores_elegiveis)
{
	std::vector<double> raizes;


	//para mais https://stackoverflow.com/questions/39224270/newtons-method-in-c


	// Define a tolerancia para a aproximação das raizes e o erro inicial
	double tolerancia = 1e-12;
	double error = tolerancia + 1; 
	int ciclo_atual = 0;
	int max_ciclos = 100;

	// Variavel que guarda o valor já aproximado da raiz
	double raiz=0;

	// Faz a testagem para todos os valores que se mostram elegiveis
	for(int i=0;i<valores_elegiveis.size();i++)
	{
		double x = valores_elegiveis[i];
		error = tolerancia + 1;

		while (error > tolerancia && ciclo_atual < max_ciclos)
		{
			//metodo de newton
		    raiz = x - (retorna_valor(x) / retorna_derivada(x));
		    error = fabs(raiz - x);
		    x = raiz;
		    ciclo_atual++;
		}

		if (error <= tolerancia)
		{
		    raizes.push_back(raiz);
		}
	}

	return raizes;
}


// Retorna o valor da função aplicada no ponto.
double Funcao::retorna_valor(double ponto){
   double valor_fx=0;

	for(int i=0;i<_expoentes.size();i++)
		valor_fx += _coeficientes[i]*pow(ponto,_expoentes[i]);

	return valor_fx;
}



//================ Grafico ===================

void Funcao::plot(){
   std::vector<double> coef = _coeficientes;
   std::vector<double> exp = _expoentes;
   std::string para_imprimir  = _input;
   Grafico g;
   g.Grafico::pl(coef, exp, para_imprimir);
}




























