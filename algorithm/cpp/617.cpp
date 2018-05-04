#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    inline void cok(TreeNode* t, TreeNode* rtn)
    {
        if (t->left != NULL)
        {
            rtn->left = new TreeNode(0);
            adder(NULL, t->left, rtn->left);
        }
        if (t->right != NULL)
        {
            rtn->right = new TreeNode(0);
            adder(NULL, t->right, rtn->right);
        }
    }

    void adder(TreeNode* t1, TreeNode* t2, TreeNode* rtn)
    {
        if (t1 == NULL && t2 == NULL) return;
        else if (t1 == NULL && t2 != NULL)
        {
            rtn->val = t2->val;
            cok(t2, rtn);
        }
        else if (t1 != NULL && t2 == NULL)
        {
            rtn->val = t1->val;
            cok(t1, rtn);
        }
        else
        {
            rtn->val = t1->val + t2->val;
            if (t1->left != NULL || t2->left != NULL)
            {
                rtn->left = new TreeNode(0);
                adder(t1->left, t2->left, rtn->left);
            }
            if (t1->right != NULL || t2->right != NULL)
            {
                rtn->right = new TreeNode(0);
                adder(t1->right, t2->right, rtn->right);
            }
        }
    }

public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL && t2 == NULL) return NULL;
        TreeNode* rtn = new TreeNode(0);
        adder(t1,t2,rtn);
        return rtn;
    }
};