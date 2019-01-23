// Exame_2015.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

/**
* Se converge |g'(x)|<1;
*/

double g(double x)
{
	return 2 * log(2 * x);
}

void picard(double x)
{
	for (unsigned int n = 0; n < 1; n++)
	{
		cout << "Residuo: " << x - g(x) << endl;
		x = g(x);
		cout << "x " << x << endl;
	}
}

int main()
{
	cout << fixed;
	cout.precision(5);
	
	cout << "Picard-Peano\n";
	picard(1.1);
	return 0;
}
