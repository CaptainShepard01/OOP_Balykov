#include "Header.h"
#include <stdio.h>
#include <iostream>

int main()
{
	Doubly_Linked_List<int>* DLL = new Doubly_Linked_List<int>;

	int size = 0;

	while (true) {
		std::cout << "Enter value for new Node: ";
		int val;
		std::cin >> val;
		system("cls");
		if (val == -1)
			break;
		DLL->addLast(val);
		size++;
	}

	std::cout << *DLL << std::endl;

	system("pause");

	//InsertSort<int>(DLL, DLL->size());

	//BubbleSort<int>(DLL, DLL->size());

	//QuickSort<Doubly_Linked_List<int>>(DLL, DLL->size(), 0, DLL->size()-1);

	//MergeSort<int>(0, DLL->size() - 1, DLL->size(), DLL);

	MergeSort<int>(DLL, 0, DLL->size() - 1);

	std::cout << *DLL << std::endl;

	delete DLL;
	return 0;
}

