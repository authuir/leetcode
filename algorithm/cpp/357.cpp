#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
	int countNumbersWithUniqueDigits(int n) {
		if (n <= 0) return 0;
		else if (n == 1) return 10;
		else{
			return this->countNumbersWithUniqueDigits(n-1) + this->fac(n-1)*(n-1) + this->fac(n);
		}
	}
private:
	int fac(int i)
	{
		int rtn = 1;
		int tmp = 9;
		while (i > 0)
		{
			rtn = rtn * tmp;
			tmp--;
			i--;
			if (tmp == 0)
				break;
		}
		return rtn;
	}
};

int main()
{
	Solution x;
	for (int i=0;i<15;i++)
		cout << x.countNumbersWithUniqueDigits(i) <<',';
	return 0;
}