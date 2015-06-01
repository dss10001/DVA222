#include "UnionIntSet.h"


UnionIntSet::UnionIntSet(IIntSet *set1, IIntSet *set2) 
{
	size = INITIAL_SIZE;
	count = 0;

	IntSetA = set1;
	IntSetB = set2;
	ExtendedUnionSet = new int[size];
}

UnionIntSet::~UnionIntSet()
{
	delete[] ExtendedUnionSet;
}


bool UnionIntSet::Contains(int elem)
{
	if (!IntSetA->Contains((elem) && !IntSetB->Contains(elem)))
	{
		for (int i = 0; i < size; i++)
		{
			if (elem == ExtendedUnionSet[i])
			{
				return true;
			}
		}
		return false;
	}
	return true;
}

void UnionIntSet::Add(int elem)
{
	if (!Contains(elem))
	{
		if (count >= size)
		{
			ExtendArray(EXTEND_VALUE);
		}
		ExtendedUnionSet[count] = elem;
		count++;
	}
}

IIntSet* UnionIntSet::Union(IIntSet &other)
{
	UnionIntSet *_union = new UnionIntSet(this, &other);
	return _union;
}

string UnionIntSet::ToString()
{
	std::ostringstream oss;
	oss << "Extended Union Int-set { ";
	for (int i = 0; i < count; i++)
	{
		oss << ExtendedUnionSet[i] << ", ";
	}
	oss << "}\n";

	string out = IntSetA->ToString().append(IntSetB->ToString().append(oss.str()));
	return "Union { \n" + out + "}\n";
}

void UnionIntSet::ExtendArray(int value)
{
	int* tmpArray = new int[size + value];

	_memccpy(tmpArray, ExtendedUnionSet, count, size);

	delete[] ExtendedUnionSet;
	size = size + value;

	*ExtendedUnionSet = *tmpArray;
}

