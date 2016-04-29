#include "InputSort.h"


InputSort::InputSort() = default;

InputSort::~InputSort() = default;

void InputSort::SortElements(std::vector<int>& series) 
{
	for (int i = 1; i < series.size(); i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (series[j] < series[i])
				break;
			std::swap(series[j], series[j + 1]);
		}
	}
}
