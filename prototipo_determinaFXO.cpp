#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include <vector>


int main(int argc, char const *argv[])
{
    //qual o X0 que você vai querer para determinar o F(x0)
	int input_X0 = 3;


    /* Essa parte não vai ser necessária para o projeto,
    ** neste caso é só para simular os valores dos
    ** coeficientes e indices do polinomio de exemplo
    ** que eh: 3x^5 + 2x^4 - x^3 + x + 2
    */
	int myints[] = {3,2,1,0,-1,2}; //coeficientes do polinomio
	int myindices[] = {5,4,3,2,1,0}; //indices do polinomio, como pode ver ele eh de grau 5
  	std::vector<int> coeficientes(myints, myints + sizeof(myints) / sizeof(int) );
  	std::vector<int> indices(myindices, myindices + sizeof(myindices) / sizeof(int) );

    /* Daqui para frente vai estar presente no metodo
    */
  	std::vector<int> X0_elevado_aos_indices;
    std::vector<int> X0_multiplicando_aos_coeficientes;
    int valor_fX0=0;
    
    //elevando input_x0 aos seus respectivos indices
    for(int i=0;i<indices.size();i++)
        X0_elevado_aos_indices.push_back(pow(input_X0,indices[i]));

    //multiplicando input_x0 aos seus respectivos coeficientes
    for(int j=0;j<coeficientes.size();j++)
        X0_multiplicando_aos_coeficientes.push_back(X0_elevado_aos_indices[j]*coeficientes[j]);
    
    for(int k=0;k<X0_multiplicando_aos_coeficientes.size();k++)
        valor_fX0 += X0_multiplicando_aos_coeficientes[k];

    std::cout << valor_fX0 << std::endl;
	return 0;
}