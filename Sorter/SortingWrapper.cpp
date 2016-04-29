#include "SortingWrapper.h"


SortingWrapper::SortingWrapper(int selector_sort) {
	SortingFactory _factory;
	_sorter = _factory.FabricMethod(selector_sort);
}


SortingWrapper::~SortingWrapper(){
	delete _sorter;
}
long long SortingWrapper::Sorting(int isWithTime, std::vector<int>& series){

	if (_sorter == nullptr){
		isWithTime = ERROR;//Если введен неправильный селектор сортировки ,то переброс сase isWithTime в ошибки 
		//В том смысле ,если селектор выбран неправильно ,смысл проверять другой селектор
	}

	std::vector<int> fake_series = series;

	switch (isWithTime)
	{
	case INFO_TIME://в наносекундах 
		return this->SortWithTime(_sorter, fake_series);
		break;
	case SORT_WITH_TIME:
		return this->SortWithTime(_sorter, series);
		break;
	case ONLY_SORT:
		_sorter->SortElements(series);
		return NOT_TIME;
		break;
	default:
		return ERROR;
		break;
	}
}

long long SortingWrapper::SortWithTime(ISorting* ptr_sort, std::vector<int>& series){
	using std::chrono::duration_cast;
	using std::chrono::steady_clock;

	steady_clock::time_point start = steady_clock::now();

	{
		ptr_sort->SortElements(series);
	}

	steady_clock::time_point end = steady_clock::now();
	return duration_cast<std::chrono::nanoseconds>(end - start).count();
}