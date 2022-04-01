/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    void recursion(TreeNode* root, vector<int>& result) {
        // left side first
        if (root->left != nullptr) recursion(root->left, result);

        // middle
        result.push_back(root->val);

        // right side
        if (root->right != nullptr) recursion(root->right, result);
    }


    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;
        recursion(root, result);
        return result;
    }


    // method 

    // testcases    
    // [] -> []
    // [1,2] -> [2,1]
    // [1,null,2] -> [1,2]
};
// @lc code=end

