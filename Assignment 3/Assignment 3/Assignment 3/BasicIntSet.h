#pragma once
#include "IIntSet.h"
#include "IntervalSet.h"
class BasicIntSet : public IIntSet
{
public:
	BasicIntSet();
	~BasicIntSet();

	virtual bool Contains(int elem) override;

	virtual void Add(int elem) override;

	virtual IIntSet* Union(IIntSet &other) override; 

	virtual char* ToString() override;

	virtual int* getSetArray() 
	{
		int* tmp = new int[size];
		for (int i = 0; i < size; i++)
		{
			tmp[i] = SetOfInts[i];
		}
		return tmp;
	};

private:
	virtual void ExtendArray(int value) override;
	int* SetOfInts;
};

