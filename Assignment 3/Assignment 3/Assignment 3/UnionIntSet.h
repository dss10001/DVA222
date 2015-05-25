#pragma once
#include "IIntSet.h"
#include "BasicIntSet.h"
#include "Interval.h"
#include <algorithm>    // std::copy
#include <string>
#include <iostream>
#include <sstream>

class UnionIntSet : public IIntSet
{
private:
	IIntSet *one, *two;
	int *SetsOfInts;
public:
	UnionIntSet(IIntSet *set1,IIntSet *set2);
	UnionIntSet(const UnionIntSet &other);
	~UnionIntSet();

	virtual bool Contains(int elem) override;

	virtual IIntSet* Union(IIntSet &other) override;

	virtual string ToString() override;

	virtual void ExtendArray(int value) override;

	virtual void Add(int elem) override;

	virtual int getSetNumOfElements() override;

	/*virtual int getSetNumOfElements(){ return count; };*/
};

