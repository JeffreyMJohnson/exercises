#include <iostream>
#include "Calc.h"

using namespace std;

void main()
{
	Calc calculator;
	float lhs = 500.5;
	float rhs = 0;
	try
	{
		cout << lhs << " + " << rhs << " = " << calculator.Add<double>(lhs, rhs) << endl;
		cout << lhs << " - " << rhs << " = " << calculator.Sub<long double>(lhs, rhs) << endl;
		cout << lhs << " * " << rhs << " = " << calculator.Mul<float>(lhs, rhs) << endl;
		cout << lhs << " / " << rhs << " = " << calculator.Div<double>(lhs, rhs) << endl;
	}
	catch (BadInput e)
	{
		cout << e.what() << endl;
	}
	catch (...)
	{
		cout << "Exception fired";
	}

	system("pause");
}