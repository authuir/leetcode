#include <iostream>
#include <vector>

using namespace std;

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

class Solution {
private:
	vector<int> rtn;

	void search(TreeNode * root, int level) {
		if (root == NULL)
			return;

		if (rtn.size() <= level)
			rtn.push_back(root->val);
		else if (root->val > rtn[level])
			rtn[level] = root->val;

		if (root->left != NULL)
			search(root->left, level + 1);
		if (root->right != NULL)
			search(root->right, level + 1);
	}

public:
	vector<int> largestValues(TreeNode* root) {
		search(root, 0);
		return rtn;
	}
};