#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.size() <= 0)
			return 0;
		if (nums.size() == 1)
			return nums[0];
		int rtn = nums[0];
		int sum = nums[0];
		int tmp = 0;
		for (int i = 1;i < nums.size(); i++)
		{
			tmp = sum + nums[i];
			if (sum >= 0 && nums[i] >= 0)
			{
				sum = sum + nums[i];
				rtn = max(rtn, sum);
			}
			else if (sum >= 0 && nums[i] < 0)
			{
				sum = sum + nums[i];
				rtn = max(rtn, sum);
			}
			else if (sum < 0 && nums[i] >= 0)
			{
				sum = nums[i];
				rtn = max(rtn, sum);
			}
			else if (sum < 0 && nums[i] < 0)
			{
				sum = 0;
				rtn = max(rtn, nums[i]);
			}

		}

		return rtn;
	}
};


int main()
{
	Solution s;
	vector<int> input = { -2,-3,-1 };
	cout << s.maxSubArray(input);
	input = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	cout << s.maxSubArray(input);
	return 0;
}