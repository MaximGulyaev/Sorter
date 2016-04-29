#pragma once
#include "ISorting.h"
#include <vector>
class InputSort :
	public ISorting
{
public:
	InputSort();
	~InputSort();
	virtual void SortElements(std::vector<int>& series) override final;
};

