#include <cspch.h>
#include "math/vec3.h"

namespace Cosmos
{
	namespace cml
	{
		vec3::vec3(const float& x, const float& y, const float& z)
		{
			this->x = x, this->y = y, this->z = z;
		}

		vec3& vec3::add(const vec3& other)
		{
			x += other.x, y += other.y, z += other.z;
			return *this;
		}

		vec3& vec3::sub(const vec3& other)
		{
			x -= other.x, y -= other.y, z -= other.z;
			return *this;
		}

		vec3& vec3::mul(const vec3& other)
		{
			x *= other.x, y *= other.y, z *= other.z;
			return *this;
		}

		vec3& vec3::div(const vec3& other)
		{
			x /= other.x, y /= other.y, z /= other.z;
			return *this;
		}

		std::string vec3::tostr() const
		{
			std::stringstream ss;
			ss << "vec3(" << x << ", " << y << ", " << z << ")";
			return ss.str();
		}
	}
}