#pragma once

#include <cspch.h>

namespace Cosmos
{
	namespace csm
	{
		struct vec3
		{
			float x = 0.0f, y = 0.0f, z = 0.0f;

			vec3() = default;
			vec3(const float& x, const float& y, const float& z);

			vec3& add(const vec3& other);
			vec3& sub(const vec3& other);
			vec3& mul(const vec3& other);
			vec3& div(const vec3& other);

			std::string tostr() const;

			friend vec3& operator+(vec3& left, const vec3& right) { return left.add(right); }
			friend vec3& operator-(vec3& left, const vec3& right) { return left.sub(right); }
			friend vec3& operator*(vec3& left, const vec3& right) { return left.mul(right); }
			friend vec3& operator/(vec3& left, const vec3& right) { return left.div(right); }

			vec3& operator+=(const vec3& other) { return add(other); }
			vec3& operator-=(const vec3& other) { return sub(other); }
			vec3& operator*=(const vec3& other) { return mul(other); }
			vec3& operator/=(const vec3& other) { return div(other); }

			bool operator==(const vec3& other) const { return x == other.x && y == other.y && z == other.z; }
			bool operator!=(const vec3& other) const { return !(*this == other); }
		};
	}
}