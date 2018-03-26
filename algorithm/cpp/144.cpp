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
	void view(TreeNode * root)
	{
		if (root == NULL)
			return;
		rtn.push_back(root->val);
		view(root->left);
		view(root->right);
	}

public:
	vector<int> preorderTraversal(TreeNode* root) {
		view(root);
		return rtn;
	}
};