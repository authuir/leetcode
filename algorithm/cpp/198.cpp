#include <iostream>
#include <vector>
using namespace std;

#define max(a, b)  (((a) > (b)) ? (a) : (b))
class Solution {

private:
	int * maxarr;

	void print(vector<int> rtn)
	{
		int rx = 0;
		for (auto iter = rtn.begin(); iter != rtn.end(); iter++)
		{
			cout << *iter << "->";
			rx += *iter;
		}
		cout << endl;
	}

	int Search(vector<int> nums, int index, int adder)
	{
		if (maxarr[index] != -1) 
			return maxarr[index];
		vector<int> nums_bak = nums;
		nums.assign( nums.begin()+ index, nums.end() );
		int size = nums.size();
		if (size > 3)
		{
			int x1, x2;
			x2 = Search(nums_bak, index + 3, adder);
			x1 = Search(nums_bak, index + 2, adder);

			
			x2 += nums[1];
			x1 += nums[0];
			maxarr[index] = max(x1, x2);
			return maxarr[index];
		}
		else if (size == 3)
		{
			maxarr[index] = max(nums[0]+ nums[2], nums[1]);
			return maxarr[index]+adder;
		}
		else if (size == 2)
		{
			maxarr[index] = max(nums[0], nums[1]);
			return maxarr[index] + adder;
		}
		else if (size == 1)
		{
			maxarr[index] = nums[0];
			return maxarr[index] + adder;
		}
		else if (size == 0)
		{
			maxarr[index] = adder;
			return maxarr[index];
		}
	}

public:
	int rob(vector<int>& nums) {
		int size = nums.size();
		if (size <= 0) return 0;
		if (size == 0) return nums[0];
		maxarr = new int[size];
		for (int i = 0; i < size; i++) maxarr[i] = -1;

		int rtn1 = Search(nums,0,0);
		int rtn2 = Search(nums, 1, 0);
		delete maxarr;
		return max(rtn1,rtn2);
	}
};

int main()
{
	Solution x;
	//cout << x.rob(vector<int> {114, 117, 207, 117, 235, 82, 90, 67, 143, 146, 53, 108, 200, 91, 80, 223, 58, 170, 110, 236, 81, 90, 222, 160, 165, 195, 187, 199, 114, 235, 197, 187, 69, 129, 64, 214, 228, 78, 188, 67, 205, 94, 205, 169, 241, 202, 144, 240});
	cout << x.rob(vector<int> {4,1,2,7,5,3,1});
	return 0;
}