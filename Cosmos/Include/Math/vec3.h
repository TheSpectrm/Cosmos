#pragma once

#include <cspch.h>
#include "Core/Logger.h"

namespace Cosmos
{
	struct vec3
	{
		float x, y, z;

		vec3();
		vec3(const float& x, const float& y, const float& z);

		vec3& Add(const vec3& other);
		vec3& Sub(const vec3& other);
		vec3& Mul(const vec3& other);
		vec3& Div(const vec3& other);

		std::string ToString() const;

		friend vec3& operator+(vec3& left, const vec3& right) { return left.Add(right); }
		friend vec3& operator-(vec3& left, const vec3& right) { return left.Sub(right); }
		friend vec3& operator*(vec3& left, const vec3& right) { return left.Mul(right); }
		friend vec3& operator/(vec3& left, const vec3& right) { return left.Div(right); }

		vec3& operator+=(const vec3& other) { return Add(other); }
		vec3& operator-=(const vec3& other) { return Sub(other); }
		vec3& operator*=(const vec3& other) { return Mul(other); }
		vec3& operator/=(const vec3& other) { return Div(other); }

		bool operator==(const vec3& other) const { return x == other.x && y == other.y && z == other.z; }
		bool operator!=(const vec3& other) const { return !(*this == other); }
	};
}