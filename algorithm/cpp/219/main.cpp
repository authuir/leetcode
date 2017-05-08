#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
	map<int, int> se;

public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		if (nums.size() == 0) return false;
		int i = 0;
		for (auto iter = nums.begin(); iter != nums.end(); iter++,i++)
		{
			if (se.find(*iter) == se.end())
				se.insert({ *iter, i });
			else
			{
				if ((i - se[*iter]) <= k)
					return true;
				else if ((i - se[*iter]) < k)
					se[*iter] = i;
			}
		}
		return false;
	}
};

int main(int argc, char* argv[])
{
	Solution x;

	cout << x.containsNearbyDuplicate(vector<int>{1, 0, 1, 1}, 1);
	return 0;
}