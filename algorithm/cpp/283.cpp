#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int size = nums.size();
		if (size <= 1) return;
		for (int i = 0; i<size - 1; i++)
		{
			if (nums[i] == 0)
			{
				int tmp = 1;
				for (int j = i+1; j<size; j++)
				{
					if (nums[j] == 0)
					{
						tmp++;
					} else {
						nums[j-tmp] = nums[j];
						nums[j] = 0;
					}
				}
			}
		}
	}
};

int main()
{
	Solution x;
	x.moveZeroes(vector<int>{0,0,11,2});
	return 0;
}