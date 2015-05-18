#pragma once
#include "IIntSet.h"
#include "Interval.h"
class UnionIntSet : public IIntSet
{
	int *arrayOfInts;
	Interval *intervalOfInts;
public:
	UnionIntSet();
	~UnionIntSet();

	virtual void ExtendArray(int value) override;

	virtual bool Contains(int elem) override;

	virtual void Add(int elem) override;

	virtual IIntSet* Union(IIntSet &other) override;

	virtual char* ToString() override;

	virtual int* getSetArray()
	{
		return 0;
	}

};

