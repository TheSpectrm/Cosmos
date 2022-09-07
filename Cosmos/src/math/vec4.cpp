#include <cspch.h>
#include "Math/vec4.h"

namespace Cosmos
{
	namespace cml
	{
		vec4::vec4(const float& x, const float& y, const float& z, const float& w)
		{
			this->x = x, this->y = y, this->z = z, this->w = w;
		}

		vec4& vec4::add(const vec4& other)
		{
			x += other.x, y += other.y, z += other.z, w += other.w;
			return *this;
		}

		vec4& vec4::sub(const vec4& other)
		{
			x -= other.x, y -= other.y, z -= other.z, w -= other.w;
			return *this;
		}

		vec4& vec4::mul(const vec4& other)
		{
			x *= other.x, y *= other.y, z *= other.z, w *= other.w;
			return *this;
		}

		vec4& vec4::div(const vec4& other)
		{
			x /= other.x, y /= other.y, z /= other.z, w /= other.w;
			return *this;
		}

		std::string vec4::tostr() const
		{
			std::stringstream ss;
			ss << "vec4(" << x << ", " << y << ", " << z << ", " << w << ")";
			return ss.str();
		}
	}
}