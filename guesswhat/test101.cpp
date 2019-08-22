#include <vector>
#include <algorithm>
#include <array>
#include <functional>
#include <set>
#include <deque>
#include <unordered_set>
#include <list>
#include <sstream>
#include <fstream>
#include <iostream>
#include <map>

using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {
	// Write your code here.
	vector<int> s{};
	int i = 0;
	for (auto it1 = array.begin(); it1 != array.end(); it1++) {
		i++;
		for (auto it2 = array.begin() + i; it2 != array.end(); it2++)
			if (*it1 + *it2 == targetSum) {
				int a = *it1;
				int b = *it2;
				s.push_back(a);
				s.push_back(b);
				std::sort(s.begin(), s.end(), [](int a, int b) {return a > b; });
				return s;
			}
	}
	return {};
}

vector<int> bubbleSort(vector<int> array) {
	// Write your code here.
	int i = 0;
	for (auto it1 = array.begin(); it1 != array.end(); it1++) {
		i++;
		for (auto it2 = array.begin(); it2 != array.end() - i; it2++) {
			if (*it2 > *(it2 + 1)) {
				int temp = *it2;
				*it2 = *(it2 + 1);
				*(it2 + 1) = temp;
			}
		}
	}
	return array;
}

int binarySearch(vector<int> array, int target) {
	// Write your code here.
	int left = 0;
	int right = array.size() - 1;
	while (left <= right) {
		int middle = (left + right) / 2;
		if (array[middle] == target) {
			return middle;
		}
		else if (array[middle] < target) {
			left = middle + 1;
		}
		else if (array[middle] > target) {
			right = middle - 1;
		}
	}
	return -1;
}


bool isPalindrome(string str) {
	// Write your code here.
	string str1, str2;


	for (auto it = str.begin(); it != str.end(); it++) {
		str1.push_back(*it);
		str2.push_back(*it);
	}
	reverse(str1.begin(), str1.end());

	//sort(str1.begin(), str1.end(), [](char a, char b) { return a > b; });
	//sort(str2.begin(), str2.end(), [](char a, char b) { return a < b; });
	if (str1 == str2)
		return true;
	else
		return false;
}

int getNthFib(int n) {
	// Write your code here.
	if (n == 1)
		return 0;
	if (n == 2)
		return 1;

	int out = getNthFib(n - 1) + getNthFib(n - 2);
	return out;

}

string caesarCypherEncryptor(string str, int key) {
	// Write your code here.
	string out{};
	int i = 0;
	if (key > 26)
		key = key % 26;
	for (auto it = str.begin(); it != str.end(); it++) {
		char a = *it;
		if (a + key > 'z')
			out.push_back('a' + (a + key - 'z' - 1));
		else
			out.push_back(a + key);
		i++;
	}
	return out;
}


vector<int> findThreeLargestNumbers(vector<int> array) {
	// Write your code here.
	sort(array.begin(), array.end());
	vector<int> arr1(array);
	vector<int> arr2(3);
	int i = 0;
	for (auto itr = arr1.end() - 3; itr != arr1.end(); itr++)
		arr2[i++] = *itr;

	return arr2;
}

set<int> myset = { 3, 1, 25, 7, 12 };
class Lsb_less {
public:
	bool operator()(int x, int y) {
		return(x % 10) < (y % 10);
	}
};

class NeedCopy {
public:
	bool operator()(int x) {
		return (x > 20) || (x < 5);
	}
};


vector<bool> multiStringSearch(string bigString, vector<string> smallStrings) {
	// Write your code here.
	vector<string> arr{};
	string s;
	stringstream ssin(bigString);
	while (ssin.good()) {
		ssin >> s;
		arr.push_back(s);
	}
	vector<bool> r{};

	for (int i = 0; i < smallStrings.size(); i++) {
		string s1 = smallStrings[i];
		bool found = false;
		for (int j = 0; j < arr.size(); j++) {
			string b1 = arr[j];
			found = true;
			for (int k = 0; k < s1.size(); k++) {
				if (s1[k] != b1[k]) {
					found = false;
					break;
				}
			}
			if (found) {
				r.push_back(true);
				break;
			}
		}
		if (!found)
           r.push_back(false);
	}
	return r;
}


//void json101() {
//	std::ifstream people_file("people.json", std::ifstream::binary);
//	people_file >> people;
//
//	cout << people; //This will print the entire json object.
//
//	//The following lines will let you access the indexed objects.
//	cout << people["Anna"]; //Prints the value for "Anna"
//	cout << people["ben"]; //Prints the value for "Ben"
//	cout << people["Anna"]["profession"]; //Prints the value corresponding to "profession" in the json for "Anna"
//
//	cout << people["profession"]; //NULL! There is no element with key "profession". Hence a new empty element will be created.
//}

