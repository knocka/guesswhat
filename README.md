# guesswhat
c++ tips

- When a function is declared as const, it can be called on any type of object. Non-const functions can only be called by non-const objects.

For example the following program has compiler errors.
--
#include<iostream> 
using namespace std; 

class Test { 
	int value; 
public: 
	Test(int v = 0) {value = v;} 
	//ERROR int getValue() {return value;} 
	int getValue() const {return value;} //PASS 
}; 

int main() { 
	const Test t; //TEST HERE 
	cout << t.getValue(); 
	return 0; 
} 
--
