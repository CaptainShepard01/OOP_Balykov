#include "Header.h"
#include "Date.h"
#include <sstream>
#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

//#define current_ns unit_doctest
//
//namespace current_ns {
//	int main(int argc, char** argv);
//}
//
//int main(int argc, char** argv) {
//
//
//	return current_ns::main(argc, argv);
//}

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

TEST_CASE("Doubly_linked_list work with int.") {
	auto DLL = new Doubly_Linked_List<int>;

	DLL->addLast(18);
	DLL->addLast(-5);
	DLL->addLast(26);
	CHECK(DLL->find_by_iter(1)->value == -5);

	SUBCASE("Sort increasing.") {
		BubbleSort(DLL, DLL->size(), 0);
		std::stringstream ss;
		ss << *DLL;
		CHECK(ss.str() == "[ -5 18 26 ]");
	}

	SUBCASE("Sort decreasing.") {
		MergeSort(DLL, 0, DLL->size() - 1, 1);
		std::stringstream ss;
		ss << *DLL;
		CHECK(ss.str() == "[ 26 18 -5 ]");
	}
}

TEST_CASE("Doubly_linked_list work with double.") {
	auto DLL = new Doubly_Linked_List<double>;

	DLL->addLast(5.68);
	DLL->addLast(-5.68);
	DLL->addLast(2.3);
	CHECK(DLL->find_by_iter(2)->value == 2.3);

	SUBCASE("Sort increasing.") {
		QuickSort(DLL, DLL->size(), 0, DLL->size() - 1, 0);
		std::stringstream ss;
		ss << *DLL;
		CHECK(ss.str() == "[ -5.68 2.3 5.68 ]");
	}

	SUBCASE("Sort decreasing.") {
		InsertSort(DLL, DLL->size(), 1);
		std::stringstream ss;
		ss << *DLL;
		CHECK(ss.str() == "[ 5.68 2.3 -5.68 ]");
	}
}

//TEST_CASE("Doubly_linked_list work with vector.") {
//	auto DLL = new Doubly_Linked_List<std::vector<int>>;
//	std::vector<int> myVector;
//
//	myVector.push_back(-5);
//	myVector.push_back(35);
//	DLL->addLast(myVector);
//	myVector.clear();
//
//	myVector.push_back(4);
//	DLL->addLast(myVector);
//	myVector.clear();
//
//	myVector.push_back(56);
//	myVector.push_back(0);
//	myVector.push_back(-8);
//	DLL->addLast(myVector);
//	
//	SUBCASE("Sort increasing.") {
//		QuickSort(DLL, DLL->size(), 0, DLL->size() - 1, 0);
//		std::stringstream ss;
//		ss << *DLL;
//		//CHECK(ss.str() == "[ -5.68 2.3 5.68 ]");
//	}
//}

TEST_CASE("Day of week") {
	SUBCASE("Deadline first lab") {
		Date date{ 29,9,2020,23,59,59 };
		CHECK(date.getWeekday() == "Tuesday");
	}

	SUBCASE("Deadline second lab") {
		Date date{ 27,10,2020,23,59,59 };
		CHECK(date.getWeekday() == "Tuesday");
	}

	SUBCASE("My birthday") {
		Date date{ 6,11,2020,0,40,0 };
		CHECK(date.getWeekday() == "Friday");
	}

	SUBCASE("New year this year.") {
		Date date{ 1, 1, 2020, 0, 0, 0 };
		CHECK(date.getWeekday() == "Wednesday");
	}
}

TEST_CASE("Date print") {
	std::stringstream ss;
	Date d{ 6,11,2001,10,50,0 };

	ss << d;

	CHECK(ss.str() == "06/11/2001 10:50:00");
}

TEST_CASE("Date difference") {
	MomentOfTime moment{ 27,10,2001,10,50,31 };

	SUBCASE("Without difference") {
		TimeDifference diff(moment, moment);
		CHECK(diff == MomentOfTime{ 0,0,0,0,0,0 });
	}

	MomentOfTime moment1{ 3,3,2001,10,50,31 };
	MomentOfTime moment2{ 7,2,2001,10,50,31 };

	SUBCASE("Smaller - bigger") {
		TimeDifference diff(moment1, moment2);
		CHECK(diff == MomentOfTime{ 24,0,0,0,0,0 });
	}

	SUBCASE("Bigger - smaller") {
		TimeDifference diff(moment2, moment1);
		CHECK(diff == MomentOfTime{ 24,0,0,0,0,0 });
	}

	SUBCASE("Time difference") {
		MomentOfTime moment1{ 3,3,2001,16,23,0 };
		MomentOfTime moment2{ 7,2,2001,10,50,31 };

		TimeDifference diff(moment1, moment2);
		CHECK(diff == MomentOfTime{ 24,0,0,5,32,29 });
	}
}

