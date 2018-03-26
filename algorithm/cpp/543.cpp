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
	int most_deep(TreeNode* root, int begin)
	{
		if (root == NULL)
			return begin;

		int left = most_deep(root->left, begin + 1);
		int right = most_deep(root->right, begin + 1);

		if (left > right)
			return left;
		else
			return right;
	}
	void search(TreeNode* root)
	{
		if (root == NULL)
			return;
		int tx = most_deep(root->left, 0) + most_deep(root->right, 0);
		if (tx > rtn)
			rtn = tx;
		search(root->left);
		search(root->right);
	}
public:
	int diameterOfBinaryTree(TreeNode* root) {
		if (root == NULL) return rtn;
		search(root);
		return rtn;
	}
};