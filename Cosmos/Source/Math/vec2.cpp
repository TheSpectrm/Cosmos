#include <cspch.h>
#include "Math/vec2.h"

namespace Cosmos
{
	vec2::vec2()
	{
		x = 0.0f;
		y = 0.0f;
	}

	vec2::vec2(const float& x, const float& y)
	{
		this->x = x;
		this->y = y;
	}

	vec2& vec2::Add(const vec2& other)
	{
		x += other.x; y += other.y;
		return *this;
	}

	vec2& vec2::Sub(const vec2& other)
	{
		x -= other.x; y -= other.y;
		return *this;
	}

	vec2& vec2::Mul(const vec2& other)
	{
		x *= other.x; y *= other.y;
		return *this;
	}

	vec2& vec2::Div(const vec2& other)
	{
		x /= other.x; y /= other.y;
		return *this;
	}

	std::string vec2::ToString() const
	{
		std::stringstream ss;
		ss << "vec2(" << x << ", " << y << ")";
		return ss.str();
	}
}