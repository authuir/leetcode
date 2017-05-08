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
	int _minDepth(TreeNode* root, int deep) {
		if (root == NULL) return 0;
		if (root->left == NULL && root->right == NULL) return deep;
		else if (root->left == NULL && root->right != NULL) return _minDepth(root->right,deep + 1);
		else if (root->left != NULL && root->right == NULL) return _minDepth(root->left, deep + 1);
		else {
			int a = _minDepth(root->right, deep + 1);
			int b = _minDepth(root->left, deep + 1);
			return a < b ? a : b;
		}
	}

public:
	int minDepth(TreeNode* root) {
		return _minDepth(root, 1);
	}
};

int main()
{
	Solution x;
	TreeNode * rtn = new TreeNode(1);
	rtn->left = new TreeNode(1);
	rtn->left->left = new TreeNode(1);
	rtn->left->left->left = new TreeNode(1);
	rtn->left->right = new TreeNode(1);
	rtn->right = new TreeNode(1);

	cout << x.minDepth(rtn);
	return 0;
}