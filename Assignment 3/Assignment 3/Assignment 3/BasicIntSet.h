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

	virtual void cpySetArray(int* Dest)
	{
		memcpy(Dest, SetOfInts, sizeof(int*)*size);
	};

private:
	virtual void ExtendArray(int value) override;
	int* SetOfInts;
};

