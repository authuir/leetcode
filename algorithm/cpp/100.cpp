#include <iostream>

using namespace std;

 struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}	
};



class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == NULL && q == NULL)
			return true;
		else if (p != NULL && q == NULL)
			return false;
		else if (p == NULL && q != NULL)
			return false;

		if (p->val != q->val)
			return false;

		if (isSameTree(p->left, q->left) == false)
			return false;

		if (isSameTree(p->right, q->right) == false)
			return false;

		return true;
	}
};

int main()
{
	Solution x;

	TreeNode s1(1);
	s1.left = new TreeNode(2);
	s1.right = new TreeNode(3);

	TreeNode s2(1);
	s2.left = new TreeNode(2);
	s2.right = new TreeNode(3);
	
	cout << x.isSameTree(&s1, &s2);
	
	return 0;

}