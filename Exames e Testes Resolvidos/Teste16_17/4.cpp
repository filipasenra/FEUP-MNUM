// 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;
double dv(double t, double v)
{
	return t * (t*0.5 + 1)*v*v*v + (t + 2.5)*v*v;
}

double euler(double t, double v, double h, double final)
{
	double tn, vn;
	unsigned int i = 0;

	while (t < final)
	{
		i++;
		tn = t + h;
		vn = v + h * dv(t, v);
		t = tn;
		v = vn;

		cout << i << " t " << t << " v " << v << endl;
	}

	return v;
}
int main()
{

	cout << fixed;
	cout.precision(6);

	cout << "Euler\n\n";

	cout << "h = 0.08\n";
	double s = euler(1, 0.1, 0.08, 1.8);

	cout << "\nh = 0.04\n";
	double s_ = euler(1, 0.1, 0.04, 1.8);

	cout << "\nh = 0.04\n";
	double s__ = euler(1, 0.1, 0.02, 1.8);

	cout << "Qc: " << (s_ - s) / (s__ - s_);
	cout << "\nErro: " << (s__ - s_) / 1 << endl;

	return 0;
}
