class Solution {
public:
	int singleNonDuplicate(vector<int>& nums) {
		if (nums.size() == 0 || nums.size() % 2 != 1)
			return 0;
		if (nums.size() == 1)
			return nums[0];
		for (int i = 0; i<nums.size(); i += 2)
		{
			if (nums[i] != nums[i + 1])
				return nums[i];
		}
		return nums.back();
	}
};