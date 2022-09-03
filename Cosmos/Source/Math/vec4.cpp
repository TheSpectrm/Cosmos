#include <cspch.h>
#include "Math/vec4.h"

namespace Cosmos
{
	vec4::vec4()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
		w = 0.0f;
	}

	vec4::vec4(const float& x, const float& y, const float& z, const float& w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	vec4& vec4::Add(const vec4& other)
	{
		x += other.x; y += other.y; z += other.z; w += other.w;
		return *this;
	}

	vec4& vec4::Sub(const vec4& other)
	{
		x -= other.x; y -= other.y; z -= other.z; w -= other.w;
		return *this;
	}

	vec4& vec4::Mul(const vec4& other)
	{
		x *= other.x; y *= other.y; z *= other.z; w *= other.w;
		return *this;
	}

	vec4& vec4::Div(const vec4& other)
	{
		x /= other.x; y /= other.y; z /= other.z; w /= other.w;
		return *this;
	}

	std::string vec4::ToString() const
	{
		std::stringstream ss;
		ss << "vec4(" << x << ", " << y << ", " << z << ", " << w << ")";
		return ss.str();
	}
}