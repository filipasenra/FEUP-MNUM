// Exame_2012.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

double f(double x)
{
	return x - 3.7 + pow(cos(x + 1.2), 3);
}

double df(double x)
{
	return 1 - 3 * pow(cos(x + 1.2), 2) * sin(x + 1.2);
}

void newton(double x)
{
	for (unsigned int n = 0; n < 1; n++)
	{
		x -= f(x) / df(x);
		cout << n + 1 << " x " << x << endl;
	}
}

int main()
{
	newton(3.8);
	return 0;
}