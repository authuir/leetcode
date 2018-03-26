class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		bool tap = true;
		int rtn = 0;
		int counter = 0;
		for (int i = 0; i<nums.size(); i++)
		{
			if (tap)
			{
				if (nums[i] == 1)
				{
					counter = 1;
					tap = false;
				}
			}
			else
			{
				if (nums[i] == 0)
				{
					if (rtn<counter)
						rtn = counter;
					tap = true;
				}
				else {
					counter++;
				}
			}
		}
		if (rtn<counter)
			rtn = counter;
		return rtn;
	}
};