#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
	int fac(int x)
	{
		int i, f = 1;
		for (i = 1;i <= x;i++)
			f *= i;
		return f;
	}
	int nums2delete(int x)
	{
		if (x == 0) return 0;
		else if (x == 1) return 0;
		else if (x == 2) return 9;
		else {
			int rtn = 9 * 9 * (fac(x - 1) - 1) + 9 + nums2delete(x - 1);
			return rtn;
		}
		return 0;
	}
	int countNumbersWithUniqueDigits(int n) {
		return pow(10, n) - nums2delete(n);
	}
};

int main()
{
	Solution x;
	cout << x.countNumbersWithUniqueDigits(3);
	return 0;
}