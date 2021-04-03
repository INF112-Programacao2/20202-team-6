#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <math.h>
#include <vector>

using namespace std;

			/* ex. 1: f(x)=1/x OK
			** ex. 2: f(x)=1/(x+1)^2 OK
			** ex. 3: f(x)= e^x OK
			*/

const long double valor0_padrao = pow(10,-10);
const long double valor1_padrao = pow(20,-10);
const long double valor2_padrao = pow(4.8828125009535601475096910917272907681763172149658203125,-10);
const long double infinito = 999800029995.883719027042388916015625;
const long double menos_infinito = -999800029995.883719027042388916015625;
const long double euler =  2.718281828459045235360287;

int main(int argc, char const *argv[])
{
	long double limite_esquerda,limite_direita, coeficiente_a, delta_esquerda, delta_direita,i;
	float valor_L;

	
	
	coeficiente_a = infinito;

	//limite para x -> infinito
	if(coeficiente_a == infinito)
	{
		for(int j=0;j<=10000;j++)
			valor_L = pow(euler,j);

		if(valor_L >= infinito) cout << "converge para: infinito" << endl;
		else cout << "converge para: " << setprecision(3) << valor_L << endl;
	}

	//limite para x -> -infinito
	else if(coeficiente_a == menos_infinito)
	{
		for(int k=0;k>=-10000;k--)
			valor_L = pow(euler,k);
		
		if(valor_L >= infinito) cout << "converge para: infinito" << endl;
		else cout << "converge para: " << setprecision(3) << valor_L << endl;
	}

	
	//limites para x -> a tal que a pertence a R
	else
	{
		i=0;
		delta_esquerda = coeficiente_a - valor0_padrao;
		delta_direita = coeficiente_a + valor0_padrao;

		for(int ii=0;ii<=10000;ii++)	
		{

			//limite_esquerda = 1/pow(((delta_esquerda+i)+1),2);
			//limite_direita = 1/pow(((delta_direita-i)+1),2);

			limite_esquerda = pow(euler,delta_esquerda+i);
			limite_direita = pow(euler,delta_direita-i);


			i = i + valor1_padrao;
		}


		if(limite_direita - limite_esquerda <= valor2_padrao) 
		{
			if(limite_esquerda >= infinito || limite_direita >= infinito) cout << "converge para: infinito" << endl;
			else
			{
				valor_L = limite_esquerda;
				cout << "converge para: " << setprecision(3) << valor_L << endl;
			}
		}
		else cout << "diverge" << endl;
	}

	return 0;
}

