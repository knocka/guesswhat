#include <iostream>
using std::cout;
using std::cin;
using std::endl;

bool isPrime(int x) {

	for (int i = 2; i <= x / i; i++) {
		int factor = x / i;
		if (factor * i == x)
			return false;
	}
	return true;
};

int primenumber_main()
{
	int x;
	cout << "Enter a number" << endl;
	cin >> x;

	bool prime = true;
	int i = 2;

	prime = isPrime(x);
	//while (i <= x / i)
	//{
	//	int factor = x / i;
	//	if (factor*i == x)
	//	{
	//		cout << "factor found: " << i << " * " << factor << endl;
	//		prime = false;
	//		break;
	//	}
	//	i = i + 1;
	//}

	cout << x << " is ";
	if (prime)
		cout << "prime" << endl;
	else
		cout << "not prime" << endl;

	return 0;
}