// Exame_2010_2011.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

void gauss_seidel(double x, double y, double z)
{
	for (unsigned int n = 0; n < 3; n++)
	{
		x = (2 - 6 * y - z) / 10;
		y = (-x - 3 * z) / 11;
		z = (-8 - 2 * x - 7 * y) / 13;
		cout << n + 1 << " x " << x << " y " << y << " z " << z << endl;
	}
}

int main()
{
	cout << "Gauss Seidel\n";

	gauss_seidel(0, 0, -1);

	return 0;

	/*Preenchimento da tabela do enunciado*/
	//xn+1 = 2 - 6yn -1zn / 10
	//yn+1  = 0 -1xn+1 -3zn / 11
	//zn+1 = -8 -2*xn+1 -7*yn+1/13
}