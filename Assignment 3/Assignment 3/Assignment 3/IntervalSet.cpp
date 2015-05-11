#include "IntervalSet.h"


IntervalSet::IntervalSet()
{
	size = 0;
	intervalOfInts = new Interval[size];

}


IntervalSet::~IntervalSet()
{
	delete[]intervalOfInts;
}

bool IntervalSet::Contains(int elem)
{
	for (int i = 0; i < size;i++)
		if (elem >= intervalOfInts[i].intervalStart && elem <= intervalOfInts[i].intervalEnd)
			return true;
	return false;
}

void IntervalSet::Add(int elem)
{
	if (!Contains(elem))
	{
		if (size /*== count*/)
		{
			ExtendArray(1);
		}
		for (int i = 0; i < size; i++)
		{
			if (elem >= intervalOfInts[i].intervalStart && elem <= intervalOfInts[i].intervalEnd)
			{

			}
		}
		for (int i = 0; i < size; i++)
		{

		}
	}
}

void IntervalSet::ExtendArray(int value)
{
	Interval *newInterval = new Interval[size + value];
	memcpy(newInterval, intervalOfInts, sizeof(Interval));
	delete []intervalOfInts;
	intervalOfInts = newInterval;
}

IIntSet* IntervalSet::Union(IIntSet &other)
{
	throw "The method or operation is not implemented.";
}

char* IntervalSet::ToString()
{
	throw "The method or operation is not implemented.";
}
