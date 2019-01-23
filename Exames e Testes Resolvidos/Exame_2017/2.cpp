// Exame_2017.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

double f(double x)
{
	return sqrt(1 + pow(2.5*exp(2.5*x), 2));
}
double simpson(double a, double b, double h)
{
	double soma = 0;
	unsigned int n = abs(b - a) / h;

	for (unsigned int i = 1; i < n; i += 2)
	{
		soma += 4 * f(a + i * h);
	}

	for (unsigned int i = 2; i < n; i += 2)
	{
		soma += 2 * f(a + i * h);
	}

	soma += f(a) + f(b);
	soma *= h / 3;

	cout << soma << endl;

	return soma;

}

double trapezio(double a, double b, double h)
{
	double soma = 0;
	unsigned int n = abs(b - a) / h;

	for (unsigned int i = 1; i < n; i += 2)
	{
		soma += 2 * f(a + i * h);
	}

	for (unsigned int i = 2; i < n; i += 2)
	{
		soma += 2* f(a + i * h);
	}

	soma += f(a) + f(b);
	soma *= h / 2;

	cout << soma << endl;

	return soma;
}

int main()
{
	cout << fixed;
	cout.precision(5);

	double h = 0.125;
	cout << "SIMPSON h= " << h << endl;
	double s = simpson(0, 1, h);

	h /= 2;
	cout << "SIMPSON h= " << h << endl;
	double s_ = simpson(0, 1, h);

	h/= 2;
	cout << "SIMPSON h= " << h << endl;
	double s__ = simpson(0, 1, h);

	cout << "Qc " << (s_ - s) / (s__ - s_) << endl;

	cout << "Erro " << (s__ - s_) / 15 << endl;

	h = 0.125;
	cout << "Trapezio h= " << h << endl;
	s = trapezio(0, 1, h);

	h /= 2;
	cout << "Trapezio h= " << h << endl;
	s_ = trapezio(0, 1, h);

	h /= 2;
	cout << "Trapezio h= " << h << endl;
	s__ = trapezio(0, 1, h);

	cout << "Qc " << (s_ - s) / (s__ - s_) << endl;

	cout << "Erro " << (s__ - s_) / 3 << endl;

	return 0;
}