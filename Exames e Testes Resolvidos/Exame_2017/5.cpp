// Exame_2017.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

double df_x(double x, double y)
{
	return -1.1*y + 14 * x - 8;
}

double df_y(double x, double y)
{
	return 12 - 1.1*x;
}

double f(double x, double y)
{
	return -1.1*x*y + 12 * y + 7 * x*x - 8 * x;
}

void gradiente(double x, double y, double h)
{
	double xn, yn;

	for (unsigned int i = 0; i < 1; i++)
	{

		xn = x - h * df_x(x, y);
		yn = y - h * df_y(x, y);

		if (f(xn, yn) < f(x, y))
		{
			h *= 2;
			x = xn;
			y = yn;
		}
		else
		{
			h /= 2.0;
		}

		cout << "f(x,n)=" << f(x, y) << endl;
	}
}

int main()
{
	gradiente(3, 1, 0.1);
	return 0;
}