#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <utility>

template<typename T>
struct Node {
	T value;
	Node<T>* prev;
	Node<T>* next;
	int iter;

	Node(T value, Node<T>* prev = nullptr, Node<T>* next = nullptr, int a = -1) : value{ value }, prev{ prev }, next{ next }, iter{ a } {}

	Node() {}
	~Node() {}
};

template<typename T>
class Doubly_Linked_List {
private:
	Node<T>* begin;
	Node<T>* end;
	std::size_t _size;
public:

	Doubly_Linked_List() : begin{ nullptr }, end{ nullptr }, _size{ 0 } {}

	~Doubly_Linked_List() {
		this->clear();
	}

	Node<T>* get_end() {
		return this->end;
	}

	Node<T>* get_beg() {
		return this->begin;
	}

	void addLast(T value) {
		auto node = new Node<T>{ value };
		if (begin == nullptr) {
			end = node; begin = node;
			node->iter = 0;
		}
		else {
			node->prev = end;
			node->iter = (node->prev)->iter + 1;
			end->next = node;
			end = node;
		}
		_size++;
	}

	void Insert_from_kb();

	void clear() {
		Node<T>* current = begin;
		while (current) {
			Node<T>* to_delete = current;
			current = current->next;
			delete to_delete;
		}
		begin = end = nullptr;
		_size = 0;
	}

	std::size_t size() {
		return _size;
	}

	T operator[](std::size_t index) {
		Node<T>* current = begin;
		std::size_t cur_index = 0;
		while (current) {
			if (cur_index == index) {
				return current->value;
			}
			current = current->next;
			cur_index++;
		}
		throw std::out_of_range{ "Ind " + std::to_string(index) + " larger than list size = " + std::to_string(_size) };
	}

	friend std::ostream& operator<<(std::ostream& out, const Doubly_Linked_List<T>& list) {
		Node<T>* current = list.begin;
		out << "[";
		while (current) {
			if (current == list.end) {
				out << '(' << current->value << ')';
				current = current->next;
			}
			else {
				out << '(' << current->value << ')' << " ";
				current = current->next;
			}
		}
		out << "]";
		return out;
	}

	Node<T>* find_by_iter(int iter);

	Node<T>* find(T key);

	bool RemoveLast();
};


//template<typename T>
//void MergeSort(int l, int r, int length, Doubly_Linked_List<T>* a, bool isDecr)
//{
//	if (r == l)
//		return;
//
//	if (r - l == 1) {
//		if (a->find_by_iter(r)->value < a->find_by_iter(l)->value) {
//			int temp = a->find_by_iter(r)->value;
//			a->find_by_iter(r)->value = a->find_by_iter(l)->value;
//			a->find_by_iter(l)->value = temp;
//		}
//		return;
//	}
//
//	int m = (r + l) / 2;
//
//
//	MergeSort(l, m, length, a);
//
//	MergeSort(m + 1, r, length, a);
//
//	Doubly_Linked_List<T>* buf = new Doubly_Linked_List<T>;
//	while (buf->size() < length) {
//		buf->addLast(0);
//	}
//
//	int xl = l;
//	int xr = m + 1;
//	int cur = 0;
//
//	while (r - l + 1 != cur)
//	{
//		if (xl > m)
//			buf->find_by_iter(cur++)->value = a->find_by_iter(xr++)->value;
//
//		else if (xr > r)
//			buf->find_by_iter(cur++)->value = a->find_by_iter(xl++)->value;
//
//		else if (a->find_by_iter(xl)->value > a->find_by_iter(xr)->value)
//			buf->find_by_iter(cur++)->value = a->find_by_iter(xr++)->value;
//
//		else
//			buf->find_by_iter(cur++)->value = a->find_by_iter(xl++)->value;
//	}
//	for (int i = 0; i < cur; i++)
//		a->find_by_iter(i + l)->value = buf->find_by_iter(i)->value;
//
//}

