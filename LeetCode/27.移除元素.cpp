/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) nums[count++] = nums[i];
        }
        return count;
    }   
};
// @lc code=end

