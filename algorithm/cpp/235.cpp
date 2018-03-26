#include <vector>
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
	vector<TreeNode *> p_path;
	vector<TreeNode *> q_path;
	void Search(TreeNode* root, TreeNode* p, TreeNode* q, vector<TreeNode*> path)
	{
		path.push_back(root);
		if (root == NULL) return;
		if (root == p) { p_path = path; }
		if (root == q) { q_path = path; }
		if (!p_path.empty() && !q_path.empty()) return;
		Search(root->left, p, q, path);
		Search(root->right, p, q, path);
		return;
	}

public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (p == NULL || q == NULL || root == NULL) return NULL;
		vector<TreeNode *> route;
		Search(root, p, q, route);
		if (p_path.empty() || q_path.empty()) return NULL;
		for (int i = p_path.size()-1; i >= 0; i--)
		{
			TreeNode * temp = p_path[i];
			for (int j = q_path.size()-1; j >= 0; j--)
			{
				if (temp == q_path[j])
					return temp;
			}
		}
		return NULL;
	}
};

int main()
{
	Solution x;
	TreeNode head(2);
	head.left = new TreeNode(1);
	head.right = new TreeNode(3);
	x.lowestCommonAncestor(&head, head.left, head.right);
	return 0;
}