#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	bool is_equal(TreeNode* p, TreeNode* q) {
		if (p == NULL && q == NULL)
			return true;
		else if (p != NULL && q == NULL)
			return false;
		else if (p == NULL && q != NULL)
			return false;

		if (p->val != q->val)
			return false;

		if (is_equal(p->left, q->right) == false)
			return false;

		if (is_equal(p->right, q->left) == false)
			return false;

		return true;
	}
public:
	bool isSymmetric(TreeNode* root) {
		if (root == NULL)
			return true;

		return is_equal(root->left, root->right);
	}
};

int main()
{
	Solution x;

	TreeNode s1(1);
	s1.left = new TreeNode(2);
	s1.right = new TreeNode(2);
	cout << x.isSymmetric(&s1);

	TreeNode s2(1);
	s2.left = new TreeNode(2);
	s2.left->left = new TreeNode(3);
	s2.right = new TreeNode(2);
	s2.right->right = new TreeNode(3);
	cout << x.isSymmetric(&s2);
	
	return 0;

}