#pragma once
#include <limits.h>

namespace libmath
{
    enum Status
    {
	   S_OK = 0,
	   S_FALSE = -1,
	   S_OVERFLOW = -2
    };

    inline int addition(const int a, int b)
    {
	if ((b > 0) && (a > INT_MAX - b))
	{
	    return S_OVERFLOW;
	}
	if ((b < 0) && (a < INT_MIN - b))
	{
	    return S_OVERFLOW;
	}
	return a + b;
    }

    inline int subtraction(int a, int b)
    {
	if ((b < 0) && (a > INT_MAX + b))
	{
	    return S_OVERFLOW;
	}
	if ((b > 0) && (a < INT_MIN + b))
	{
	    return S_OVERFLOW;
	}
	return a - b;
    }

    inline int multiplication(int a, int b)
    {
	if (a > 0)
	{
	    if (b > 0)
	    {
		if (a > INT_MAX / b)
		    return S_OVERFLOW;
	    }
	    else
	    {
		if (b < INT_MIN / a)
		    return S_OVERFLOW;
	    }
	}
	else
	{
	    if (b > 0)
	    {
		if (a < INT_MIN / b)
		    return S_OVERFLOW;
	    }
	    else
	    {
		if (a != 0 && b < INT_MAX / a)
		    return S_OVERFLOW;
	    }
	}
	return a * b;
    }

    inline int division(int a, int b, int& c)
    {
	if (!b)
	{
	    return S_FALSE;
	}

	if (a == INT_MIN && b == -1)
	{
	    return S_OVERFLOW;
	}

	c = a / b;
	return S_OK;
    }

    inline int power(const int& a, const int& pow)
    {
	if (pow < 0)
	{
	    return S_FALSE;
	}

	if (pow == 0)
	{
	    return 1;
	}

	int res = 1;
	for (int i = 0; i < pow; ++i)
	{
	    if (res > INT_MAX / a)
	    {
		return S_OVERFLOW;
	    }
	    res = res * a;
	}
	return res;
    }

    inline int factorial(int n)
    {
	if (n < 0)
	{
	    return S_FALSE;
	}

	if (n > 12)
	{
	    return S_OVERFLOW;
	}

	if (n <= 1)
	{
	    return 1;
	}

	return n * factorial(n - 1);
    }
}
