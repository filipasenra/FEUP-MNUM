// Exame_2012.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

double f(double x, double y)
{
	return 3 * x*x - x * y + 11 * y + y * y - 8 * x;
}

double df_x(double x, double y)
{
	return -y + 6 * x - 8;
}

double df_y(double x, double y)
{
	return 2 * y - x + 11;
}

void gradiente(double x, double y, double h)
{
	double xn, yn;

	cout << 0 << " x " << x << " y " << y << " f(x,y) " << f(x, y) << " df_x " << df_x(x, y) << " df_y " << df_y(x, y) << endl;

	for (unsigned int n = 0; n < 1; n++)
	{
		xn = x - h * df_x(x, y);
		yn = x - h * df_y(x, y);

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

		cout << n + 1 << " x " << x << " y " << y << " f(x,y) " << f(x, y) << " df_x " << df_x(x, y) << " df_y " << df_y(x, y) << endl;
	}
}

int main()
{
	gradiente(2, 2, 0.5);
	return 0;
}