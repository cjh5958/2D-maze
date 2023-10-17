#pragma once

#ifndef TEST_MATH_FUNC_H
#define TEST_MATH_FUNC_H

#include "test.h"

class TEST_MATH_FUNC
{
public:
	static int test_math_funs_main(void)
	{
		double input = -44.11223;
		input = Math::abs(input);
		cout << input << endl;
		return 0;
	}
};

#endif