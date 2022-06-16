#pragma once
#include <iostream>

using namespace std;

class stack112 {
	char* arr = nullptr;
	int curr_size = 0;
	int max_size = 0;
public:
	stack112(size_t max) {
		this->max_size = max;
		this->arr = new char[max];
	}

	stack112(const stack112& st) {
		this->curr_size = st.curr_size;
		this->max_size = st.max_size;
		this->arr = new char[this->max_size + 1];
		for (size_t i = 0; i < this->curr_size; i++) {
			this->arr[i] = st.arr[i];
		}
	}

	stack112& operator=(const stack112& st) {
		if (this == &st)
			return *this;
		this->~stack112();
		this->curr_size = st.curr_size;
		this->max_size = st.max_size;
		this->arr = new char[this->max_size];
		for (size_t i = 0; i < this->curr_size; i++) {
			this->arr[i] = st.arr[i];
		}
		return *this;
	}

	stack112(stack112&& st) {
		swap(this->max_size, st.max_size);
		swap(this->curr_size, st.curr_size);
		swap(this->arr, st.arr);
	}

	stack112& operator=(stack112&& st) {
		swap(this->max_size, st.max_size);
		swap(this->curr_size, st.curr_size);
		swap(this->arr, st.arr);
		return *this;
	}

	bool fool() const {
		return this->curr_size == this->max_size;
	}

	bool empty() const {
		return this->curr_size == 0;
	}

	void push(char ch) {
		if (!this->fool()) {
			this->arr[this->curr_size] = ch;
			this->curr_size++;
		}
		else
			cout << "Stack overflow." << endl;
	}

	void pop() {
		if (!this->empty()) {
			this->curr_size--;
		}
		else
			cout << "Stack is emty." << endl;
	}

	char top() const {
		return this->arr[this->curr_size - 1];
	}

	char& top() {
		return this->arr[this->curr_size - 1];
	}

	int size() const {
		return this->curr_size - 1;
	}

	int get_max_size() const {
		return this->max_size;
	}

	void print() const {
		for (size_t i = 0; i < this->curr_size; i++)
		{
			cout << this->arr[i] << "\t";
		}
	}

	~stack112() {
		if (this->arr != nullptr) {
			delete[] this->arr;
			this->arr = nullptr;
			this->curr_size = 0;
			this->max_size = 0;
		}
	}







};