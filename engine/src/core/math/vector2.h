#pragma once

#include <cstdio>
#include "func.h"

#include <ostream>


namespace Engine{

	class Vector2i;

	class Vector2 {
	public:

		union {
			struct {
				union {
					float x;
					float width;
				};

				union {
					float y;
					float height;
				};
			};

			float coord[2] = { 0 };
		};

		inline float &operator[](int _idx) {
			/// warn: unsafe operation, need to check if it's _idx < 2
			return coord[_idx];
		}

		float first() const { return coord[0]; }
		float second() const { return coord[1]; }

		float length() const { return Math::sqrt(x * x + y * y); }
		float distance_to(const Vector2& _vector2) const {
			return Math::sqrt(Math::pow((x - _vector2.x), 2) + Math::pow((y - _vector2.y), 2));
		}

		Vector2 floor() const;
		Vector2 ceil() const;
		Vector2 round() const;

		bool operator==(const Vector2 &_vector2) const;
		bool operator!=(const Vector2 &_vector2) const;

		Vector2 operator*(const float &_num) const;
		void operator*=(const float& _num);

		Vector2 operator/(const float& _num) const;
		void operator/=(const float& _num);

		inline Vector2 operator+(const Vector2& _vector2) const;
		inline Vector2 operator-(const Vector2& _vector2) const;
		inline Vector2 operator*(const Vector2& _vector2) const;
		inline Vector2 operator/(const Vector2& _vector2) const;

		//operator Vector2i() const;

		inline Vector2() {}
		inline Vector2(const float _x, const float _y) 
		{
			x = _x;
			y = _y;
		}

		friend std::ostream& operator<<(std::ostream& ofs, const Vector2 &_vector2) {
			return ofs << '(' << _vector2.x << ", " << _vector2.y << ')';
		}

	};	//class Vector2

	inline Vector2 floor(Vector2 _vector2) { return _vector2.floor(); }

}	//namespace Engine

