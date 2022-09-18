/* VECTOR 2D IMPLEMENTATION */
#pragma once

namespace Cosmos
{
	namespace Cml
	{
		struct Vec2
		{
			float X = 0.0f, Y = 0.0f;

			Vec2() = default;
			Vec2(const float& x, const float& y);

			Vec2& Add(const Vec2& other);
			Vec2& Sub(const Vec2& other);
			Vec2& Mul(const Vec2& other);
			Vec2& Div(const Vec2& other);

			std::string ToString() const;

			friend Vec2& operator+(Vec2& left, const Vec2& right) { return left.Add(right); }
			friend Vec2& operator-(Vec2& left, const Vec2& right) { return left.Sub(right); }
			friend Vec2& operator*(Vec2& left, const Vec2& right) { return left.Mul(right); }
			friend Vec2& operator/(Vec2& left, const Vec2& right) { return left.Div(right); }

			Vec2& operator+=(const Vec2& other) { return Add(other); }
			Vec2& operator-=(const Vec2& other) { return Sub(other); }
			Vec2& operator*=(const Vec2& other) { return Mul(other); }
			Vec2& operator/=(const Vec2& other) { return Div(other); }

			bool operator==(const Vec2& other) const { return X == other.X && Y == other.Y; }
			bool operator!=(const Vec2& other) const { return !(*this == other); }
		};
	}
}