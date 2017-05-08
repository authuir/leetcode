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
	vector<int> BST;
	void Search(TreeNode* root)
	{
		if (root == NULL) return;
		Search(root->left);
		BST.push_back(root->val);
		Search(root->right);
	}

public:
	vector<int> findMode(TreeNode* root) {
		Search(root);
		int max_cnt = 0;
		int cnt = 0;
		int num_in_cnt = 0xABCDEF;
		vector<int> rtn;
		for (int i = 0; i<BST.size(); i++)
		{
			if (BST[i] == num_in_cnt)
			{
				cnt++;
			}
			else
			{
				cnt = 1;
				num_in_cnt = BST[i];
			}

			if (cnt>max_cnt)
			{
				max_cnt = cnt;
				rtn.clear();
				rtn.push_back(num_in_cnt);
			}
			else if (cnt == max_cnt)
			{
				rtn.push_back(num_in_cnt);
			}
		}

		return rtn;
	}
};

int main()
{
	Solution x;

	TreeNode* head = new TreeNode(1);
	head->right = new TreeNode(2);
	//head->right->left = new TreeNode(2);

	x.findMode(head);

	return 0;
}