#include "IIntSet.h"


IIntSet::IIntSet()
{
}


bool IIntSet::Contains(int elem)
{
	return false;
}

void IIntSet::Add(int elem)
{

}

IIntSet* IIntSet::Union(IIntSet &other)
{
	return this;
}

char* IIntSet::ToString()
{
	return "";
}

IIntSet::~IIntSet()
{
}
