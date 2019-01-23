// 2012_2013_1.cpp
//

#include "pch.h"
#include <iostream>

using namespace std;

double f(double x)
{
	return (-x + 40 * cos(sqrt(x)) + 3);
}

double df(double x)
{
	return ((-20 * sin(sqrt(x))) / sqrt(x) - 1);
}

void newton(double x)
{
	double xn;

	cout << 0 << " x " << x << " f(x) " << f(x) << endl;

	for (unsigned int n = 0; n < 2; n++)
	{
		xn = x;
		x = xn - f(xn) / df(xn);
		cout << n + 1 << " x " << x << " f(x) " << f(x) << endl;
	}
}

int main()   
{
	newton(1.7);
	return 0;
}
