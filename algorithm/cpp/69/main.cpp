#include <iostream>

class Solution {
public:
	int mySqrt(int x) {
		if (x == 0)
			return 0;
		if (x < 0)
			return -1;
		unsigned tmp = x/2;
		if (tmp >= 46340) tmp = 46340;
		while (tmp*tmp != x)
		{
			if (tmp*tmp > x && (tmp-1)*(tmp-1) <x)
			{
				return tmp-1;
			}
			else if (tmp*tmp > x)
			{
				tmp /= 2;
			}
			else 
			{
				tmp = tmp + 1;
			}
		}
		return tmp;
	}
};

int main(int argc, char *argv[])
{
	Solution s;
	std::cout << s.mySqrt(2147395599);
	return 0;
}