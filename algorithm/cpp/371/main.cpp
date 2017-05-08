#include <iostream>
using namespace std;

class Solution {
public:
	int getSum(int a, int b) {
		int rtn = 0;
		int j = 0;
		for (int i = 0; i < 32; i++)
		{
			if (j == 0)
			{
				rtn += ((0x01 & (a >> i)) ^ (0x01 & (b >> i))) << i;
				j = ((0x01 & (a >> i)) & (0x01 & (b >> i)));
			}
			else
			{
				rtn += (!((0x01 & (a >> i)) ^ (0x01 & (b >> i)))) << i;
				j = ((0x01 & (a >> i)) | (0x01 & (b >> i)));
			}
		}
		return rtn;
	}
};

int main()
{
	Solution x;
	cout << x.getSum(1, 2);
	cout << x.getSum(-1, -2);
	return 0;
}