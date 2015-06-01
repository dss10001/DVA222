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
	for (int i = 0; i < size; i++)
	{
		if (elem >= intervalOfInts[i].intervalStart && elem <= intervalOfInts[i].intervalEnd)
		{
			return true;
		}
	}
	return false;
}

void IntervalSet::Add(int elem)
{
	if (!Contains(elem))
	{
		int actionCount = 0;	// count number of overwritten intervals by 'elem'
		int index1, index2;		// indeces of overwritten interval elements. 

		if (size >= count)
		{
			ExtendArray(10);
		}

		for (int i = 0; i < count; i++)
		{
			if (elem == intervalOfInts[i].intervalStart - 1)
			{
				// set intervalstart = elem
				intervalOfInts[i].intervalStart = elem;
				actionCount++;
				index2 = i;
			}
			else if (elem == intervalOfInts[i].intervalEnd + 1)
			{
				// set intervalend = elem
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

IIntSet* IntervalSet::Union(IIntSet &other)
{
	UnionIntSet* _union = new UnionIntSet(this, &other);
	return _union;
}

string IntervalSet::ToString()
{
	std::ostringstream oss;
	oss << "Interval Int-set: {";
	int min_value, max_value;
	for (int i = 0; i < count; i++)
	{
		min_value = intervalOfInts[i].intervalStart;
		max_value = intervalOfInts[i].intervalEnd;

		for (int x = min_value; x <= max_value; x++)
		{
			oss << x << ", ";
		}
	}
	oss << "}\n";
	return oss.str();
}

void IntervalSet::ExtendArray(int value)
{
	Interval *newInterval = new Interval[size + value];
	memcpy(newInterval, intervalOfInts, sizeof(Interval));
	delete[]intervalOfInts;
	intervalOfInts = newInterval;
}