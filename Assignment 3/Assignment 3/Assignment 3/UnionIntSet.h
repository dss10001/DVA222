#pragma once
#include "IIntSet.h"
#include "Interval.h"
#include <algorithm>    // std::copy

class UnionIntSet : public IIntSet
{
	int *arrayOfIntsOne, *arrayOfIntsTwo;
public:
	UnionIntSet();
	~UnionIntSet();

	virtual void ExtendArray(int value) override;

	virtual bool Contains(int elem) override;

	virtual void Add(int elem) override;

	virtual IIntSet* Union(IIntSet &other) override;

	virtual char* ToString() override;

	virtual void getSetArray(int* Dest){};
};

