class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		vector<int> rtn;
		int* xi = new int[nums.size()];
		for (int i = 0; i<nums.size(); i++)
		{
			xi[i] = 0;
		}
		for (int i = 0; i<nums.size(); i++)
		{
			xi[nums[i] - 1] = 1;
		}
		for (int i = 0; i<nums.size(); i++)
		{
			if (xi[i] == 0)
			{
				rtn.push_back(i + 1);
			}
		}
		delete xi;
		return rtn;
	}
};