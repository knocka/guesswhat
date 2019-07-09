#include "pch.h"
#include "TemplateJungle.h"

void templatejungle_test() {
	cout << "templatejungle_test" << endl;
	cout << hello_add(1, 2) << endl;
	cout << hello_add(1.1, 2.2) << endl;
	cout << hello_add<string>("123", "abc") << endl;
	string a{ "hello" }, b{ "world" };
	cout << hello_add(a, b) << endl;
	Hello<int> H1{ 1 }, H2{ 2 };
	cout << (H1 + H2).x() << endl;
	Hello<double> Hd1{ 1.1 }, Hd2{ 2.2 };
	cout << (Hd1 + Hd2).x() << endl;
	Hello<string> Hs1{ "abc" }, Hs2{ "123" };
	cout << (Hs1 + Hs2).x() << endl;
};