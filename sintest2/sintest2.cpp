// sintest.cpp : main project file.

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <conio.h>
using namespace std;
const double pi = 3.1415926535897932384626433832795;
float radical(long deg)
{
	// This function is required to connvert degree into radians for C++ to calculate the related trignometric ratio of.
	double rad = pi / 180 * deg;
	return rad;
}
void sinsummer(long deg)
{
	double sinsuming = 0;
	for (int i = 1; i <= deg; i++)
		sinsuming += sin(radical(i));
	cout << "The actual value of sin x from 1 to " << deg << " is " << sinsuming;
}
void main()
{
	long n;
	cout << "Enter value of n" << '\n';
	cin >> n;
	for (int k = 1; pow(2,k) <= n; k++)
	{
		double sinsum;
		sinsum = pow(2, k)*sin(radical((n + 1) / 2));
		for (int i = 2; i <= k; i++)
			sinsum = sinsum*cos(radical((n / pow(2, i))));
		double q = 0;
		for (int j = 1; j <= n / pow(2, k); j++)
			q = q + cos(radical(((pow(2, k - 1) + (j - 1)*pow(2, k) - n) / pow(2, k))));
		sinsum = sinsum * q;
		cout << "Sum when k= " << k << " is " << sinsum << '\n';
	}
	sinsummer(n);
	_getch();
}