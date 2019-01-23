// 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

double dx(double x, double t)
{
	return sin(2 * x) + sin(2 * t);
}

void rk4(double x0, double t0, double h)
{
	double xn, tn;
	int i = 0;
	while(x0 != 1.5)
	{
		double a1 = h * dx(x0, t0);
		double a2 = h * dx(x0 + h * 0.5, t0 + a1 * 0.5);
		double a3 = h * dx(x0 + h * 0.5, t0 + a2 * 0.5);
		double a4 = h * dx(x0 + h, t0 + a3);

		xn = x0 + h;
		tn = t0 + a1 / 6 + a2 / 3 + a3 / 3 + a4 / 6;

		cout << i + 0 << " xn " << xn << " tn " << tn << endl;
		i++;
		x0 = xn;
		t0 = tn;
	}
}

int main()
{
	cout << "RK4\n";

	rk4(1, 1, 0.125);

}
