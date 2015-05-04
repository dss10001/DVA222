#pragma once
#include "Structs.h"
#include <math.h>

namespace Helper
{
	static double GetVectorLength(Vector vec)
	{
		return sqrt(vec.X * vec.X + vec.Y * vec.Y);
	}

	static Vector NormalizeVector(Vector vec)
	{
		double length = GetVectorLength(vec);

		if (length != 0)
		{
			vec.X = vec.X / length;
			vec.Y = vec.Y / length;
		}
		return vec;
	}

	static bool IsInRange(double v1, double v2, double e)
	{
		if (e > v1 && e < v2)
		{
			return true;
		}
		return false;
	}

	static double clamp(double min, double max, double val)
	{
		if (val < min)
		{
			val = min;
		}
		if (val > max)
		{
			val = max;
		}

		return val;
	}
}