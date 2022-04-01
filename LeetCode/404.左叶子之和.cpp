/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
    int sum = 0;
    int recursion(TreeNode* root, bool is_left) {
        if (root == nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr && is_left) {
            return root->val;
        } 
        return recursion(root->left, true) + recursion(root->right,false );
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return recursion(root, false);

    }

    // recursive approach, keep track if node is a left node
};
// @lc code=end