TEST_CASE("Date operator +") {
	Date date{ 27,10,2001,10,50,31 };

	SUBCASE("Add zero time") {
		date += TimeDifference(0, 0, 0, 0, 0, 0);
		CHECK(date == Date{ 27, 10, 2001, 10, 50, 31 });
	}

	SUBCASE("Add different time") {
		Date anotherDate{ 2, 3, 2004, 13, 3, 0 };

		TimeDifference td(date, anotherDate);
		date += td;
		CHECK(date == anotherDate);
	}
}

TEST_CASE("Date operator -") {
	Date date{ 27,10,2001,10,50,31 };
	MomentOfTime moment1{ 3,3,2001,16,23,0 };
	MomentOfTime moment2{ 7,2,2001,10,50,31 };

	SUBCASE("Subtract zero time") {
		date -= TimeDifference(0, 0, 0, 0, 0, 0);
		CHECK(date == Date{ 27, 10, 2001, 10, 50, 31 });
	}

	SUBCASE("Subtract different time") {
		Date anotherDate{ 2, 3, 2004, 13, 3, 0 };

		TimeDifference td(date, anotherDate);
		anotherDate -= td;
		CHECK(anotherDate == date);
	}
}

TEST_CASE("Day of week") {
	SUBCASE("Deadline first lab") {
		Date date{ 29,9,2020,23,59,59 };
		CHECK(date.getWeekday() == "Tuesday");
	}

	SUBCASE("Deadline second lab") {
		Date date{ 27,10,2020,23,59,59 };
		CHECK(date.getWeekday() == "Tuesday");
	}

	SUBCASE("Birthday of Mr.X") {
		Date date{ 6,11,2020,0,40,0 };
		CHECK(date.getWeekday() == "Friday");
	}
}

TEST_CASE("UTC normalizer") {
	Date date1{ 27,10,2020,23,59,59,-2 };
	Date date2{ 27,10,2020,23,59,59,2 };

	CHECK(date1 - date2 == TimeDifference{ 0,0,0,4,0,0 });
}

TEST_CASE("Week number") {

	SUBCASE("Day at the beginning of the year") {
		Date date{ 5,1,2020,0,40,0 };
		CHECK(date.getWeekNumberInYear_naive() == 2);
	}

}

TEST_CASE("Doubly_linked_list work with Date") {
	auto DLL = new Doubly_Linked_List<Date>;
	Date newDate(1, 1, 2020, 1, 1, 1);

	DLL->addLast(newDate);

	CHECK(DLL->find_by_iter(0)->value == Date(1, 1, 2020, 1, 1, 1));

	DLL->addLast(Date(2, 1, 2020, 1, 1, 1));
	DLL->addLast(Date(1, 1, 2019, 1, 1, 1));

	SUBCASE("Increasing sort") {
		QuickSort(DLL, DLL->size(), 0, DLL->size() - 1, 0);
		std::stringstream ss;
		ss << *DLL;
		std::cout << ss.str();
		CHECK(ss.str() == "[ -5.68 2.3 5.68 ]");
	}
}

//TEST_CASE("Number of week.") {
//	Date d(29, 9, 2020, 10, 10, 10);
//
//	CHECK(d.getWeekNumberInYear_naive() == 39);
//
//}

//int main(int argc, char** argv) {
//	//doctest stuff
//	doctest::Context context;
//	context.applyCommandLine(argc, argv);
//	int res = context.run();
//	if (context.shouldExit())
//		return res;
//
//	//my return code
//	int client_stuff_return_code = 0;
//
//	return res + client_stuff_return_code;
//}
//
//
//int main(int argc, char** argv)
//{
//	Doubly_Linked_List<double>* DLL = new Doubly_Linked_List < double > ;
//
//	int size = 0;
//
//
//	DLL->Insert_from_kb();
//
//	DLL->operator[](1);
//	std::cout << *DLL << std::endl;
//
//	system("pause");
//
//	//InsertSort<double>(DLL, DLL->size(), 1);
//
//	//BubbleSort<double>(DLL, DLL->size(), 1);
//
//	//QuickSort<double>(DLL, DLL->size(), 0, DLL->size()-1, 0);
//
//	//MergeSort<int>(0, DLL->size() - 1, DLL->size(), DLL);
//
//	//MergeSort<double>(DLL, 0, DLL->size() - 1, 1);
//
//	std::cout << *DLL << std::endl;
//
//	delete DLL;
//	return 0;
//}
