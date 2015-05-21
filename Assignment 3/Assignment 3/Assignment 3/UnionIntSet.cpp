#include "UnionIntSet.h"
#include <stdarg.h>
using std::copy;

UnionIntSet::UnionIntSet()
{
	size = 0; 
	count = 0; 
	arrayOfIntsOne = new int[0];
	arrayOfIntsTwo = new int[0];
	this->size_one = this->size_two = 0;
}

UnionIntSet::UnionIntSet(const UnionIntSet &other)
{	
	memcpy(this->arrayOfIntsOne, other.arrayOfIntsOne, 4*other.size_one);
	memcpy(this->arrayOfIntsTwo, other.arrayOfIntsTwo, 4*other.size_two);
	count = other.count;
	this->size_one = other.size_one;
	this->size_two = other.size_two;

}

UnionIntSet::~UnionIntSet()
{
	if (arrayOfIntsOne)
	{
		delete[] arrayOfIntsOne;
	}
	if (arrayOfIntsTwo)
	{
		delete[] arrayOfIntsTwo;
	}
	
	
}

void UnionIntSet::ExtendArray(int value)
{
	throw "The method or operation is not implemented.";
}

bool UnionIntSet::Contains(int elem)
{
	throw "The method or operation is not implemented.";
}

void UnionIntSet::Add(int elem)
{
	throw "The method or operation is not implemented.";
}

IIntSet* UnionIntSet::Union(IIntSet &other)
{
	throw "The method or operation is not implemented.";
}

char* UnionIntSet::ToString()
{
	/*BasicIntSet printSet;
	for (int i = 0; i < size_one; i++)
	{
		printSet.Add(arrayOfIntsOne[i]);
	}
	for (int i = 0; i < size_two; i++)
	{
		printSet.Add(arrayOfIntsTwo[i]);
	}

	return printSet.ToString();*/
	return NULL;
}

void UnionIntSet::setSet1(int* Array, int size)
{
	int* tmpArray = new int[size];
	memcpy(tmpArray, Array, sizeof(int)*size);
	delete[] arrayOfIntsOne;
	size_one = size;
	*arrayOfIntsOne = *tmpArray;
}

void UnionIntSet::setSet2(int* Array, int size)
{
	arrayOfIntsTwo = new int[size];
	memcpy(arrayOfIntsTwo, Array, size);
	this->size_two = size;
}