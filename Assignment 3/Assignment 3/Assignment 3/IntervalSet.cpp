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
		int actionCount = 0;	// count number of overwritten intervals by 'elem'
		int index1, index2;		// indeces of overwritten interval elements. 

		if (size == count)
		{
			ExtendArray(10);
		}

		for (int i = 0; i < count; i++)
		{
			if (elem == intervalOfInts[i].intervalStart - 1)
			{
				// set intervalstart to elem
				intervalOfInts[i].intervalStart = elem;
				actionCount++;
				index2 = i;
			}
			else if (elem == intervalOfInts[i].intervalEnd + 1)
			{
				// set intervalend to elem
				intervalOfInts[i].intervalEnd = elem;
				actionCount++;
				index1 = i;
			}
		}
		if (actionCount == 0)
		{
			// Add new standalone interval
			Interval newInterval;
			newInterval.intervalStart = newInterval.intervalEnd = elem;
			intervalOfInts[count] = newInterval;
			count++;
		}
		else if (actionCount == 2)
		{
			// extend interval to represent both intervals
			intervalOfInts[index1].intervalEnd = intervalOfInts[index2].intervalEnd;
			// compact intervalArray to fill empty space
			for (int i = index2; i < count; i++)
			{
				intervalOfInts[i] = intervalOfInts[i + 1];
			}
			// subtract element count. 
			count--;
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
