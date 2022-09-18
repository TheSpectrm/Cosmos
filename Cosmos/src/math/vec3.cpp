#include <cspch.h>
#include "math/vec3.h"

namespace Cosmos
{
	namespace Cml
	{
		Vec3::Vec3(const float& x, const float& y, const float& z)
		{
			this->X = x, this->Y = y, this->Z = z;
		}

		Vec3& Vec3::Add(const Vec3& other)
		{
			X += other.X, Y += other.Y, Z += other.Z;
			return *this;
		}

		Vec3& Vec3::Sub(const Vec3& other)
		{
			X -= other.X, Y -= other.Y, Z -= other.Z;
			return *this;
		}

		Vec3& Vec3::Mul(const Vec3& other)
		{
			X *= other.X, Y *= other.Y, Z *= other.Z;
			return *this;
		}

		Vec3& Vec3::Div(const Vec3& other)
		{
			X /= other.X, Y /= other.Y, Z /= other.Z;
			return *this;
		}

		std::string Vec3::ToString() const
		{
			std::stringstream ss;
			ss << "vec3(" << X << ", " << Y << ", " << Z << ")";
			return ss.str();
		}
	}
}