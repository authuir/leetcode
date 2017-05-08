#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
	map<int, bool> se;

public:
	bool containsDuplicate(vector<int>& nums) {
		if (nums.size() == 0) return false;

		for (auto iter = nums.begin(); iter != nums.end(); iter++)
		{
			if (se.find(*iter) == se.end())
				se.insert({ *iter, true });
			else
				return true;
		}
		return false;
	}
};

int main(int argc, char* argv[])
{
	Solution x;

	cout << x.containsDuplicate(vector<int>{0,1,2,3,4});
	return 0;
}