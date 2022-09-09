#pragma once

#include "math/mat4.h"

namespace Cosmos
{
	namespace cml
	{
		const mat4 identity();

		mat4 orthographic(float left, float right, float top, float bottom, float near, float far);
		mat4 perspective(float fov, float aspectRatio, float near, float far);

		mat4 translate(mat4& m, vec3 translation);
		mat4 rotate(mat4& m, float angle, vec3 axis);
		mat4 scale(mat4&, vec3 scale);
	}
}