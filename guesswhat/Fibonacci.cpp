#include "Fibonacci.h"
using namespace std;

Fibonacci::Fibonacci()
{
};


Fibonacci::~Fibonacci()
{
};

int Fibonacci::get(int x) {
	if (x == 0)
		return 0;
	if (x == 1)
		return 1;
	int out = get(x - 1) + get(x - 2);
	return out;
};

void Fibonacci::process() {
	cout << "process" << endl;
	for (int i{ 0 }; i < num; i++) {
		v.push_back(get(i));
	}
};

void Fibonacci::display() {
	cout << "Fibonacci size: " << v.size() << endl;
	for (int e : v) {
		cout << e << "  ";
	}
	cout << endl;
};
