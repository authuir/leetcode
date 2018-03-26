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
	bool _hasPathSum(TreeNode* root, int adder, int sum) {
		if (root == NULL) return false;
		if (root->left == NULL && root->right == NULL) {
			return (root->val + adder) == sum;
		}
		else if (root->left == NULL && root->right != NULL) return _hasPathSum(root->right, adder+ root->val, sum);
		else if (root->left != NULL && root->right == NULL) return _hasPathSum(root->left, adder + root->val, sum);
		else {
			bool a = _hasPathSum(root->right, adder + root->val, sum);
			bool b = _hasPathSum(root->left, adder + root->val, sum);
			return a || b;
		}
	}
public:
	bool hasPathSum(TreeNode* root, int sum) {
		return _hasPathSum(root, 0, sum);
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

	cout << x.hasPathSum(rtn, 1) << endl;
	cout << x.hasPathSum(rtn, 2) << endl;
	cout << x.hasPathSum(rtn, 3) << endl;
	cout << x.hasPathSum(rtn, 4) << endl;
	cout << x.hasPathSum(rtn, 5) << endl;
	return 0;
}