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
private:
    vector<long> log;
    vector<long> count;
    void searchTree(TreeNode* root, int level)
    {
        if (root == NULL) return;
        while (level >= log.size())
        {
            log.push_back(0);
            count.push_back(0);
        }
        log[level] = log[level] + root->val;
        count[level]++;
        searchTree(root->left,  level+1);
        searchTree(root->right, level+1);
    }
    
public:
    vector<double> averageOfLevels(TreeNode* root) {
        searchTree(root, 0);
        vector<double> rtn;
        for (int i=0; i<log.size(); i++)
        {
            rtn.push_back(double(log[i]) / double(count[i]));
        }
        return rtn;
    }
};