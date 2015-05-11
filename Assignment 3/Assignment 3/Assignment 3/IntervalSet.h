#pragma once
#include "IIntSet.h"
struct Interval
{
	int intervalStart, intervalEnd;

};
class IntervalSet : public IIntSet
{
private:
	Interval *intervalOfInts;
public:
	
	IntervalSet();
	~IntervalSet();

	virtual bool Contains(int elem) override;

	virtual void Add(int elem) override;

};

