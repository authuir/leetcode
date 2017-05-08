#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		
		int size = nums.size();
		if (size == 1) return nums[0];
		int cnt = size / 2;
		
		 
		sort(nums.begin(), nums.end());
		vector<int>::iterator iter = nums.begin();
		int now = *iter;
		int now_cnt = 1;
		iter++;
		for (; iter != nums.end(); iter++)
		{
			if (*iter != now)
			{
				if (now_cnt > cnt)
				{
					return now;
				}
				else
				{
					now = *iter;
					now_cnt = 1;
				}
			}
			else
			{
				now_cnt++;
			}
		}
		if (now_cnt > cnt)
		{
			return now;
		}
		return NULL;
	}
};

int main(int argc, char * argv[])
{
	Solution x;
	cout << x.majorityElement(vector<int>{2,2});
	return 0;
}