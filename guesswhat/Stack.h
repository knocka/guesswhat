#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int SIZE(256);
class Stack {
private:
	int num[SIZE]{};
	int top{-1};
	//vector<array<int, SIZE>> num;
public:
	Stack() {
		std::fill_n(num, SIZE, 0);
		top = -1;
		cout << "Stack constructor" << endl;
	};
	~Stack() {
		cout << "Stack destructor" << endl;
	};
	int push(int);
	int pop();
	int isEmplty();
	int isFull();
	void displayItems() const;
};
