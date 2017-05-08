#include <sstream>

class Solution {
public:
	vector<string> findRelativeRanks(vector<int>& nums) {
		if (nums.size() <= 0)
			return vector<string>{};
		if (nums.size() == 1)
			return vector<string>{"Gold Medal"};
		if (nums.size() == 2)
		{
			if (nums[0] <= nums[1])
				return vector<string>{"Silver Medal", "Gold Medal"};
			else
				return vector<string>{"Gold Medal", "Silver Medal"};
		}
		vector<string> rtn;
		vector<int> tmp = nums;
		sort(tmp.begin(), tmp.end());
		reverse(tmp.begin(), tmp.end());
		map<int, string> rank;
		for (int iter = 0; iter < tmp.size(); iter++)
		{
			string rt;

			if (iter == 0)
				rt = "Gold Medal";
			else if (iter == 1)
				rt = "Silver Medal";
			else if (iter == 2)
				rt = "Bronze Medal";
			else
			{
				stringstream ss;
				ss << (1 + iter);
				ss >> rt;
			}
			rank.insert({ tmp[iter],rt });
		}
		for (int iter = 0; iter < tmp.size(); iter++)
		{
			rtn.push_back(rank[nums[iter]]);
		}
		return rtn;
	}
};