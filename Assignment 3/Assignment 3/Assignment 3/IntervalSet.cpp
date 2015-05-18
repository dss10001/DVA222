#include "IntervalSet.h"


IntervalSet::IntervalSet()
{
	size = 0;
	count = 0;
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
		if (size == count)
		{
			ExtendArray(10);
		}

		for (int i = 0; i < count; i++)
		{
			if (elem >= intervalOfInts[i].intervalStart && elem <= intervalOfInts[i].intervalEnd)
			{

			}
			else if (elem >= intervalOfInts[i].intervalEnd && elem <= intervalOfInts[i + 1].intervalStart)
			{
				// left fusion
				// right fusion
				// double dusion
				// standAlone
			}
		}
		for (int i = 0; i < size; i++)
		{

		}
		count++;
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
	return NULL;

}

char* IntervalSet::ToString()
{
	return NULL;
}

void IntervalSet::cpySetArray(int* Dest)
{


	int index = 0,min,max;
	for (int i = 0; i < count; i++)
	{
		min = intervalOfInts[i].intervalStart;
		max = intervalOfInts[i].intervalEnd;
		for (int r = min; r <= max;r++)
		{
			Dest[index] = r;
			index++;
		}
	}
}

int IntervalSet::getSetNumOfElements()
{
	//Gets count of elements
	int actualSize = 0, min, max;
	for (int i = 0; i < count; i++)
	{
		min = intervalOfInts[i].intervalStart;
		max = intervalOfInts[i].intervalEnd;
		actualSize += max - min;
	}
	return actualSize;
}
