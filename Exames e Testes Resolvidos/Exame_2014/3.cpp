// Exame_2014.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

/**
* @brief Subtrair uma linha pela outra
*
* @matriz onde serao realizados os calculos
* @param linha com o pivo
* @param linha afeta aos calculos
* @param fator a subtrair
*/
void rowop(vector<vector<double>> & m, unsigned int i, unsigned int j, double k)
{
	for (unsigned int n = 0; n < m[0].size(); n++)
	{
		m[j][n] -= k * m[i][n];
	}
}

void gauss(vector<vector<double>> & m, bool triangular)
{
	for (unsigned int i = 0; i < m.size(); i++)
	{
		unsigned int n = 0;
		if (triangular)
			n = i + 1;

		//pivo a 1
		rowop(m, i, i, 1 - 1 / m[i][i]);

		for (unsigned int j = n; j < m.size(); j++)
		{
			if (j != i)
			rowop(m, i, j, m[j][i]);
		}
	}
}

void showMatrix(vector<vector<double>> m)
{
	for (unsigned int i = 0; i < m.size(); i++)
	{
		for (unsigned int j = 0; j < m[i].size(); j++)
			cout << m[i][j] << "\t\t";
		cout << endl;
	}
}

int main()
{
	cout << fixed;
	cout.precision(6);

	vector<vector<double>> m = { {1, 1 / 2.0, 1 / 3.0, -1}, {1 / 2.0, 1 / 3.0, 1 / 4.0, 1}, {1 / 3.0, 1 / 4.0, 1 / 5.0, 1} };
	gauss(m, false);
	showMatrix(m);
	return 0;
}