// Exame_2014.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

//Equação a usar:
//dL = sqrt(1+(2.5*e^(k*x))^2)

double dL(double x)
{
	return sqrt(1 + pow(2.5*exp(2.5*x), 2));
}

double trapezios(double xi, double xf, double h)
{
	unsigned int n = abs(xf - xi) / h;

	double soma = 0;

	for (unsigned int i = 1; i < n; i += 2)
	{
		soma += 2 * dL(xi + h * i);
	}

	for (unsigned int i = 2; i < n; i += 2)
	{
		soma += 2* dL(xi + h * i);
	}

	soma += dL(xi) + dL(xf);
	soma *= h / 2;
	cout << soma << endl;

	return soma;
}

double simpson(double xi, double xf, double h)
{
	unsigned int n = abs(xf - xi) / h;

	double soma = 0;

	for (unsigned int i = 1; i < n; i+=2)
	{
		soma += 4 * dL(xi + h*i);
	}

	for (unsigned int i = 2; i < n; i += 2)
	{
		soma += 2* dL(xi + h*i);
	}

	soma += dL(xi) + dL(xf);
	soma *= h / 3;
	cout << soma << endl;

	return soma;

}

int main()
{
	cout << fixed;
	cout.precision(5);

	cout << "SIMPSON h=0.125\n";
	double h = 0.125;
	double s = simpson(0, 1, h);

	cout << "SIMPSON h=0.125/2\n";
	h /= 2;
	double s_ = simpson(0, 1, h);

	cout << "SIMPSON h=0.125/4\n";
	h /= 2;
	double s__ = simpson(0, 1, h);

	cout << "SIMPSON QC: " << (s_ - s) / (s__ - s_) << endl;
	cout.precision(10);
	cout << "SIMPSON Erro estimado: " << (s__ - s_)/15 << endl;
	cout.precision(5);

	cout << "\nTrapezios h=0.125\n";
	h = 0.125;
	s = trapezios(0, 1, h);

	cout << "Trapezidos h=0.125/2\n";
	h /= 2;
	s_ = trapezios(0, 1, h);

	cout << "Trapezios h=0.125/4\n";
	h /= 2;
	s__ = trapezios(0, 1, h);

	cout << "Trapezios QC: " << (s_ - s) / (s__ - s_) << endl;
	cout.precision(10);
	cout << "Trapezios Erro estimado: " << (s__ - s_) / 3 << endl;


	return 0;
}