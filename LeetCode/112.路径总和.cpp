/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool recursion(TreeNode* root, int currentSum, int targetSum) {
        // path has no more to add, return false
        if (root == nullptr) return false;

        // if current node + sum is target, also has to be leaf node
        if (root->val + currentSum == targetSum  && (root->left == nullptr && root->right == nullptr)) return true;

        // if not reach target, continue on with left and right
        // search left and right, also has to be a leaf node to root node
        return 
            ( recursion(root->left, currentSum + root->val, targetSum) || 
            recursion(root->right, currentSum + root->val, targetSum));
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return recursion(root, 0, targetSum);

    }
};
// @lc code=end

