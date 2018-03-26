#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		if (nums.size() ==0)
			return 0;
		if (nums[0] >= target)
			return 0;

		int prev = nums[0];
		int i = 1;
		for (;i < nums.size();i++)
		{
			if (target <= nums[i])
				return i;
		}
		return i;
	}
};

int main()
{
	vector<int> nums = { 1,3 };
	Solution x;
	cout << x.searchInsert(nums,4) << endl;
	return 0;
}