/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
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
    void recursion(TreeNode *p , TreeNode *q) {
        // false if
        // 1. not same
        // 2. only one of child nodes is nullptr, while other does not
        // 3. current node is null
        if (
            (p == nullptr || q == nullptr) ||
            p->val != q->val || 
            ((p->left != nullptr && q->left == nullptr) || (p->left == nullptr && q->left != nullptr)) ||
            ((p->right != nullptr && q->right == nullptr) || (p->right == nullptr && q->right != nullptr))
        ) {
            throw false;
        }
       
        // if both are not null, keep iterating
        if (p->left != nullptr && q->left != nullptr) recursion(p->left, q->left);
        if (p->right != nullptr &&  q->right != nullptr) recursion(p->right, q->right);
    }

    bool recursion_2(TreeNode *p, TreeNode *q) {
        // both reach nullptr at same time, true
        if (p == nullptr && q == nullptr) return true;
        // if on one reach nullptr and other doesn't, false
        if (p == nullptr || q == nullptr) return false;

        //
        return (p->val == q->val && recursion_2(p->left, q->left) && recursion_2(p->right, q->right));
    }


    bool isSameTree(TreeNode* p, TreeNode* q) {
        // if (p == nullptr && q == nullptr) return true; 
        // bool isSame = true;
        // try {
        //     recursion(p, q);
        // }
        // catch (bool e) {
        //     isSame = e;
        // }

        // // recursion(p, q, isSame);
        // return isSame;
        return recursion_2(p, q);
    }

    // testcases
    // [1,2,3]\n[1,2,3] true
    // [1,2]\n[1,null,2] false
    // [1,2,1]\n[1,1,2] false
    // [1,2,1]\n[1,2,2] false

    // []\n[] true
    // []\n[0] false


};
// @lc code=end

