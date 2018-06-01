#include <algorithm>

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
    int max_at(vector<int>& nums, int begin, int end)
    {
        int rtn = begin;
        for (int i=begin; i<=end; i++){
            if (nums[rtn] < nums[i])
                rtn = i;
        }
        return rtn;
    }
    TreeNode* construct(vector<int>& nums, int begin, int end) {
        if (begin > end)
            return NULL;
        else if (begin == end)
            return new TreeNode(nums[begin]);
        
        int it = max_at(nums, begin, end);
        TreeNode* rtn = new TreeNode(nums[it]);
        rtn->left = construct(nums, begin, it-1);
        rtn->right = construct(nums, it+1, end);
        return rtn;
    }
    
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0) return NULL;
        TreeNode* Header = NULL;
        Header = construct(nums, 0, nums.size()-1);
        return Header;
    }
};