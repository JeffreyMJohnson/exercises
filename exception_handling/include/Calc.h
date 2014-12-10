#ifndef _CALC_H_
#define _CALC_H_
#include <exception>
#include <iostream>

class BadInput
	: public std::exception
{
public:
	BadInput(){};
	~BadInput(){};
	const char* what()
	{
		return "Bad Input exception\n.";
	}
};

class Calc
{
public:
	Calc(){};
	~Calc(){};

	template<typename T>
	T Add(T lhs, T rhs)
	{
		//check if input valid
		//could fail if tyype not a number
		try
		{
			if (isValid(lhs, rhs))
				throw BadInput();
			else
				return lhs + rhs;
		}
		catch (BadInput e)
		{
			throw e;
		}
		catch (std::exception e)
		{
			throw e;
		}

	}

	template<typename T>
	T Sub(const T& lhs, const T& rhs)
	{
		//check if input valid
		//could fail if tyype not a number
		try
		{
			if (isValid(lhs, rhs))
				throw BadInput();
			else
				return lhs - rhs;
		}
		catch (BadInput e)
		{
			throw e;
		}
		catch (std::exception e)
		{
			throw e;
		}
	}

	template<typename T>
	T Mul(const T& lhs, const T& rhs)
	{
		//check if input valid
		//could fail if tyype not a number
		try
		{
			if (isValid(lhs, rhs))
				throw BadInput();
			else
				return lhs * rhs;
		}
		catch (BadInput e)
		{
			throw e;
		}
		catch (std::exception e)
		{
			throw e;
		}
	}

	template<typename T>
	T Div(const T& lhs, const T& rhs)
	{
		//check if input valid
		//could fail if tyype not a number
		try
		{
			if (isValid(lhs, rhs) || rhs == 0)
				throw BadInput();
			else
				return lhs / rhs;
		}
		catch (BadInput e)
		{
			throw e;
		}
		catch (std::exception e)
		{
			throw e;
		}
	}

private:
	template <typename T>
	bool isValid(T& lhs, T& rhs)
	{
		return lhs < -1000 || lhs > 1000 || rhs < -1000 || rhs > 1000;
	}
};


#endif
