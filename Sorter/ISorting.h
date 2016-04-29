#pragma once
#include <vector>
#include <algorithm>
class ISorting
{
public:
	typedef std::vector<int> Container_t;
	ISorting();
	virtual ~ISorting();
	virtual void SortElements(Container_t& serries) = 0;
};

