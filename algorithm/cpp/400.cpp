#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int findNthDigit(int n) {
		unsigned int nums = 1;
		unsigned int rtn;
		unsigned int cnt = 2;
		unsigned long long tho = 9;
		unsigned long long old_tho = 0;

		while (n > tho)
		{
			old_tho = tho;
			tho = tho + 9 * pow(10, cnt - 1)*cnt;
			cnt++;
		}

		if (old_tho != 0)
		{
			cnt -= 1;
			unsigned long long ys = n - old_tho;
			unsigned long long x = ys / cnt;
			unsigned long long x_cnt = ys % cnt;
			if (x_cnt == 1)
				cout << endl;
			if (x_cnt == 0)
			{
				unsigned long long tx = (x + pow(10, cnt - 1) - 1);
				return (tx % 10);
			}
				
			else
			{
				unsigned long long tx = ((x + pow(10, cnt - 1)));
				tx = tx / pow(10, cnt - x_cnt);
				return (tx % 10);
			}
				
		}
		else
		{
			return n;
		}
	}
};

int main()
{
	Solution x;
	for (int i = 788888889;i < 1000000010; i++)
	{
		cout << x.findNthDigit(i) << endl;

	}

	return 0;
}