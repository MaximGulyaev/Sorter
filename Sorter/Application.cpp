#include "Application.h"


Application::Application() = default;


Application::~Application() = default;

void Application::RunApp(){

	int action = 0;
	Series series;
	do{
		PrintMenu();
		if (!Read(action))
		{
			ShowInputError();
			continue;
		}

		switch (action)//Переключатель Меню
		{
		case ADD_VALUE:
		{
			AddValueMenu(series);
			break;
		}
		case SORTING_SERIES:
		{
			SortingSeriesMenu(series);
			break;
		}
		case SHOW_SERIES:
		{
			ShowSeriesMenu(series);
			break;
		}
		case FILLING_SERIES:
		{
			FillingSeriesMenu(series);
			break;
		}
		case FILE_INPUT:
		{
			FileInputMenu(series);
			break;
		}
		case FILE_OUTPUT:
		{
			FileOutputMenu(series);
			break;
		}
		default:
			ShowInputError();
		}
	} while (true);
}

template < class T >
bool Application::Read(T& res){
	std::string s;
	std::cin >> s;

	std::istringstream sin(s);
	if (!(sin >> res))
	{
		return false;
	}

	if (!sin.eof()) return false;

	return true;
}

void Application::PrintMenu(){
	std::cout << "Menu" << std::endl;
	std::cout << ADD_VALUE << ". Add value in series" << std::endl;
	std::cout << SORTING_SERIES << ". Sorting series" << std::endl;
	std::cout << SHOW_SERIES << ". Show series" << std::endl;
	std::cout << FILLING_SERIES << ". Add random series" << std::endl;
	std::cout << FILE_INPUT << ". File input" << std::endl;
	std::cout << FILE_OUTPUT << ". File output" << std::endl;
}

void Application::ShowInputError()
{
	std::cout << "Error: incorrect input" << std::endl;

}
void Application::AddValueMenu(Series &series){
	int value;
	std::cout << "Input element" << std::endl;
	if (!Read(value))
	{
		ShowInputError();
		return;
	}
	series.AddElement(value);
	std::cout << "Element is added" << "\n\n";
}
void Application::ShowSeriesMenu(Series &series)const{
	if (series.GetSize() == 0){
		std::cout << "Series is empty" << std::endl;
		return;
	}
	std::cout << series;
}
void Application::SortingSeriesMenu(Series &series){
	if (series.GetSize() == 0){
		std::cout << "Series is empty" << std::endl;
		return;
	}
	std::cout << "QuickSort or ChoiseSort or MyQuickSort or InputSort or ShellSort <1/2/3/4/5>";
	int selector_sort;
	int isWithTime;
	if (!Read(selector_sort))
	{
		ShowInputError();
		return;
	}

	std::cout << "Info about  time/Sort with time/ Only sort <1/2/3>";

	if (!Read(isWithTime))
	{
		ShowInputError();
		return;
	}

	long long time = series.DoSortingSeries(selector_sort, isWithTime);
	if (time == ERROR){
		std::cout << " Invalid parametrs " << std::endl;
	}

	if (time >= 0){
		std::cout << time << std::endl;
	}


}
void Application::FillingSeriesMenu(Series &series){
	int max_number;
	std::cout << "Input max number" << std::endl;
	if (!Read(max_number))
	{
		ShowInputError();
		return;
	};
	std::cout << "Input quantity" << std::endl;
	unsigned int quantity;
	if (!Read(quantity))
	{
		ShowInputError();
		return;
	};
	series.FillingSeries(max_number, quantity);
	std::cout << "Series is created" << std::endl;
}
void Application::FileInputMenu(Series &series){
	std::string filename;
	std::cout << "Input  the file's name  ";
	std::cin >> filename;
	//filename = "C:\data.txt";
	std::ifstream fin(filename);

	//Проверка успешности открытия файла для чтения
	if (!fin.is_open()) {
		std::cout << "File not exist" << std::endl;
		return;
	}
	int numb = 0;
	while (fin >> numb){
		series.AddElement(numb);
	}
	//Закрытие файла
	fin.close();
}

void Application::FileOutputMenu(Series &series){
	std::string filename;
	std::cout << "Input  the file's name  ";
	std::cin >> filename;
	//filename = "C:\data.txt";
	std::ofstream fof(filename);

	//Проверка успешности открытия файла для чтения
	if (!fof.is_open()) {
		std::cout << "File not exist" << std::endl;
		return;
	}
	fof << series;
	//Закрытие файла
	fof.close();
}