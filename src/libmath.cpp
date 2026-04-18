#include "libmath.h"

namespace libmath
{
    int S_OK = 0;
    int S_FALSE = -1;

    int addition(const int a, int b)
    {
	return a + b;
    }

    int subtraction(int a, int b)
    {
	return a - b;
    }

    int multiplication(int a, int b)
    {
	return a * b;
    }

    int division(int a, int b, int& c)
    {
	if (!b)
	    return S_FALSE;

	c = a / b;
	    return S_OK;
    }

    int power(const int& a, const int& pow)
    {
	int res = 1;
	for (int i = 0; i < pow; ++i)
	{
	    res = res * a;
	}
	return res;
    }

    int factorial(int n)
    {
	if (n <= 1)
	{
	    return 1;
	}

	int result = 1;
	for (int i = 2; i <= n; ++i)
	{
	    result *= i;
	}
	   return result;
       }
}
