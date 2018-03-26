#include <vector>
#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		set<int> tmp;
		for (auto iter : nums)
		{
			if (tmp.find(iter) == tmp.end())
			{
				tmp.insert(iter);
			}
			else
			{
				tmp.erase(iter);
			}
		}
		vector<int>rtn;
		for (auto iter : tmp)
		{
			rtn.push_back(iter);
		}
		return rtn;
	}
};

int main()
{
	Solution x;
	x.singleNumber(vector<int>{1, 2, 1, 3, 2, 5});
	return 0;
}