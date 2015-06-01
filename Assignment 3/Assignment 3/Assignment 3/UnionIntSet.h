#pragma once
#include "IIntSet.h"
#include "BasicIntSet.h"
#include "IntervalSet.h"
#include <algorithm>
#include <iostream>
#include <sstream>

class UnionIntSet : public IIntSet
{
private:
	IIntSet *IntSetA, *IntSetB;
	int *ExtendedUnionSet;
	virtual void ExtendArray(int value) override;

public:
	UnionIntSet(IIntSet *set1,IIntSet *set2);
	~UnionIntSet();

	virtual bool Contains(int elem) override;

	virtual void Add(int elem) override;

	virtual IIntSet* Union(IIntSet &other) override;

	virtual string ToString() override;	
};

