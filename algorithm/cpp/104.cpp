#include <iostream>
#include <math.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (root == NULL) return 0;
		int left = maxDepth(root->left);
		int right = maxDepth(root->right);
		int childdeep = left > right ? left : right;

		return 1 + childdeep;
	}
};

int main()
{
	Solution x;
	TreeNode tree(1);
	tree.left = new TreeNode(2);
	tree.right = new TreeNode(2);
	tree.left->left = new TreeNode(2);
	tree.left->left->left = new TreeNode(2);
	cout << x.maxDepth(&tree);
	return 0;
}