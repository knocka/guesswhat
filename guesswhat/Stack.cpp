#include "pch.h"
#include "Stack.h"

int Stack::push(int n)
{
	if (isFull())
		return -1;
	else
		num[++top] = n;
	return n;
}

int Stack::pop() {
	if (isEmplty())
		return -1;

	return num[top--];
}

int Stack::isEmplty() {
	if (top < 0)
		return 1;
	return 0;
}

int Stack::isFull() {
	if (top >= SIZE)
		return 1;
	return 0;
}
void Stack::displayItems() const {
	if (top < 0) {
		cout << "stack empty" << endl;
		return;
	}
	cout << "top: " << top << " STACK is: ";
	for (int i = top; i >= 0; --i) {
		cout << "(" << i << ")";
		cout << num[i] << " ";
	}
	cout << endl;
}
