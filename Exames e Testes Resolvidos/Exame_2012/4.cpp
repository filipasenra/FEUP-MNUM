// Exame_2012.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

double y(double x)
{
	return exp(1.5*x);
}

double simpson(double a, double b, double h)
{
	unsigned int n = abs(b - a) / h;
	double soma = 0;

	for (unsigned int i = 1; i < n; i += 2)
	{
		soma += 4 * y(a + h * i);
	}

	for (unsigned int i = 2; i < n; i += 2)
	{
		soma += 2 * y(a + h * i);
	}

	soma += y(a) + y(b);
	soma *= h / 3.0;

	cout << soma << endl;

	return soma;
}

int main()
{
	double h = 0.125;
	cout << "SIMPSON h = " << h << endl;
	double s = simpson(1, 1.5, h);

	h /= 2;
	cout << "SIMPSON h = " << h << endl;
	double s_ = simpson(1, 1.5, h);

	h /= 2;
	cout << "SIMPSON h = " << h << endl;
	double s__ = simpson(1, 1.5, h);

	cout << "Qc " << (s_ - s) / (s__ - s_) << endl;
	cout << "Erro " << (s__ - s_) / 15 << endl;
	cout << "Erro relativo " << (s__ - 3.337364510680308) / 3.337364510680308 << endl;

	return 0;
}