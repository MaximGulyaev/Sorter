#pragma once
#include "ISorting.h"
#include "Series.h"
class QuickSort :
	public ISorting
{
public:
	QuickSort();
	~QuickSort();
	virtual void SortElements(std::vector<int> &series) override final;
};

