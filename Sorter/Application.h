#pragma once
#include <sstream>
#include <string>
#include "Series.h"
#include "SortingWrapper.h"


class Application
{
public:
	Application();
	~Application();
	void RunApp();
private:
	static const int ADD_VALUE = 1;
	static const int SORTING_SERIES = 2;
	static const int SHOW_SERIES = 3;
	static const int FILLING_SERIES = 4;
	static const int FILE_INPUT = 5;
	static const int FILE_OUTPUT = 6;
	static const int ERROR = -404;//- так как время может быть положительным ,если оно совпадет ,то будет печаль

	template < class T >
	bool Read(T& res);
	void PrintMenu();
	void ShowInputError();
	void AddValueMenu(Series &series);
	void ShowSeriesMenu(Series &series)const;
	void SortingSeriesMenu(Series &series);
	void FillingSeriesMenu(Series &series);
	void FileInputMenu(Series &series);
	void FileOutputMenu(Series &series);
};

