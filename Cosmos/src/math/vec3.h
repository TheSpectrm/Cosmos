/* VECTOR 3D IMPLEMENTATION */
#pragma once

namespace Cosmos
{
	namespace Cml
	{
		struct Vec3
		{
			float X = 0.0f, Y = 0.0f, Z = 0.0f;

			Vec3() = default;
			Vec3(const float& x, const float& y, const float& z);

			Vec3& Add(const Vec3& other);
			Vec3& Sub(const Vec3& other);
			Vec3& Mul(const Vec3& other);
			Vec3& Div(const Vec3& other);

			std::string ToString() const;

			friend Vec3& operator+(Vec3& left, const Vec3& right) { return left.Add(right); }
			friend Vec3& operator-(Vec3& left, const Vec3& right) { return left.Sub(right); }
			friend Vec3& operator*(Vec3& left, const Vec3& right) { return left.Mul(right); }
			friend Vec3& operator/(Vec3& left, const Vec3& right) { return left.Div(right); }

			Vec3& operator+=(const Vec3& other) { return Add(other); }
			Vec3& operator-=(const Vec3& other) { return Sub(other); }
			Vec3& operator*=(const Vec3& other) { return Mul(other); }
			Vec3& operator/=(const Vec3& other) { return Div(other); }

			bool operator==(const Vec3& other) const { return X == other.X && Y == other.Y && Z == other.Z; }
			bool operator!=(const Vec3& other) const { return !(*this == other); }
		};
	}
}