#include "UnionIntSet.h"


UnionIntSet::UnionIntSet()
{
	size = 0; 
	count = 0; 
	arrayOfIntsOne = new int[0];
	arrayOfIntsTwo = new int[0];
}

UnionIntSet::~UnionIntSet()
{
	delete[] arrayOfIntsOne;
	delete[] arrayOfIntsTwo;
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
	BasicIntSet printSet;
	for (int i = 0; i < size_one; i++)
	{
		printSet.Add(arrayOfIntsOne[i]);
	}
	for (int i = 0; i < size_two; i++)
	{
		printSet.Add(arrayOfIntsTwo[i]);
	}

	return printSet.ToString();
}

void UnionIntSet::setSet1(int* Array, int size)
{
	arrayOfIntsOne = new int[size];
	memcpy(arrayOfIntsOne, Array, sizeof(int*)*size);
	this->size_one = size;
}

void UnionIntSet::setSet2(int* Array, int size)
{
	arrayOfIntsTwo = new int[size];
	memcpy(arrayOfIntsTwo, Array, size);
	this->size_two = size;
}