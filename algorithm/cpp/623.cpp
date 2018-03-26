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
	int target_depth = 0;
	int target_value = 0;

	void travel(TreeNode* root, int depth)
	{

		if (root == NULL)
			return;

		if (depth == target_depth - 1)
		{
			if (root->left != NULL)
			{
				TreeNode * node_to_insert = new TreeNode(target_value);
				TreeNode * tmp = root->left;
				root->left = node_to_insert;
				root->left->left = tmp;
			}
			else {
				root->left = new TreeNode(target_value);
			}
			if (root->right != NULL)
			{
				TreeNode * node_to_insert = new TreeNode(target_value);
				TreeNode * tmp = root->right;
				root->right = node_to_insert;
				root->right->right = tmp;
			}
			else {
				root->right = new TreeNode(target_value);
			}
		}

		travel(root->left, depth + 1);
		travel(root->right, depth + 1);
	}

public:
	TreeNode* addOneRow(TreeNode* root, int v, int d) {
		if (d == 1)
		{
			TreeNode * node_to_insert = new TreeNode(v);
			node_to_insert->left = root;
			return node_to_insert;
		}

		this->target_depth = d;
		this->target_value = v;
		travel(root, 1);
		return root;
	}
};

int main()
{
	Solution x;
	TreeNode * head = new TreeNode(4);
	head->left = new TreeNode(2);
	head->left->left = new TreeNode(3);
	head->left->right = new TreeNode(1);

	x.addOneRow(head, 1, 3);
	return 0;
}
