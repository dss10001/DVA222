#pragma once
#include <stdio.h>
#include <iostream>
#include "IIntSet.h"
#include "Interval.h"
class IntervalSet : public IIntSet
{
private:
	Interval *intervalOfInts;
	int count;
	virtual void ExtendArray(int value);
public:
	
	IntervalSet();
	~IntervalSet();

	virtual bool Contains(int elem) override;

	virtual void Add(int elem) override;

	virtual IIntSet* Union(IIntSet &other) override;

	virtual char* ToString() override;

	virtual void getSetArray(int* Dest);
};

