#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int rtn = 0;
		int status = 0; // 0:Free 1:Holding
		int holding = 0;
		int size = prices.size();

		if (size <= 1) return rtn;

		for (int i = 0; i < size - 1; i++)
		{
			if ((prices[i] < prices[i + 1]) && status == 0)
			{
				holding = prices[i];
				status = 1;
			}
			else if ((prices[i] > prices[i + 1]) && status == 1)
			{
				rtn += prices[i] - holding;
				status = 0;
			}
			else if ((prices[i] == prices[i + 1]) && status == 1)
			{
				rtn += prices[i] - holding;
				status = 0;
			}
		}
		if (status == 1)
		{
			rtn += prices[size-1] - holding;
			status = 0;
		}
		return rtn;
	}
};

int main()
{
	Solution x;
	cout << x.maxProfit(vector<int>{1,2});
	return 0;
}