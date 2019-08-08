class Solution {
public:
	int hammingDistance(int x, int y) {
		//cout << bitset<32>(x) << endl;
		//cout << bitset<32>(y) << endl;
		int x1{ 0 }, y1{ 0 }, count{ 0 };
		x1 = x;
		y1 = y;
		//cout << sizeof(int) << endl;
		for (int i = 1; i < (8 * sizeof(int)); i++) {
			x1 &= 1;
			y1 &= 1;
			//cout << bitset<32>(x1) << endl;
			//cout << bitset<32>(y1) << endl;
			//cout << "x1: " << x1 << ", y1: " << y1 << endl;
			if (x1 != y1) count++;
			x1 = x >> i;
			y1 = y >> i;
		}
		//std::cout << count << endl;
		return count;
	}
};