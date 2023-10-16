#pragma once

#ifndef MATH_FUNC
#define MATH_FUNC

#include <math.h>

#include "../typedefs.h"


class Math {

public:

	static inline double sin(double _x) { return ::sin(_x); }
	static inline float sin(float _x) { return ::sinf(_x); }

	static inline double cos(double _x) { return ::cos(_x); }
	static inline float cos(float _x) { return ::cosf(_x); }

	static inline double tan(double _x) { return ::tan(_x); }
	static inline float tan(float _x) { return ::tanf(_x); }

	static inline double sinh(double _x) { return ::sinh(_x); }
	static inline float sinh(float _x) { return ::sinhf(_x); }

	static inline double cosh(double _x) { return ::cosh(_x); }
	static inline float cosh(float _x) { return ::coshf(_x); }

	static inline double tanh(double _x) { return ::tanh(_x); }
	static inline float tanh(float _x) { return ::tanhf(_x); }

};	//class Math


#endif	//MATH_FUNC
