#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include "SortingWrapper.h"
class Series
{
public:
	Series();
	~Series();
	void AddElement(int a);
	long long DoSortingSeries(int selector_sort, int isWithTime);
	void FillingSeries(int max_number, unsigned int quantity);

	typedef std::vector<int> Series_t;
	unsigned int GetSize(){ return _series.size(); }
	const Series_t& GetSeries()const{ return _series; };
private:
	Series_t _series;//числовой ряд
};
std::ofstream& operator << (std::ofstream& fos, const Series& series);
std::ostream& operator << (std::ostream& os, const Series& series);

