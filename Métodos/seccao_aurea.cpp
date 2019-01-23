//Teste_2_metodos.cpp : This file contains the 'main' function.Program execution begins and ends there.
//

/**
* Seccao Aurea
*/

#include "pch.h"
#include <iostream>
#include <cmath>

using namespace std;

// Aurea Method

double f(double x)
{
	return 5 * cos(x) - sin(x);
}

int main()
{

	cout << "Seccao Aurea\n";

	double b = (sqrt(5) - 1) / 2.0;
	double a = pow(b, 2);

	double x1 = 2;
	double x2 = 4;
	double x3 = x1 + a * (x2 - x1);
	double x4 = x1 + b * (x2 - x1);

	cout << "Iteracao 0:" << endl << "X1: " << x1 << endl << "X2: " << x2 << endl << "X3: " << x3 << endl << "X4: " << x4 << endl << endl;

	for (unsigned int i = 0; i < 2; i++)
	{
		//Para o calcular o Máximo é só trocar o sinal "<" por ">"

		if (f(x3) < f(x4))
			x2 = x4;
		else
			x1 = x3;

		x3 = x1 + a * (x2 - x1);
		x4 = x1 + b * (x2 - x1);

		cout << "Iteracao " << i + 1 << ":" << endl << "X1: " << x1 << endl << "X2: " << x2 << endl << "X3: " << x3 << endl << "X4: " << x4 << endl << endl;
	}

	return 0;
}