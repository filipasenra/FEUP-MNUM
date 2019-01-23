// Exame_2010_2011.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

double f(double x)
{
	return (2 * log(2 * x));
}

double df(double x)
{
	return 2.0 / x;
}

void picard(double x)
{
	for (unsigned int n = 0; n < 3; n++)
	{
		x = f(x);
		cout << n + 1 << " x " << x << endl;
	}
}

int main()
{
	picard(0.9);
	return 0;
}