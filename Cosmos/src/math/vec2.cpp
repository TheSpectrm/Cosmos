#include <cspch.h>
#include "math/vec2.h"

namespace Cosmos
{
	namespace cml
	{
		vec2::vec2(const float& x, const float& y)
		{
			this->x = x, this->y = y;
		}

		vec2& vec2::add(const vec2& other)
		{
			x += other.x, y += other.y;
			return *this;
		}

		vec2& vec2::sub(const vec2& other)
		{
			x -= other.x, y -= other.y;
			return *this;
		}

		vec2& vec2::mul(const vec2& other)
		{
			x *= other.x, y *= other.y;
			return *this;
		}

		vec2& vec2::div(const vec2& other)
		{
			x /= other.x, y /= other.y;
			return *this;
		}

		std::string vec2::tostr() const
		{
			std::stringstream ss;
			ss << "vec2(" << x << ", " << y << ")";
			return ss.str();
		}
	}
}