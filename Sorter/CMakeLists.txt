cmake_minimum_required(VERSION 3.3)

project(Sorter)

set(SOURCES Source.cpp
			Application.cpp
			ChoiseSort.cpp
			InputSort.cpp
			ISorting.cpp
			MyQuickSort.cpp
			QuickSort.cpp
			Series.cpp
			ShellSort.cpp
			SortingFactory.cpp
			SortingWrapper.cpp
)

set(HEADERS HelpStruct.h
			Application.h
			ChoiseSort.h
			InputSort.h
			ISorting.h
			MyQuickSort.h
			QuickSort.h
			Series.h
			ShellSort.h
			SortingFactory.h
			SortingWrapper.h
)




add_executable(SorteR ${SOURCES} ${HEADERS})

target_link_libraries(SorteR)