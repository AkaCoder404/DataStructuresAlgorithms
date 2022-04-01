/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    void recursion(TreeNode* root, vector<int>& nums) {
        nums.push_back(root->val);
        if(root->left != nullptr) recursion(root->left, nums);
        if(root->right != nullptr) recursion(root->right, nums);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr) return vector<int>();
        std::vector<int> tree;
        recursion(root, tree);
        return tree;
    }
};
// @lc code=end

