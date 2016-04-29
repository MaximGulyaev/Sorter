#pragma once
#include "ISorting.h"
#include <vector>
class ChoiseSort:
	public ISorting
{
public:
	ChoiseSort();
	~ChoiseSort();
	virtual void SortElements(std::vector<int>& series) override final;
};

