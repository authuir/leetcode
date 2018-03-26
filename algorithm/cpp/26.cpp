#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		int tmp;
		bool flag = true;
		tmp = nums[0];
		for (vector<int>::iterator iter = nums.begin()+1 ;iter != nums.end();)
		{

			if ( (*iter) == tmp )
			{
				iter = nums.erase(iter);
			}
			else
			{
				tmp = *iter;
				++iter;
			}
		}
		return nums.size();
	}
};

int main(int argc, char * argv[])
{
	Solution x;

	vector<int> input;
	input.push_back(1);

	cout << x.removeDuplicates(input) << endl;
	return 0;
}
