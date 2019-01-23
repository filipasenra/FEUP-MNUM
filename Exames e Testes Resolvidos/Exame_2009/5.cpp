// Exame_2009.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

//dx/dt = sin(x)+sin(2*t)
double dx(double x, double t)
{
	return sin(x) + sin(2 * t);
}

double rk4(double x, double t, double h, int n)
{
	for (unsigned int i = 0; i < n; i++)
	{
		double x1 = h * dx(x, t);
		double x2 = h * dx(x + x1 / 2.0, t + h / 2.0);
		double x3 = h * dx(x + x2 / 2.0, t + h / 2.0);
		double x4 = h * dx(x + x3, t + h);
		x += x1 / 6.0 + x2 / 3.0 + x3 / 3.0 + x4 / 6.0;
		t += h;

		cout << i+1 << " t " << t << " x " << x << endl;
	}

	return x;
}

int main()
{
	cout << fixed;
	cout.precision(6);

	cout << "RK4\n";

	double h = 0.5;
	double ti = 1, tf = 1.5;
	int n = abs(tf - ti) / h;
	cout << "Rk4 h = 0.5\n";
	double s = rk4(ti, 1, h, n);

	h = 0.5 / 2.0;
	n = abs(tf - ti) / h;
	cout << "Rk4 h = 0.250\n";
	double s_ = rk4(ti, 1, h, n);

	h = 0.5 / 4.0;
	n = abs(tf - ti) / h;
	cout << "Rk4 h = 0.1250\n";
	double s__ = rk4(ti, 1, h, n);

	cout << "Qc " << (s_ - s) / (s__ - s_) << endl;

	return 0;
}
