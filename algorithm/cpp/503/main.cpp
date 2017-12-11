class Solution {
public:
	vector<int> nextGreaterElements(vector<int>& nums) {
		vector<int> rtn;

		for (int i = 0; i < nums.size(); i++)
		{
			int j = i + 1;
			for (; j%nums.size() != i; j++)
			{
				if (nums[j%nums.size()] > nums[i])
				{
					rtn.push_back(nums[j%nums.size()]);
					break;
				}
			}
			if (j%nums.size() == i)
				rtn.push_back(-1);
		}

		return rtn;
	}
};