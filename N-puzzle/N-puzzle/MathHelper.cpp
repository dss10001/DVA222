#include "MathHelper.h"


MathHelper::MathHelper()
{
}


MathHelper::~MathHelper()
{
}
bool MathHelper::isSquared(int number, int &length)
{
	if (number < 0)
		return false;
	int root(round(sqrt((double)number)));
	length = root;
	return number == root * root;
}