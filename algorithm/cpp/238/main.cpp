class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> rtn;
		long all_times = 1;
		int is_exsit_zero = 0;
		if (nums.size() <= 0)
			return rtn;
		for (auto iter = nums.begin(); iter != nums.end(); iter++)
		{
			if (*iter != 0)
				all_times = all_times * (*iter);
			else
				is_exsit_zero++;
		}

		for (int i = 0; i < nums.size(); i++)
		{
			if (is_exsit_zero == 0)
			{
				rtn.push_back(all_times / nums[i]);
			}
			else if (is_exsit_zero == 1)
			{
				if (nums[i] == 0)
					rtn.push_back(all_times);
				else
					rtn.push_back(0);
			}
			else
				rtn.push_back(0);
		}

		return rtn;
	}
};