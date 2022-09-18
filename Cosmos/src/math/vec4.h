/* VECTOR 4D IMPLEMENTATION */
#pragma once

namespace Cosmos
{
	namespace Cml
	{
		struct Vec4
		{
			float X = 0.0f, Y = 0.0f, Z = 0.0f, W = 0.0f;

			Vec4() = default;
			Vec4(const float& x, const float& y, const float& z, const float& w);

			Vec4& Add(const Vec4& other);
			Vec4& Sub(const Vec4& other);
			Vec4& Mul(const Vec4& other);
			Vec4& Div(const Vec4& other);

			std::string ToString() const;

			friend Vec4& operator+(Vec4& left, const Vec4& right) { return left.Add(right); }
			friend Vec4& operator-(Vec4& left, const Vec4& right) { return left.Sub(right); }
			friend Vec4& operator*(Vec4& left, const Vec4& right) { return left.Mul(right); }
			friend Vec4& operator/(Vec4& left, const Vec4& right) { return left.Div(right); }

			Vec4& operator+=(const Vec4& other) { return Add(other); }
			Vec4& operator-=(const Vec4& other) { return Sub(other); }
			Vec4& operator*=(const Vec4& other) { return Mul(other); }
			Vec4& operator/=(const Vec4& other) { return Div(other); }

			bool operator==(const Vec4& other) const { return X == other.X && Y == other.Y && Z == other.Z && W == other.W; }
			bool operator!=(const Vec4& other) const { return !(*this == other); }
		};
	}
}