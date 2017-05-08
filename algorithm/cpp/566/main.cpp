#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
		if (nums.size() == NULL) return nums;
		if (nums.size()*nums[0].size() != r*c) return nums;
		vector<vector<int>> rtn;
		vector<int> tmp;
		for (int i = 0; i<r*c; i++)
		{
			if (i%c == 0 && i != 0)
			{
				rtn.push_back(tmp);
				tmp.clear();
			}
			int rr = i/nums[0].size();		//r
			int cc = i%nums[0].size();	//c

			tmp.push_back(nums[rr][cc]);
		}
		if (tmp.size() != 0)
			rtn.push_back(tmp);
		return rtn;
	}
};

int main()
{
	Solution x;
//	x.matrixReshape(vector<vector<int>>{vector<int>{1, 2, 3, 4}}, 2, 2);
	x.matrixReshape(vector<vector<int>>{vector<int>{1, 2}, vector<int>{ 3, 4}}, 1, 4);

	return 0;
}