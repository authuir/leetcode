class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
		vector<int> rtn;
		for (int i = 0; i<findNums.size(); i++)
		{
			auto iter = find(nums.begin(), nums.end(), findNums[i]);
			int flag = 0;
			while (iter + 1 != nums.end())
			{
				iter++;
				if (*iter > findNums[i])
				{
					rtn.push_back(*iter);
					flag = 1;
					break;
				}
			}
			if (flag == 0)
				rtn.push_back(-1);
		}
		return rtn;
	}
};