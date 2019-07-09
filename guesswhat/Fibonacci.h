#pragma once
#include <vector>
#include <algorithm>
#include <iostream>

using std::vector;

class Fibonacci
{
	int num{ 0 };
	vector<int> v;
protected:
	int get(int x);
public:
	Fibonacci();
	inline Fibonacci(int n) { 
		num = n;
	} ;
	~Fibonacci();
	void process();
	void display();
};

