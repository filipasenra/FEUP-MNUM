// Exame_2015.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

void rowop(vector<vector<double>> & m, unsigned int i, unsigned int j, double k)
{
	for (unsigned int n = 0; n < m[i].size(); n++)
	{
		m[j][n] -= k * m[i][n];
	}
}

void gauss(vector<vector<double>> & m)
{
	for (unsigned int i = 0; i < m.size(); i++)
	{
		//pivo a 1
		rowop(m, i, i, 1 - 1 / m[i][i]);

		//se for para ser triangular j = i+1
		for (unsigned int j = 0; j < m.size(); j++)
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
		{
			cout << m[i][j] << "\t\t";
		}
		cout << endl;
	}
}

int main()
{
	cout << fixed;
	cout.precision(5);

	vector<vector<double>> m = { { 1, 1 / 2.0, 1 / 3.0, -1} , {1 / 2.0, 1 / 3.0, 1 / 4.0, 1}, {1 / 3.0, 1 / 4.0, 1 / 5.0, 1} };
	gauss(m);
	showMatrix(m);

	return 0;
}
