/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode* recursion(int start, int end, vector<int>& nums) {
        // base case, no more splitting
        if (end - start < 1) return nullptr;

        // middle
        int mid = (start + end) / 2; 
        TreeNode* node = new TreeNode(nums[mid]);
        // insert left children
        node->left = recursion(start, mid, nums);
        // insert right children
        node->right = recursion(mid + 1, end, nums); 
        return node;
    }


    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) return nullptr;
        TreeNode* head = recursion(0, nums.size(), nums); 
        return head;
    }
    // method1 use array positions and link, fast, O(n), but takes up space bc store nodes
};
// @lc code=end

