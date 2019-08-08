
#include <stdexcept>
#include <iostream>
#include <vector>
#include <utility>

std::pair<int, int> findTwoSum(const std::vector<int>& list, int sum)
{
	//throw std::logic_error("Waiting to be implemented");
	std::vector<std::pair<int, int>> v{};
	auto it1 = list.begin();
	auto size = list.size();
	auto it2 = list.end();
	auto it = it1;
	for (int i = 0; i < size-1; i++) {
		for (int j = 1; j < size; j++) {
			if ((it[i] + it[j]) == sum)
			{
				//v.push_back(std::pair<int, int> { *it, *(it + 1) });
				return std::pair<int, int> { it[i], it[j] };
			}
		}
	}
};

//#ifndef RunTests
int findtwosum_main()
{
	std::vector<int> list = { 3, 1, 5, 7, 5, 9 };
	std::pair<int, int> indices = findTwoSum(list, 10);
	std::cout << indices.first << '\n' << indices.second;
	return 0;
}
//#endif