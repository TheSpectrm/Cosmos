#pragma once

#include "math/vec3.h"

namespace Cosmos
{
	namespace cml
	{
		const float pi = 3.14159f;

		struct mat4
		{
			float m[16];

			mat4();
			mat4(float d);

			mat4& multiply(const mat4& other);

			friend mat4& operator*(mat4& left, const mat4& right) { return left.multiply(right); }
			mat4& operator*=(const mat4& other) { return multiply(other); }
		};

		float radians(float degrees);
	}
}