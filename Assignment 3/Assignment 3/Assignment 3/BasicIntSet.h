#pragma once
#include "IIntSet.h"
class BasicIntSet : public IIntSet
{
public:
	BasicIntSet();
	~BasicIntSet();

	virtual bool Contains(int elem) override;

	virtual void Add(int elem) override;

};

