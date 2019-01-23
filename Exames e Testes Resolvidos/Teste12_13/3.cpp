// 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

const double a = 20.00000;
const double b = 0.50000;

double dC(double t, double C, double T)
{
	return (-exp(-b / (T + 273)) * C);
}

double dT(double t, double C, double T)
{
	return (a*exp(-b / (T + 273))*C - b * (T - 20));
}

double euler(double t0, double C0, double T0, double h)
{
	double tn, Cn, Tn;

	cout << 0 << " tn " << t0 << " Cn " << C0 << " Tn " << T0 << endl;

	for (unsigned int i = 0; i < 2 || t0 < 0.39999; i++)
	{
		tn = t0 + h;
		Cn = C0 + h * dC(t0, C0, T0);
		Tn = T0 + h * dT(t0, C0, T0);

		cout << i + 1 << " tn " << tn << " Cn " << Cn << " Tn " << Tn << endl;

		t0 = tn;
		C0 = Cn;
		T0 = Tn;
	}

	return C0;
}

double rk4(double t0, double C0, double T0, double h)
{
	double tn, Cn, Tn;

	cout << 0 << " tn " << t0 << " Cn " << C0 << " Tn " << T0 << endl;
	
	for (unsigned int i = 0; i < 3; i++)
	{
		double a1 = h * dC(t0, C0, T0);
		double b1 = h * dT(t0, C0, T0);

		double a2 = h * dC(t0 + h / 2, C0 + a1 / 2, T0 + b1 / 2);
		double b2 = h * dT(t0 + h / 2, C0 + a1 / 2, T0 + b1 / 2);

		double a3 = h * dC(t0 + h / 2, C0 + a2 / 2, T0 + b2 / 2);
		double b3 = h * dT(t0 + h / 2, C0 + a2 / 2, T0 + b2 / 2);

		double a4 = h * dC(t0 + h, C0 + a3, T0 + b3);
		double b4 = h * dT(t0 + h, C0 + a3, T0 + b3);

		tn = t0 + h;
		Cn = C0 + a1 / 6 + a2 / 3 + a3 / 3 + a4 / 6;
		Tn = T0 + b1 / 6 + b2 / 3 + b3 / 3 + b4 / 6;

		t0 = tn;
		C0 = Cn;
		T0 = Tn;

		cout << 0 << " tn " << t0 << " Cn " << C0 << " Tn " << T0 << endl;
	}

	return C0;
}

double quocient(double S, double S_, double S__)
{
	return (S_ - S) / (S__ - S_);
}

int main()
{
	cout << fixed;
	cout.precision(5);

	cout << "Euler\n";

	double S= euler(0, 2, 20, 0.2);
	double S_= euler(0, 2, 20, 0.1);
	double S__ = euler(0, 2, 20, 0.05);

	cout << "RK4\n";

	rk4(0, 2, 20, 0.2);

	cout << "Quociente Euler: " << quocient(S, S_, S__);

}
