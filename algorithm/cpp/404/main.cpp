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
	int sum(TreeNode* root)
	{
		if (root == NULL) return 0;

		int left = 0;

		if (root->left != NULL)
		{
			if (root->left->left == NULL && root->left->right == NULL)
				left += root->left->val;
			else
				left += sum(root->left);
		}
		if (root->right != NULL)
		{
			left += sum(root->right);
		}
		return left;
	}

public:
	int sumOfLeftLeaves(TreeNode* root) {
		if (root == NULL) return 0;

		return sum(root);
	}
};