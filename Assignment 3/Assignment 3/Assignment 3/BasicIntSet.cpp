#include "BasicIntSet.h"


BasicIntSet::BasicIntSet() : IIntSet()
{
	size = INITIAL_SIZE;
	count = 0;
	SetOfInts = new int[size];
}

BasicIntSet::~BasicIntSet()
{
	delete[] SetOfInts;
}

bool BasicIntSet::Contains(int elem)
{
	for (int i = 0; i < size; i++)
	{
		if (elem == SetOfInts[i])
		{
			return true;
		}
	}
	return false;
}

void BasicIntSet::Add(int elem)
{
	if (!Contains(elem))
	{
		if (count >= size)
		{
			ExtendArray(EXTEND_VALUE);
		}
		SetOfInts[count] = elem;
		count++;
	}
}

void BasicIntSet::ExtendArray(int value)
{
	int* tmpArray = new int[size + value];
	
	_memccpy(tmpArray, SetOfInts, count, size);

	delete[] SetOfInts;
	size = size + value;

	*SetOfInts = *tmpArray;
}

IIntSet* BasicIntSet::Union(IIntSet &other)
{
	// create objects, bad solution.
	UnionIntSet *_union = new UnionIntSet(this,&other);
	
	return _union;
}

string BasicIntSet::ToString()
{
	std::ostringstream oss;
	oss << "Int set: { ";
	for (int i = 0; i < count; i++)
	{
		oss << SetOfInts[i] << ", ";
	}
	oss << "}";
	return oss.str();
}

