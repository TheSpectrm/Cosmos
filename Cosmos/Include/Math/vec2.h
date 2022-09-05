#pragma once

#include <cspch.h>

namespace Cosmos
{
	namespace csm
	{
		struct vec2
		{
			float x = 0.0f, y = 0.0f;

			vec2() = default;
			vec2(const float& x, const float& y);

			vec2& add(const vec2& other);
			vec2& sub(const vec2& other);
			vec2& mul(const vec2& other);
			vec2& div(const vec2& other);

			std::string tostr() const;

			friend vec2& operator+(vec2& left, const vec2& right) { return left.add(right); }
			friend vec2& operator-(vec2& left, const vec2& right) { return left.sub(right); }
			friend vec2& operator*(vec2& left, const vec2& right) { return left.mul(right); }
			friend vec2& operator/(vec2& left, const vec2& right) { return left.div(right); }

			vec2& operator+=(const vec2& other) { return add(other); }
			vec2& operator-=(const vec2& other) { return sub(other); }
			vec2& operator*=(const vec2& other) { return mul(other); }
			vec2& operator/=(const vec2& other) { return div(other); }

			bool operator==(const vec2& other) const { return x == other.x && y == other.y; }
			bool operator!=(const vec2& other) const { return !(*this == other); }
		};
	}
}