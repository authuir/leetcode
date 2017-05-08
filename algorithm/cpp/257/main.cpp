class Solution {
private:
	vector<string> rtn;
	void Search(TreeNode * root, string path)
	{
		if (root == NULL) return;
		if (root->left == NULL && root->right == NULL)
		{
			ostringstream tmp;
			tmp << root->val;
			path = path + tmp.str();
			rtn.push_back(path);
		}
		if (root->left != NULL)
		{
			ostringstream tmp;
			tmp << root->val << "->";
			string path1 = path + tmp.str();
			Search(root->left, path1);
		}
		if (root->right != NULL)
		{
			ostringstream tmp;
			tmp << root->val << "->";
			string path2 = path + tmp.str();
			Search(root->right, path2);
		}
	}

public:
	vector<string> binaryTreePaths(TreeNode* root) {
		Search(root, "");
		return rtn;
	}
};