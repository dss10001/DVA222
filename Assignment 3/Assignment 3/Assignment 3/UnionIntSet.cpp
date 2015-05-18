#include "UnionIntSet.h"


UnionIntSet::UnionIntSet(int *arrayOfInts, int *arrayOfIntsTwo)
{
	std::copy(arrayOfInts, (int)(sizeof(arrayOfInts) / sizeof(*arrayOfInts)), arrayOfIntsOne);
}

UnionIntSet::~UnionIntSet()
{
}

void UnionIntSet::ExtendArray(int value)
{
	
}

bool UnionIntSet::Contains(int elem)
{
	
}

void UnionIntSet::Add(int elem)
{
	
}

IIntSet* UnionIntSet::Union(IIntSet &other)
{
	
}

char* UnionIntSet::ToString()
{
	
}
