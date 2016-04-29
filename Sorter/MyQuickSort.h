#pragma once
#include "ISorting.h"
#include "Series.h"
class MyQuickSort :
	public ISorting
{
public:
	MyQuickSort();
	~MyQuickSort();
	virtual void SortElements(Container_t& series) override final;
private:
	template<typename TIterator, typename T, typename TCompare>
	void QuickSort(TIterator first, TIterator last, const T& pv, TCompare cmp);
	template<typename TIterator, typename TCompare>
	void DoSortElements(TIterator first, TIterator last, TCompare cmp);
};

