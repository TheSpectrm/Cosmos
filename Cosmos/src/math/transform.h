/* MATRIX TRANSFORMATION IMPLEMENTATION */
#pragma once

#include "core/csdefs.h"
#include "math/mat4.h"

namespace Cosmos
{
	namespace Cml
	{
		Mat4 Identity();

		Mat4 Orthographic(float left, float right, float top, float bottom, float near, float far);
		Mat4 Perspective(float fov, float aspectRatio, float near, float far);

		Mat4 Translate(Vec3 translation);
		Mat4 Rotate(float angle, Vec3 axis);
		Mat4 Scale(Vec3 scale);

		float Radians(float degrees);
	}
}