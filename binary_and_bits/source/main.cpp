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

	Binary(int decimal)
	{
		*this = DecToBin(false, decimal);
	}

	Binary(bool isSigned, int decimal)
	{
		*this = DecToBin(isSigned, decimal);
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
		isSigned = a_bin.isSigned;
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
		Binary b(result);
		b.isSigned = this->isSigned;
		return b;
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
		bool isNegative = (int)bin.mBinary[0] - 48;
		if (bin.isSigned && isNegative)
		{
			//convert to actual binary value
			bin = Binary(bin.GetFlip());
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

	string GetFlip()
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

	friend ostream& operator<<(ostream& out, const Binary& b)
	{
		out << "Binary [mBinary = \"" << b.mBinary << "\" isSigned = " << b.isSigned << "]";
		return out;
	}

	/*
	returns Binary object that has binary representation of given number to convert in signed or unsigned format
	as given by param. NOTE: number to convert must be positive if isSigned param is false, else returns a Binary = 0
	*/
	Binary DecToBin(bool isSigned, const int numToConvert)
	{

		Binary result;
		result.isSigned = isSigned;

		bool isNegative = numToConvert < 0;
		if (isNegative && !isSigned)
			return result;

		int n = numToConvert;
		//make positive for convert if needed
		if (isNegative)
			n *= -1;

		string binS = "";
		while (n > 0)
		{
			int i = n % 2;
			n = n / 2;
			binS.insert(0, 1, (char)(i + 48));
		}
		result.mBinary = binS;
		if (isSigned)
		{
			result.mBinary = result.GetFlip();
			result = result + Binary("1");

			//add sign bit
			if (isNegative)
			{
				result.mBinary.insert(0, 1, '1');
			}
			else
			{
				result.mBinary.insert(0, 1, '0');
			}
		}
		return result;

	}
};

/*
returns maximum power the given base can be without being larger than given test number
*/
int MaxPower(const int base, const int numToTest)
{
	int power = 0;
	int r = pow(base, power);
	while (r <= numToTest)
	{
		power++;
		r = pow(base, power);
	}
	return power - 1;
}

/*
return maximum multiple of given base to the given power that is less than or equal to given number to test
*/
int MaxMultiple(const int base, const int power, const int numToTest)
{
	int r = 0;
	while (r * pow(base, power) <= numToTest)
	{
		r++;
	}
	return r - 1;
}



void main()
{
	//int one = 0x01;
	//int two = 0x02;
	//int four = 0x04;
	//int eight = 0x08;
	//int sixteen = 0x10;
	//int thirty_two = 0x20;
	//int sixty_four = 0x30;

	//int n = 0x00;

	//n = n | two | eight;

	//cout << n << endl;

	//bool twoSet = n & two;
	//bool fourSet = n & four;

	//cout << "is two set? " << twoSet << endl;
	//cout << "is three set? " << fourSet << endl;

	unsigned int n = 0;
	unsigned int r = n & 1;
	cout << "n: " << n << endl;
	cout << "r: " << r << endl;
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