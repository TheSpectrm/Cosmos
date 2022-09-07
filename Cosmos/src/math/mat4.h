#pragma once

#include "math/vec3.h"

namespace Cosmos
{
	namespace cml
	{
		const float pi = 3.14159f;

		struct mat4
		{
			float m[16] = {
				0.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 0.0f,
			};

			mat4() = default;
			mat4(float d);

			mat4& multiply(const mat4& other);

			friend mat4& operator*(mat4& left, const mat4& right) { return left.multiply(right); }
			mat4& operator*=(const mat4& other) { return multiply(other); }
		};

		const mat4 identity();

		mat4 orthographic(float left, float right, float top, float bottom, float near, float far);
		mat4 perspective(float fov, float aspectRatio, float near, float far);

		void translate(mat4& m, vec3 translation);
		void rotate(mat4& m, float angle, vec3 axis);
		void scale(mat4&, vec3 scale);

		float radians(float degrees);
	}
}