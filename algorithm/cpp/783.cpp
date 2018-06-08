/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> gap;
    void search(TreeNode* root)
    {
        if (root == NULL)
            return;
        search(root->left);
        gap.push_back(root->val);
        search(root->right);
        return;
    }
    int minDiffInBST(TreeNode* root) {
        search(root);
        int rtn = 100000000;
        for (int i=0; i<gap.size()-1; i++)
        {
            int tmp = abs(gap[i] - gap[i+1]);
            if (rtn >  tmp)
                rtn = tmp;
        }
        return rtn;
    }
};