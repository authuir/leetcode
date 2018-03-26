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
	vector<int> data;
	TreeNode* rtn = new TreeNode(0);
	int cnt = 0;


	void search_copy(TreeNode* root, TreeNode* cp)
	{
		if (root == NULL)
			return;
		if (root->left != NULL)
		{
			cp->left = new TreeNode(0);
			search_copy(root->left, cp->left);
		}
		data.push_back(root->val);
		cp->val = root->val;
		if (root->right != NULL)
		{
			cp->right = new TreeNode(0);
			search_copy(root->right, cp->right);
		}
		return;
	}

	int pos(int num)
	{
		int rtn = 0;
		for (int i = num + 1; i<data.size(); i++)
		{
			rtn += data[i];
		}
		return rtn;
	}

	void search(TreeNode* root)
	{
		if (root == NULL)
			return;
		search(root->left);

		root->val = root->val + pos(cnt);
		cnt++;

		search(root->right);
	}

public:
	TreeNode* convertBST(TreeNode* root)
	{
		if (root == NULL)
			return NULL;
		search_copy(root, rtn);
		search(rtn);
		return rtn;
	}
};

class Solution2 {
private:
	vector<int> data;
	TreeNode* rtn = new TreeNode(0);
	int tmp = 0;

	void search_copy(TreeNode* root, TreeNode* cp)
	{
		if (root == NULL)
			return;

		if (root->right != NULL)
		{
			cp->right = new TreeNode(0);
			search_copy(root->right, cp->right);
		}

		data.push_back(root->val);
		cp->val = root->val + tmp;
		tmp = cp->val;

		if (root->left != NULL)
		{
			cp->left = new TreeNode(0);
			search_copy(root->left, cp->left);
		}

		return;
	}
public:
	TreeNode* convertBST(TreeNode* root)
	{
		if (root == NULL)
			return NULL;
		search_copy(root, rtn);
		return rtn;
	}
};
int main()
{
	TreeNode* input = new TreeNode(5);
	input->left = new TreeNode(2);
	input->right = new TreeNode(13);
	Solution2 x;
	x.convertBST(input);


	return 0;
}