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
   
   // Iterador pos. Serve para salvar as cópias dos valores das Matches. Recebe o inicio e o final da string, além da Expressão regular
   std::sregex_iterator group(input.cbegin(), input.cend(), rgx);
   // É um iterador de fim de sequencia. Quando o std::sregex_iterator é incrementado após atingir a última Match, 'pos' fica igual 'end
   std::sregex_iterator end;
   
   // Define o tipo da função como Polinomio inicialmente
   this->_tipo = "Polinomio";

   // Verificando se a função de entrada é válida
   for( ; group!=end; group++){
      
      // Define a função como raiz n-ésima / racional
      if( (group->str(3)).find("-")!=std::string::npos || (group->str(0)).find("/")!= std::string::npos) 
         this->_tipo = "Raiz n-esima/racional";

      try{
         if(group->str(0).empty() && group->position() != input.length())
            throw std::invalid_argument("<Entrada invalida> Nao e um Polinomio ou Raiz n-esima ou racional.\nEntrada: ");
      }catch(std::invalid_argument &e){
         std::cerr << e.what() << input << std::endl;
         exit(1);
      }
   }
   
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

   coeficientes.pop_back();
   expoentes.pop_back();

   _coeficientes = coeficientes;
   _expoentes = expoentes;

   // TIRAR ESSES PRINTS DOS EXPOENTES, COEFICIENTES E TIPO DEPOIS
   static int I = 1;
  // std::cout << "\n<Funcao " << I++ << ": " << this->_tipo << ">" << std::endl;

   //for(int i = 0; i < _coeficientes.size(); i++)
   //{
     // std::cout << "\ncoeficientes: " << _coeficientes[i] << "\n";
      //std::cout << "expoentes: " << _expoentes[i] << "\n";
   //}
}

// Escreve o dominio no terminal e carrega a string _dominio.
void Funcao::get_dominio(){
   std::string dominio;

   //'e' indica 'pertence à' e 'R' numeros reais(como e' polinomio x sempre pertence a R);
   dominio="{x e R}";

        std::ofstream outfile;	
        outfile.open("RELATORIO.txt",  std::ios::app);
        outfile << "\n Tipo da Funcao: " <<  this->_tipo  << std::endl;
        outfile << "\ndominio: " << dominio << std::endl;
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


        outfile << "\nimagem: {y e R/ " << menor << " <= y <= " << maior << "} \n";

        outfile.close();

   std::vector<double> imagem = {menor, maior};
   _imagem = imagem;

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

// Escreve as raizes no terminal e carrega o vector _raizes .
//void Funcao::get_raizes()
//{
//	//std::cout.precision(2);
//	std::vector<double> valores_elegiveis;
//	
//	valores_elegiveis = salva_inversao_sinal();
//	if(valores_elegiveis.size()==0) std::cout << "Nao ha raizes\n";
//	else
//	{ 
//		std::vector<double> raizes;
//		raizes = metodo_newton(valores_elegiveis);
//		
//
//		for(int i=0;i<_raizes.size();i++)
//			std::cout << "Raiz " << i << ": " << _raizes[i] << std::endl;
//
//		_raizes = raizes;
//	}
//} 

// Retorna a derivada númerica de uma função
double Funcao::retorna_derivada(double x0)
{
	//metodo das secantes

	double valor_derivada=0;
	double h = 10e-7;


    double fmais = retorna_valor(x0 + h); 
    double fmenos = retorna_valor(x0 - h);

    valor_derivada = (fmais - fmenos)/(2.*h);

    return valor_derivada;
}

// Retorna um vetor com os valores de x0 limitrofes a troca de sinal, ou seja, as possíveis raizes da função dada
std::vector<double> Funcao::salva_inversao_sinal()
{
	std::vector<double> _elegiveis;
	double delta_x0 = 0.01;
	double delta_x1 = 0.0001;
	double delta_x2 = 0.000001;

	for(double i=-1000;i<=1000;i+=delta_x0)
	{
		double x0 = i-delta_x0;
		double x1 = i;

		double valor_a = retorna_valor(x0);
		double valor_b = retorna_valor(x1);

		if((valor_a <= 0.1 && valor_b >= -0.1) || (valor_a >= -0.1 && valor_b <= 0.1))
		{
	
			/********** FLAGS ***********/
			//std::cout << "valores x0 e x1: " << x0 << "|" << x1 << "\n";
			//std::cout << "valores a e b: " << valor_a << "|" << valor_b << "\n";
			for(double j=x0; j<x1;j+=delta_x1)
			{
				double x2 = j-delta_x1;
				double x3 = j;

				double valor_c = retorna_valor(x2);
				double valor_d = retorna_valor(x3);


				if((valor_c <= 0.01 && valor_d >= -0.01) || (valor_c >= -0.01 && valor_d <= 0.01))
				{
					/********** FLAGS **********					*/
					//std::cout << "valores x2 e x3: " << x2 << "|" << x3 << "\n";
					//std::cout << "size of elegiveis: " << _elegiveis.size() << "\n";	
                            for(double j=x2; j<x3;j+=delta_x2)
			                {
				                double x4 = j-delta_x2;
				                double x5 = j;
                
				                double valor_e = retorna_valor(x4);
				                double valor_f = retorna_valor(x5);


				                if((valor_e <= 0 && valor_f >= 0) || (valor_e >= 0 && valor_f <= 0))
				                {
				                	/********** FLAGS **********					*/
				                	//std::cout << "valores x4 e x5: " << x4 << "|" << x5 << "\n";
					            	


					                //para mais https://en.wikipedia.org/wiki/Brent%27s_method
					                fabs(valor_e)<=fabs(valor_f) ? _elegiveis.push_back(x4):_elegiveis.push_back(x5);
				                }
			                }	
				}
			}	
		}
	}

	compara_vetor(_elegiveis);
	return _elegiveis;
}

// Retorna um vetor com as raizes da função dada
std::vector<double> Funcao::metodo_newton(std::vector<double> valores_elegiveis)
{
	std::vector<double> raizes;

	//para mais https://en.wikipedia.org/wiki/Newton%27s_method

	// Define a tolerancia para a aproximação das raizes e o erro inicial
	double tolerancia = 1e-12;
	double error = tolerancia + 1; 
	int ciclo_atual = 0;
	int max_ciclos = 1000;

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

			double h = retorna_valor(x) / retorna_derivada(x);
			if(!isnormal(h)) h=0; // verificando se h = 0/0;
		    raiz = x - h;
		    error = fabs(raiz - x);
		    x = raiz;
		    ciclo_atual++;
		}

		if (error <= tolerancia)
		{
		    raizes.push_back(x);
		}

			// FLAGS
			//std::cout << ciclo_atual << std::endl;
			//std::cout << raiz << std::endl;
			//std::cout << error << std::endl;
	}

	compara_vetor(raizes);
	return raizes;
}

// Elimina os termos repitidos de um vetor
void Funcao::compara_vetor(std::vector<double> &vec)
{
	vec.erase(
      std::unique(vec.begin(), vec.end()),
      vec.end());
}

// Retorna o valor da função aplicada no ponto.
double Funcao::retorna_valor(double ponto){
   double valor_fx=0;

	for(int i=0;i<_expoentes.size();i++)
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




























