#include <cspch.h>
#include "math/mat4.h"

namespace Cosmos
{
	namespace cml
	{
		mat4::mat4()
		{
			memset(m, 0, sizeof(float) * 16);
		}

		mat4::mat4(float d)
		{
			memset(m, 0, sizeof(float) * 16);
			m[0 + 0 * 4] = d; m[1 + 1 * 4] = d; m[2 + 2 * 4] = d; m[3 + 3 * 4] = d;
		}

		mat4& mat4::multiply(const mat4& other)
		{
			for (int row = 0; row < 4; ++row)
			{
				for (int col = 0; col < 4; ++col)
				{
					float sum = 0.0f;
					for (int e = 0; e < 4; ++e) 
						sum += m[col + e * 4] * other.m[e + row * 4];

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