#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int thirdMax(vector<int>& nums) {
		int size = nums.size();
		if (size == 0) return 0;
		if (size == 1) return nums[0];
		if (size == 2) return nums[0] > nums[1] ? nums[0] : nums[1];

		vector<int> sis;
		int cnt = 0;
		for (int i = 0; i<size; i++)
		{
			if (cnt < 3)
			{
				switch (cnt)
				{
					case 0: sis.push_back(nums[i]);cnt++;break;
					case 1: {
						if (nums[i] == sis[0])
							break;
						else if (nums[i] > sis[0])
						{
							sis.push_back(sis[0]);
							cnt++;
							sis[0] = nums[i];
						}
						else
						{
							sis.push_back(nums[i]);
							cnt++;
						}
						break;
					}
					case 2: {
						if (nums[i] == sis[0])
							break;
						else if (nums[i] > sis[0])
						{
							sis.push_back(sis[1]);
							sis[1] = sis[0];
							sis[0] = nums[i];
							cnt++;
						}
						else
						{
							if (nums[i] == sis[1])
								break;
							else if (nums[i] > sis[1])
							{
								sis.push_back(sis[1]);
								sis[1] = nums[i];
								cnt++;
							}
							else
							{
								sis.push_back(nums[i]);
								cnt++;
							}
						}
						break;
					}
				}
			}
			else
			{
				if (nums[i] == sis[0] || nums[i] == sis[1] || nums[i] == sis[2])
					continue;
				else if (nums[i] > sis[0])
				{
					sis[2] = sis[1];
					sis[1] = sis[0];
					sis[0] = nums[i];
				}
				else if (nums[i] > sis[1])
				{
					sis[2] = sis[1];
					sis[1] = nums[i];
				}
				else if (nums[i] > sis[2])
				{
					sis[2] = nums[i];
				}
			}
		}

		if (cnt == 1)
			return sis[0];
		else if (cnt == 2)
			return sis[0];
		else if (cnt == 3)
			return sis[2];
		return 0;
	}
};

int main()
{
	Solution x;

	x.thirdMax(vector<int> {1, 2, 2, 5, 3, 5});

	return 0;
}