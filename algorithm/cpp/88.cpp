#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		if (n == 0) return;
		if (m == 0)
		{
			nums1 = nums2;
			return;
		}
		vector<int>::iterator tx = nums1.begin();
		for (int i = 0; i < m; i++)
		{
			tx++;
		}
		nums1.erase(tx, nums1.end());
		int nums2_index = 0;
		auto iter = nums1.begin();
		for (; iter != nums1.end(); iter++)
		{
			if (*iter > nums2[nums2_index])
			{
				iter = nums1.insert(iter, nums2[nums2_index]);
				nums2_index++;
				if (nums2_index >= n)
					break;
				continue;
			}
		}
		while (nums2_index < n)
		{
			nums1.insert(nums1.end(), nums2[nums2_index]);
			nums2_index++;
		}
		return;
	}
};

int main(int argc, char *argv[])
{
	vector<int> nums1 = {1,2,5,6,0,0,0};
	vector<int> nums2 = { 3,4,7,8 };
	Solution s1;
	s1.merge(nums1, 4, nums2, nums2.size());
	for (auto iter = nums1.begin(); iter != nums1.end(); iter++)
		cout << *iter <<" -> ";
	return 0;
}
