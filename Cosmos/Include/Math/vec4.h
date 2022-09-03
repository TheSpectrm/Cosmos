#pragma once

#include <cspch.h>
#include "Core/Logger.h"

namespace Cosmos
{
	struct vec4
	{
		float x, y, z, w;

		vec4();
		vec4(const float& x, const float& y, const float& z, const float& w);

		vec4& Add(const vec4& other);
		vec4& Sub(const vec4& other);
		vec4& Mul(const vec4& other);
		vec4& Div(const vec4& other);

		std::string ToString() const;

		friend vec4& operator+(vec4& left, const vec4& right) { return left.Add(right); }
		friend vec4& operator-(vec4& left, const vec4& right) { return left.Sub(right); }
		friend vec4& operator*(vec4& left, const vec4& right) { return left.Mul(right); }
		friend vec4& operator/(vec4& left, const vec4& right) { return left.Div(right); }

		vec4& operator+=(const vec4& other) { return Add(other); }
		vec4& operator-=(const vec4& other) { return Sub(other); }
		vec4& operator*=(const vec4& other) { return Mul(other); }
		vec4& operator/=(const vec4& other) { return Div(other); }

		bool operator==(const vec4& other) const { return x == other.x && y == other.y && z == other.z && w == other.w; }
		bool operator!=(const vec4& other) const { return !(*this == other); }
	};
}