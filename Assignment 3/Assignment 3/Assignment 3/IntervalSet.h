#pragma once
#include "IIntSet.h"
#include "Interval.h"
#include "UnionIntSet.h"
#include <stdio.h>
#include <iostream>

class IntervalSet : public IIntSet
{
private:
	Interval*  intervalOfInts;
	virtual void ExtendArray(int value);

public:	
	IntervalSet();
	~IntervalSet();

	virtual bool Contains(int elem) override;

	virtual void Add(int elem) override;

	virtual IIntSet* Union(IIntSet &other) override;

	virtual string ToString() override;
};

