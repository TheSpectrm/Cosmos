/* MATRIX 4X4 IMPLEMENTATION */
#pragma once

#include "math/vec3.h"

namespace Cosmos
{
	namespace Cml
	{
		const float PI = 3.14159f;

		struct Mat4
		{
			float M[16];

			Mat4();
			Mat4(const float& d);

			Mat4& Multiply(const Mat4& other);

			friend Mat4& operator*(Mat4& left, const Mat4& right) { return left.Multiply(right); }
			Mat4& operator*=(const Mat4& other) { return Multiply(other); }
		};
	}
}