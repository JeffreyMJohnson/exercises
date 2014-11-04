#include <iostream>
#include <string>
#include <stack>

using namespace std;

void NumberConvert(const int numToConvert, const int radix, string& result);

void main()
{
	int convert = 255;
	int radix = 2;
	string result = "";
	NumberConvert(convert, radix, result);

	cout << convert << " converted to base " << radix << " = " << result << endl;
	system("pause");

}

void NumberConvert(const int numToConvert, const int radix, string& result)
{
	stack<char> stack;
	int m = numToConvert;

	while (m >= radix)
	{
		char b[2];
		_itoa_s(m % radix, b, 2, 10);
		stack.push(*b);
		m = m / radix;
	}

	result = "";
	char b[2];
	_itoa_s(m, b, 2, 10);
	result += *b;

	while (stack.size() > 0)
	{
		
		result += stack.top();
		stack.pop();
	}

	return;
}