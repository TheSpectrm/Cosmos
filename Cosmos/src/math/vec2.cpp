#include <cspch.h>
#include "math/vec2.h"

namespace Cosmos
{
	namespace Cml
	{
		Vec2::Vec2(const float& x, const float& y)
		{
			this->X = x, this->Y = y;
		}

		Vec2& Vec2::Add(const Vec2& other)
		{
			X += other.X, Y += other.Y;
			return *this;
		}

		Vec2& Vec2::Sub(const Vec2& other)
		{
			X -= other.X, Y -= other.Y;
			return *this;
		}

		Vec2& Vec2::Mul(const Vec2& other)
		{
			X *= other.X, Y *= other.Y;
			return *this;
		}

		Vec2& Vec2::Div(const Vec2& other)
		{
			X /= other.X, Y /= other.Y;
			return *this;
		}

		std::string Vec2::ToString() const
		{
			std::stringstream ss;
			ss << "vec2(" << X << ", " << Y << ")";
			return ss.str();
		}
	}
}