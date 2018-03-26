#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
private:
	vector<set<int>> rtn;
	vector<int> used;

	void search(int i, vector<int>& nums, set<int>& rx)
	{
		if (rx.find(i) != rx.end())
		{
			return;
		}
		used[i] = 1;
		rx.insert(i);
		search(nums[i], nums, rx);
	}

public:
	int arrayNesting(vector<int>& nums) {
		used = vector<int>(nums.size(), 0);

		for (int i = 0; i < nums.size(); i++)
		{
			if (used[i] == 0)
			{
				used[i] = 1;
				rtn.push_back(set<int>{});
				search(i, nums, rtn.back());
			}
		}

		sort(rtn.begin(), rtn.end(), [](const set<int> &foo1, const set<int> &foo2){ 
			return (foo1.size() > foo2.size());
		});

		return rtn[0].size();
	}
};

int main(int argc, char * argv[])
{
	Solution x;
	cout << x.arrayNesting(vector<int>{5, 4, 0, 3, 1, 6, 2});

	return 0;
}