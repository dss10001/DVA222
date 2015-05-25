#include "UnionIntSet.h"
#include <stdarg.h>
using std::copy;


UnionIntSet::UnionIntSet(const UnionIntSet &other)
{	
	/*memcpy(this->arrayOfIntsOne, other.arrayOfIntsOne, 4*other.size_one);
	memcpy(this->arrayOfIntsTwo, other.arrayOfIntsTwo, 4*other.size_two);
	count = other.count;
	this->size_one = other.size_one;
	this->size_two = other.size_two;
*/
}

UnionIntSet::UnionIntSet(IIntSet *set1, IIntSet *set2) 
{
	*one = *set1;
	*two = *set2;
	size = INITIAL_SIZE;
	count = 0;
	SetsOfInts = new int[size];
}


UnionIntSet::~UnionIntSet()
{
	delete[] SetsOfInts;
}

bool UnionIntSet::Contains(int elem)
{
	if (!one->Contains((elem) && !two->Contains(elem)))
	{
		for (int i = 0; i < size; i++)
		{
			if (elem == SetsOfInts[i])
			{
				return true;
			}
		}
		return false;
	}
	return true;
}


IIntSet* UnionIntSet::Union(IIntSet &other)
{
	UnionIntSet *_union = new UnionIntSet(this, &other);

	return _union;
}

string UnionIntSet::ToString()
{
	std::ostringstream oss;
	oss <<" { ";
	for (int i = 0; i < count; i++)
	{
		oss << SetsOfInts[i] << ", ";
	}
	oss << "}";
	string out = one->ToString().append(two->ToString().append(oss.str()));
	return out;
}



void UnionIntSet::ExtendArray(int value)
{
	int* tmpArray = new int[size + value];

	_memccpy(tmpArray, SetsOfInts, count, size);

	delete[] SetsOfInts;
	size = size + value;

	*SetsOfInts = *tmpArray;
}

void UnionIntSet::Add(int elem)
{
	if (!Contains(elem))
	{
		if (count >= size)
		{
			ExtendArray(EXTEND_VALUE);
		}
		SetsOfInts[count] = elem;
		count++;
	}
}

int UnionIntSet::getSetNumOfElements()
{
	throw std::logic_error("The method or operation is not implemented.");
}

//void UnionIntSet::setSet1(int* Array,int sizeArr)
//{
//	//int* tmpArray = new int[size];
//	if (!arrayOfIntsOne)
//	{
//		delete[] arrayOfIntsOne;
//	}
//	
//	memcpy(arrayOfIntsOne, Array, sizeof(int)*sizeArr);
//	
//	size_one = sizeArr;
//	size += size_one;
//	//*arrayOfIntsOne = *tmpArray;
//}

//void UnionIntSet::setSet2(int* Array, int sizeArr)
//{
//	if (!arrayOfIntsTwo)
//	{
//		delete[] arrayOfIntsTwo;
//	}
//
//	memcpy(arrayOfIntsTwo, Array, sizeof(int)*sizeArr);
//
//	size_two = sizeArr;
//	size += size_two;
//}