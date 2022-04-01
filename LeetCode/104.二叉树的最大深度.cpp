/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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

    int recursion(TreeNode* root, int depth) {
        // base case, no more child nodes
        if (root == nullptr) return depth;
        return max(recursion(root->left, depth + 1), recursion(root->right, depth+1));
    }
    
    int maxDepth(TreeNode* root) {
        
        return recursion(root, 0);
    }   

    // method1 dfs, O(n), search each node once
};
// @lc code=end

