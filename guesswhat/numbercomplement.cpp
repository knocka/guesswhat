#include <vector>
#include <iostream>
#include <bitset>
using namespace std;

class Solution {
public:
	int findComplement(int num) {
		int NO_OF_BITS = sizeof(num) * 8;
		unsigned int x_num = 0, i, temp;
		vector<int> v{};
		//cout <<  bitset<32>(num) << endl;
		for (i = 0; i < NO_OF_BITS; i++)
		{
			temp = (num >> i) & 1;
			//cout << "temp:" << bitset<32>(temp) << endl;
			v.push_back(temp);
		}
		cout << "size: " << v.size() << endl;

		int ii{ 0 };
		bool xxx = false;
		for (ii = NO_OF_BITS - 1; ii >= 0; ii--) {
			int x = v.at(ii);
			//cout << x << endl;
			if (xxx == false) {
				if (x > 0)
					xxx = true;
				else
					continue;
			}

			if (xxx) {
				cout << x << endl;
				if (x > 0) {
					x_num |= 0UL << ii;
					cout << "1-" << bitset<32>(x_num) << endl;
				}
				else {
					x_num |= 1UL << ii;
					cout << "0-" << bitset<32>(x_num) << endl;
				}
			}


		}
		//cout << x_num << endl;
		//cout << bitset<32>(x_num) <<endl;
		//cout << "-----------" << endl;
		return x_num;
	}
};