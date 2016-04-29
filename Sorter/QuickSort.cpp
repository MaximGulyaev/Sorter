#include "QuickSort.h"


QuickSort::QuickSort() = default;


QuickSort::~QuickSort() = default;

void QuickSort::SortElements(std::vector<int> &series) 
{
	sort(series.begin(), series.end());
}
