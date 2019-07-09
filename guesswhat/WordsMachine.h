#pragma once
#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Stack.h"

class WordsMachine {
private:
	Stack *stk;
public:
	WordsMachine() {
		stk = new Stack();
		cout << "defaut constructor" << endl;
	};
	~WordsMachine() {
		delete stk;
		cout << "default destructor" << endl;
	}
	size_t split(const string &txt, vector<string> &strs, char ch);
	size_t cmd_code(const string & cmd);
	void cmd_process(const size_t code, const string & cmd);
	void displayItems() {
		stk->displayItems();
	}
};