/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
#include <math>

class Solution {
private:
	vector<int> storage;

	void search(TreeNode* root)
	{
		if (root == NULL)
			return;

		if (root->left != NULL)
			search(root->left);

		storage.push_back(root->val);

		if (root->right != NULL)
			search(root->right);

	}

public:
	int getMinimumDifference(TreeNode* root) {
		if (root == NULL)
			return 0;
		if (root->left == NULL && root->right == NULL)
			return 0;

		search(root);
		int rtn = storage[1] - storage[0];
		for (int i = 1; i<storage.size() - 1; i++)
		{
			int tmp = storage[i + 1] - storage[i];
			if (tmp < rtn)
				rtn = tmp;
		}

		return rtn;
	}
};