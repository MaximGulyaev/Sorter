#include "Series.h"


Series::Series() = default;

Series::~Series() = default;

void Series::AddElement(int a){
	_series.push_back(a);
}

long long Series::DoSortingSeries(int selector_sort, int isWithTime){
	SortingWrapper sorter(selector_sort);
	return sorter.Sorting(isWithTime, _series);
}

void Series::FillingSeries(int max_number, unsigned int quantity){
	_series.reserve(quantity);
	for (int i = 0; i < quantity; i++){
		_series.push_back(rand() % max_number);
	}
}

std::ostream& operator << (std::ostream& os, const Series& series)
{
	for (auto& element : series.GetSeries())
	{
		os << element << ' ';
	}
	os << std::endl;
	return os;
}
std::ofstream& operator << (std::ofstream& fos, const Series& series)
{
	for (auto& element : series.GetSeries())
	{
		fos << element << ' ';
		static int i = 0; i++;
		if (i == 100){
			fos << std::endl;
			i = 0;
		}
	}
	return fos;
}
