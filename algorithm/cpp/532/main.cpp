#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int findPairs(vector<int>& nums, int k) {
		if (k < 0) return 0;
		int size = nums.size();
		vector<pair<int, int>> sto;
		for (int i = 0; i<size - 1; i++)
			for (int j = i+1; j<size; j++)
			{
				if (nums[i] - nums[j] == k)
				{
					if (find(sto.begin(), sto.end(), pair<int, int>{nums[i], nums[j]}) == sto.end())
					{
						sto.push_back(pair<int, int>{nums[i], nums[j]});
					}
				}
				else if (nums[j] - nums[i] == k)
				{
					if (find(sto.begin(), sto.end(), pair<int, int>{nums[j], nums[i]}) == sto.end())
					{
						sto.push_back(pair<int, int>{nums[j], nums[i]});
					}
				}
			}
		return sto.size();
	}
};

int main()
{
	Solution x;
	x.findPairs(vector<int>{1, 3, 1, 5, 4}, 0);
	
	return 0;

}