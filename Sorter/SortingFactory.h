#pragma once
#include "ChoiseSort.h"
#include "MyQuickSort.h"
#include "QuickSort.h"
#include "InputSort.h"
#include "ShellSort.h"

class SortingFactory
{
public:
	SortingFactory()=default;
	~SortingFactory() = default;
	ISorting* FabricMethod(int selector);
private:
	static const int CHOISE = 1;
	static const int QUICK = 2;
	static const int MYQUICK = 3;
	static const int INPUT = 4;
	static const int SHELL = 5;
};

