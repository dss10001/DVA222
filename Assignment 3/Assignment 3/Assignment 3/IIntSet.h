#pragma once
class IIntSet
{
protected:
	int size;	// size of Array
	int count;	// count of elements
	/* Function to extend a array by the size of 'value'. */
	virtual void ExtendArray(int value) = 0;
public:

	/* Returns whether this set includes the element 'elem' or not. */
	virtual bool Contains(int elem) = 0;

	/* Add the element 'elem' to this set. After the call, Contains(elem) will
	* return true. */
	virtual void Add(int elem) = 0;

	/* Return a set that is the union of this set and 'other'. All elements contained
	* in either this set or in 'other' will be contained in the resulting set. */
	virtual IIntSet* Union(IIntSet &other) = 0;

	/* Return an array of integers that contains all the individual values in this set. */
	virtual char* ToString() = 0;

	virtual int* getSetArray(int* Dest) = 0;
};
