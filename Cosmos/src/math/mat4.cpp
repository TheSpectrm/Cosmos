#include <cspch.h>
#include "math/mat4.h"

namespace Cosmos
{
	namespace Cml
	{
		Mat4::Mat4()
		{
			memset(M, 0, sizeof(float) * 16);
		}

		Mat4::Mat4(const float& d)
		{
			memset(M, 0, sizeof(float) * 16);
			M[0 + 0 * 4] = d; M[1 + 1 * 4] = d; M[2 + 2 * 4] = d; M[3 + 3 * 4] = d;
		}

		Mat4& Mat4::Multiply(const Mat4& other)
		{
			for (int row = 0; row < 4; ++row)
			{
				for (int col = 0; col < 4; ++col)
				{
					float sum = 0.0f;
					for (int e = 0; e < 4; ++e) sum += M[col + e * 4] * other.M[e + row * 4];
					M[col + row * 4] = sum;
				}
			}

			return *this;
		}
	}
}