
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Stack.h"
#include "WordsMachine.h"

size_t WordsMachine::split(const string &txt, vector < string> & strs, char ch) {
	size_t initPos = 0;
	size_t pos = txt.find(ch);
	strs.clear();
	cout << "npos: " << string::npos << endl;
	while (pos != string::npos) {
		strs.push_back(txt.substr(initPos, pos - initPos));
		initPos = pos + 1;
		pos = txt.find(ch, initPos);
		cout << pos << endl;
	}

	cout << pos << endl;
	size_t txtSize = txt.size();
	size_t lastPos = min(pos, txtSize);
	strs.push_back(txt.substr(initPos, lastPos - initPos + 1));
	return strs.size();
};

size_t WordsMachine::cmd_code(const string & cmd) {
	size_t code = 1;
	if (cmd.compare("POP") == 0)
		code = 2;
	if (cmd.compare("DUP") == 0)
		code = 3;
	if (cmd.compare("+") == 0)
		code = 4;
	if (cmd.compare("-") == 0)
		code = 5;
	return code;
};

void WordsMachine::cmd_process(const size_t code, const string & cmd) {
	int temp(0), temp1(0);
	int n(0);
	switch (code) {
	case 1: //int
		std::string::size_type sz;   // alias of size_t
		n = std::stoi(cmd, &sz);
		temp = stk->push(n);
		if (temp < 0)
			cout << "STACK is FULL." << endl;
		else
			cout << temp << " inserted." << endl;
		break;
	case 2: //POP
		temp = stk->pop();
		if (temp < 0)
			cout << "STACK is EMPTY." << endl;
		else
			cout << temp << " popped." << endl;
		break;
	case 3: //DUP
		temp1 = stk->pop();
		temp = stk->push(temp1);
		temp = stk->push(temp1);
		break;
	case 4: //+
		temp = stk->pop();
		temp1 = stk->pop();
		stk->push(temp1);
		stk->push(temp);
		temp = temp1 + temp;
		stk->push(temp);
		break;
	case 5:  //-
		temp = stk->pop();
		temp1 = stk->pop();
		stk->push(temp1);
		stk->push(temp);
		temp = temp1 - temp;
		stk->push(temp);
		break;
	default:
		break;
	}
};

