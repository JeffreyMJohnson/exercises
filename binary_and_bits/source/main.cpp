#include <iostream>
#include <string>
#include <stack>

using namespace std;

void NumberConvert(const int numToConvert, const int radix, string& result);
int BinToDec(bool isSigned, string& bin);

struct Binary
{
	bool isSigned;
	string mBinary;

	Binary()
	{
		mBinary = "";
		isSigned = false;
	}

	Binary(const char* a_bin)
	{
		mBinary = string(a_bin);
		isSigned = false;
	}

	Binary(const string& a_bin)
	{
		mBinary = a_bin;
		isSigned = false;
	}

	Binary(const Binary& a_bin)
	{
		mBinary = a_bin.mBinary;
		isSigned = false;
	}

	Binary operator+(const Binary& rhs)
	{
		string result;
		string lhs = this->mBinary;
		string right = rhs.mBinary;
		int carry = 0;

		if (right.size() == 0)
			return Binary(this->mBinary);
		else if (this->mBinary.size() == 0)
		{
			return Binary(rhs);
		}

		//ensure padded same
		if (lhs.size() < right.size())
		{
			int pad = right.size() - lhs.size();
			lhs.insert(0, pad, '0');
		}
		else if (lhs.size() > right.size())
		{
			int pad = lhs.size() - right.size();
			right.insert(0, pad, '0');
		}

		for (int i = right.size() - 1; i >= 0; i--)
		{
			//convert char to int
			int n = lhs[i] - 48;
			int m = right[i] - 48;

			if (carry)
			{
				n += carry;
				carry = 0;
			}
			//do the add
			n += m;

			if (n > 1)
			{
				n = 1;
				carry = 1;
			}
			char digit = n + 48;

			result.insert(0, 1, digit);

		}
		return Binary(result);
	}

	Binary& operator=(const Binary& rhs)
	{
		mBinary = rhs.mBinary;
		isSigned = rhs.isSigned;
		return *this;
	}

	int GetDecimal()
	{
		Binary bin;
		bin = *this;
		//int end = 0;
		bool isNegative = (int)bin.mBinary[0] -48;
		if (bin.isSigned && isNegative)
		{
			//convert to actual binary value
			bin = Binary(bin.Flip());
			bin = bin + Binary("1");
			bin.isSigned = true;
			//remove sign bit
			bin.mBinary.erase(0, 1);
			//skip first digit
			//end++;
		}

		int result = 0;

		for (int i = bin.mBinary.size() - 1, count = 0; i >= 0; i--, count++)
		{
			//subtract 48 to convert from ascii to value
			int n = bin.mBinary[i] - 48;
			result += n * pow(2, count);
		}
		if (bin.isSigned && isNegative)
		{
			result *= -1;
		}
		return result;
	}

	string Flip()
	{
		string result = "";
		Binary bin = *this;
		for (int i = 0; i < bin.mBinary.size(); i++)
		{
			char n = '0';
			if (bin.mBinary[i] == '0')
				n = '1';
			result.push_back(n);
		}
		return result;
	}


};

void main()
{
	Binary bin2("11111111");
	bin2.isSigned = false;

	int r = bin2.GetDecimal();

	cout << bin2.mBinary << " => " << r;
	//system("pause");

}

int BinToDec(bool isSigned, string& bin)
{

	if (isSigned)
	{
		//convert to actual binary value


	}

	int result = 0;
	for (int i = bin.size() - 1, count = 0; i >= 0; i--, count++)
	{
		//subtract 48 to convert from ascii to value
		int n = bin[i] - 48;
		result += n * pow(2, count);
	}
	return result;
}

/*
divide method
*/
void NumberConvert(const int numToConvert, const int radix, string& result)
{
	//check if zero radix so don't divide by zero
	if (radix == 0)
	{
		result = "1";
		return;
	}

	//use a stack because we are working from back to front
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