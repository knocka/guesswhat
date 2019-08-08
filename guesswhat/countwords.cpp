
#include <iostream>     // std::cout
#include <sstream>      // std::istringstream
#include <string>       // std::string
#include <set>
#include <algorithm>

int countWords(std::string x) {
	int Num = 0;
	char prev = ' ';
	for (unsigned int i = 0; i < x.size(); i++) {
		if (x[i] != ' ' && prev == ' ') Num++;
		prev = x[i];
	}
	return Num;
}

int countwords_main() {

	std::string stringvalues = "125 320 512 750  333 abcdef   ";
	std::istringstream iss(stringvalues);
	std::set<std::string> v{};

	int num = countWords(stringvalues);
	std::cout << "num: " << num << std::endl;

	for (int n = 0; n < num; n++)
	{
		std::string val;

		iss >> val;

		v.insert(val);
		std::cout << val << '\n';
	}

	for (auto it = v.begin(); it != v.end(); it++)
		std::cout << *it << ":";
	std::cout << std::endl;

	return 0;
}
