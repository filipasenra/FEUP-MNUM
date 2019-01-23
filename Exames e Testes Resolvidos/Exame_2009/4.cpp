// Exame_2009.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

//y = 5*cos(x)-sin(x)

const double b = (sqrt(5) - 1) / 2.0;
const double a = b * b;

double f(double x)
{
	return 5 * cos(x) - sin(x);
}

void aurea(double x1, double x2)
{
	double x3, x4;

	for (unsigned int n = 0; n < 3; n++)
	{
		x3 = a * (x2 - x1) + x1;
		x4 = b * (x2 - x1) + x1;

		cout << n + 1 << " x1 " << x1 << " x2 " << x2 << " x3 " << x3 << " x4 " << x4 << endl;
		cout << "f(x1) " << f(x1) << " f(x2) " << f(x2) << " f(x3) " << f(x3) << " f(x4) " << f(x4) << endl;
			
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
	}
}

int main()
{
	cout << "Seccao áurea (minimo)\n";

	aurea(2, 4);

	return 0;
}
