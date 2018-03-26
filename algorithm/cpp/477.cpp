class Solution {

public:
	int totalHammingDistance(vector<int>& nums) {
		int rtn = 0;
		if (nums.size() <= 1)
			return 0;

		for (int i = 0; i < 32; i++)
		{
			int cnt = 0;
			for (int j = 0; j < nums.size(); j++)
				if (nums[j] >> i & 0x01 == 1)
					cnt++;

			rtn = rtn + cnt*(nums.size() - cnt);
		}

		return rtn;
	}
};