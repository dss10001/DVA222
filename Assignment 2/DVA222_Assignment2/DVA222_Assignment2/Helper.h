#pragma once
#include <math.h>

namespace Helper
{
	double GetVectorLength(Vector vec)
	{
		return sqrt(vec.X * vec.X + vec.Y * vec.Y);
	}

	Vector NormalizeVector(Vector vec)
	{
		double length = GetVectorLength(vec);

		if (length != 0)
		{
			vec.X = vec.X / length;
			vec.Y = vec.Y / length;
		}
		return vec;
	}
}