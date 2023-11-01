#include "vector2.h"
using namespace Engine;

Vector2 Vector2::floor() const
{
	Vector2 v = (*this);
	v.x = Math::floor(v.x);
	v.y = Math::floor(v.y);
	return v;
}

Vector2 Vector2::ceil() const
{
	Vector2 v = (*this);
	v.x = Math::ceil(v.x);
	v.y = Math::ceil(v.y);
	return v;
}

Vector2 Vector2::round() const
{
	Vector2 v = (*this);
	v.x = Math::round(v.x);
	v.y = Math::round(v.y);
	return v;
}

bool Vector2::operator==(const Vector2& _vector2) const
{
	return x==_vector2.x && y==_vector2.y ;
}

bool Vector2::operator!=(const Vector2& _vector2) const
{
	return x != _vector2.x || y != _vector2.y;
}

Vector2 Vector2::operator*(const float &_num) const
{
	return Vector2(x*_num, y*_num);
}

void Vector2::operator*=(const float &_num)
{
	x *= _num;
	y *= _num;
}

Vector2 Vector2::operator/(const float& _num) const
{
	return Vector2(x/_num, y/_num);
}

void Engine::Vector2::operator/=(const float& _num)
{
}

