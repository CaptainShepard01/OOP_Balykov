#include "Header.h"
#include <stdio.h>
#include <iostream>

int main()
{
	Doubly_Linked_List<double>* DLL = new Doubly_Linked_List < double > ;

	int size = 0;

	DLL->Insert_from_kb();

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