template<typename T>
inline void Doubly_Linked_List<T>::Insert_from_kb()
{
	while (true)
	{
		T val;

		std::string a;

		std::cout << "Current type of value: " << typeid(val).name() << std::endl << std::endl;
		std::cout << "Enter the value (to stop adding type 'end'): ";

		std::stringstream ss;

		std::getline(std::cin, a);

		ss.str(a.c_str());

		if (ss.str() == "end")
		{
			system("cls");
			break;
		}

		ss >> val;

		if (ss.fail())
		{
			ss.clear();

			system("cls");
			std::cout << "You can't enter different types of values!" << std::endl;
			system("pause");
			system("cls");
			continue;
		}

		system("cls");

		this->addLast(val);
	}
}

template<typename T>
inline Node<T>* Doubly_Linked_List<T>::find_by_iter(int iter)
{
	Node<T>* cur = begin;
	while (cur) {
		if (cur->iter == iter)
			break;
		cur = cur->next;
	}
	return cur;
}

template<typename T>
inline Node<T>* Doubly_Linked_List<T>::find(T key) {
	Node<T>* cur = begin;
	while (cur) {
		if (cur->value == key)
			break;
		cur = cur->next;
	}
	return cur;
}

template<typename T>
inline bool Doubly_Linked_List<T>::RemoveLast()
{
	if (begin == nullptr) {
		std::cout << "There are no elements!" << std::endl << std::endl;
		return false;
	}
	else {
		Node<T>* cur = end;
		end = (end)->prev;
		(end)->next = nullptr;
		delete cur;
		std::cout << "Successful!" << std::endl;
		return true;
	}
}

template<typename T>
void QuickSort(Doubly_Linked_List<T>* a, int length, int L, int R, bool isDecr) {
	int i = L, j = R;
	int mid = (R + L) / 2;

	T first = a->find_by_iter(mid)->value;
	T sec;

	if (isDecr) {
		do {
			while (a->find_by_iter(i)->value > first)
				i++;

			while (first > a->find_by_iter(j)->value)
				j--;

			if (i <= j) {
				sec = a->find_by_iter(i)->value;
				a->find_by_iter(i)->value = a->find_by_iter(j)->value;
				a->find_by_iter(j)->value = sec;

				i++;
				j--;
			}
		} while (i < j);
	}
	else {
		do {
			while (a->find_by_iter(i)->value < first)
				i++;

			while (first < a->find_by_iter(j)->value)
				j--;

			if (i <= j) {
				sec = a->find_by_iter(i)->value;
				a->find_by_iter(i)->value = a->find_by_iter(j)->value;
				a->find_by_iter(j)->value = sec;

				i++;
				j--;
			}
		} while (i < j);
	}

	if (L < j)
		QuickSort(a, length, L, j, isDecr);

	if (i < R)
		QuickSort(a, length, i, R, isDecr);
}

template<typename T>
void BubbleSort(Doubly_Linked_List<T>* a, int size, bool isDecr) {
	T x;
	int i, j;
	if (isDecr) {
		for (i = 0; i < size; i++) {
			for (j = size - 1; j > i; j--) {
				if (a->find_by_iter(j - 1)->value < a->find_by_iter(j)->value) {
					x = a->find_by_iter(j - 1)->value;
					a->find_by_iter(j - 1)->value = a->find_by_iter(j)->value;
					a->find_by_iter(j)->value = x;
				}
			}
		}
	}
	else {
		for (i = 0; i < size; i++) {
			for (j = size - 1; j > i; j--) {
				if (a->find_by_iter(j - 1)->value > a->find_by_iter(j)->value) {
					x = a->find_by_iter(j - 1)->value;
					a->find_by_iter(j - 1)->value = a->find_by_iter(j)->value;
					a->find_by_iter(j)->value = x;
				}
			}
		}
	}
}

template<typename T>
void InsertSort(Doubly_Linked_List<T>* a, int size, bool isDecr) {
	T x;
	int i, j;
	if (isDecr) {
		for (i = 0; i < size; ++i) {
			x = a->find_by_iter(i)->value;
			for (j = i - 1; j >= 0 && a->find_by_iter(j)->value < x; j--)
				a->find_by_iter(j + 1)->value = a->find_by_iter(j)->value;
			a->find_by_iter(j + 1)->value = x;
		}
	}
	else {
		for (i = 0; i < size; ++i) {
			x = a->find_by_iter(i)->value;
			for (j = i - 1; j >= 0 && a->find_by_iter(j)->value > x; j--)
				a->find_by_iter(j + 1)->value = a->find_by_iter(j)->value;
			a->find_by_iter(j + 1)->value = x;
		}
	}
}

