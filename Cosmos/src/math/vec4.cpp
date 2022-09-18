#include <cspch.h>
#include "math/vec4.h"

namespace Cosmos
{
	namespace Cml
	{
		Vec4::Vec4(const float& x, const float& y, const float& z, const float& w)
		{
			this->X = x, this->Y = y, this->Z = z, this->W = w;
		}

		Vec4& Vec4::Add(const Vec4& other)
		{
			X += other.X, Y += other.Y, Z += other.Z, W += other.W;
			return *this;
		}

		Vec4& Vec4::Sub(const Vec4& other)
		{
			X -= other.X, Y -= other.Y, Z -= other.Z, W -= other.W;
			return *this;
		}

		Vec4& Vec4::Mul(const Vec4& other)
		{
			X *= other.X, Y *= other.Y, Z *= other.Z, W *= other.W;
			return *this;
		}

		Vec4& Vec4::Div(const Vec4& other)
		{
			X /= other.X, Y /= other.Y, Z /= other.Z, W /= other.W;
			return *this;
		}

		std::string Vec4::ToString() const
		{
			std::stringstream ss;
			ss << "vec4(" << X << ", " << Y << ", " << Z << ", " << W << ")";
			return ss.str();
		}
	}
}