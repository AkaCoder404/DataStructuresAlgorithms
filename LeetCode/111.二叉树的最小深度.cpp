/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
struct TreeNodeDepth {
    TreeNode* node;
    int depth;
    TreeNodeDepth(TreeNode* node, int depth) : node(node), depth(depth) {}
};

class Solution {
    int recursion(TreeNode* node, int cur_depth, int min_depth) {
        // no node, just return depth
        if (node == nullptr) return min_depth;
        // reach leaf node, check if current depth is smaller than min, if it is update
        if (node->left == nullptr && node->right == nullptr)  {
            if (cur_depth < min_depth) {
                min_depth = cur_depth;
                return min_depth;
            }
        }
        // stop searching any further because current depth is bigger than min_depth
        if (cur_depth > min_depth) return min_depth;

        // recursively search left and right side and return the smallest depth
        min_depth = min(recursion(node->left, cur_depth + 1, min_depth), recursion(node->right, cur_depth + 1, min_depth));
        return min_depth;
    }

    
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        // return recursion(root, 1, 10000);

        // BFS, find first leaf node, takes up more memory, but about 20 percent faster?
        std::deque<TreeNodeDepth* > q;
        TreeNodeDepth* temp;
        q.push_back(new TreeNodeDepth(root, 1));
        while(q.size() != 0) {
            temp = q.front();

            // if child node
            if (temp->node->left == nullptr && temp->node->right == nullptr) 
                return temp->depth;

            if(temp->node->left != nullptr) q.push_back(new TreeNodeDepth(temp->node->left, temp->depth + 1));
            if(temp->node->right != nullptr) q.push_back(new TreeNodeDepth(temp->node->right, temp->depth + 1));
            q.pop_front();
        }
        return 1;
    }
};
// @lc code=end

