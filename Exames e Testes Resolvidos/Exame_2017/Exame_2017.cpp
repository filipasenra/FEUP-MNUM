// Exame_2017.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

/*
* Poderemos usar um dos três méotodos abordados na unidade Curricular:
* 1. Método da Secção Áurea
* 2. Método do Gradiente
* 3. Métodos da Quádrica
*
* Nâo usarei o método da Quádrica, pois este só tem especial interesse quando usado
* quando usado em conjunção com outro método, pois apenas funciona bem na vizinhança do mínimo (ou máximo)
* Não usarei o Método do Gradiente, pois este existe um esforço de cálculo adicional no cálculo das derivadas
* direcionais, quando comparado com o método da Secção Áurea
* 
* Usarei como critério de paragem a precisão 0.001 entre os valores x1-x4 ou x2-x3,
* ou seja, o intervalo em que se encontra o minimo é menor que 0.001.
*
* Um intervalo que contém o mínimo da função é [1,3] (observado no maxima).
*/
const double b = (sqrt(5) - 1) / 2.0;
const double a = b * b;

double f(double x)
{
	return (x - 7)*(x - 7) + pow(x, 4);
}

void aurea(double x1, double x2)
{
	double x4, x3;
	do
	{
		x3 = x1 + a * (x2 - x1);
		x4 = x1 + b * (x2 - x1);

		if (f(x3) < f(x4))
		{
			x2 = x4;
			x4 = x3;
		}
		else
		{
			x1 = x3;
			x3 = x4;
		}

	} while (abs(x1 - x4) > 0.001 && abs(x3 - x2) > 0.001);

	cout << "x1 " << x1 << " x2 " << x2 << endl;
}

int main()
{
	aurea(1, 3);
    
	return 0;
}