#include "Header.h"
#include <stdio.h>
#include <sstream>
#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#define current_ns unit_doctest

namespace current_ns {
	int main(int argc, char** argv);
}

int main(int argc, char** argv) {


	return current_ns::main(argc, argv);
}

TEST_CASE("Doubly_linked_list work with string.") {
	auto DLL = new Doubly_Linked_List<std::string>;

	DLL->addLast("Hello");
	DLL->addLast("Aaaaa");
	DLL->addLast("Gggggg");
	CHECK(DLL->find_by_iter(0)->value == "Hello");

	SUBCASE("Sort increasing.") {
		InsertSort(DLL, DLL->size(), 0);
		std::stringstream ss;
		ss << *DLL;
		CHECK(ss.str() == "[ Aaaaa Gggggg Hello ]");
	}

	SUBCASE("Sort decreasing.") {
		QuickSort(DLL, DLL->size(), 0, DLL->size() - 1, 1);
		std::stringstream ss;
		ss << *DLL;
		CHECK(ss.str() == "[ Hello Gggggg Aaaaa ]");
	}

	
}

int main(int argc, char** argv)
{
	Doubly_Linked_List<double>* DLL = new Doubly_Linked_List < double > ;

	int size = 0;


	DLL->Insert_from_kb();

	DLL->operator[](1);
	std::cout << *DLL << std::endl;

	system("pause");

	//InsertSort<double>(DLL, DLL->size(), 1);

	//BubbleSort<double>(DLL, DLL->size(), 1);

	//QuickSort<double>(DLL, DLL->size(), 0, DLL->size()-1, 0);

	//MergeSort<int>(0, DLL->size() - 1, DLL->size(), DLL);

	//MergeSort<double>(DLL, 0, DLL->size() - 1, 1);

	std::cout << *DLL << std::endl;

	delete DLL;
	return 0;
}
