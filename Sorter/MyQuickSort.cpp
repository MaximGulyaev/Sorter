#include "MyQuickSort.h"
#include "HelpStruct.h"


MyQuickSort::MyQuickSort() = default;

MyQuickSort::~MyQuickSort() = default;


void MyQuickSort::SortElements(Container_t& series) 
{
	DoSortElements(series.begin(), series.end(), TCompare<int>());
}

template<typename TIterator, typename T, typename TCompare>
void MyQuickSort::QuickSort(TIterator first, TIterator last, const T& pv, TCompare cmp){
	T v = *(first + ((last - first) / 2));
	TIterator f = first;
	TIterator l = last;

	do {
		while ((f < last) && cmp(*f, v))
			++f;
		while ((l > first) && cmp(v, *l))
			--l;

		if (f <= l){
			std::swap(*f, *l);
			++f;
			--l;
		}
	} while (f <= l);

	if (l > first)
		QuickSort(first, l, v, cmp);
	if (last > f)
		QuickSort(f, last, v, cmp);
}

template<typename TIterator, typename TCompare>
void MyQuickSort::DoSortElements(TIterator first, TIterator last, TCompare cmp){
	if (first < --last)
		QuickSort(first, last, *first, cmp);
}

