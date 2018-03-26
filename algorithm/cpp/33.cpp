#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.size() <= 0)
			return -1;
		int change_point = 0;
		int last_val = nums[0];
		int rtn = -1;
		if (target == nums[0])
			rtn = 0;
		for (int i = 1; i< nums.size(); i++)
		{
			if (nums[i] < last_val)
				change_point = i;

			if (target == nums[i])
				rtn = i;
		}
		if (rtn == -1)
			return rtn;
		// if (rtn < change_point)
		//     rtn = nums.size() - rtn;
		// else if (rtn >= change_point)
		//     rtn = rtn - change_point;
		return rtn;
	}
};

int main(int argc, char const *argv[])
{
	return 0;
}