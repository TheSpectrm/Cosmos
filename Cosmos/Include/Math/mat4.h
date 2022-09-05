#pragma once

#include "Math/vec3.h"

#if defined(near) && defined(far)
	#undef near
	#undef far
#endif

namespace Cosmos
{
	namespace csm
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

			friend mat4& operator*(mat4 left, const mat4& right) { return left.multiply(right); }
			mat4& operator*=(const mat4& other) { return multiply(other); }
		};

		mat4 identity();

		mat4 orthographic(float left, float right, float top, float bottom, float near, float far);
		mat4 perspective(float fov, float aspectRatio, float near, float far);

		void translate(mat4& m, const vec3& translation);
		void rotate(mat4& m, float angle, const vec3& axis);
		void scale(mat4&, const vec3& scale);

		float radians(float degrees);
	}
}