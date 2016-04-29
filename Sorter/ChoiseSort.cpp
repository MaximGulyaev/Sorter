#include "ChoiseSort.h"


ChoiseSort::ChoiseSort() = default;



ChoiseSort::~ChoiseSort() = default;

void ChoiseSort::SortElements(std::vector<int>& series) 
{
	for (unsigned int i = 0; i < series.size(); ++i) // i - номер текущего шага
	{
		int pos = i;
		for (unsigned int j = i + 1; j < series.size(); ++j) // цикл выбора наименьшего элемента
		{
			if (series[j] < series[i])
			{
				pos = j;
			}
		}
		std::swap(series[pos], series[i]);// меняем местами наименьший с serries[i]
	}
}
