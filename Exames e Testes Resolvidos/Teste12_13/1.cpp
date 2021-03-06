// 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

void gauss_jacobi(vector<vector<double>> m, vector<double> x0)
{
	vector<double> xn = x0;

	for (unsigned int i = 0; i < 2; i++)
	{

		xn[0] = (m[0][4] - m[0][1] * x0[1] - m[0][2] * x0[2] - m[0][3] * x0[3]) / m[0][0];
		xn[1] = (m[1][4] - m[1][0] * x0[0] - m[1][2] * x0[2] - m[1][3] * x0[3]) / m[1][1];
		xn[2] = (m[2][4] - m[2][0] * x0[0] - m[2][1] * x0[1] - m[2][3] * x0[3]) / m[2][2];
		xn[3] = (m[3][4] - m[3][0] * x0[0] - m[3][1] * x0[1] - m[3][2] * x0[2]) / m[3][3];

		cout << i + 1 << "x0 " << xn[0] << " x1 " << xn[1] << " x2 " << xn[2] << " x3 " << xn[3] << endl;

		x0 = xn;
	}
}

int main()
{
	cout << "Gauss-Jacobi\n";

	vector<vector<double>> m = { {4.5, -1, -1, 1, 1}, {-1, 4.5, 1, -1, -1}, {-1, 2, 4.5, -1, -1},
	{ 2, -1, -1, 4.5, 0} };

	vector<double> x0{ 0.25, 0.25, 0.25, 0.25};

	gauss_jacobi(m, x0);

}
