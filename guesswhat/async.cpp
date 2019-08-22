#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <future>
#include <string>
#include <mutex>
#include <thread>
#include <functional>

int foo() {
	/* Do something here, then return the result. */
	std::cout << "foo" << std::endl;
	return 1000;
};

int async_main() {
	auto handle = std::async(std::launch::async, foo);  // create an async task
	std::cout << "wait" << std::endl;
	auto result = handle.get();  // wait for the result
	std::cout << result << std::endl;
	return 0;
};

void foo1(bool clause) { 
	/* do something... */
	std::cout << "foo1: " << clause << std::endl;
};

int thread_main() {
	std::vector<std::thread> threadsVector;
	threadsVector.emplace_back([]() {
		// Lambda function that will be invoked  
		std::cout << "lambda thread" << std::endl;
	});
	threadsVector.emplace_back(foo1, true);  // thread will run foo(true)
	for (auto& thread : threadsVector) {
		thread.join(); // Wait for threads to finish
	}
	return 0;
};