#pragma once
#include "IIntSet.h"
#include "UnionIntSet.h"
#include <iostream>
#include <sstream>

#define INITIAL_SIZE 20
#define EXTEND_VALUE 50

class BasicIntSet : public IIntSet
{
private:
	int* SetOfInts;
	virtual void ExtendArray(int value) override;

public:
	BasicIntSet();
	~BasicIntSet();

	virtual bool Contains(int elem) override;

	virtual void Add(int elem) override;

	virtual IIntSet *Union(IIntSet &other) override; 

	virtual string ToString() override;
};

