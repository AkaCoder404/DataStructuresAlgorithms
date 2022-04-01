/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public: 
    void recursion(TreeNode * root, vector<int>& nums) {
        if(root->left != nullptr) recursion(root->left, nums);
        if(root->right != nullptr) recursion(root->right, nums);
        nums.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr) return std::vector<int>();
        std::vector<int> nums;
        recursion(root, nums);
        return nums;
    }
};
// @lc code=end

