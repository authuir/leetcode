#include <iostream>
using namespace std;

class Solution {
public:
	bool isPerfectSquare(int num) {
		if (num == 1) return true;
		if (num<4) return false;

		int last = num / 2;
		if (last*last == num) return true;
		for (int i = 2; i <= last; i++)
		{
			if (i*i == num) return true;
		}
		return false;
	}
};

int main()
{
	Solution x;
	x.isPerfectSquare(4);
	return 0;
}