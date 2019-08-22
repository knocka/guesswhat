// guesswhat.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Stack.h"
#include "WordsMachine.h"
#include "Fibonacci.h"
#include "DailyUsed.h"
#include "binarysearchtree.h"


using namespace std;
extern void test103();
extern void test102();
extern void test101();
extern int usingstd_main();
extern int findtwosum_main();
extern int binarytreesearch_main();
extern int primenumber_main();
extern void listdemo_main();
extern int stackoverflowdemo_main();
extern int stackdemo1_main();
extern int binarysearch_main();
extern void templatejungle_test();
extern int ploygon_main();
extern int btree_main();
extern void str2array_test();
extern int quicksort_main(); 
void playground();


template <typename T>
T GetMax(T a, T b) {
	std::cout << "T is: " << typeid(T).name() << '\n';

	T result;
	result = (a > b) ? a : b;
	return (result);
}

int test_main() {
	int i = 5, j = 6, k;
	long l = 10, m = 5, n;
	k = GetMax<int>(i, j);
	n = GetMax<long>(l, m);
	k = GetMax(i, j);

	cout << k << endl;
	cout << n << endl;
	return 0;
}

void test_split(const string &txt) {
	vector<string> strs;
	WordsMachine WM;
	size_t n_elements;
	n_elements = WM.split(txt, strs, ' ');
	cout << n_elements << endl;
	cout << "---" << endl;
	auto WM1 = new WordsMachine();
	n_elements = WM1->split(txt, strs, ' ');
	delete WM1;
	cout << n_elements << endl;
}

void words_machine(const string &txt) {
	vector<string> strs;
	auto WM = WordsMachine();
	size_t n = WM.split(txt, strs, ' ');
	for (int i = 0; i < n; i++) {
		string cmd = strs[i];
		size_t code = WM.cmd_code(cmd);
		WM.cmd_process(code, cmd);
	}
	WM.displayItems();
}



// Function to return the only odd occurring element 
int findOdd(int arr[], int n) {
	int res = 0, i;
	for (i = 0; i < n; i++)
		res ^= arr[i];
	return res;
}

void swap(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
};

//quick sort
void sortme(int*a, int n) {
	int i{ 0 }, j{ 0 }, min, temp;
	for (; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++) {
			if (a[min] > a[j])
				min = j;
		}
		if (i!=j)
		  swap(a[i], a[min]);
	}
};

void bubblesort(int*a, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (a[j] > a[j + 1]) {
				int temp = a[j+1];
				a[j + 1] = a[j];
				a[j] = temp;
			}
		}
	}
};

#include <forward_list> 
#include <iterator> 
#include "Box.h"
extern int async_main();
extern int thread_main();
extern int countwords_main();
int main()
{
	test103();
	test102();
	test101();
	
	countwords_main();
	thread_main();
	async_main();
	{
		std::forward_list<string> l1 {"123", "abc", "xyz", "987"};
		auto b = l1.begin();
		auto e = l1.end();
		while (b != e) {
			cout << *b++ << " ";
		}
		cout << endl;
	}
	{
		std::forward_list<Box> boxes;
		std::copy(std::istream_iterator<Box>(std::cin), std::istream_iterator<Box>(), std::front_inserter(boxes));

		boxes.sort();                                    // Sort the boxes
		std::cout << "\nAfter sorting the sequence is:\n";
		// Just to show that we can with Box objects - use an ostream iterator
		std::copy(std::begin(boxes), std::end(boxes), std::ostream_iterator<Box>(std::cout, " "));
		std::cout << std::endl;
	}
	bool askMore{ true };
	usingstd_main();
	//return 0;
	findtwosum_main();
	//return 0;
	binarytreesearch_main();
	//return 0;
	primenumber_main();
	//return 0;
	listdemo_main();
	//return 0;

	stackoverflowdemo_main();
	//stackdemo1_main();
	//binarysearch_main();

	templatejungle_test();
	
	test_main();
	quicksort_main();

	DailyUsed DU =  DailyUsed();
	DU.explore();
	
	str2array_test();
	
	auto FB{ Fibonacci(12) };
	FB.process();
	FB.display();
	
	int arr[] = { 12, 12, 14, 90, 14, 14, 14};
	int siz = sizeof(arr) / sizeof(arr[0]);
	sortme(arr,  siz);
	for (int i = siz - 1; i >= 0; i--)
		cout << arr[i] << " ";
	cout << endl;

	bubblesort(arr, siz);

	for (int i = siz - 1; i >= 0; i--)
		cout << arr[i] << " ";
	cout << endl;

	int n = sizeof(arr) / sizeof(arr[0]);
	string flowerLine(8, '*');
	cout << flowerLine << '\n';
	printf("The odd occurring element is %d ", findOdd(arr, n));

	btree_main();
	ploygon_main();

	string txt = "13 DUP 4 POP 5 DUP + DUP + DUP + -";
	test_split(txt);
	words_machine(txt);
	txt = "13 DUP 4 POP 5 DUP + DUP + DUP + - + + 13 DUP 4 POP 5 DUP + DUP + DUP + -";
	words_machine(txt);
	
	//playground();

	return 0;
}

void playground() {
	int n1 = 5;
	int cc = 0;

	while (n1--)
	{
		cc = cc + 1;
	}
	std::cout << cc << ":" << n1 << endl;
	n1 = 5;
	cc = 0;

	while (--n1) {
		cc = cc + 1;
	}
	std::cout << cc << ":" << n1 << endl;

	for (int i = 0; i < n1; ++i) {
		cc = i;
	}

	cc = 0;

	for (int i = 0; i < n1; i++) {
		cc = i;
	}

	int qq = 0;
	std::cout << qq + 1;

	std::cout << "Hello World!\n";

	int a = 5, b = 6, c, d;

	c = a, b;

	d = (a, b);

	cout << c << 't' << d;

	int i, j;

	j = 10;

	i = (j++, j + 100, 999 + j);

	cout << i;

	int a1 = 5, b1 = 10, c1 = 15;

	int *arr[] = { &a1, &b1, &c1 };

	cout << arr[1] << endl;

	int n;

	n = 43;

	cout << hex << n << oct << n << dec << n << endl;
}





// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


