#pragma once

#include <cspch.h>

namespace Cosmos
{
	namespace csm
	{
		struct vec4
		{
			float x = 0.0f, y = 0.0f, z = 0.0f, w = 0.0f;

			vec4() = default;
			vec4(const float& x, const float& y, const float& z, const float& w);

			vec4& add(const vec4& other);
			vec4& sub(const vec4& other);
			vec4& mul(const vec4& other);
			vec4& div(const vec4& other);

			std::string tostr() const;

			friend vec4& operator+(vec4& left, const vec4& right) { return left.add(right); }
			friend vec4& operator-(vec4& left, const vec4& right) { return left.sub(right); }
			friend vec4& operator*(vec4& left, const vec4& right) { return left.mul(right); }
			friend vec4& operator/(vec4& left, const vec4& right) { return left.div(right); }

			vec4& operator+=(const vec4& other) { return add(other); }
			vec4& operator-=(const vec4& other) { return sub(other); }
			vec4& operator*=(const vec4& other) { return mul(other); }
			vec4& operator/=(const vec4& other) { return div(other); }

			bool operator==(const vec4& other) const { return x == other.x && y == other.y && z == other.z && w == other.w; }
			bool operator!=(const vec4& other) const { return !(*this == other); }
		};
	}
}