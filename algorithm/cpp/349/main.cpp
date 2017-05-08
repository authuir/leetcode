#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		vector<int> rtn;
		for (auto iter2 = nums2.begin(); iter2 != nums2.end(); iter2++)
		{
			if (find(rtn.begin(), rtn.end(), *iter2) == rtn.end())
			{
				for (auto iter1 = nums1.begin(); iter1 != nums1.end(); iter1++)
				{
					if (*iter1 == *iter2)
						if (find(rtn.begin(), rtn.end(), *iter1) == rtn.end())
							rtn.push_back(*iter1);
				}
			}
		}
		return rtn;
	}
};