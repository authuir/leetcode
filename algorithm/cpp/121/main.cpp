#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int rtn = 0;
		int size = prices.size();
		if ( size <= 1 )
			return rtn;
		vector<int> max;
		vector<int> min;
		min.assign(size, 0);
		max.assign(size, 0);
		min[0] = prices[0];
		max[size - 1] = prices[size - 1];

		for (int i = 1; i < size; i++)
		{
			if (prices[i] < min[i - 1])
				min[i] = prices[i];
			else
				min[i] = min[i - 1];

			if (prices[size -1 - i] > max[size - i])
				max[size-i - 1] = prices[size-1-i];
			else
				max[size-i - 1] = max[size - i];
		}
		for (int i = 0; i < size; i++)
		{
			if (rtn < (max[i] - min[i]))
				rtn = max[i] - min[i];
		}
		return rtn;
	}
};

int main()
{
	Solution x;
	cout << x.maxProfit(vector<int>{7, 1, 5, 3, 6, 4});
	return 0;
}