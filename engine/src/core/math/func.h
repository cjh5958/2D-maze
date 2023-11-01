#pragma once

#ifndef MATH_FUNC
#define MATH_FUNC

#include <math.h>
#include <cstdint>
#include <cfloat>

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

	static inline double asin(double _x) { return ::asin(_x); }
	static inline float asin(float _x) { return ::asinf(_x); }

	static inline double acos(double _x) { return ::acos(_x); }
	static inline float acos(float _x) { return ::acosf(_x); }

	static inline double atan(double _x) { return ::atan(_x); }
	static inline float atan(float _x) { return ::atanf(_x); }

	static inline double asinh(double _x) { return ::asinh(_x); }
	static inline float asinh(float _x) { return ::asinhf(_x); }

	static inline double acosh(double _x) { return ::acosh(_x); }
	static inline float acosh(float _x) { return ::acoshf(_x); }

	static inline double atanh(double _x) { return ::atanh(_x); }
	static inline float atanh(float _x) { return ::atanhf(_x); }

	static inline int abs(int g) { return ::abs(g); }
	static inline double abs(double g) { return ::fabs(g); }
	static inline float abs(float g) { return absf(g); }

	static inline double sqrt(double _x) { return ::sqrt(_x); }
	static inline float sqrt(float _x) { return ::sqrtf(_x); }

	static inline double fmod(double _x, double _y) { return ::fmod(_x, _y); }
	static inline float fmod(float _x, float _y) { return ::fmodf(_x, _y); }

	static inline double exp(double _x) { return ::exp(_x); }
	static inline float exp(float _x) { return ::expf(_x); }

	static inline double floor(double _x) { return ::floor(_x); }
	static inline float floor(float _x) { return ::floorf(_x); }

	static inline double ceil(double _x) { return ::ceil(_x); }
	static inline float ceil(float _x) { return ::ceilf(_x); }

	static inline double round(double _x) { return ::round(_x); }
	static inline float round(float _x) { return ::roundf(_x); }

	static inline double pow(double _x, double _y) { return ::pow(_x, _y); }
	static inline float pow(float _x, float _y) { return ::powf(_x, _y); }

	static inline double log(double _x) { return ::log(_x); }
	static inline float log(float _x) { return ::logf(_x); }

	static inline double log2(double _x) { return ::log2(_x); }
	static inline float log2(float _x) { return ::log2f(_x); }

	static inline bool isnan(double _val) {
#ifdef _MSC_VER
		return _isnan(_val);
#else
		return isnan(_val);
#endif
	}

	static inline bool isnan(float _val) {
#ifdef _MSC_VER
		return _isnan(_val);
#else
		return isnan(_val);
#endif
	}

private:

	static inline float absf(float _g) { 
		union {
			float f;
			uint32_t i;
		} u;

		u.f = _g;
		u.i &= 2147483647u;

		return u.f;
	}
 
};	//class Math


#endif	//MATH_FUNC
