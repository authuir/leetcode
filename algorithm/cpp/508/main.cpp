#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	vector<long signed int> rtn;

	int search(TreeNode* root)
	{
		int left = 0;
		int right = 0;
		if (root == NULL)
			return 0;
		if (root->left != NULL)
		{
			left = search(root->left);
		}

		if (root->right != NULL)
		{
			right = search(root->right);
		}

		rtn.push_back(left + right + root->val);

		return (left + right + root->val);
	}

public:
	vector<int> findFrequentTreeSum(TreeNode* root) {
		search(root);
		
		sort(rtn.begin(), rtn.end());

		int cnt = 0;
		int maxcnt = 1;
		int lgo = 0;

		vector<int> rtnx;

		for (auto x = rtn.begin(); x != rtn.end(); x++)
		{
			if (cnt == 0)
				lgo = *x;
			if (lgo == *x)
				cnt++;
			else
			{
				if (maxcnt == cnt)
					rtnx.push_back(lgo);
				else if (maxcnt < cnt)
				{
					rtnx.clear();
					rtnx.push_back(lgo);
					maxcnt = cnt;
				}
				lgo = *x;
				cnt = 1;
			}
		}
		if (maxcnt == cnt)
			rtnx.push_back(lgo);
		else if (maxcnt < cnt)
		{
			rtnx.clear();
			rtnx.push_back(lgo);
			maxcnt = cnt;
		}

		return rtnx;
	}
};

int main()
{
	Solution x;
	TreeNode * head = new TreeNode(5);
	head->left = new TreeNode(2);
	head->right = new TreeNode(-5);
	x.findFrequentTreeSum(head);
	return 0;
}