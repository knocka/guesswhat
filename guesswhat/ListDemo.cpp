
#include "pch.h"
#include "List.h"
#include "string"
using namespace std;

void listdemo_main() {
	List<string> L1{};
	cout << " Created an empty list: " << L1 << "\n\n";
	L1.InsertHead("a11");
	L1.InsertHead("b22");
	L1.InsertHead("c33");
	L1.InsertHead("d44");
	auto pos = L1.Find("b22");
	L1.InsertAfter(pos, "B22");
	cout << " Current list: " << L1 << "\n\n";
	auto pos1 = L1.Find("b22");
	L1.RemoveAfter(pos1);
	L1.RemoveHead();
	cout << " Current list: " << L1 << "\n\n";
	L1.printList();
	L1.Clear();

	cout << " Current list: " << L1 << "\n\n";
};