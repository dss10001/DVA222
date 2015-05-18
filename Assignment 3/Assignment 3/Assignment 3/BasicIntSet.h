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

	int* getIntArray() { return SetOfInts; };

	virtual void getSetArray(int* Dest){};
	virtual int getSetSize(){ return size; };

private:
	virtual void ExtendArray(int value) override;
	int* SetOfInts;
};

