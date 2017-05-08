#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		vector<int> rtn;
		for (auto iter1 = nums1.begin(); iter1 != nums1.end();)
		{
			for (auto iter2 = nums2.begin(); iter2 != nums2.end();)
			{
				if (*iter1 == *iter2)
				{
					rtn.push_back(*iter1);
					iter1 = nums1.erase(iter1, iter1 + 1);
					iter2 = nums2.erase(iter2, iter2 + 1);
				}
				if (iter2 != nums2.end())
					iter2++;
			}
			if (iter1 != nums1.end())
				iter1++;
		}
		return rtn;
	}
};

int main()
{
	Solution x;
	x.intersect(vector<int>{4, 7, 9, 7, 6, 7}, vector<int>{5, 0, 0, 6, 1, 6, 2, 2, 4});
	return 0;
}