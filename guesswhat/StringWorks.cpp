
#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstring>

int(*func)(std::string);

void str2array(const std::string &s_input, int s_input_size, std::vector<std::string> &output) {
	//char input[100] = "A bird came down the walk";
	//char *input = _strdup(s_input);                /* Make writable copy.  */
	std::string s2_input = s_input;
	int input_size = s_input.size();
	char *input = new char[input_size + 1];

	strcpy_s(input, input_size+1, s_input.c_str());

	char *token = strtok_s(input, " ", &input);
	while (token != NULL) {
		//std::cout << token << '\n';
		output.push_back(token);
		token = strtok_s(NULL, " ", &input);
	}

	//delete [] input;
};

void str2array_test() {
	std::string input = "A bird came down the walk";
	std::vector<std::string> v;
	str2array(input, input.size(), v);
	for (std::string item : v) {
		std::cout << item << " " << std::endl;
	}
};