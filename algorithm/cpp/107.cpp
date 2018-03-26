#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	void Search(TreeNode * root, vector<int>& data, vector<int>& level, int deep)
	{
		if (root == NULL)
			return;
		Search(root->left, data, level, deep + 1);
		Search(root->right, data, level, deep + 1);
		data.insert(data.end(), root->val);
		level.insert(level.end(), deep);
		return;
	}

public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> rtn;
		if (root == NULL) return rtn;
		vector<int> data;
		vector<int> level;
		Search(root, data, level, 0);
		for (int i = 0; i < data.size(); i++)
		{
			//cout << data[i] << ',' << level[i] << endl;
			while (rtn.size() < level[i]+1)
			{
				vector<int> lst;
				rtn.insert(rtn.end(), lst);
			}
			rtn[level[i]].insert(rtn[level[i]].end(), data[i]);
		}
		reverse(rtn.begin(),rtn.end());
		return rtn;
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
	vector<vector<int>> saver = x.levelOrderBottom(&tree);
	cout << saver.size() << endl;

	for (auto iter = saver.begin(); iter != saver.end(); iter++)
		cout << 't';
	return 0;
}
