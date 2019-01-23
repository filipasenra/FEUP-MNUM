// Exame_2010_2011.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

double z(double x, double y)
{
	return 6 * x*x - x * y + 12 * y + y * y - 8 * x;
}

double dz_x(double x, double y)
{
	return -y + 12 * x - 8;
}

double dz_y(double x, double y)
{
	return 2 * y - x + 12;
}

void gradiente(double x, double y, double h)
{
	double xn, yn;

	cout << 0 << " x " << x << " y " << y << endl;
	cout << "z " << z(x, y) << " dz_x " << dz_x(x, y) << " dz_y " << dz_y(x, y) << endl;

	for (unsigned int n = 0; n < 2; n++)
	{
		xn = x - h * dz_x(x, y);
		yn = y - h * dz_y(x, y);

		if (z(xn, yn) < z(x, y))
		{
			h *= 2;
			x = xn;
			y = yn;
		}
		else
			h /= 2;
		
		cout << n + 1 << " x " << x << " y " << y << endl;
		cout << "z " << z(x,y) << " dz_x " << dz_x(x, y) << " dz_y " << dz_y(x, y) << endl;
	}
}

int main()
{
	gradiente(0, 0, 0.25);
	return 0;
}