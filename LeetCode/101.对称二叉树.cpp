/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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

#include <deque>

class Solution {
public:
    bool recursion(TreeNode *p, TreeNode *q) {
        // base case, if reach end, then true
        if (p == nullptr && q == nullptr) return true;

        // on
        if (p == nullptr || q == nullptr) return false;
        // return true if values match and continue comparing children
        return ( p->val == q->val && recursion(p->left, q->right) && recursion(p->right, q->left) );
    }

    bool isSymmetric(TreeNode* root) {
       if (root == nullptr) return false;
       return recursion(root->left, root->right);
    }

    // queue vs deque
    // deque also supports constant time insertion and removal of elements at the beginning of the sequence

    // ..

    // tests
    // [1,0] - root is wrong, can't add root->left
    // [1,2,2,null,3,3] - row doesn't have to be full to be symetrical
    
};
// @lc code=end

