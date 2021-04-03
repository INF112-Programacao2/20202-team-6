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
	double myints[] = {3,2,1,0,1,2};
	double myindices[] = {5,4,3,2,1,0};
  	std::vector<double> coeficientes(myints, myints + sizeof(myints) / sizeof(double) );
  	std::vector<double> indices(myindices, myindices + sizeof(myindices) / sizeof(double) );

    /* Daqui para frente vai estar presente no metodo
    */
  	std::vector<double> X0_elevado_aos_indices;
    std::vector<double> X0_multiplicando_aos_coeficientes;
    double valor_fX0=0;
    //elevando input_x0 aos seus respectivos indices
    for(int i=0;i<indices.size();i++)
    {
        X0_elevado_aos_indices.push_back(pow(input_X0,indices[i]));
        X0_multiplicando_aos_coeficientes.push_back(X0_elevado_aos_indices[i]*coeficientes[i]);
        valor_fX0 += X0_multiplicando_aos_coeficientes[i];
    }

    
    std::cout << valor_fX0 << std::endl;
	return 0;
}