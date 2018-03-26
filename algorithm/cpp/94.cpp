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

	void pushit(TreeNode* root) {
		if (root == NULL)
			return;

		pushit(root->left);
		rtn.push_back(root->val);
		pushit(root->right);
		return;
	}

public:
	vector<int> inorderTraversal(TreeNode* root) {
		pushit(root);
		return rtn;
	}
};