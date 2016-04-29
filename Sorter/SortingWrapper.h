
#pragma once
#include <ctime>
#include <chrono>
#include "SortingFactory.h"
#pragma warning

using std::chrono::duration_cast;
using std::chrono::steady_clock;

class SortingWrapper{
public:
	SortingWrapper(int selector_sort);

	~SortingWrapper();

	//Селектор сортировки 
	long long Sorting(int isWithTime, std::vector<int>& series);
private:
	ISorting* _sorter;// Решил здесь оставить ,так как думаю ,что пользователю лучше не стоит знать об указателях в принципе
	static const int INFO_TIME = 1;
	static const int SORT_WITH_TIME = 2;
	static const int ONLY_SORT = 3;
	static const int NOT_TIME = -1;
	static const int ERROR = -404;//- так как время может быть положительным ,если оно совпадет ,то будет печаль
	//Сортировка с засеканием времени 
	long long SortWithTime(ISorting* ptr_sort, std::vector<int>& series);
};