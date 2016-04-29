#pragma once
#include "ISorting.h"
class ShellSort :
	public ISorting
{
public:
	ShellSort();
	~ShellSort();
	virtual void SortElements(std::vector<int>& series) override final;
};