template<typename T>
void merge(Doubly_Linked_List<T>* a, int lb, int split, int ub, bool isDecr) {
	long pos1 = lb;
	long pos2 = split + 1;

	long pos3 = 0;

	T tmp = {};

	Doubly_Linked_List<T>* temp = new Doubly_Linked_List<T>;
	while (temp->size() < ub - lb + 1) {
		temp->addLast(tmp);
	}


	if (isDecr) {
		while (pos1 <= split && pos2 <= ub) {
			if (a->find_by_iter(pos1)->value > a->find_by_iter(pos2)->value) {
				temp->find_by_iter(pos3++)->value = a->find_by_iter(pos1++)->value;
			}
			else {
				temp->find_by_iter(pos3++)->value = a->find_by_iter(pos2++)->value;
			}
		}

		while (pos2 <= ub) {
			temp->find_by_iter(pos3++)->value = a->find_by_iter(pos2++)->value;
		}
		while (pos1 <= split) {
			temp->find_by_iter(pos3++)->value = a->find_by_iter(pos1++)->value;
		}

		for (pos3 = 0; pos3 < ub - lb + 1; pos3++) {
			a->find_by_iter(lb + pos3)->value = temp->find_by_iter(pos3)->value;
		}
	}
	else {
		while (pos1 <= split && pos2 <= ub) {
			if (a->find_by_iter(pos1)->value < a->find_by_iter(pos2)->value) {
				temp->find_by_iter(pos3++)->value = a->find_by_iter(pos1++)->value;
			}
			else {
				temp->find_by_iter(pos3++)->value = a->find_by_iter(pos2++)->value;
			}
		}

		while (pos2 <= ub) {
			temp->find_by_iter(pos3++)->value = a->find_by_iter(pos2++)->value;
		}
		while (pos1 <= split) {
			temp->find_by_iter(pos3++)->value = a->find_by_iter(pos1++)->value;
		}

		for (pos3 = 0; pos3 < ub - lb + 1; pos3++) {
			a->find_by_iter(lb + pos3)->value = temp->find_by_iter(pos3)->value;
		}
	}
	delete temp;
}

template<typename T>
void MergeSort(Doubly_Linked_List<T>* a, int lb, int ub, bool isDecr) {
	int split;

	if (lb < ub) {
		split = (lb + ub) / 2;

		MergeSort(a, lb, split, isDecr);
		MergeSort(a, split + 1, ub, isDecr);
		merge(a, lb, split, ub, isDecr);
	}
}

int increment(int inc[], int size) {
	int p1, p2, p3, s;

	p1 = p2 = p3 = 1;
	s = -1;
	do {
		if (++s % 2) {
			inc[s] = 8 * p1 - 6 * p2 + 1;
		}
		else {
			inc[s] = 9 * p1 - 9 * p3 + 1;
			p2 *= 2;
			p3 *= 2;
		}
		p1 *= 2;
	} while (3 * inc[s] < size);

	return s > 0 ? --s : 0;
}

template<typename T>
void ShellSort(Doubly_Linked_List<T>* a, int size, bool isDecr) {
	int inc, i, j, seq[40];
	int s;

	s = increment(seq, size);
	if (isDecr) {
		while (s >= 0) {
			inc = seq[s--];

			for (i = inc; i < size; i++) {
				T temp = a->find_by_iter(i)->value;
				for (j = i - inc; (j >= 0) && (a->find_by_iter(j)->value < temp); j -= inc)
					a->find_by_iter(j + inc)->value = a->find_by_iter(j)->value;
				a->find_by_iter(j + inc)->value = temp;
			}
		}
	}
	else {
		while (s >= 0) {
			inc = seq[s--];

			for (i = inc; i < size; i++) {
				T temp = a->find_by_iter(i)->value;
				for (j = i - inc; (j >= 0) && (a->find_by_iter(j)->value > temp); j -= inc)
					a->find_by_iter(j + inc)->value = a->find_by_iter(j)->value;
				a->find_by_iter(j + inc)->value = temp;
			}
		}
	}
}