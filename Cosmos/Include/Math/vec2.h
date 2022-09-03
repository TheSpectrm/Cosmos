#pragma once

#include <cspch.h>
#include "Core/Logger.h"

namespace Cosmos
{
	struct vec2
	{
		float x, y;

		vec2();
		vec2(const float& x, const float& y);

		vec2& Add(const vec2& other);
		vec2& Sub(const vec2& other);
		vec2& Mul(const vec2& other);
		vec2& Div(const vec2& other);

		std::string ToString() const;

		friend vec2& operator+(vec2& left, const vec2& right) { return left.Add(right); }
		friend vec2& operator-(vec2& left, const vec2& right) { return left.Sub(right); }
		friend vec2& operator*(vec2& left, const vec2& right) { return left.Mul(right); }
		friend vec2& operator/(vec2& left, const vec2& right) { return left.Div(right); }

		vec2& operator+=(const vec2& other) { return Add(other); }
		vec2& operator-=(const vec2& other) { return Sub(other); }
		vec2& operator*=(const vec2& other) { return Mul(other); }
		vec2& operator/=(const vec2& other) { return Div(other); }

		bool operator==(const vec2& other) const { return x == other.x && y == other.y; }
		bool operator!=(const vec2& other) const { return !(*this == other); }
	};
}