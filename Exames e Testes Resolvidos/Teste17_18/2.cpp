// 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

void gauss_seidel(vector<vector<double>> m, vector<double> x0)
{
	//vector<double> xn = x0;

	for (unsigned int i = 0; i < 1; i++)
	{
		//repare-se que utiliza os valores atualizados
		//dá para fazer para equações maiores ou menores
		for (unsigned int j = 0; j < x0.size(); j++)
		{
			x0[j] = m[j][m[0].size() - 1];

			for (unsigned int a = 0; a < x0.size(); a++)
			{
				if (a != j)
					x0[j] -= m[j][a] * x0[a];
			}

			x0[j] *= 1 / m[j][j];

			cout << "x" << j << " " << x0[j] << " ";
		}

		cout << endl;

		/*
		//Mais especifico
		x0[0] = 1 / m[0][0] * (m[0][4] - m[0][1] * x0[1] - m[0][2] * x0[2] - m[0][3] * x0[3]);
		x0[1] = 1 / m[1][1] * (m[1][4] - m[1][0] * x0[0] - m[1][2] * x0[2] - m[1][3] * x0[3]);
		x0[2] = 1 / m[2][2] * (m[2][4] - m[2][0] * x0[0] - m[2][1] * x0[1] - m[2][3] * x0[3]);
		x0[3] = 1 / m[3][3] * (m[3][4] - m[3][0] * x0[0] - m[3][1] * x0[1] - m[3][2] * x0[2]);

		cout << "x0 " << x0[0] << " x1 " << x0[1] << " x2 " << x0[2] << " x3 " << x0[3] << endl;
		*/
	}
}

int main()
{
	cout << fixed;
	cout.precision(6);

	cout << "Gauss-Seidel\n";

	vector<vector<double>> m = { {6, 0.5, 3, 0.25, 25}, {1.2, 3, 0.25, 0.2, 10} , {-1, 0.25, 4, 2, 7},
	{2, 4, 1, 8, -12} };
	vector<double> x0 = { 2.12687, 2.39858, 3.99517, -3.73040 };

	gauss_seidel(m, x0);

}
