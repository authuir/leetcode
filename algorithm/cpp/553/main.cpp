#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
	string optimalDivision(vector<int>& nums) {
		string rtn;
		if (nums.size() <= 0)
			return rtn;
		else if (nums.size() == 1) {
			rtn = to_string(nums[0]);
			return rtn;
		}
		else if (nums.size() == 2)
		{
			rtn = to_string(nums[0]) + "/" + to_string(nums[1]);
			return rtn;
		}
		rtn = to_string(nums[0]) + "/(" + to_string(nums[1]);
		for (int i = 2; i < nums.size();i++)
		{
			rtn = rtn + "/" + to_string(nums[i]);
		}
		rtn = rtn + ")";
		return rtn;
	}
};

int main()
{
	Solution x;
	ostringstream so;
	so << x.optimalDivision(vector<int> {1000, 100, 10, 2});
	cout << so.str(); 
	return 0;
}