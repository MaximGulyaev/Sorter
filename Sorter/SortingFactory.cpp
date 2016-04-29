#include "SortingFactory.h"


ISorting* SortingFactory::FabricMethod(int selector){
	switch (selector)
	{
	case CHOISE:
		return new ChoiseSort();
		break;
	case QUICK:
		return new QuickSort();
		break;
	case MYQUICK:
		return new MyQuickSort();
		break;
	case INPUT:
		return new InputSort();
		break;
	case SHELL:
		return new ShellSort();
		break;
	default:
		return nullptr;
	}
}