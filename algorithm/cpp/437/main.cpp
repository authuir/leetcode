#include <iostream>
#include <vector>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	int sx = 0;
	int rtn = 0;
	void pathSums(TreeNode* root, int sum) {
		if (root == NULL) return;
		if (root->val == sum) rtn++;
		pathSums(root->left, sum - root->val);
		pathSums(root->right, sum - root->val);
	}
	void p2(TreeNode* root, int sum)
	{
		if (root == NULL) return;
		pathSums(root->left, sx);
		pathSums(root->right, sx);
		if (root->left != NULL)
			p2(root->left, sx);
		if (root->right != NULL)
			p2(root->right, sx);
	}

public:
	int pathSum(TreeNode* root, int sum) {
		sx = sum;
		p2(root, sum);
		pathSums(root, sum);
		return rtn;
	}
};

int main()
{
	Solution x;
	TreeNode * head = new TreeNode(1);
	head->right = new TreeNode(2);
	head->right->right = new TreeNode(3);
	head->right->right->right = new TreeNode(4);
	head->right->right->right->right = new TreeNode(5);


	cout << x.pathSum(head ,3);
	
	return 0;
}