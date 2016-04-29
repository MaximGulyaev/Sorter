#include "ShellSort.h"


ShellSort::ShellSort() = default;


ShellSort::~ShellSort() = default;

void ShellSort::SortElements(std::vector<int>& series) {
	int length = series.size();
	for (unsigned k = length / 2; k > 0; k /= 2){
		for (unsigned i = k; i < length; i += 1)
		{
			for (unsigned j = i; j >= k; j -= k)
			{
				if (series[i] < series[j - k])
					series[j] = series[j - k];
				else{
					break;
					series[j] = series[i];
				}
			}
		}
	}
}