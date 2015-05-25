#include "BasicIntSet.h"


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
	UnionIntSet *_union = new UnionIntSet();
	int* s1 = new int[getSetNumOfElements()];
	int* s2 = new int[other.getSetNumOfElements()];
	// copy set information.
	cpySetArray(s1);
	other.cpySetArray(s2);
	// set 'set' information
	_union->setSet1(s1, getSetNumOfElements());
	_union->setSet2(s2, other.getSetNumOfElements());
	
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

