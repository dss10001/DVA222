#include "BasicIntSet.h"
#include "IntervalSet.h"
#include "UnionIntSet.h"
#include <string>
#include <iostream>
#include <sstream>
#define INITIAL_SIZE 100
#define EXTEND_VALUE 100


BasicIntSet::BasicIntSet()
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
		SetOfInts[count];
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
	throw "The method or operation is not implemented.";
}

char* BasicIntSet::ToString()
{
	std::ostringstream oss;
	oss << "Int set: { ";
	for (int i = 0; i < count; i++)
	{
		oss << SetOfInts[i] << ", ";
	}
	oss << "}";
	return (char*)oss.str().c_str();
}

