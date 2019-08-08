
#include <numeric>                                       // For accumulate() - sums a range of elements
#include <iostream>                                      // For standard streams
#include <iterator>                                      // For iterators and begin() and end()
#include <algorithm>                        // For transform()
#include <functional> // For function
#include <iomanip>                               // For stream manipulators
#include <array>                                 // For array<T,N>



class Root
{
public:
	double operator()(double x) { return std::sqrt(x); };
};


int usingstd_main() {
	{
		double data[]{ 2.5, 4.5, 6.5, 5.5, 8.5 };
		std::cout << "The array contains:\n";
		for (auto iter = std::begin(data); iter != std::end(data); ++iter)
			std::cout << *iter << " ";
		auto total = std::accumulate(std::begin(data), std::end(data), 0.0);
		std::cout << "\nThe sum of the array elements is " << total << std::endl;
	}
	//---
	{
		std::cout << "Enter numeric values separated by spaces and enter Ctrl+Z to end:" << std::endl;

		std::cout << "\nThe sum of the values you entered is "
			<< std::accumulate(std::istream_iterator<double>(std::cin),
				std::istream_iterator<double>(), 0.0)
			<< std::endl;
	}
	//---
	{
		double data[]{ 1.5, 2.5, 3.5, 4.5, 5.5 };

		// Passing a function object
		Root root;                                // Function object
		std::cout << "Square roots are:" << std::endl;
		std::transform(std::begin(data), std::end(data), std::ostream_iterator<double>(std::cout, " "), root);

		// Using an lambda expression as an argument
		std::cout << "\n\nCubes are:" << std::endl;
		std::transform(std::begin(data), std::end(data), std::ostream_iterator<double>(std::cout, " "), [](double x) {return x * x*x; });

		// Using a variable of type std::function<> as argument
		std::function<double(double)> op{ [](double x) { return x * x*x; } };
		std::cout << "\n\nSquares are:" << std::endl;
		std::transform(std::begin(data), std::end(data), std::ostream_iterator<double>(std::cout, " "), op);

		// Using a lambda expression that calls another lambda expression as argument
		std::cout << "\n\n4th powers are:" << std::endl;
		std::transform(std::begin(data), std::end(data), std::ostream_iterator<double>(std::cout, " "), [&op](double x) {return op(x)*op(x); });
		std::cout << std::endl;
	}
	//---
	{
		const unsigned int min_wt{ 100U };              // Minimum weight in table in lbs
		const unsigned int max_wt{ 250U };              // Maximum weight in table in lbs
		const unsigned int wt_step{ 10U };              // Weight increment
		const size_t wt_count{ 1 + (max_wt - min_wt) / wt_step };

		const unsigned int min_ht{ 48U };               // Minimum height in table in inches
		const unsigned int max_ht{ 84U };               // Maximum height in table in inches
		const unsigned int ht_step{ 2U };               // Height increment
		const size_t ht_count{ 1 + (max_ht - min_ht) / ht_step };

		const double lbs_per_kg{ 2.20462 };             // Conversion factor lbs to kg
		const double ins_per_m{ 39.3701 };              // Conversion factor ins to m

		std::array<unsigned int, wt_count> weight_lbs;
		std::array<unsigned int, ht_count> height_ins;

		// Create weights from 100lbs in steps of 10lbs
		for (size_t i{}, w{ min_wt }; i < wt_count; w += wt_step, ++i)
		{
			weight_lbs.at(i) = w;
		}

		// Create heights from 48 inches in steps of 2 inches
		unsigned int h{ min_ht };
		for (auto& height : height_ins)
		{
			height = h;
			h += ht_step;
		}

		// Output table headings
		std::cout << std::setw(7) << " |";
		for (const auto& w : weight_lbs)
			std::cout << std::setw(5) << w << "  |";
		std::cout << std::endl;

		// Output line below headings
		for (size_t i{ 1 }; i < wt_count; ++i)
			std::cout << "---------";
		std::cout << std::endl;

		double bmi{};                                 // Stores BMI
		unsigned int feet{};                          // Whole feet for output
		unsigned int inches{};                        // Whole inches for output
		const unsigned int inches_per_foot{ 12U };
		for (const auto& h : height_ins)
		{
			feet = h / inches_per_foot;
			inches = h % inches_per_foot;
			std::cout << std::setw(2) << feet << "'" << std::setw(2) << inches << "\"" << "|";
			std::cout << std::fixed << std::setprecision(1);
			for (const auto& w : weight_lbs)
			{
				bmi = h / ins_per_m;
				bmi = (w / lbs_per_kg) / (bmi*bmi);
				std::cout << std::setw(2) << " " << bmi << " |";
			}
			std::cout << std::endl;
		}
		// Output line below table
		for (size_t i{ 1 }; i < wt_count; ++i)
			std::cout << "---------";
		std::cout << "\nBMI from 18.5 to 24.9 is normal" << std::endl;
	}
	//---


	return 0;
};