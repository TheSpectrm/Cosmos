#include <cspch.h>
#include "Math/vec3.h"

namespace Cosmos
{
	vec3::vec3()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}

	vec3::vec3(const float& x, const float& y, const float& z)
	{ 
		this->x = x;
		this->y = y;
		this->z = z;
	}

	vec3& vec3::Add(const vec3& other)
	{
		x += other.x; y += other.y; z += other.z;
		return *this;
	}

	vec3& vec3::Sub(const vec3& other)
	{
		x -= other.x; y -= other.y; z -= other.z;
		return *this;
	}

	vec3& vec3::Mul(const vec3& other)
	{
		x *= other.x; y *= other.y; z *= other.z;
		return *this;
	}

	vec3& vec3::Div(const vec3& other)
	{
		x /= other.x; y /= other.y; z /= other.z;
		return *this;
	}

	std::string vec3::ToString() const
	{
		std::stringstream ss;
		ss << "vec3(" << x << ", " << y << ", " << z << ")";
		return ss.str();
	}
}