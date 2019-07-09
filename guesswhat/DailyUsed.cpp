
#include "pch.h"
#include <vector>
#include <array>
#include <iterator>
#include <iostream>
#include <algorithm>
#include "DailyUsed.h"

using namespace std;

void DailyUsed::explore()
{
	vector_test();
	span_test();
	array_test();
	count_test();
	find_test();
}

void DailyUsed::vector_test()
{
	std::vector<int> v = { 7, 5, 16, 8 };

	// Add two more integers to vector
	v.push_back(25);
	v.push_back(13);

	// Iterate and print values of vector
	for (int n : v) {
		std::cout << n << '\n';
	}
};

void DailyUsed::span_test()
{
};

void DailyUsed::array_test()
{
	// construction uses aggregate initialization
	std::array<int, 3> a1{ {1, 3, 2 } }; // double-braces required in C++11 prior to the CWG 1270 revision
										// (not needed in C++11 after the revision and in C++14 and beyond)
	std::array<int, 3> a2 = { 1, 2, 3 };  // never required after =
	std::array<std::string, 2> a3 = { std::string("a"), "b" };

	// container operations are supported
	std::sort(a1.begin(), a1.end());
	std::reverse_copy(a2.begin(), a2.end(),
		std::ostream_iterator<int>(std::cout, " "));

	std::cout << '\n';

	// ranged for loop is supported
	for (const auto & s : a3)
		std::cout << s.c_str() << ' ';
}
void DailyUsed::count_test()
{
	std::vector<int> v{ 1, 2, 3, 4, 4, 3, 7, 8, 9, 10 };
	std::vector<string> sv{ "hello", "world", "good", "hello" };

	// determine how many integers in a std::vector match a target value.
	int target1 = 3;
	int target2 = 5;
	int num_items1 = std::count(v.begin(), v.end(), target1);
	int num_items2 = std::count(v.begin(), v.end(), target2);
	std::cout << "number: " << target1 << " count: " << num_items1 << '\n';
	std::cout << "number: " << target2 << " count: " << num_items2 << '\n';
	//int num_itemsv = std::count(sv.begin(), sv.end(), target1);

	// use a lambda expression to count elements divisible by 3.
	int num_items3 = std::count_if(v.begin(), v.end(), [](int i) {return i % 3 == 0; });
	std::cout << "number divisible by three: " << num_items3 << '\n';
}
void DailyUsed::find_test()
{
	int n1 = 3;
	int n2 = 5;

	std::vector<int> v{ 0, 1, 2, 3, 4 };
	std::vector<string> sv{ "hello", "world", "good", "hello" };
	auto result3 = std::find(std::begin(sv), std::end(sv), "hello");

	auto result1 = std::find(std::begin(v), std::end(v), n1);
	auto result2 = std::find(std::begin(v), std::end(v), n2);

	if (result1 != std::end(v)) {
		std::cout << "v contains: " << n1 << '\n';
	}
	else {
		std::cout << "v does not contain: " << n1 << '\n';
	}

	if (result2 != std::end(v)) {
		std::cout << "v contains: " << n2 << '\n';
	}
	else {
		std::cout << "v does not contain: " << n2 << '\n';
	}
}

#include <algorithm>
#include <iostream>
#include <iterator>
#include <tuple>
#include <utility>
#include <vector>

//template <typename T>
//std::ostream& operator<<(std::ostream& o, std::vector<T> const& data)
//{
//	std::copy_n(begin(data), size(data) - 1,
//		std::ostream_iterator<T>{o, ", "});
//	return o << data.back();
//};

template <typename I, typename S>
std::ostream& write_range(std::ostream& o, I const& first, S const& last)
{
	using std::prev;
	if (first != last) {
		std::copy(first, prev(last), std::ostream_iterator<int>{o, ", "});
		o << *prev(last);
	}
	return o;
};

void DailyUsed::range_test()
{
	//auto v = std::vector<std::istream_iterator<int>> ({std::cin}, {});
	//std::cout << "pre-sorted range: " << v << '\n';
	//std::sort(begin(v), end(v));
	//std::cout << "post-sorted range: " << v << '\n';
	//{
	//	auto const even_only = [&v] {
	//		auto result = v;
	//		result.erase(std::remove_if(begin(result), end(result), [](auto const i) noexcept {
	//			return i % 2 != 0; }), end(result));
	//		return result;
	//	}();
	//	std::cout << "even-only range: " << even_only << '\n';

	//	auto const unique = [&even_only] {
	//		auto result = decltype(even_only){};
	//		std::unique_copy(begin(even_only), end(even_only), back_inserter(result));
	//		return result;
	//	}();
	//	std::cout << "unique range: " << unique << '\n';
	//}
	/*{
		auto [mod3_order, remainder1, remainder2] = [&v] {
			auto result = v;
			auto remainder1 = std::partition(begin(result), end(result),
				[](auto const i) noexcept { return i % 3 == 0; });
			auto remainder2 = std::stable_partition(remainder1, end(result),
				[](auto const i) noexcept { return i % 3 == 1; });
			return std::make_tuple(std::move(result), remainder1, remainder2);
		}();
		std::cout << "elements % 3 == 0: ";
		write_range(std::cout, begin(mod3_order), remainder1) << '\n';

		std::cout << "elements % 3 == 1: ";
		write_range(std::cout, remainder1, remainder2) << '\n';

		std::cout << "elements % 3 == 2: ";
		write_range(std::cout, remainder2, end(mod3_order)) << '\n';
	}*/
};
