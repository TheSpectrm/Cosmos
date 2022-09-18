#include <cspch.h>
#include "math/transform.h"

namespace Cosmos
{
	namespace Cml
	{
		Mat4 Identity()
		{
			return Mat4(1.0f);
		}

		Mat4 Orthographic(float left, float right, float top, float bottom, float near, float far)
		{
			Mat4 r(1.0f);

			r.M[0 + 0 * 4] = 2.0f / (right - left);
			r.M[1 + 1 * 4] = 2.0f / (top - bottom);
			r.M[2 + 2 * 4] = -2.0f / (far - near);

			r.M[0 + 3 * 4] = -(right + left) / (right - left);
			r.M[1 + 3 * 4] = -(top + bottom) / (top - bottom);
			r.M[2 + 3 * 4] = -(far + near) / (far - near);

			return r;
		}

		Mat4 Perspective(float fov, float aspectRatio, float near, float far)
		{
			Mat4 r(1.0f);

			float fovRad, a, b, c, d;
			fovRad = tan(Radians(fov / 2.0f));
			a = 1.0f / (aspectRatio * fovRad);
			b = 1.0f / fovRad;
			c = -(far + near) / (far - near);
			d = -(2.0f * far * near) / (far - near);

			r.M[0 + 0 * 4] = a; 
			r.M[1 + 1 * 4] = b; 
			r.M[2 + 2 * 4] = c; 
			r.M[3 + 2 * 4] = -1.0f; 
			r.M[2 + 3 * 4] = d;

			return r;
		}

		Mat4 Translate(Vec3 translation)
		{
			Mat4 r(1.0f);

			r.M[0 + 3 * 4] = translation.X;
			r.M[1 + 3 * 4] = translation.Y;
			r.M[2 + 3 * 4] = translation.Z;

			return r;
		}

		Mat4 Rotate(float angle, Vec3 axis)
		{
			Mat4 r(1.0f);

			float rd, c, s, d, x, y, z;
			rd = Radians(angle);
			c = cos(rd); s = sin(rd);
			d = 1.0f - c;
			x = axis.X; y = axis.Y; z = axis.Z;

			r.M[0 + 0 * 4] = x * d + c;
			r.M[1 + 0 * 4] = y * x * d + z * s; 
			r.M[2 + 0 * 4] = x * z * d - y * s;

			r.M[0 + 1 * 4] = x * y * d - z * s;
			r.M[1 + 1 * 4] = y * d + c; 
			r.M[2 + 1 * 4] = y * z * d + x * s;

			r.M[0 + 2 * 4] = x * z * d + y * s; 
			r.M[1 + 2 * 4] = y * z * d - x * s; 
			r.M[2 + 2 * 4] = z * d + c;

			return r;
		}

		Mat4 Scale(Vec3 scale)
		{
			Mat4 r(1.0f);

			r.M[0 + 0 * 4] = scale.X;
			r.M[1 + 1 * 4] = scale.Y;
			r.M[2 + 2 * 4] = scale.Z;

			return r;
		}

		float Radians(float degrees)
		{
			return degrees * (PI / 180.0f);
		}
	}
}