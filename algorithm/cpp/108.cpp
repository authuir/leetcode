#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {

public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		int size = nums.size();
		if (size <= 0)
			return NULL;

		unsigned int mid = size / 2;
		TreeNode* rtn = new TreeNode(nums[mid]);

		if (size == 1) return rtn;
		if (size == 2) {
			rtn->left = new TreeNode(nums[0]);
			rtn->val = nums[1];
		}
		if (size == 3) {
			rtn->left = new TreeNode(nums[0]);
			rtn->val = nums[1];
			rtn->right = new TreeNode(nums[2]);
		}

		if (mid > 0)
		{
			vector<int> left; left.assign(nums.begin(), nums.begin() + mid  );
			rtn->left = sortedArrayToBST(left);//left
		}
			
		if (mid < size-1)
		{
			vector<int> right; right.assign(nums.begin()+mid+1, nums.end());
			rtn->right = sortedArrayToBST(right);//right
		}
		return rtn;
	}
};

int main()
{
	Solution x;
	TreeNode * rtn = x.sortedArrayToBST(vector<int> {0,1,2,3});
	rtn = x.sortedArrayToBST(vector<int> {0, 1, 2, 3, 4,5,6});
	return 0;
}