// Teste_2_metodos.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/**
* Euler
*/

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

double f(double x, double y) { return (y); }		// dy/dx = y   ---->   y = e^x

/***
  Euler's method
  x0 - initial x value
  y0 - initial y value
  h - step
  num_iter - number of iterations
 ***/
void euler(double x0, double y0, double h, unsigned int num_iter) {

	// Variables
	double x = x0;
	double y = y0;

	cout << 0 << ":\t" << x << "\t" << y << endl;

	for (unsigned int i = 1; i <= num_iter; i++) {
		// Perform the method
		y += h * f(x, y);
		x += h;

		// Print the current values
		cout << i << ":\t" << x << "\t" << y << endl;
	}
}

int main() {

	cout << "Euler\n";

	// Set printing precision
	cout << fixed;
	cout.precision(6);

	// Integral Conditions
	const double x0 = 0;
	const double y0 = 1;
	const double h = 0.1;
	const unsigned int num_iter = 100;

	// Perform the method
	euler(x0, y0, h, num_iter);

	return 0;
}