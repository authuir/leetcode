class Solution {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		vector<int> rtn;
		if (nums.size() <= 0)
			return rtn;

		vector<int> dp(nums.size() + 1, 1);
		for (int i = 0; i<nums.size(); i++)
			dp[nums[i]]--;
		for (int i = 0; i<dp.size(); i++)
		{
			if (dp[i]<0)
				rtn.push_back(i);
		}
		return rtn;
	}
};