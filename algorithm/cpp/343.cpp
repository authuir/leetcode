#include <iostream>

using namespace std;

class Solution {
public:
	int integerBreak(int n) {
		int rtn = 0;
		for (int i = 2;;i++)
		{
			int tmp = 1;
			int x = floor((float)n / (float)i);
			int x_1 = n - i*x;

			for (int j = 0; j < i; j++)
			{
				if (x_1 > 0)
				{
					tmp = tmp * (x + 1);
					x_1--;
				}
				else
					tmp = tmp * x;
			}
			if (tmp > rtn)
				rtn = tmp;

			if (x == 1)
				break;
		}
		return rtn;
	}
};

int main()
{
	Solution x;
	x.integerBreak(4);
}