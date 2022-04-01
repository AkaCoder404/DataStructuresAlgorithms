/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    int abs(int x) {
        return x < 0 ? -1 * x : x;
    }
    int max(int x, int y) {
        return x > y ? x : y;
    }
    int treeHeight(TreeNode* root, bool &balanced) {
        if (root == nullptr || !balanced) {
            return 0;
        }
        int left = treeHeight(root->left, balanced);
        int right = treeHeight(root->right, balanced);
        
        // tree is unbalanced if abs dif of height between left and right is more than one
        if (abs(left - right) <= 1) {
            balanced = false;
        }
        return max(left, right) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        bool balanced = true;
        treeHeight(root, balanced);
        return balanced;

    }
};
// @lc code=end

