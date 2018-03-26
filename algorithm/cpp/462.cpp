#include <stdlib.h>
class Solution {
public:
	int minMoves2(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int len = nums.size();
		if (len % 2 == 1)
		{
			len = len - 1;
		}
		len = len / 2;
		int ev = nums[len];
		int rtn = 0;
		for (int i = 0; i< nums.size(); i++)
		{
			rtn += abs(nums[i] - ev);
		}
		return rtn;
	}
};