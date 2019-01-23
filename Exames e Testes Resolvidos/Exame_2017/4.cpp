// Exame_2017.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

const double b = 0.5;
const double a = 30;

double dC(double T, double C)
{
	return -exp(-b / (T + 273))* C;
}

double dT(double T, double C)
{
	return a * exp(-b / (T + 273)) * C - b * (T - 20);
}

double euler(double t, double C, double T, double h)
{
	double Cn, Tn;

	cout << 0 << " t " << t << " T " << T << " C " << C << endl;

	unsigned int a = abs(0.5 - 0) / h;

	for (unsigned int n = 0; n < a; n++)
	{
		Tn = T;
		Cn = C;

		T = Tn + h * dT(Tn, Cn);
		C = Cn + h * dC(Tn, Cn);
		t += h;

		cout << n + 1 << " t " << t << " T " << T << " C " << C << endl;
	}

	return T;
}

void rk4(double t, double C, double T, double h)
{
	cout << 0 << " t " << t << " C " << C << " T " << T << endl;

	unsigned int a = abs(0.5 - 0) / h;

	for (unsigned int n = 0; n < a; n++)
	{
		double T1 = h * dT(T, C);
		double C1 = h * dC(T, C);

		double T2 = h * dT(T + T1 / 2.0, C + C1 / 2.0);
		double C2 = h * dC(T + T1 / 2.0, C + C1 / 2.0);

		double T3 = h * dT(T + T2 / 2.0, C + C2 / 2.0);
		double C3 = h * dC(T + T2 / 2.0, C + C2 / 2.0);

		double T4 = h * dT(T + T3, C + C3);
		double C4 = h * dC(T + T3, C + C3);

		T += T1 / 6.0 + T2 / 3.0 + T3 / 3.0 + T4 / 6.0;
		C += C1 / 6.0 + C2 / 3.0 + C3 / 3.0 + C4 / 6.0;
		t += h;

		cout << n + 1 << " t " << t << " C " << C << " T " << T << endl;
	}
}

int main()
{
	cout << fixed;
	cout.precision(5);

	double h = 0.25;
	cout << "Euler h = " << h << endl;
	double s = euler(0, 2.5, 25, h);

	h /= 2.0;
	cout << "Euler h = " << h << endl;
	double s_ = euler(0, 2.5, 25, h);

	h /= 2.0;
	cout << "Euler h = " << h << endl;
	double s__ = euler(0, 2.5, 25, h);

	cout << "Qc: " << (s_ - s) / (s__ - s_) << endl;
	cout << "Erro: " << abs(s__ - s_) / 1 << endl;

	cout << "\nRK4\n";
	rk4(0, 2.5, 25, 0.25);

	return 0;
}