// Exame_2012.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

//z = dy/dt
//dz/dt= A+t*t + t*z

using namespace std;

double dy(double t, double z)
{
	return z;
}

double dz(double t, double z)
{
	return 0.5 + t * t + t * z;
}

void euler(double t, double z, double y, double h)
{
	double tn, zn, yn;

	cout << 0 << " t " << t << " y " << y << " z " << z << endl;

	for (unsigned int n = 0; n < 2; n++)
	{
		tn = t;
		zn = z;
		yn = y;

		z += h * dz(tn, zn);
		y += h * dy(tn, zn);
		t += h;
		cout << n + 1 << " t " << t << " y " << y << " z " << z << endl;
	}
}

void rk4(double t, double z, double y, double h)
{

	cout << 0 << " t " << t << " y " << y << " z " << z << endl;

	for (unsigned int n = 0; n < 2; n++)
	{
		double y1 = h * dy(t, z);
		double z1 = h * dz(t, z);

		double y2 = h* dy(t + h/2.0, z + z1/2.0);
		double z2 = h * dz(t + h / 2.0, z + z1 / 2.0);

		double y3 = h * dy(t + h/ 2.0, z + z2 / 2.0);
		double z3 = h * dz(t + h / 2.0, z + z2 / 2.0);

		double y4 = h * dy(t + h, z + z3);
		double z4 = h * dz(t + h, z + z3);

		z += z1 / 6.0 + z2 / 3.0 + z3 / 3.0 + z4 / 6.0;
		y += y1 / 6.0 + y2 / 3.0 + y3 / 3.0 + y4 / 6.0;
		t += h;
		cout << n + 1 << " t " << t << " y " << y << " z " << z << endl;
	}
}

int main()
{
	cout << "Euler\n";
	euler(0, 1, 0, 0.25);

	cout << "RK4\n";
	rk4(0, 1, 0, 0.25);
	return 0;
}