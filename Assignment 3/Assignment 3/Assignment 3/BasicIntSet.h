#pragma once
#include "IIntSet.h"
class BasicIntSet : public IIntSet
{
public:
	BasicIntSet();
	~BasicIntSet();

	virtual bool Contains(int elem) override;

	virtual void Add(int elem) override;

	virtual IIntSet* Union(IIntSet &other) override; 

	virtual char* ToString() override;

private:
	virtual void ExtendArray(int value) override;
};

