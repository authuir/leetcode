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
	int rtn = 0;
	int sum(TreeNode* root)
	{
		if (root == NULL) return 0;
		return sum(root->left) + root->val + sum(root->right);
	}
	void search(TreeNode* root)
	{
		if (root == NULL) return;
		if (root->left == NULL && root->right == NULL) return;
		rtn += abs(sum(root->left) - sum(root->right));
		search(root->left);
		search(root->right);
	}

public:
	int findTilt(TreeNode* root) {
		search(root);
		return rtn;
	}
};