// Teste_2_metodos.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/**
* Eliminacao de Gauss
*/

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;
/**
* @brief retira k valor a toda a fila
*
*/
void rowop(vector<vector<double>> & m, unsigned int a, unsigned int b, double k) {
	for (unsigned int i = 0; i < m[0].size(); i++) {
		m[a][i] -= k * m[b][i];
	}
}

/**
* @brief Metodo de eliminacao de Gauss
*
* @param matrix a resolver
* @return
*/
void gauss(vector<vector<double>> & m) {

	//m[a][b]
	//a = linha
	//b = coluna

	//percorre as colunas
	for (unsigned int i = 0; i < m.size(); i++) {

		//coloca o pivo a 1
		rowop(m, i, i, 1 - 1 / m[i][i]);

		//percorre as linhas e subtrai de acordo com o pivo a ser utilizado
		for (unsigned int j = 0; j < m.size(); j++) {
			if (i != j)	
				rowop(m, j, i, m[j][i]);
			//m[j][i] elemento a ficar a 0
		}
	}
}

/* Print a matrix on the screen */
void print_matrix(const vector<vector<double> > & m) {
	for (unsigned int i = 0; i < m.size(); i++) {
		for (unsigned int j = 0; j < m[0].size(); j++) {
			cout << m[i][j] << '\t';
		}
		cout << '\n';
	}
}

int main()
{
	cout << "Metodo de Eliminacao de Gauss\n";

	// Matrix (vector de vectores de doubles) com as equacoes a resolver
	vector<vector<double> > m = {{7, 2, 0, 24}, {4, 20, 7, 27}, {5, -2, 8, 27}};

	gauss(m);
	print_matrix(m);
}
