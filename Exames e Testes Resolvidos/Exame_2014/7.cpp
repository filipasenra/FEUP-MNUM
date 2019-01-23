// Exame_2014.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

double f(double x)
{
	return x * x*x - 10 * sin(x) + 2.8;
}

void bissecao(double a, double b)
{
	for (unsigned int n = 0; n < 2; n++)
	{
		double m = (a + b) / 2.0;
		if (f(a)*f(m) < 0)
			b = m;
		else
			a = m;

		cout << n + 1 << " a " << a << " b " << b << endl;
	}
}

int main()
{
	bissecao(1.5, 4.2);
	return 0;
}