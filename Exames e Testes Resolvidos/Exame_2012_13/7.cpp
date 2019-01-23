// 2012_2013_1.cpp
//

#include "pch.h"
#include <iostream>

using namespace std;

double g(double x)
{
	return pow((4 * x*x*x - x + 3), (1 / 4.0));
}

void PicardPeano(double x)
{
	cout << 0 << " x " << x << endl;
	for (unsigned int n = 0; n < 2; n++)
	{
		x = g(x);
		cout << n + 1 << " x " << x << endl;
	}
}

int main()
{
	PicardPeano(3.5);
	return 0;
}
