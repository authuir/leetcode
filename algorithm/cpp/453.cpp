#include <algorithm>

class Solution {
public:
	int minMoves(vector<int>& nums) {
		if (nums.size() <= 1) return 0;
		sort(nums.begin(), nums.end());
		int* ax = new int[nums.size() - 1];
		for (int i = 0; i < nums.size() - 1; i++)
		{
			ax[i] = nums[i + 1] - nums[i];
		}
		int rtn = 0;
		for (int i = 0; i < nums.size() - 1; i++)
		{
			rtn += ax[i] * (nums.size() - 1 - i);
		}
		return rtn;
	}
};