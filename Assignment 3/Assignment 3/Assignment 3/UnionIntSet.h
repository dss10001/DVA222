#pragma once
#include "IIntSet.h"
#include "BasicIntSet.h"
#include "Interval.h"
#include <algorithm>    // std::copy

class UnionIntSet : public IIntSet
{
private:
	int *arrayOfIntsOne, *arrayOfIntsTwo;
	int size_one, size_two;
public:
	UnionIntSet();
	~UnionIntSet();

	virtual void ExtendArray(int value) override;

	virtual bool Contains(int elem) override;

	virtual void Add(int elem) override;

	virtual IIntSet* Union(IIntSet &other) override;

	virtual char* ToString() override;

	virtual void cpySetArray(int* Dest){};

	void setSet1(int* Array, int size);

	void setSet2(int* Array, int size);
};

