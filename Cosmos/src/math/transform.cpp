#include <cspch.h>
#include "math/transform.h"

namespace Cosmos
{
	namespace cml
	{
		const mat4 identity()
		{
			return mat4(1.0f);
		}

		mat4 orthographic(float left, float right, float top, float bottom, float near, float far)
		{
			mat4 r(1.0f);

			r.m[0 + 0 * 4] = 2.0f / (right - left);
			r.m[1 + 1 * 4] = 2.0f / (top - bottom);
			r.m[2 + 2 * 4] = 2.0f / (far - near);

			r.m[0 + 3 * 4] = -(right + left) / (right - left);
			r.m[1 + 3 * 4] = -(top + bottom) / (top - bottom);
			r.m[2 + 3 * 4] = -(far + near) / (far - near);

			return r;
		}

		mat4 perspective(float fov, float aspectRatio, float near, float far)
		{
			mat4 r(1.0f);

			float fovRad, a, b, c, d;
			fovRad = tan(radians(fov / 2.0f));
			a = 1.0f / (aspectRatio * fovRad);
			b = 1.0f / fovRad;
			c = -((far + near) / (far - near));
			d = -((2.0f * far * near) / (far - near));

			r.m[0 + 0 * 4] = a; 
			r.m[1 + 1 * 4] = b; 
			r.m[2 + 2 * 4] = c; 
			r.m[3 + 2 * 4] = -1.0f; 
			r.m[2 + 3 * 4] = d;

			return r;
		}

		mat4 translate(mat4& m, vec3 translation)
		{
			mat4 r(1.0f);

			r.m[0 + 3 * 4] = translation.x;
			r.m[1 + 3 * 4] = translation.y;
			r.m[2 + 3 * 4] = translation.z;

			return r * m;
		}

		mat4 rotate(mat4& m, float angle, vec3 axis)
		{
			mat4 r(1.0f);

			float rd, c, s, d, x, y, z;
			rd = radians(angle);
			c = cos(rd); s = sin(rd);
			d = 1.0f - c;
			x = axis.x; y = axis.y; z = axis.z;

			r.m[0 + 0 * 4] = x * x * d + c;
			r.m[0 + 1 * 4] = y * x * d + z * s; 
			r.m[0 + 2 * 4] = x * z * d - y * s;

			r.m[1 + 0 * 4] = x * y * d - z * s;
			r.m[1 + 1 * 4] = y * y * d + c; 
			r.m[1 + 2 * 4] = y * z * d + x * s;

			r.m[2 + 0 * 4] = x * z * d + y * s; 
			r.m[2 + 1 * 4] = y * z * d - x * s; 
			r.m[2 + 2 * 4] = z * z * d + c;

			return r * m;
		}

		mat4 scale(mat4& m, vec3 scale)
		{
			mat4 r(1.0f);

			m.m[0 + 0 * 4] = scale.x;
			m.m[1 + 1 * 4] = scale.y;
			m.m[2 + 2 * 4] = scale.z;

			return r * m;
		}
	}
}