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
	vector<int> stash;
	int cs = 0;

	void search(TreeNode* root, int height)
	{
		if (root == NULL) return;

		if (height > cs)
		{
			cs = height;
			stash.clear();
		}

		search(root->left, height + 1);

		if (height == cs)
			stash.push_back(root->val);

		search(root->right, height + 1);

		return;
	}

public:
	int findBottomLeftValue(TreeNode* root) {
		if (root == NULL) return 0;
		search(root, 0);
		return stash.front();
	}
};