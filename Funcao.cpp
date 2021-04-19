#include <iostream>
#include <string>
#include <vector>
#include <regex>

#include "Funcao.h"

// Carrega a string _input e chama o método get_parametros.
Funcao::Funcao(std::string input) {
   _input = input;
   get_parametros(_input);
}

// Retorna o sinal de um coeficiente
int sign(std::string t)
{
   if(t[0] == '-')
      return -1;
        
   return 1;
}

// Retorna o denominador de um coeficiente ou expoente
double get_denominador(std::string t)
{
   if(atof(t.c_str()) != 0)
      return atof(t.c_str());
    
   return 1;
}


// Carrega o vector _coeficientes e o vector _expoentes (Usado no Construtor).
void Funcao::get_parametros(std::string input){
   // Expressão Regular que identifica os coeficientes dentro de um polinomio.
   /*
      Explicando a expressão regular:

      ( [+-]? \\d* (?: \\/ (\\d+) )? )

      [+-]? : identifica o sinal de + ou - ou nenhum sinal;
      \\d*  : identifica o coeficiente que possui nenhum ou mais digitos (Numerador);
      (?: \\/ (\\d+) )? : identifica se existe uma divisão com o digito anterior(Numerador) e captura o denominador;
      ()    : Captura tudo

      (?: x (?: \\^ (?: \\(? (\\d+) (?: \\/ (\\d+) \\) )? )? )? )?      

      x : identifica a variavel x;
      (?: \\^ (?: \\(? (\\d+) (?: \\/ (\\d+) \\) )? )? )? : identifica se há um a notação de expoente(^) seguido
      de abre parenteses, com o digito(numerador) lá dentro e, caso haja uma divisão também capturo o 
      denominador, fechando o parenteses no final.
      (?:)? : junta os dois anteriores e digo que eles podem ou não ocorrer
   */
   std::regex r("([+-]?\\d*(?:\\/(\\d+))?)(?:x(?:\\^(?:\\(?(\\d+)(?:\\/(\\d+)\\))?)?)?)?");
   std::vector<double>coeficientes;
   std::vector<double>expoentes;
   
   // Iterador pos. Serve para salvar as cópias dos valores das Matches. Recebe o inicio e o final da string, além da Expressão regular
   std::sregex_iterator pos(input.cbegin(), input.cend(), r);
   std::sregex_iterator end; // É um iterador de fim de sequencia. Quando o std::sregex_iterator é incrementado após atingir a ultima Match, pos == end
   
   // Percorrendo todas as Matches encontradas até não ter mais nenhuma (pos fica igual a end)
   for( ; pos!=end; pos++)
   {
      /* pos->str(x) é o retorno da match em std::string e x é o indice que identifica um grupo. A cada pos++ temos as Matches que foram encontradas pelo iterador pos ao ser construido
         Exemplo: -2/3x^(3/8)-5x+x^2+9
         
         Grupo 0: Match total
         Grupo 1: Numerador do coeficiente
         Grupo 2: Denominador do coeficiente
         Grupo 3: Numerador do expoente
         Grupo 4: Denominador do expoente
         
         Match 1: -2/3x^(3/8)   Grupo 1 / Grupo 2: -0.666667;   Grupo 3 / Grupo 4: 0.375
         Match 2: -5x           Grupo 1: -5;                    Grupo 3: 1
         Match 3: +x^2          Grupo 1: 1;                     Grupo 3: 2
         Match 4: +9            Grupo 1: 9;                     Grupo 3: 0
      */
      
      //  == COEFICIENTES ==
      // Se no retorno de uma Match que tem o Grupo 1 estiver vazio(não armazenou nenhum valor do grupo) OU o valor armazenado não é um numero (sinal de + ou -)  
      if((pos->str(1)).empty() || atof((pos->str(1)).c_str()) == 0)
      {
         // Isso é para os casos onde se tem a entrada de x ou +x ou -x
         coeficientes.push_back(1 * sign(pos->str(1))); // Multiplica um pelo sinal do coeficiente
      }
      else
      {
         // Caso seja um retorno numérico, armazena esse valor. (Numerador / 1) ou (Numerador / Denominador)
         coeficientes.push_back(atof( (pos->str(1)).c_str()) / get_denominador(pos->str(2)) );
      }
      
      // == EXPOENTES ==
      // Mesma coisa do anterior só que com o grupo 3. Isso é para os casos onde o expoente é 1 ou 0
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
         // Caso seja um retorno numérico, armazena esse valor. (Numerador / 1) ou (Numerador / Denominador)
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

   for(int i = 0; i < coeficientes.size(); i++)
   {
      std::cout << "\ncoeficientes: " << _coeficientes[i] << "\n";
      std::cout << "expoentes: " << _expoentes[i] << "\n";
   }

   std::cout << "======================================\n";
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

