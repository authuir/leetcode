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
private:
	int Height(TreeNode* root,int deep) {
		if (root == NULL) return deep;
		deep++;
		int left = Height(root->left, deep);
		int right = Height(root->right, deep);
		return left > right ? left : right;
	}

public:
	bool isBalanced(TreeNode* root) {
		if (root == NULL) return true;
		if (root->left == NULL && root->right == NULL) return true;

		if (isBalanced(root->left) && isBalanced(root->right))
		{
			if (abs(Height(root->left,0) - Height(root->right,0)) <= 1)
				return true;
		}
		return false;
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

	cout << x.isBalanced(rtn);
	return 0;
}