void readfilex() {
	int sum = 0;
	int x;
	ifstream inFile;

	inFile.open("C:\\Users\\paullin\\Documents\\Workspace\\testcpp\\repos\\guesswhat\\x64\\Debug\\test.txt");
	if (!inFile) {
		cout << "Unable to open file";
		exit(1); // terminate with error
	}

	while (inFile >> x) {
		sum = sum + x;
	}

	inFile.close();
	cout << "Sum = " << sum << endl;
}

void invidi() {
	cout << "invidi" << endl;
	// [ 2 ] -> [ 16 ] -> [ 92 ] -> [ 16 ] -> [ 4 ] 
	std::cout << "This is a debug message" << std::endl;
	vector<int> in = { 2, 16, 92, 16, 4 };
	map<int, int> m{};
	for (int i = 0; i < in.size(); i++) {
		auto itr = m.find(in[i]);
		if (itr == m.end()) {
			m.insert(std::pair<int, int>(in[i], 1));
		}
		else {
			m[in[i]]++;
		}
	}

	int least_key = 0;
	int least_count = 0;
	int index = 0;
	for (auto it = m.begin(); it != m.end(); it++) {
		int key = (int)it->first;
		int val = (int)it->second;
		if (index < 1) {
			least_count = val;
			least_key = key;
		}
		else {
			if (val < least_count) {
				least_count = val;
				least_key = key;
			}
		}
		index++;
	}

	cout << "key:" << least_key << " , count:" << least_count << endl;

	//return 0;

}

vector<vector<int> > threeNumberSum(vector<int> array, int targetSum) {
	// Write your code here.
	vector<vector<int>> out;
	for (int i = 0; i < array.size(); i++) {
		for (int j = i + 1; j < array.size(); j++) {
			for (int k = j + 1; k < array.size(); k++) {
				int a = array[i];
				int b = array[j];
				int c = array[k];
				if (targetSum == a + b + c) {
					std::vector<int> s = { a, b, c };
					sort(s.begin(), s.end());
					out.push_back(s);
				}
			}
		}
	}
	sort(out.begin(), out.end(), [](vector<int> a, vector<int> b) 
	{ 
		if ((a[0] == b[0]) && a[1] == b[1])
			return a[2] < b[2];
		else if (a[0] == b[0])
			return a[1] < b[1];
		else
			return a[0] < b[0];
	});

	return out;
}


void test101() {
	invidi();
	//exit(0);
	readfilex();
	//vector<int> v = { 3, 5, -4, 9, 11, 1, -1, 6 };
	//vector<int> v = { 10, 5, 9, 10, 12 };
	vector<int> v = { 55, 7,8 };
	//vector<int> v = { 4,6,1 };
	//vector<int> r = twoNumberSum(v, 5);
	//vector<int> r = bubbleSort(v);
	//int x = binarySearch(r, 11);
	//isPalindrome("aba");
	//int x = getNthFib(1);
	//string s = caesarCypherEncryptor("abc", 52);

	//vector<int> r = findThreeLargestNumbers(v);
	set<int, Lsb_less> myset = { 3, 1, 25, 7, 12 };
	deque<int> d{};
	transform(myset.begin(), myset.end(),
		back_inserter(d),
		NeedCopy());

	//unordered_set<string> s = {"123", "abc", "xyz"};
	//list<string> s = { "123", "xyz", "abc", "xyz" };
	vector<string> s = { "123", "xyz", "abc", "xyz" };
	//unordered_set<string>::iterator itr;

	//auto itr = s.find("abc");
	//auto itr1 = find(s.begin(), s.end(), "xyz");
	sort(s.begin(), s.end());

	//string bs = "this is a big string";
	//vector<string> vs = {"this","yo","is","a","bigger","string","kappa" };
	string bs = "Mary goes to the shopping center every week.";
	vector<string> vs = { "to", "Mary", "centers", "shop", "shopping", "string", "kappa" };
	//string bs = "shopping center every week.";
	//vector<string> vs = { "shop", "shopping", "string", "kappa" };
	auto x = multiStringSearch(bs, vs);
	vector<int> n1 = { 12,3,1,2,-6,5,-8,6 };
	n1 = { 8, 10, -2, 49, 14 };
	int sum = 57;
	//ector<vector<int> > expected{ {-8, 2, 6}, {-8, 3, 5}, {-6, 1, 5} };
	//REQUIRE(threeNumberSum({ 12, 3, 1, 2, -6, 5, -8, 6 }, 0) == expected);
	n1 = { 12,3,1,2,-6,5,-8,6 };
	sum = 0;
	auto y = threeNumberSum(n1, sum);
}