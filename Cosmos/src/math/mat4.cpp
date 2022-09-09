#include <cspch.h>
#include "math/mat4.h"

namespace Cosmos
{
	namespace cml
	{
		mat4::mat4()
		{
			for (int i = 0; i < 16; ++i)
				m[i] = 0.0f;
		}

		mat4::mat4(float d)
		{
			for (int i = 0; i < 16; ++i)
				m[i] = 0.0f;

			m[0 + 0 * 4] = d; m[1 + 1 * 4] = d; m[2 + 2 * 4] = d; m[3 + 3 * 4] = d;
		}

		mat4& mat4::multiply(const mat4& other)
		{
			int row, col;
			for (row = 0; row < 4; ++row)
			{
				for (col = 0; col < 4; ++col)
				{
					float sum = 0.0f;
					for (int e = 0; e < 4; ++e) 
						sum += m[e + row * 4] * other.m[col + e * 4];

					m[col + row * 4] = sum;
				}
			}

			return *this;
		}

		float radians(float degrees)
		{
			return degrees * (pi / 180.0f);
		}
	}
}