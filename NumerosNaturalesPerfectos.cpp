#include <iostream>
#include <math.h>

using namespace std;

//N�meros naturales perfectos -> Aquellos cuya suma de divisores (- el mismo) dan el mismo n�mero.

class NNP {
public:
	int *ArregloNNP;

	void operator = (const NNP & other);
	
	int Arreglo(int n)
	{
		ArregloNNP = new int[n];
	}

	void calculo(int NNP) {
		int i = NNP - 1;
		int j = 0;
		while (i > 0)
		{
			if ((NNP % i) == 0) {
				ArregloNNP[j] = i;
				j++;
			}
			else
				i--;
		}
		cout << ArregloNNP << endl;
	}
};

void NNP::operator = (const NNP & other)
{
}

int main()
{
	NNP numero;
	numero.calculo(6);
}