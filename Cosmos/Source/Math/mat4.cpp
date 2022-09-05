#include <cspch.h>
#include "Math/mat4.h"

namespace Cosmos
{
	csm::mat4::mat4(float d)
	{
		m[0 + 0 * 4] = d; m[1 + 1 * 4] = d; m[2 + 2 * 4] = d; m[3 + 3 * 4] = d;
	}

	csm::mat4& csm::mat4::multiply(const mat4& other)
	{
		float data[16];
		for (int row = 0; row < 4; ++row)
		{
			for (int col = 0; col < 4; ++col)
			{
				float sum = 0.0f;
				for (int e = 0; e < 4; ++e) sum += m[e + row * 4] * other.m[col + e * 4];
				data[col + row * 4] = sum;
			}
		}
		memcpy(m, data, sizeof(float) * 16);
		return *this;
	}

	csm::mat4 csm::identity()
	{
		return mat4(1.0f);
	}

	csm::mat4 csm::orthographic(float left, float right, float top, float bottom, float near, float far)
	{
		mat4 m = identity();

		m.m[0 + 0 * 4] = 2.0f / (right - left);
		m.m[1 + 1 * 4] = 2.0f / (top - bottom);
		m.m[2 + 2 * 4] = 2.0f / (far - near);

		m.m[0 + 3 * 4] = -((right + left) / (right - left));
		m.m[1 + 3 * 4] = -((top + bottom) / (top - bottom));
		m.m[2 + 3 * 4] = -((far + near) / (far - near));

		return m;
	}

	csm::mat4 csm::perspective(float fov, float aspectRatio, float near, float far)
	{
		mat4 m = identity();

		float fovRad, a, b, c, d;
		fovRad = tan(radians(fov / 2.0f));
		a = 1.0f / (aspectRatio * fovRad);
		b = 1.0f / fovRad;
		c = -((far + near) / (far - near));
		d = -((2.0f * far * near) / (far - near));

		m.m[0 + 0 * 4] = a; m.m[1 + 1 * 4] = b; m.m[2 + 2 * 4] = c; m.m[3 + 2 * 4] = -1.0f; m.m[2 + 3 * 4] = d;

		return m;
	}

	void csm::translate(mat4& m, const vec3& translation)
	{
		m.m[0 + 3 * 4] = translation.x; m.m[1 + 3 * 4] = translation.y; m.m[2 + 3 * 4] = translation.z;
	}

	void csm::rotate(mat4& m, float angle, const vec3& axis)
	{
		float r, c, s, omc, x, y, z;
		r = radians(angle);
		c = cos(r); s = sin(r);
		omc = 1.0f - c;
		x = axis.x; y = axis.y; z = axis.z;

		m.m[0 + 0 * 4] = x * omc + c; m.m[1 + 0 * 4] = y * x * omc + z * s; m.m[2 + 0 * 4] = x * z * omc - y * s;
		m.m[0 + 1 * 4] = x * y * omc - z * s; m.m[1 + 1 * 4] = y * omc + c; m.m[2 + 1 * 4] = y * z * omc + x * s;
		m.m[0 + 2 * 4] = x * z * omc + y * s; m.m[1 + 2 * 4] = x * z * omc - x * s; m.m[2 + 2 * 4] = z * omc + c;
	}

	void csm::scale(mat4& m, const vec3& scale)
	{
		m.m[0 + 0 * 4] = scale.x; m.m[1 + 1 * 4] = scale.y; m.m[2 + 2 * 4] = scale.z;
	}

	float csm::radians(float degrees)
	{
		return degrees * (pi / 180.0f);
	}
}