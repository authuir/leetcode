#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> rtn;
		for (int i = 0; i < nums.size() - 1; i++)
		{
			for (int j = i + 1; j < nums.size(); j++)
			{
				if ((nums[i] + nums[j]) == target)
				{
					rtn.push_back(i);
					rtn.push_back(j);
					break;
				}
			}
		}
			
		return rtn;
	}
};

int main(int argc, char * argv[])
{
	Solution x;
	vector<int> input;
	input.push_back(2);
	input.push_back(3);
	input.push_back(5);
	input.push_back(7);
	cout << x.twoSum(input, 5)[0] << x.twoSum(input, 5)[1];
	return 0;
}